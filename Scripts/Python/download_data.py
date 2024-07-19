import os
import sys
import subprocess
import argparse
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin

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


def main():
    parser = argparse.ArgumentParser(description="Download datasets to a specified directory.")
    parser.add_argument('--dest', type=str, help="Destination directory to download the datasets. If not provided, the DATA_ROOT_DIR environment variable will be used.")

    subparsers = parser.add_subparsers(dest='command', required=True, help='Sub-command help')

    parser_git = subparsers.add_parser('download-from-git', help='Download a repository from a Git URL')
    parser_git.add_argument('--git-url', type=str, required=True, help='URL of the Git repository')

    parser_url = subparsers.add_parser('download-from-url', help='Download content from a URL')
    parser_url.add_argument('--url', type=str, required=True, help='URL to download content from')

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
    else:
        parser.print_help()
        print("\nError: You must specify a subcommand (download-from-git or download-from-url).")
        sys.exit(1)

if __name__ == "__main__":
    main()
