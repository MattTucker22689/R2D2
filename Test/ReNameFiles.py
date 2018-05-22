# Author: Matt Tucker
# Date: 15June17
# Description: This program runs through a folder and renames every file numerically. For example, the first file is
#              labeled 1, the second is labeled 2, and so on.
# Note: As an observation I had to delete the file labeled 1 when done, it was .DS_Store -> 1

import os

# Path to folder which files exist in
path = input("Input the directory path here: ")
print(path)
# Starts naming files at 1
i = 1
for filename in os.listdir(path):
    print(filename)
    # Rest of Code
    filename_without_ext = os.path.splitext(filename)[0]
    extension = os.path.splitext(filename)[1]
    # Name file current value of i
    new_file_name = str(i)
    new_file_name_with_ext = new_file_name + extension
    print(new_file_name_with_ext)
    os.rename(os.path.join(path, filename), os.path.join(path, new_file_name_with_ext))
    # increase value by 1 so the next value is the next integer value
    i += 1
