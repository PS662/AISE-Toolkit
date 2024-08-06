import os
import sys
import subprocess
import argparse
import requests
from urllib.parse import urljoin
from pytubefix import YouTube
from pytubefix.cli import on_progress

def get_youtube_video_url(video_url):
    try:
        yt = YouTube(video_url)
        # Try to get the best progressive stream.
        stream = yt.streams.filter(progressive=True, file_extension='mp4').order_by('resolution').desc().first()
        
        # If no progressive stream, try adaptive streams.
        if not stream:
            stream = yt.streams.filter(adaptive=True, file_extension='mp4').order_by('resolution').desc().first()
        
        # Handle live streams by attempting to fetch HLS or DASH URL.
        if not stream:
            streaming_data = yt.vid_info.get('streamingData', {})
            hls_url = streaming_data.get('hlsManifestUrl')
            dash_url = streaming_data.get('dashManifestUrl')
            return hls_url or dash_url

        if stream:
            return stream.url
    except Exception as e:
        print(f"Error occurred while fetching video URL: {e}")
        return None


def download_youtube_video(video_url, output_path):
    try:
        yt = YouTube(video_url, on_progress_callback=lambda stream, chunk, bytes_remaining: print(f"Downloading... {100 - int(bytes_remaining / stream.filesize * 100)}% complete"))
        print(f"Downloading video: {yt.title}")
        stream = yt.streams.get_highest_resolution()
        os.makedirs(output_path, exist_ok=True)
        stream.download(output_path=output_path)
        print(f"Downloaded video: {yt.title} to {output_path}")
    except Exception as e:
        print(f"An error occurred while downloading the video: {e}")

    
def download_from_git(git_url, destination_dir):
    """Download a repository from a given Git URL to the specified directory."""
    repo_name = git_url.split('/')[-1]
    if repo_name.endswith('.git'):
        repo_name = repo_name[:-4]  # Remove the .git from the end
    
    # Create the full path where the repo will be cloned
    full_path = os.path.join(destination_dir, repo_name)

    # Create the destination directory if it doesn't exist
    if not os.path.exists(full_path):
        os.makedirs(full_path)
    try:
        subprocess.run(['git', 'clone', git_url, full_path], check=True)
        print(f"Repository successfully cloned to {destination_dir}")
    except subprocess.CalledProcessError as e:
        print(f"An error occurred while cloning the repository: {e}")
        sys.exit(1)


def add_common_arguments(parser):
    """Adds common arguments to the provided subparser."""
    parser.add_argument('--dest', type=str, required=True, help="Destination directory for downloads. If not provided, the DATA_ROOT_DIR environment variable will be used.")


def main():
    parser = argparse.ArgumentParser(description="Download datasets to a specified directory.")
    subparsers = parser.add_subparsers(dest='command', required=True, help='Sub-command help')

    # Subcommand for downloading from Git
    parser_git = subparsers.add_parser('download-from-git', help='Download a repository from a Git URL')
    parser_git.add_argument('--git-url', type=str, required=True, help='URL of the Git repository')
    add_common_arguments(parser_git)

    # Subcommand for downloading from a URL
    parser_url = subparsers.add_parser('download-from-url', help='Download a YouTube video from a URL')
    parser_url.add_argument('--url', type=str, required=True, help='URL of the YouTube video to download')
    add_common_arguments(parser_url)

    # Subcommand for getting a URL
    parser_get_url = subparsers.add_parser('get-url', help='Get the stream URL of a YouTube video')
    parser_get_url.add_argument('--url', type=str, required=True, help='URL of the YouTube video to get the stream URL from')
    add_common_arguments(parser_get_url)

    args = parser.parse_args()


    # Check for the destination directory argument or environment variable
    destination_dir = args.dest or os.getenv('DATA_ROOT_DIR')
    if not destination_dir:
        parser.print_help()
        print("\nError: You must specify a destination directory using --dest or set the DATA_ROOT_DIR environment variable.")
        sys.exit(1)

    # Create the destination directory if it doesn't exist
    if not os.path.exists(destination_dir):
        os.makedirs(destination_dir)

    # Proceed to download the specified datasets
    if args.command == 'download-from-git':
        download_from_git(args.git_url, destination_dir)
    elif args.command == 'download-from-url':
        download_youtube_video(args.url, destination_dir)
    elif args.command == 'get-url':
        video_url = get_youtube_video_url(args.url)
        print(f"Video URL: {video_url}")

    else:
        parser.print_help()
        print("\nError: You must specify a subcommand (download-from-git or download-from-url).")
        sys.exit(1)

if __name__ == "__main__":
    main()
