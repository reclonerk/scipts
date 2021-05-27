import glob
import os

# Function to remove files/content in a folder
def remove_files_folder():
    files = glob.glob('Tasks/*')
    for f in files:
        os.remove(f)


remove_files_folder()