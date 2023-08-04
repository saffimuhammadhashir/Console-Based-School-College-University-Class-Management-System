/*          EXPLANATION           */
/*This C++ code defines a class called `Assignment` with constructors, getter functions, and utility functions to manage and store assignment details. Let's break down the code step by step:

1. **Include Necessary Libraries:**
   - The code includes the `<iostream>` library for input/output operations.

2. **Define Color Codes for Console Text:**
   - The code defines several color codes using preprocessor macros. These color codes are used to display text in different colors on the console.

3. **Include "Assignment.h" Header File:**
   - The code includes a header file named "Assignment.h" using `#include` directive. The content of this header file is not provided here but
    is presumably used to declare the class `Assignment`.

4. **Namespace:**
   - The code uses the `using namespace std;` statement to bring the entire `std` namespace into the current scope. This allows using standard 
   library functions without prefixing them with `std::`.

5. **Constructor without Parameters:**
   - The class `Assignment` has a default constructor without parameters. It initializes a member variable `Link` to `nullptr`. Then it prompts
    the user to input assignment details like course subject, title, description, deadline, attached files, and point value. After taking user input,
     it saves the assignment details to a file using the `save_Assignment_To_File_in_Assignment()` function.

6. **Constructor with Parameters:**
   - The class `Assignment` has a parameterized constructor that takes multiple parameters (by reference) representing assignment details such
    as subject, title, description, deadline, attached files, and point value. It initializes the corresponding member variables with the provided 
    parameter values and sets `Link` to `nullptr`. Then it saves the assignment details to a file using the `save_Assignment_To_File_in_Assignment()` function.

7. **Getter Functions:**
   - The class provides several getter functions to access private member variables like `title_in_Assignment`, `description_in_Assignment`,
    `deadline_in_Assignment`, `attachedFiles_in_Assignment`, and `pointValue_in_Assignment`. These functions are used to retrieve assignment details
     from outside the class.

8. **Update Assignment Details Function:**
   - The class has a function named `update_Assignment_Details__in_Assignment()` that allows updating assignment details. It takes new values
    for assignment title, description, deadline, attached files, and point value as parameters (by reference). It then updates the corresponding member
     variables and saves the updated details to a file using the `save_Assignment_To_File_in_Assignment()` function.

9. **Display Assignment Details Function:**
   - The class has a function named `display_Assignment_Details_in_Assignment()` that displays the assignment details on the console. It simply
    prints the values of various assignment details, like title, description, deadline, attached files, and point value.

10. **Save Assignment Details to a File Function:**
    - The class contains a function called `save_Assignment_To_File_in_Assignment()` that saves the assignment details to a file. It generates 
    the filename based on the subject of the assignment, opens the file for writing, writes the assignment details to the file, and then closes the file.
     If successful, it prints a success message; otherwise, it prints an error message.

Please note that the code references variables and functions not provided in this code snippet, such as `subject_in_Assignment`, `Link`, and `ofstream`.
 These variables and functions are likely declared in the "Assignment.h" header file or other parts of the program not shown here.

Overall, this code appears to be a part of a larger program that manages assignments and stores their details in files. It demonstrates object-oriented
 programming concepts with a class (`Assignment`) that encapsulates assignment data and provides methods to manipulate and display this data.
*/
// Include necessary libraries
#pragma once
#include <iostream>

// Define color codes for console text
/*Libraries and Color Codes:
The code includes the necessary library iostream for input and output operations. It also defines several
 color codes using escape sequences for printing colored text in the console. 
For example, RESET, RED, GREEN, etc., which can be used to change the color of the text in the console.*/
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

// Include the "Assignment.h" header file
/*Assignment Class:
The Assignment class contains private member variables and public member functions for handling assignment details.*/
#include "Assignment.h"

using namespace std;

// Constructor without parameters
/*Constructors:
The class has two constructors:

Assignment(): This constructor is used when creating a new assignment without any parameters. It prompts the user to input
 various details for the assignment, such as subject, title, description, deadline, attached files, and point value. It then saves
  these details to a file using the save_Assignment_To_File_in_Assignment() function.
*/
Assignment::Assignment() : Link(nullptr) {
    // Initialize the point value variable
    int pointValue_in_Assignment;

    // Prompt the user to input assignment details
    cin.ignore(); // Ignore any previous input in the buffer
    cout << "********** Create Assignment **********\n";
    cout << "Enter Course subject: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, subject_in_Assignment);

    // ... (similar input prompts for other fields)
    cout << "Enter assignment title: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, title_in_Assignment);
    cout << "Enter assignment description: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, description_in_Assignment);
    cout << "Enter assignment deadline_in_Assignment: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, deadline_in_Assignment);
    cout << "Enter attached files: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, attachedFiles_in_Assignment);
    
    // Prompt the user to input assignment point value
    cout << "Enter assignment point value: ";
    cout << CYAN;
    cin >> pointValue_in_Assignment; // Read and store the point value
    
    // Store the point value in the assignment object
    this->pointValue_in_Assignment = pointValue_in_Assignment;

    // Save assignment details to a file
    save_Assignment_To_File_in_Assignment();
}

// Constructor with parameters
/*
Assignment(string&, string&, string&, string&, string&, int): This constructor is used when creating a new assignment with parameters. 
It accepts all the assignment details as parameters and initializes the corresponding member variables with them. It also saves the details
 to a file using the save_Assignment_To_File_in_Assignment() function.**/

Assignment::Assignment(string &subject_in_Assignment,
    string &title_in_Assignment, string &description_in_Assignment,
    string &deadline_in_Assignment, string &attachedFiles_in_Assignment,
    int pointValue_in_Assignment)
    : subject_in_Assignment(subject_in_Assignment),
      title_in_Assignment(title_in_Assignment),
      description_in_Assignment(description_in_Assignment),
      deadline_in_Assignment(deadline_in_Assignment),
      attachedFiles_in_Assignment(attachedFiles_in_Assignment),
      pointValue_in_Assignment(pointValue_in_Assignment), Link(nullptr) {
    // Save assignment details to a file
    save_Assignment_To_File_in_Assignment();
}
/*Getter Functions:
The class provides several getter functions to access the private member variables:


*/
// Getter function for the assignment title
/*getTitle_in_Assignment(): Returns the title of the assignment.*/
string Assignment::getTitle_in_Assignment() {
    return title_in_Assignment;
}

// Getter function for the assignment description
/*getDescription_in_Assignment(): Returns the description of the assignment.*/
string Assignment::getDescription_in_Assignment() {
    return description_in_Assignment;
}

// Getter function for the assignment deadline
/*getDeadline_in_Assignment(): Returns the deadline of the assignment.*/
string Assignment::getDeadline_in_Assignment() {
    return deadline_in_Assignment;
}

// Getter function for the attached files
/*getAttachedFiles_in_Assignment(): Returns the attached files of the assignment.*/
string Assignment::getAttachedFiles_in_Assignment() {
    return attachedFiles_in_Assignment;
}

// Getter function for the assignment point value
/*getPointValue_in_Assignment(): Returns the point value of the assignment.*/
int Assignment::getPointValue_in_Assignment() {
    return pointValue_in_Assignment;
}

// Function to update assignment details
/*update_Assignment_Details__in_Assignment() Function:
This function allows updating the details of an existing assignment. It takes new values for title, description,
 deadline, attached files, and point value as input parameters and updates the corresponding member variables with these values. After updating,
 it calls save_Assignment_To_File_in_Assignment() to save the updated details to a file.*/
void Assignment::update_Assignment_Details__in_Assignment(
    string &newTitle, string &newDescription,
    string &newDeadline_deadline_in_Assignment,
    string &newAttachedFiles_attachedFiles_in_Assignment,
    int newPointValue_pointValue_in_Assignment) {
    // Update assignment details
    title_in_Assignment = newTitle;
    description_in_Assignment = newDescription;
    deadline_in_Assignment = newDeadline_deadline_in_Assignment;
    attachedFiles_in_Assignment = newAttachedFiles_attachedFiles_in_Assignment;
    pointValue_in_Assignment = newPointValue_pointValue_in_Assignment;

    // Save the updated assignment details to a file
    save_Assignment_To_File_in_Assignment();
}

// Function to display assignment details
/*display_Assignment_Details_in_Assignment() Function:
This function displays the details of an assignment in the console. It prints the assignment's title, description, deadline, attached files, and point value.*/
void Assignment::display_Assignment_Details_in_Assignment() {
    // Display the assignment details
    cout << "Title: " << title_in_Assignment << "\n"
         << "Description: " << description_in_Assignment << "\n"
         << "Deadline deadline: " << deadline_in_Assignment << "\n"
         << "Attached Files: " << attachedFiles_in_Assignment << "\n"
         << "Point Value: " << pointValue_in_Assignment << "\n"
         << "--------------------------\n";
}

// Function to save assignment details to a file
/*save_Assignment_To_File_in_Assignment() Function:
This function is responsible for saving the assignment details to a file. It generates a filename based on the assignment's
 subject, opens the file for writing, writes all the assignment details to the file,
 and closes it. If the file is successfully written, it prints a success message; otherwise, it prints an error message.*/
void Assignment::save_Assignment_To_File_in_Assignment() {
    // Generate the filename based on the subject
    string filename(subject_in_Assignment + " assignment.txt");

    // Open the file for writing
    ofstream file(filename);
    if (file.is_open()) {
        // Write the assignment details to the file
        file << "Subject: " << subject_in_Assignment << "\n"
             << "Title: " << title_in_Assignment << "\n"
             << "Description: " << description_in_Assignment << "\n"
             << "Deadline deadline: " << deadline_in_Assignment << "\n"
             << "Attached Files: " << attachedFiles_in_Assignment << "\n"
             << "Point Value: " << pointValue_in_Assignment << "\n"
             << "--------------------------\n";

        // Close the file
        file.close();

        // Print a success message
        cout << "Assignment details saved to file: " << filename << "\n";
    } else {
        // Print an error message if the file couldn't be opened
        cout << "Error saving assignment details to file: " << filename << "\n";
    }
}
/*Overall, this code provides a basic framework for managing assignments, allowing users to create new assignments,
 display their details, update them, and save them to files for later
 reference. Note that the actual implementation of the Assignment class may involve additional functionality and
  error handling not shown in this code snippet.*/
 