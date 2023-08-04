// Include necessary header files
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "linking.cpp"         // Include the header file for LinkUsers (linking.cpp)
#include "GradeBook.cpp"       // Include the header file for GradeBook (GradeBook.cpp)
#include "Submission.cpp"      // Include the header file for Submission (Submission.cpp)
#include<windows.h>           // Include the Windows API header file for system-related functions
const int MAX_STUDENTS_in_class = 50; // Maximum number of enrolled students in the class

using namespace std;

// Class definition for Class
class Class {
private:
    // Private data members
    std::string class_Name_in_class;     // Class name
    std::string subject_in_class;        // Subject of the class
    std::string teacher_in_class;        // Name of the teacher for the class
    std::string description_in_class;    // Description of the class
    LinkAssignment assignments_in_class; // Link to assignments for the class
    LinkFile file_in_class;              // Link to files for the class
    LinkNotification notification_in_class; // Link to notifications for the class
    string teacher_portal = "       ######## ########    ###     ######  ##     ## ######## ########     ########   #######  ########  ########    ###    ##\n          ##    ##         ## ##   ##    ## ##     ## ##       ##     ##    ##     ## ##     ## ##     ##    ##      ## ##   ##\n          ##    ##        ##   ##  ##       ##     ## ##       ##     ##    ##     ## ##     ## ##     ##    ##     ##   ##  ##\n          ##    ######   ##     ## ##       ######### ######   ########     ########  ##     ## ########     ##    ##     ## ##\n          ##    ##       ######### ##       ##     ## ##       ##   ##      ##        ##     ## ##   ##      ##    ######### ##\n          ##    ##       ##     ## ##    ## ##     ## ##       ##    ##     ##        ##     ## ##    ##     ##    ##     ## ##\n          ##    ######## ##     ##  ######  ##     ## ######## ##     ##    ##         #######  ##     ##    ##    ##     ## ########\n";
    string student_portal = "        ######  ######## ##     ## ########  ######## ##    ## ########    ########   #######  ########  ########    ###    ##\n       ##    ##    ##    ##     ## ##     ## ##       ###   ##    ##       ##     ## ##     ## ##     ##    ##      ## ##   ##\n       ##          ##    ##     ## ##     ## ##       ####  ##    ##       ##     ## ##     ## ##     ##    ##     ##   ##  ##\n        ######     ##    ##     ## ##     ## ######   ## ## ##    ##       ########  ##     ## ########     ##    ##     ## ##\n             ##    ##    ##     ## ##     ## ##       ##  ####    ##       ##        ##     ## ##   ##      ##    ######### ##\n       ##    ##    ##    ##     ## ##     ## ##       ##   ###    ##       ##        ##     ## ##    ##     ##    ##     ## ##\n        ######     ##     #######  ########  ######## ##    ##    ##       ##         #######  ##     ##    ##    ##     ## ########\n";

public:
    Class* Link; // Link to the next Class object in the list

    // Public data members
    std::string enrolled_Students_in_class[MAX_STUDENTS_in_class]; // Array to store enrolled students in the class
    int num_Enrolled_Students_in_class = 0; // Number of enrolled students in the class
    int notification_count_in_class = 0;    // Notification count for the class
    GradeBook grades_in_class;              // GradeBook object to manage grades for the class

    // Constructors
    Class() {} // Default constructor
    Class(LinkUsers& other); // Constructor that initializes the object with a LinkUsers object

    Class(const std::string& className, const std::string& subject,
        const std::string& teacher, const std::string& description); // Parameterized constructor to create a new class

    // Getter methods
    std::string getClass_Name_in_class();      // Get the class name
    std::string getsubject_in_class() const;   // Get the subject of the class
    std::string getTeacher_in_class() const;   // Get the name of the teacher for the class
    std::string getDescription_in_class() const; // Get the description of the class

    // Function to add a student to the class
    void add_Student_in_class(const string& studentID, LinkUsers& otherlinkusers);

    // Function to remove a student from the class
    void remove_Student_in_class(const std::string& studentID);

    // Function to update class details
    void update_Class_Details_in_class(const std::string& newClassName, const std::string& newsubject,
        const std::string& newTeacher, const std::string& newDescription);

    // Function to display class details
    void display_Class_Details_in_class() const;

    // Functions related to managing assignments
    void manage_assignment_in_class();
    void add_assignment_in_class();
    void all_assignments_in_class();
    void manage_assignment_student_in_class(User& obj);
    void submit_assignment_in_class(std::string Id);
    void search_assignment_in_class();
    bool search_assignment_students_in_class();

    // Function to manage grades for the class
    void manage_grades_in_class();

    // Functions related to managing files
    void manage_File_Student_in_class();
    void manage_File_in_class();

    // Function to manage notifications for the class
    void manage_Notifications_in_class();

    // File I/O functions for managing grades and data for the class
    void save_Grades_To_File_in_class(Class& classObj);
    void read_Grades_From_File_in_class(Class& classObj);
    void save_Data_To_File_in_class(Class& classObj);
    void read_Assignments_From_File_in_class(Class& obj);
    void save_Enrolled_in_class_Students_To_File_in_class();
    void read_Enrolled_Students_From_File_in_class();

    // Function to display grades for a specific student
    void display_Student_Grades_in_class(std::string& studentID);

    // Function to pause execution and wait for user input (Windows specific)
    void is_to_delay() {
        std::cout << "Press Enter to continue: ";
        std::cin.ignore();
        system("cls");
    }
};
