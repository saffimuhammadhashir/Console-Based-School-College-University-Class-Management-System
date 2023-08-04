// Include necessary header files


/*          EXPLAINATION            */
/*The provided code defines the implementation of the `FileManager` class. This class appears to provide functionalities to manage files in a file folder.
 It includes the following member functions:

1. `upload_File_in_file_folder(string &file_name_in_file_folder, string &content)`:
   - This function takes a `file_name_in_file_folder` and `content` as input parameters.
   - It attempts to open the file with the given name for writing and writes the provided content into the file.
   - If the file is successfully opened and written, it displays a success message; otherwise, it displays an error message.

2. `download_File_in_file_folder(string &file_name_in_file_folder)`:
   - This function takes a `file_name_in_file_folder` as an input parameter.
   - It attempts to open the file with the given name for reading.
   - If the file exists and can be opened, it reads the file line by line and returns the entire content as a string.
   - It displays a success message after downloading the file.
   - If the file doesn't exist or cannot be opened, it displays an error message and returns an empty string.

3. `delete_File_in_file_folder(string &file_name_in_file_folder)`:
   - This function takes a `file_name_in_file_folder` as an input parameter.
   - It checks if the file exists in the folder using the `file_Exists_in_file_folder` helper method.
   - If the file exists, it attempts to delete the file using the `remove` function.
   - If the file is successfully deleted, it displays a success message; otherwise, it displays an error message.

4. `display_FileContent_in_file_folder(string &file_name_in_file_folder)`:
   - This function takes a `file_name_in_file_folder` as an input parameter.
   - It calls the `download_File_in_file_folder` function to get the content of the file.
   - If the content is not empty (i.e., the file exists and can be read), it displays the file name and its content.
   - If the content is empty or the file doesn't exist, it displays an error message.

5. `file_Exists_in_file_folder(string &file_name_in_file_folder)`:
   - This is a helper method that takes a `file_name_in_file_folder` as an input parameter.
   - It checks if the file exists in the folder by attempting to open the file in ifstream mode.
   - It returns `true` if the file is in a good state (i.e., it exists and can be read), otherwise returns `false`.

Overall, the `FileManager` class provides basic file management functionalities such as uploading content to a file, downloading content
 from a file, deleting a file, and displaying the content of a file. The class assumes that the file folder exists and the file operations
  are performed in that folder. The `FileManager` class is designed to be used with the `fstream` library for file handling in C++.*/
#pragma once

#include<iostream>

// Include the custom FileManager header file
#include "FileManager.h"

using namespace std;

// Function to upload a file to the file folder
/*upload_File_in_file_folder(string &file_name_in_file_folder, string &content):

Takes the file_name_in_file_folder and content as input parameters.
Creates an ofstream object to handle file writing.
Writes the content to the file and closes it.
If the file cannot be opened, it displays an error message.*/
void FileManager::upload_File_in_file_folder(string &file_name_in_file_folder, string &content) {
    // Create an ofstream object to handle file writing
    ofstream file(file_name_in_file_folder);

    // Check if the file is open
    if (file.is_open()) {
        // Write the content to the file
        file << content;
        // Close the file and provide a success message
        file.close();
        cout << "File '" << file_name_in_file_folder << "' uploaded successfully.\n";
    } else {
        // If the file couldn't be opened, display an error message
        cout << "Error uploading file '" << file_name_in_file_folder << "'.\n";
    }
}

// Function to download a file from the file folder

/*download_File_in_file_folder(string &file_name_in_file_folder):

Takes file_name_in_file_folder as an input parameter.
Creates an ifstream object to handle file reading.
Reads the content of the file line by line and stores it in the content string.
If the file is not found or cannot be opened, it displays an error message.
Returns the downloaded content as a string.*/string FileManager::download_File_in_file_folder(string &file_name_in_file_folder) {
    // Create an ifstream object to handle file reading
    ifstream file(file_name_in_file_folder);
    string content, line;

    // Check if the file exists in the folder
    if (file_Exists_in_file_folder(file_name_in_file_folder)) {
        // Check if the file is open
        if (file.is_open()) {
            // Read each line of the file and store it in the content string
            while (getline(file, line)) {
                content += line + "\n";
            }
            // Close the file and provide a success message
            file.close();
            cout << "File '" << file_name_in_file_folder << "' downloaded successfully.\n";
        } else {
            // If the file couldn't be opened, display an error message
            cout << "Error downloading file '" << file_name_in_file_folder << "'. File not found.\n";
        }
    }
    // Return the downloaded content
    return content;
}

// Function to delete a file from the file folder
/*delete_File_in_file_folder(string &file_name_in_file_folder):

Takes file_name_in_file_folder as an input parameter.
Checks if the file exists in the file folder using the file_Exists_in_file_folder helper method.
If the file exists, it attempts to remove the file using the remove() function.
Displays a success message if the file is deleted, or an error message if the file cannot be deleted or is not found.*/
void FileManager::delete_File_in_file_folder(string &file_name_in_file_folder) {
    // Check if the file exists in the folder
    if (file_Exists_in_file_folder(file_name_in_file_folder)) {
        // Attempt to remove the file
        if (remove(file_name_in_file_folder.c_str()) == 0) {
            // Display a success message if the file was deleted
            cout << "File '" << file_name_in_file_folder << "' deleted successfully.\n";
        } else {
            // Display an error message if the file couldn't be deleted
            cout << "Error deleting file '" << file_name_in_file_folder << "'. File not found.\n";
        }
    } else {
        // Display a message if the file doesn't exist
        cout << "File '" << file_name_in_file_folder << "' does not exist.\n";
    }
}

// Function to display the content of a file from the file folder
/*display_FileContent_in_file_folder(string &file_name_in_file_folder):

Takes file_name_in_file_folder as an input parameter.
Calls the download_File_in_file_folder method to download the content of the file.
If the content is not empty, it displays the file name and its content.
If the content is empty or the file doesn't exist, it displays an error message.*/
void FileManager::display_FileContent_in_file_folder(string &file_name_in_file_folder) {
    // Download the file content using the download function
    string content = download_File_in_file_folder(file_name_in_file_folder);

    // Check if the content is not empty
    if (!content.empty()) {
        // Display the file name and its content
        cout << "File '" << file_name_in_file_folder << "' content:\n";
        cout << content;
    } else {
        // Display an error message if the content is empty or the file doesn't exist
        cout << "Error reading file '" << file_name_in_file_folder << "'. File not found or empty.\n";
    }
}
/*file_Exists_in_file_folder(string &file_name_in_file_folder):

Takes file_name_in_file_folder as an input parameter.
Creates an ifstream object to check if the file exists.
Returns true if the file is in good state (exists) or false otherwise.*/
// Helper method to check if the file exists in the folder
bool FileManager::file_Exists_in_file_folder(string &file_name_in_file_folder) {
    // Create an ifstream object to check if the file exists
    ifstream file(file_name_in_file_folder);
    // Return true if the file is in good state (exists)
    return file.good();
}
/*The FileManager class utilizes input and output file streams (ifstream and ofstream) to perform file operations
 like reading and writing. The class provides functions to upload content to a file, download content from a file, delete files,
  and display the content of a file. Additionally, it has a helper method to check if a file exists in the file folder.

Overall, this FileManager class can be used as a utility for handling files in a file folder, enabling basic file management operations in C++.*/



