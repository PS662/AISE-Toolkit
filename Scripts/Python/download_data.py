import os
import sys
import subprocess
import argparse

def download_from_git(destination_dir, git_url):
    """Download a repository from a given Git URL to the specified directory."""
    try:
        subprocess.run(['git', 'clone', git_url, destination_dir], check=True)
        print(f"Repository successfully cloned to {destination_dir}")
    except subprocess.CalledProcessError as e:
        print(f"An error occurred while cloning the repository: {e}")
        sys.exit(1)

def main():
    parser = argparse.ArgumentParser(description="Download datasets to a specified directory.")
    parser.add_argument('--dest', type=str, help="Destination directory to download the datasets. If not provided, the DATA_ROOT_DIR environment variable will be used.")

    subparsers = parser.add_subparsers(dest='command', required=True, help='Sub-command help')

    # Subparser for downloading from Git
    parser_git = subparsers.add_parser('download-from-git', help='Download a repository from a Git URL')
    parser_git.add_argument('--git-url', type=str, required=True, help='URL of the Git repository')
    parser_git.set_defaults(func=download_from_git)

    # Subparser for downloading all datasets
    parser_all = subparsers.add_parser('download-all', help='Download all datasets')
    parser_all.set_defaults(func=lambda args: download_from_git(args.dest, 'https://github.com/intel-iot-devkit/sample-videos'))

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
        args.func(destination_dir, args.git_url)
    elif args.command == 'download-all':
        args.func(destination_dir, 'https://github.com/intel-iot-devkit/sample-videos')

if __name__ == "__main__":
    main()
