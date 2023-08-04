// This directive ensures that the header file is included only once during compilation
#pragma once

// These are color codes used for text coloring in the console
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// These are the standard C++ libraries being included
#include <iostream>
#include <string>
#include <fstream>

// Included user-defined header files for different classes
#include "User.cpp"
#include "Class.cpp"
#include "Assignment.cpp"
#include "FileManager.cpp"
#include "Notification.cpp"

// Declaration of the 'LinkUsers' class
class LinkUsers {
private:
    int count_in_user_list = 1; // A counter for the number of users in the list

public:
    User* start_Users_in_User_list; // Pointer to the start of the users list

    // Constructors for the 'LinkUsers' class
    LinkUsers();

    // Method to add a new user to the user list
    void adding_User_in_user_list();

    // Method to add a user via file to the user list
    void adding_User_via_file_in_user_list(User*);

    // Method to print the user list
    void print_in_user_list();

    // Method to confirm if a user exists in the user list
    User* confirmation_of_user_in_user_list(string&);

    // Method to read user data from files and add to the user list
    void reading_User_Data_in_file_list_From_Files_in_user_list();
};

// Declaration of the 'LinkAssignment' class
class LinkAssignment {
private:
    Assignment* start_Assignment_in_assignment_list; // Pointer to the start of the assignments list

public:
    // Constructor for the 'LinkAssignment' class
    LinkAssignment();

    // Method to add a new assignment to the assignment list
    void adding_Assignment_in_assignment_list();

    // Method to add an assignment via pointer to the assignment list
    void adding_Assignment_in_assignment_list(Assignment*);

    // Method to print the assignment list
    void print_in_assignment_list();

    // Method to confirm if an assignment exists in the assignment list
    Assignment* confirmation_of_user_in_assignment_list(string&);

    // Method to delete an assignment from the assignment list
    void deleteAssignment_in_assignment_list(string&);
};

// Structure to store data about files in a file list
struct data_in_file_list {
    string fileName = "";
    data_in_file_list* Link = nullptr;
};

// Declaration of the 'LinkFile' class
class LinkFile {
private:
    data_in_file_list* start_File_in_file_list; // Pointer to the start of the file list

public:
    // Constructor for the 'LinkFile' class
    LinkFile();

    // Method to add a new file to the file list
    void adding_File_in_file_list(string);

    // Method to print the file list for a given user
    void print_in_file_list(string&);

    // Method to download a file from the file list
    void download_file__in_file_list();

    // Method to delete a file from the file list
    void delete_file__in_file_list();

    // Method to display file details from the file list
    void display_file__in_file_list();

    // Method to confirm if a file exists in the file list
    data_in_file_list* confirmation_of_user_in_file_list();
};

// Declaration of the 'LinkNotification' class
class LinkNotification {
private:
    Notification* start_Notification_in_Notification; // Pointer to the start of the notification list
    int count_in_Notification_list = 1; // A counter for the number of notifications in the list

public:
    // Constructor for the 'LinkNotification' class
    LinkNotification();

    // Method to add a new notification to the notification list
    void adding_Notification_in_Notification_list(string, int);

    // Method to print the notification list
    void print_in_Notification_list();

    // Method to display notification details from the notification list
    void display_Notification_in_Notification_list();

    // Method to confirm if a notification exists in the notification list
    Notification* confirmation_in_Notification_list();
};
