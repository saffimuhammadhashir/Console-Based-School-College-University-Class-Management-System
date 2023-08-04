// Include necessary header files
#pragma once
#include<iostream>

/*          EXPLAINATION                */
/*The provided code defines the implementation of several classes (`LinkUsers`, `LinkAssignment`, `LinkFile`, and `LinkNotification`) that 
are part of a larger program. The classes handle various functionalities related to user management, assignment management, file management,
 and notification management. Here's a brief explanation of each class and its member functions:

1. `LinkUsers` class:
   - Manages a linked list of `User` objects.
   - It has member functions to add a new user, print user details, confirm user existence, read user data from files, etc.

2. `LinkAssignment` class:
   - Manages a linked list of `Assignment` objects.
   - It has member functions to add a new assignment, print assignment details, confirm assignment existence, and delete an assignment from the list.

3. `LinkFile` class:
   - Manages a linked list of `data_in_file_list` objects, representing files.
   - It has member functions to add a new file, print file content, download a file, delete a file, and display file content.
   - The file content is saved to and read from files using the `FileManager` class, which seems to be implemented in a separate file.

4. `LinkNotification` class:
   - Manages a linked list of `Notification` objects.
   - It has member functions to add a new notification, print notification details, and display notification details.

The classes make use of various other classes, such as `User`, `Assignment`, `Notification`, and `FileManager`, which are not explicitly defined in the provided
 code snippet.

The program appears to be a management system where users, assignments, files, and notifications are managed and interacted with through the linked lists.

Please note that to fully understand the program's functionality and how it fits into the larger context, it would be helpful to review the definitions and 
implementations of the classes `User`, `Assignment`, `Notification`, and `FileManager`, along with how these classes are used together in the overall program.*/
// Define text color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

// Include the linking header file
#include "linking.h"

using namespace std;

// Initialize LinkUsers class

// Default constructor
/*LinkUsers::LinkUsers()

Default constructor for the LinkUsers class.
Initializes the start_Users_in_User_list pointer to nullptr.
Calls the function reading_User_Data_in_file_list_From_Files_in_user_list() to read user data from files and populate the user list.*/
LinkUsers::LinkUsers() : start_Users_in_User_list(nullptr) {
    // Initialize LinkUsers class and read user data from files
    reading_User_Data_in_file_list_From_Files_in_user_list();
}

// Add user to user list
/*LinkUsers::adding_User_in_user_list()

Adds a new user to the user list.
Creates a new User object and sets its data by taking input from the user.
If the user list is empty, the new user becomes the first element (start_Users_in_User_list).
If the list is not empty, the new user is appended to the end of the list.
*/
void LinkUsers::adding_User_in_user_list() {
    // Create a new user and add it to the user list
    User *create = new User;
    if (start_Users_in_User_list == nullptr)
        start_Users_in_User_list = create;
    else {
        User *current = start_Users_in_User_list;
        while (current->Link != nullptr) {
            current = current->Link;
        }
        create->sethidden_Id(count_in_user_list);
        create->save_in_file();
        current->Link = create;
    }
}

// Add user via file to user list
/**LinkUsers::adding_User_via_file_in_user_list(User create)

Adds a user (received via parameter) to the user list.
If the user list is empty, the new user becomes the first element (start_Users_in_User_list).
If the list is not empty, the new user is appended to the end of the list.*/
void LinkUsers::adding_User_via_file_in_user_list(User *create) {
    // Add a user (via parameter) to the user list
    if (start_Users_in_User_list == nullptr)
        start_Users_in_User_list = create;
    else {
        User *current = start_Users_in_User_list;
        while (current->Link != nullptr) {
            current = current->Link;
        }
        current->Link = create;
        create->Link = nullptr;
    }
}

// Print user list
/*LinkUsers::print_in_user_list()

Prints the details of all users in the user list.
It traverses the linked list of users (start_Users_in_User_list) and calls the print_all_data() function on each user to display their information.*/
void LinkUsers::print_in_user_list() {
    // Print the details of all users in the user list
    User *current = start_Users_in_User_list;
    while (current != nullptr) {
        current->print_all_data();
        cout << endl;
        current = current->Link;
    }
}

// Confirm user in user list
/*LinkUsers::confirmation_of_user_in_user_list(string &name_passed_via_value)

Checks whether a user with the given name exists in the user list.
It traverses the linked list of users (start_Users_in_User_list) and compares the input name with each user's name.
If a match is found, it returns a pointer to the matched user; otherwise, it returns nullptr.*/
User* LinkUsers::confirmation_of_user_in_user_list(string &name_passed_via_value) {
    // Confirm a user's existence in the user list based on their name
    User *current = start_Users_in_User_list;
    while (current != nullptr) {
        if (current->getmy_name() == name_passed_via_value) {
            return current;
        }
        current = current->Link;
    }
    return nullptr;
}

// Read user data from files and populate user list
/*LinkUsers::reading_User_Data_in_file_list_From_Files_in_user_list()

Reads user data from files and populates the user list.
It uses an instance of the FileManager class to read user data from text files (with the extension ".txt") and create User objects with the data.
Each User object is added to the user list using the adding_User_via_file_in_user_list function.*/
void LinkUsers::reading_User_Data_in_file_list_From_Files_in_user_list() {
    // Read user data from files and populate the user list
    FileManager fileManager;
    std::string extension = ".txt";

    int userId = 2; // Assume unique IDs start from 2
    std::string fileName = std::to_string(userId) + extension;

    // Iterate through user data files
    while (fileManager.file_Exists_in_file_folder(fileName)) {
        std::ifstream file(fileName);
        std::string name, email, role, uniqueID, password, contactInfo;

        // Read user data from file
        std::string line;
        while (std::getline(file, line)) {
            // Extract user data fields
            if (line.find("Name: ") == 0) {
                name = line.substr(6);
            } else if (line.find("Email: ") == 0) {
                email = line.substr(7);
            } else if (line.find("Role: ") == 0) {
                role = line.substr(6);
            } else if (line.find("Unique ID: ") == 0) {
                uniqueID = line.substr(11);
            } else if (line.find("Password : ") == 0) {
                password = line.substr(11);
            } else if (line.find("Contact Info: ") == 0) {
                contactInfo = line.substr(14);
            }
        }

        // Create a new user instance and add it to the user list
        User *newUser = new User(name, email, role, uniqueID, password, contactInfo);
        adding_User_via_file_in_user_list(newUser);

        // Increment user ID to read the next file
        userId++;
        fileName = std::to_string(userId) + extension;
        if (userId != 1)
            count_in_user_list = userId;
    }
    std::cout << "User data from files read successfully.\n";
}

// Initialize LinkAssignment class

// Default constructor
/*LinkAssignment::LinkAssignment()

Default constructor for the LinkAssignment class.
Initializes the start_Assignment_in_assignment_list pointer to nullptr.*/
LinkAssignment::LinkAssignment() : start_Assignment_in_assignment_list(nullptr) {}

// Add assignment to assignment list
/*LinkAssignment::adding_Assignment_in_assignment_list()

Adds a new assignment to the assignment list.
Creates a new Assignment object and sets its data by taking input from the user.
If the assignment list is empty, the new assignment becomes the first element (start_Assignment_in_assignment_list).
If the list is not empty, the new assignment is appended to the end of the list.*/
void LinkAssignment::adding_Assignment_in_assignment_list() {
    // Add a new assignment to the assignment list
    Assignment *create = new Assignment;
    if (start_Assignment_in_assignment_list == nullptr)
        start_Assignment_in_assignment_list = create;
    else {
        Assignment *current = start_Assignment_in_assignment_list;
        while (current->Link != nullptr) {
            current = current->Link;
        }
        current->Link = create;
    }
}
/**LinkAssignment::adding_Assignment_in_assignment_list(Assignment create)

Adds an assignment (received via parameter) to the assignment list.
If the assignment list is empty, the new assignment becomes the first element (start_Assignment_in_assignment_list).
If the list is not empty, the new assignment is appended to the end of the list.*/
// Add assignment to assignment list via parameter
void LinkAssignment::adding_Assignment_in_assignment_list(Assignment *create) {
    // Add an assignment (via parameter) to the assignment list
    if (start_Assignment_in_assignment_list == nullptr)
        start_Assignment_in_assignment_list = create;
    else {
        Assignment *current = start_Assignment_in_assignment_list;
        while (current->Link != nullptr) {
            current = current->Link;
        }
        current->Link = create;
    }
}

// Print assignment list
/*LinkAssignment::print_in_assignment_list()

Prints the details of all assignments in the assignment list.
It traverses the linked list of assignments (start_Assignment_in_assignment_list) and 
calls the display_Assignment_Details_in_Assignment() function on each assignment to display their information.*/
void LinkAssignment::print_in_assignment_list() {
    // Print the details of all assignments in the assignment list
    Assignment *current = start_Assignment_in_assignment_list;
    while (current != nullptr) {
        current->display_Assignment_Details_in_Assignment();
        cout << endl;
        current = current->Link;
    }
}

// Confirm assignment in assignment list
/*LinkAssignment::confirmation_of_user_in_assignment_list(string &name_passed_via_value)

Checks whether an assignment with the given title exists in the assignment list.
It traverses the linked list of assignments (start_Assignment_in_assignment_list) and compares the input title with each assignment's title.
If a match is found, it returns a pointer to the matched assignment; otherwise, it returns nullptr.*/
Assignment* LinkAssignment::confirmation_of_user_in_assignment_list(string &name_passed_via_value) {
    // Confirm an assignment's existence in the assignment list based on its title
    Assignment *current = start_Assignment_in_assignment_list;
    while (current != nullptr) {
        if (current->getTitle_in_Assignment() == name_passed_via_value) {
            return current;
        }
        current = current->Link;
    }
    return nullptr;
}

// Delete assignment from assignment list
/*LinkAssignment::deleteAssignment_in_assignment_list(string &name_passed_via_value)

Deletes an assignment from the assignment list based on its title.
It traverses the linked list of assignments (start_Assignment_in_assignment_list) to find the assignment with the matching title.
If found, it removes the assignment from the list and deallocates its memory.*/
void LinkAssignment::deleteAssignment_in_assignment_list(string &name_passed_via_value) {
    // Delete an assignment from the assignment list based on its title
    Assignment *previous = nullptr;
    Assignment *current = start_Assignment_in_assignment_list;
    FileManager filemanager;
    while (current != nullptr) {
        if (current->getTitle_in_Assignment() == name_passed_via_value) {
            if (previous == nullptr) {
                start_Assignment_in_assignment_list = current->Link;
            } else {
                previous->Link = current->Link;
            }

            current->Link = nullptr; // Remove the link from the deleted assignment

            delete current; // Deallocate the memory of the deleted assignment
            current = nullptr;

            cout << "Assignment '" << name_passed_via_value << "' deleted.\n";
            return;
        }

        previous = current;
        current = current->Link;
    }

    cout << "Assignment '" << name_passed_via_value << "' not found.\n";
}

// Initialize LinkFile class

// Default constructor
/*LinkFile::LinkFile()

Default constructor for the LinkFile class.
Initializes the start_File_in_file_list pointer to nullptr.*/
LinkFile::LinkFile() : start_File_in_file_list(nullptr) {}

// Add file to file list
void LinkFile::adding_File_in_file_list(string fName) {
    // Add a new file to the file list
    string fileName = (fName + "File.txt");
    string fileContent;
    cin.ignore();
    cout << "********** File Management **********\n";
    cout << "Enter file content: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, fileContent);

    data_in_file_list *create = new data_in_file_list;
    create->fileName = fileName;
    if (start_File_in_file_list == nullptr)
        start_File_in_file_list = create;
    else {
        data_in_file_list *current = start_File_in_file_list;
        while (current->Link != nullptr) {
            current = current->Link;
        }
        current->Link = create;
    }

    FileManager *file = new FileManager;
    file->upload_File_in_file_folder(fileName, fileContent);
}

// Print file list
/*LinkFile::adding_File_in_file_list(string fName)

Adds a new file to the file list.
Takes input for the file content and uses the FileManager class to upload the file to the file folder.
Creates a new data_in_file_list object to represent the file and adds it to the file list.*/
void LinkFile::print_in_file_list(string &filename) {
    // Print the content of all files in the file list
    data_in_file_list *current = start_File_in_file_list;
    FileManager create;
    while (current != nullptr) {
        cout << "File '" << current->fileName << "' content:\n";
        create.display_FileContent_in_file_folder(current->fileName);
        cout << endl;
        current = current->Link;
    }
    create.is_to_delay();
}

// Download file from file list
/*LinkFile::print_in_file_list(string &filename)

Prints the content of all files in the file list.
Uses the FileManager class to display the content of each file in the file list.*/

/*LinkFile::download_file__in_file_list()

Downloads and displays the content of a file from the file list.
Uses the confirmation_of_user_in_file_list() function to confirm the existence of the file in the list.
If the file is found, it uses the FileManager class to display the content of the file.*/
void LinkFile::download_file__in_file_list() {
    // Download and display the content of a file from the file list
    FileManager create;
    data_in_file_list *fileauth = confirmation_of_user_in_file_list();
    if (fileauth != nullptr) {
        create.display_FileContent_in_file_folder(fileauth->fileName);
    } else {
        cout << "No such Files Found in Record !!\n\n";
    }
}

// Delete file from file list
/*LinkFile::delete_file__in_file_list()

Deletes a file from the file list.
Uses the confirmation_of_user_in_file_list() function to confirm the existence of the file in the list.
If the file is found, it uses the FileManager class to delete the file from the file folder.*/
void LinkFile::delete_file__in_file_list() {
    // Delete a file from the file list
    FileManager create;
    data_in_file_list *fileauth = confirmation_of_user_in_file_list();
    if (fileauth != nullptr) {
        create.delete_File_in_file_folder(fileauth->fileName);
    } else {
        cout << "No such Files Found in Record !\n\n";
    }
}

// Display file from file list
/*LinkFile::display_file__in_file_list()

Displays the content of a file from the file list.
Uses the confirmation_of_user_in_file_list() function to confirm the existence of the file in the list.
If the file is found, it uses the FileManager class to display the content of the file.*/
void LinkFile::display_file__in_file_list() {
    // Display the content of a file from the file list
    FileManager create;
    data_in_file_list *fileauth = confirmation_of_user_in_file_list();
    if (fileauth != nullptr) {
        create.display_FileContent_in_file_folder(fileauth->fileName);
    } else {
        cout << "No such Files Found in Record !!\n\n";
    }
}
/*LinkFile::confirmation_of_user_in_file_list()

Confirms a file's existence in the file list based on its name.
Takes input for the file name and traverses the linked list of files (start_File_in_file_list) to find the file with the matching name.
If a match is found, it returns a pointer to the matched file; otherwise, it returns nullptr.*/
// Confirm file in file list
data_in_file_list *LinkFile::confirmation_of_user_in_file_list() {
    // Confirm a file's existence in the file list based on its name
    string fileName;
    cin.ignore();
    cout << "Enter file name: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, fileName);
    data_in_file_list *current = start_File_in_file_list;
    while (current != nullptr) {
        if (current->fileName == fileName) {
            return current;
        }
        current = current->Link;
    }
    return nullptr;
}

// Initialize LinkNotification class

// Default constructor
/*LinkNotification::LinkNotification()

Default constructor for the LinkNotification class.
Initializes the start_Notification_in_Notification pointer to nullptr.*/
LinkNotification::LinkNotification() : start_Notification_in_Notification(nullptr) {}

// Add notification to notification list
/*LinkNotification::adding_Notification_in_Notification_list(string class_name, int count)

Adds a new notification to the notification list.
Takes input for the notification message and recipient and creates a new Notification object with the given data.
Adds the new notification to the notification list.*/
void LinkNotification::adding_Notification_in_Notification_list(string class_name, int count) {
    // Add a new notification to the notification list
    string notificationMessage, recipient;
    cout << "********** Notification **********\n";
    cout << "Enter notification message: ";
    cin.ignore();
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, notificationMessage);

    cout << "Enter recipient: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, recipient);

    string name = "Notification for " + class_name + " " + to_string(count);
    cout << name << endl;

    Notification *notification = new Notification(name, notificationMessage, recipient);

    if (start_Notification_in_Notification == nullptr)
        start_Notification_in_Notification = notification;
    else {
        Notification *current = start_Notification_in_Notification;
        while (current->Link != nullptr) {
            current = current->Link;
        }
        current->Link = notification;
    }

    FileManager file;
    string delivered = (notification->isNotificationDelivered_in_Notifications() ? "Yes" : "No");
    string place = string("\nNotification Id: " + name + "\n\n  Message: " + notificationMessage + "\n\n\n\n        Recipients: " + notification->getRecipient_in_Notifications()) + "\n        Sent at: " + to_string(notification->getTimestamp_in_Notifications()) + "\n        Delivery Status: " + delivered;
    file.upload_File_in_file_folder(name, place);
}

// Print notification list
/*LinkNotification::print_in_Notification_list()

Prints the details of all notifications in the notification list.
Uses the FileManager class to display the content of each notification file in the notification list.*/
void LinkNotification::print_in_Notification_list() {
    // Print the details of all notifications in the notification list
    Notification *current = start_Notification_in_Notification;
    while (current != nullptr) {
        FileManager file;
        string place = current->getName_in_Notifications();
        file.display_FileContent_in_file_folder(place);
        cout << endl;
        current = current->Link;
    }
    current->is_to_delay();
}


// Display notification from notification list
/*LinkNotification::display_Notification_in_Notification_list()

Displays the details of a notification from the notification list.
Uses the confirmation_in_Notification_list() function to confirm the existence of the notification in the list.
If the notification is found, it uses the FileManager class to display the content of the notification file.*/
void LinkNotification::display_Notification_in_Notification_list() {
    // Display the details of a notification from the notification list
    FileManager file;
    Notification *notificationAuth = confirmation_in_Notification_list();
    if (notificationAuth != nullptr) {
        string place = notificationAuth->getName_in_Notifications();
        file.display_FileContent_in_file_folder(place);
    } else {
        cout << "No such Files Found in Record !!\n\n";
    }
}

// Confirm notification in notification list
/*LinkNotification::confirmation_in_Notification_list()

Confirms a notification's existence in the notification list based on its name (file name).
Takes input for the file name and traverses the linked list of notifications (start_Notification_in_Notification) to find the notification with the matching name.
If a match is found, it returns a pointer to the matched notification; otherwise, it returns nullptr.*/
Notification *LinkNotification::confirmation_in_Notification_list() {
    // Confirm a notification's existence in the notification list based on its name
    string fileName;
    cout << "Enter file name: ";
    cin.ignore();
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, fileName);
    Notification *current = start_Notification_in_Notification;
    while (current != nullptr) {
        if (current->getName_in_Notifications() == fileName) {
            return current;
        }
        current = current->Link;
    }
    return nullptr;
}
/*These functions are part of classes that handle user management (LinkUsers), assignment management (LinkAssignment), file management (LinkFile), 
and notification management (LinkNotification). The classes use linked lists to maintain the collections of users, assignments, files, and notifications.
 The FileManager class is utilized to perform file-related operations like uploading, downloading, displaying, and deleting files.*/
