// This pragma once ensures that this header file is included only once during compilation to prevent multiple definitions.
#pragma once

// Standard library includes
#include <iostream>
#include <string>

// Define color codes for console output (optional, used for styling)
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Include header files for related classes and functionalities
#include "User.cpp"
#include "linking.cpp"
#include "Class.cpp"
#include "FileManager.cpp"

// LinkClass class definition
class LinkClass {
private:
    // Strings representing teacher and student portal ASCII art
     string teacher_portal = "       ######## ########    ###     ######  ##     ## ######## ########     ########   #######  ########  ########    ###    ##\n          ##    ##         ## ##   ##    ## ##     ## ##       ##     ##    ##     ## ##     ## ##     ##    ##      ## ##   ##\n          ##    ##        ##   ##  ##       ##     ## ##       ##     ##    ##     ## ##     ## ##     ##    ##     ##   ##  ##\n          ##    ######   ##     ## ##       ######### ######   ########     ########  ##     ## ########     ##    ##     ## ##\n          ##    ##       ######### ##       ##     ## ##       ##   ##      ##        ##     ## ##   ##      ##    ######### ##\n          ##    ##       ##     ## ##    ## ##     ## ##       ##    ##     ##        ##     ## ##    ##     ##    ##     ## ##\n          ##    ######## ##     ##  ######  ##     ## ######## ##     ##    ##         #######  ##     ##    ##    ##     ## ########\n";
     // ASCII art representing the teacher portal
   string student_portal = "        ######  ######## ##     ## ########  ######## ##    ## ########    ########   #######  ########  ########    ###    ##\n       ##    ##    ##    ##     ## ##     ## ##       ###   ##    ##       ##     ## ##     ## ##     ##    ##      ## ##   ##\n       ##          ##    ##     ## ##     ## ##       ####  ##    ##       ##     ## ##     ## ##     ##    ##     ##   ##  ##\n        ######     ##    ##     ## ##     ## ######   ## ## ##    ##       ########  ##     ## ########     ##    ##     ## ##\n             ##    ##    ##     ## ##     ## ##       ##  ####    ##       ##        ##     ## ##   ##      ##    ######### ##\n       ##    ##    ##    ##     ## ##     ## ##       ##   ###    ##       ##        ##     ## ##    ##     ##    ##     ## ##\n        ######     ##     #######  ########  ######## ##    ##    ##       ##         #######  ##     ##    ##    ##     ## ########\n";
    // ASCII art representing the student portal

    // Pointer to the start of the linked list of classes
    Class* start_Class_in_list_of_classes;

    // Instance of LinkUsers used for linking user objects in the list of classes
    LinkUsers other_users_link_in_list_of_classes;

public:
    // Constructors

    // Constructor with LinkUsers object as a parameter
    LinkClass(LinkUsers& other);

    // Member functions

    // Methods to add a class to the linked list of classes
    void add_Class_in_list_of_classes(LinkUsers& other);
    void add_Class_in_list_of_classes(Class& otherclass, LinkUsers& other);

    // Pause the program for a specified duration (in seconds)
    void pause_in_list_of_classes(int dur);

    // Generate and return a random boolean value
    bool random_Boolean_in_list_of_classes();

    // Methods for student enrollment and grade management in classes
    void student_enrollment_in_list_of_classes(User& obj);
    void student_grades_in_list_of_classes(User& obj);

    // Methods for course search and student course search
    bool course_search_in_list_of_classes(std::string course_selection);
    bool student_course_search_in_list_of_classes(std::string course_selection, std::string StudentId);

    // Method to find and return the class pointer for a student in a given course
    Class* student_class_search_in_list_of_classes(std::string course_selection, std::string StudentId);

    // Methods for viewing class files and assignments
    void view_class_files_in_list_of_classes(User& obj);
    void assignment_view_in_list_of_classes(User& obj);

    // Method to modify a class in the linked list of classes
    void modify_class_in_list_of_classes();

    // Method to print the content of the linked list of classes
    void print_in_list_of_classes();

    // Convert a string to lowercase
    std::string to_Lower_Case_in_list_of_classes(const std::string & input);

    // Method to confirm user existence in the linked list of classes
    Class* confirmation_of_user_in_list_of_classes(const std::string& inputName);

    // Methods for saving and reading data to/from files
    void save_Data_To_File_in_list_of_classes(Class& classObj);
    void read_Data_From_File_in_list_of_classes(LinkUsers& otherlinkusers);

    // Utility method to convert a string to lowercase
    std::string to_Lower_Case(const std::string& input);

    // Method to introduce a delay (pause) in the program execution
    void is_to_delay();

    // Destructor
    ~LinkClass();
};
