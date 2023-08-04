// Include necessary header files
#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Class definition for FileManager
class FileManager {
public:
    // Function to pause execution and wait for user input (Windows specific)
    void is_to_delay() {
        cout << "Press Enter to continue: ";
        cin.ignore();
        system("cls");
    }

    // Function to upload a file to the file folder
    void upload_File_in_file_folder(string& filename, string& content);

    // Function to download the content of a file from the file folder
    string download_File_in_file_folder(string& filename);

    // Function to delete a file from the file folder
    void delete_File_in_file_folder(string& filename);

    // Function to display the content of a file from the file folder
    void display_FileContent_in_file_folder(string& filename);

    // Function to check if a file exists in the file folder
    bool file_Exists_in_file_folder(string& filename);
};
