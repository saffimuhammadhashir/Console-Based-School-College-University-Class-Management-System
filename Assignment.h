// This directive ensures that the header file is included only once during compilation
#pragma once

// These are the standard C++ libraries being included
#include <iostream>
#include <string>
#include <fstream>

// The code is in the 'std' namespace for convenience
using namespace std;

// Declaration of the 'Assignment' class
class Assignment {
private:
    // Private member variables of the 'Assignment' class
    string subject_in_Assignment;         // Subject of the assignment
    string title_in_Assignment;           // Title of the assignment
    string description_in_Assignment;     // Description of the assignment
    string deadline_in_Assignment;        // Deadline for the assignment
    string attachedFiles_in_Assignment;   // Attached files related to the assignment
    int pointValue_in_Assignment = 0;     // Point value or marks associated with the assignment

public:
    Assignment* Link; // A pointer to another 'Assignment' object (not used in this code)

    // Constructors for the 'Assignment' class
    Assignment(); // Default constructor
    Assignment(string& subject, string& title, string& description, string& deadline, string& attachedFiles, int pointValue);

    // Getter methods for private member variables
    string getTitle_in_Assignment();
    string getDescription_in_Assignment();
    string getDeadline_in_Assignment();
    string getAttachedFiles_in_Assignment();
    int getPointValue_in_Assignment();

    // Method to update the details of an assignment
    void update_Assignment_Details__in_Assignment(string& newTitle, string& newDescription, string& newDeadline, string& newAttachedFiles, int newPointValue);

    // Method to display the details of an assignment
    void display_Assignment_Details_in_Assignment();

    // Method to save the assignment details to a file
    void save_Assignment_To_File_in_Assignment();
};
