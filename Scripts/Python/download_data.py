import os
import sys
import subprocess
import argparse

def download_intel_sample_videos(destination_dir):
    """Download Intel sample videos to the specified directory."""
    try:
        subprocess.run(['git', 'clone', 'https://github.com/intel-iot-devkit/sample-videos', os.path.join(destination_dir, 'sample-videos')], check=True)
        print(f"Intel sample videos successfully cloned to {destination_dir}")
    except subprocess.CalledProcessError as e:
        print(f"An error occurred while cloning the Intel sample videos repository: {e}")
        sys.exit(1)


def main():
    parser = argparse.ArgumentParser(description="Download datasets to a specified directory.")
    parser.add_argument('--dest', type=str, help="Destination directory to download the datasets.")
    
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('--intel-sample-videos', action='store_true', help="Download Intel sample videos.")
    group.add_argument('--download-all', action='store_true', help="Download all datasets.")

    args = parser.parse_args()

    # Check for the destination directory argument or environment variable
    destination_dir = args.dest or os.getenv('DATA_ROOT_DIR')

    if not destination_dir:
        print("Usage: python script.py --dest <destination_directory> --intel-sample-videos")
        print("or set the environment variable DATA_ROOT_DIR to specify the destination directory.")
        sys.exit(1)

    # Create the destination directory if it doesn't exist
    if not os.path.exists(destination_dir):
        os.makedirs(destination_dir)

    # Proceed to download the specified datasets
    if args.intel_sample_videos:
        download_intel_sample_videos(destination_dir)
    elif args.download_all:
        download_intel_sample_videos(destination_dir)

if __name__ == "__main__":
    main()