/*          EXPLANATION             */
/*The provided code appears to be an implementation of member functions of the `LinkClass` class, which is part of the broader system for managing classes and students. Below is the explanation of the remaining member functions:

1. **LinkClass::LinkClass(LinkUsers &other)**
   - Constructor for the `LinkClass` class that initializes the object with another `LinkUsers` object.
   - It also reads data from a file associated with the provided `LinkUsers` object using `read_Data_From_File_in_list_of_classes()`.

2. **LinkClass::to_Lower_Case_in_list_of_classes(const std::string &input)**
   - Converts a string to lowercase.
   - It iterates through each character of the input string and appends its lowercase version to the result string.
   - Returns the resulting lowercase string.

3. **LinkClass::add_Class_in_list_of_classes(LinkUsers &other)**
   - Adds a new class to the list of classes.
   - It displays the teacher portal message and prompts the user to provide class details like name, subject, teacher's name, and description.
   - Creates a new `Class` object with the provided class details.
   - Adds the new `Class` object to the list of classes using a linked list.

4. **LinkClass::add_Class_in_list_of_classes(Class &otherclass, LinkUsers &other)**
   - Overloaded version of `add_Class_in_list_of_classes()` to add a class to the list of classes with the provided `Class` object.
   - It takes a `Class` object and a `LinkUsers` object as inputs.
   - If the list of classes is empty, it sets the start class as the provided class.
   - Otherwise, it traverses the list to find the last class and links the provided class to it.

5. **LinkClass::pause_in_list_of_classes(int dur)**
   - Introduces a pause in the program execution for the given duration (in seconds).
   - It calculates the end time of the pause and waits until the current time reaches the calculated end time using a `while` loop.

6. **LinkClass::random_Boolean_in_list_of_classes()**
   - Generates a random boolean value (true or false).
   - It seeds the random number generator with the current time.
   - Generates a random integer between 0 and 1 and converts it to a boolean value (0 maps to false, 1 maps to true).
   - Returns the generated boolean value.

7. **LinkClass::student_enrollment_in_list_of_classes(User &obj)**
   - Handles the student enrollment process in a class.
   - Displays the student portal message and the enrollment application portal message.
   - Prompts the user to choose a course from the available classes or type 'exit' to return.
   - Validates the course selection and processes the enrollment application.
   - Uses random boolean values to simulate the acceptance or denial of the application.
   - If accepted, the student is added to the class using the `add_Student_in_class()` method, and the enrolled student data is saved to a file.
   - If denied, a denial message is displayed.

8. **LinkClass::student_grades_in_list_of_classes(User &obj)**
   - Displays the student's grades for all classes.
   - It iterates through each class and reads grades from a file using the `read_Grades_From_File_in_class()` method.
   - Displays the student's grades for each class using the `display_Student_Grades_in_class()` method.

9. **LinkClass::course_search_in_list_of_classes(std::string course_selection)**
   - Searches for a course in the list of classes.
   - It iterates through each class and compares the provided course selection with the class names (case-insensitive).
   - Returns true if a match is found, otherwise returns false.

10. **LinkClass::student_course_search_in_list_of_classes(std::string course_selection, string StudentId)**
    - Searches for a course and student enrollment in the list of classes.
    - It iterates through each class and compares the provided course selection with the class names (case-insensitive).
    - If a match is found, it iterates through enrolled students and checks if the provided student ID matches.
    - Returns true if both the course and student are found, otherwise returns false.

11. **LinkClass::student_class_search_in_list_of_classes(std::string course_selection, string StudentId)**
    - Searches for a course and returns the associated class.
    - It iterates through each class and compares the provided course selection with the class names (case-insensitive).
    - If a match is found, it iterates through enrolled students and checks if the provided student ID matches.
    - Returns the found class if both the course and student are found, otherwise returns nullptr.

12. **LinkClass::view_class_files_in_list_of_classes(User &obj)**
    - Allows a student to view class files for a specific class.
    - Displays the student portal message and prompts the user to provide the name of the class they want to access.
    - Validates the class selection and searches for the class using `student_course_search_in_list_of_classes()`.
    - If the class is found and the student is enrolled in it, the student can manage class files using `manage_File_Student_in_class()`.

13. **LinkClass::assignment_view_in_list_of_classes(User &obj)**
    - Allows a student to view assignments for a specific class.
    - Displays the student portal message and prompts the user to provide the name of the class they want to access.
    - Validates the class selection and searches for the class using `student_course_search_in_list_of_classes()`.
    - If the class is found and the student is enrolled in it, the student can manage assignments using `manage_assignment_student_in_class()`.

14. **LinkClass::modify_class_in_list_of_classes()**
    - Allows a teacher to modify a class's details.
    - Displays the teacher portal message and prompts the user to provide the name of the class they want to modify.
    - Searches for the class using `confirmation_of_user_in_list_of_classes()` and presents options to update the class details, remove specific students, or add specific students.
    - Updates the class details using `update_Class_Details_in_class()`, removes students using `remove_Student_in_class()`, and adds students using `add_Student_in_class()`.
    - Uses `save_Enrolled_in_class_Students_To_File_in_class()` to save enrolled students' data to a file.

15. **LinkClass::print_in_list_of_classes()**
    - Displays the details of all classes.
    - It iterates through each class and displays class details using `display_Class_Details_in_class()`.

16. **LinkClass::confirmation_of_user_in_list_of_classes(const std::string &inputName)**
    - Confirms a class's existence in the list of classes based on the provided class name (inputName).
    - It iterates through each class and compares the provided input name with the class names (case-insensitive).
    - If a match is found, it returns a pointer to the matched class; otherwise, it returns nullptr.

17. **LinkClass::save_Data_To_File_in_list_of_classes(Class &classObj)**
    - Saves class data to a file.
    It takes a Class object and opens a file named "class1.txt" in append mode.
    Writes class details, enrolled students' grades, and grades data to the file.
    Closes the file after writing.
18. LinkClass::read_Data_From_File_in_list_of_classes(LinkUsers &otherlinkusers)

    Reads data from a file and creates classes.
    It uses the FileManager class to check if the file "class1.txt" exists in the file folder.
    If the file exists, it opens the file and reads class details.
For each class, it creates a new Class object with the read details and adds it to the list of classes using add_Class_in_list_of_classes().
19. LinkClass::is_to_delay()

    Introduces a delay animation using a loading animation.
    It displays a loading animation and prompts the user to press enter to continue.
20. LinkClass::~LinkClass()

    Destructor for the LinkClass class.
    It deletes all Class objects in the list of classes to clean up dynamically allocated memory.

Note: Since the provided code is a part of a larger system, some variables and functions mentioned
 in the code might be defined in other parts of the system, such as the Class class and the FileManager class.
 It would be helpful to review the entire system code to understand its complete functionality and how these parts
 interact with each other.*/
// Include necessary header files
#pragma once
#include <iostream>
#include "Linking_Class.h" // Include the header file for Linking_Class

// Define color codes for console output
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

using namespace std;

// Implementation of the LinkClass member functions
/*LinkClass::LinkClass(LinkUsers &other)

Constructor that initializes the LinkClass object with another LinkUsers object.
Reads data from a file associated with the LinkUsers object.
Sets the start_Class_in_list_of_classes pointer to nullptr to initialize the linked list of classes.*/
LinkClass::LinkClass(LinkUsers &other) : start_Class_in_list_of_classes(nullptr)
{
    // Constructor initializes the object with another LinkUsers object
    // It also reads data from a file associated with the LinkUsers object
    other_users_link_in_list_of_classes = other;
    read_Data_From_File_in_list_of_classes(other_users_link_in_list_of_classes);
}

// Function to convert a string to lowercase
/*LinkClass::to_Lower_Case_in_list_of_classes(const std::string &input)

Converts a given string to lowercase characters.
It takes a string input as an argument and iterates through its characters, converting each character to its lowercase form.
Returns the converted string.*/
std::string LinkClass::to_Lower_Case_in_list_of_classes(const std::string &input)
{
    std::string result;
    for (char c : input)
    {
        result += std::tolower(c);
    }
    return result;
}

// Function to add a class to the list of classes
/*LinkClass::add_Class_in_list_of_classes(LinkUsers &other)

Adds a new class to the list of classes.
Displays the teacher portal message.
Stores the provided LinkUsers object in the other_users_link_in_list_of_classes member variable.
Creates a new Class object using the LinkUsers object and adds it to the list of classes.
If the list of classes is empty, the new class becomes the start_Class_in_list_of_classes.
Otherwise, it traverses the list to find the last class and links the new class to it.
Finally, it saves the class data to a file using the save_Data_To_File_in_list_of_classes function.*/
void LinkClass::add_Class_in_list_of_classes(LinkUsers &other)
{
    // Display teacher portal message in red and cyan
    cout << RED << teacher_portal << CYAN << endl;
    
    // Store the provided LinkUsers object
    other_users_link_in_list_of_classes = other;
    
    // Create a new Class object
    Class *create = new Class(other_users_link_in_list_of_classes);
    
    // Add the new Class object to the list of classes
    if (start_Class_in_list_of_classes == nullptr)
        start_Class_in_list_of_classes = create;
    else
    {
        // Traverse the list to find the last class and link the new class to it
        Class *current = start_Class_in_list_of_classes;
        while (current->Link != nullptr)
        {
            current = current->Link;
        }
        current->Link = create;
    }
    
    // Save the class data to a file
    save_Data_To_File_in_list_of_classes(*create);
}

// Overloaded function to add a class to the list of classes
/*LinkClass::add_Class_in_list_of_classes(Class &otherclass, LinkUsers &other)

An overloaded version of the add_Class_in_list_of_classes function that allows adding an existing Class object to the list of classes.
It stores the provided LinkUsers object in the other_users_link_in_list_of_classes member variable.
If the list of classes is empty, it sets the start class as the provided class.
Otherwise, it traverses the list to find the last class and links the provided class to it, then sets the provided class's link to nullptr.
Reads enrolled students' data from a file for the provided class using the read_Enrolled_Students_From_File_in_class function.
Reads grades data from a file for the provided class using the read_Grades_From_File_in_class function.*/
void LinkClass::add_Class_in_list_of_classes(Class &otherclass, LinkUsers &other)
{
    // Store the provided LinkUsers object
    other_users_link_in_list_of_classes = other;
    
    // If the list of classes is empty, set the start class as the provided class
    if (start_Class_in_list_of_classes == nullptr)
        start_Class_in_list_of_classes = &otherclass;
    else
    {
        // Traverse the list to find the last class and link the provided class to it
        Class *current = start_Class_in_list_of_classes;
        while (current->Link != nullptr)
        {
            current = current->Link;
        }
        current->Link = &otherclass;
        otherclass.Link = nullptr;
    }
    
    // Read enrolled students' data from a file
    otherclass.read_Enrolled_Students_From_File_in_class();
    // Read grades data from a file
    otherclass.read_Grades_From_File_in_class(otherclass);
}

// Function to introduce a pause in the program execution for a given duration
/*LinkClass::pause_in_list_of_classes(int dur)

Introduces a pause in the program execution for a given duration.
It calculates the time at which the pause should end by adding the given duration dur (in seconds) to the current time.
The function then waits until the current time reaches the calculated end time to introduce the pause.*/
void LinkClass::pause_in_list_of_classes(int dur)
{
    // Calculate the time at which the pause should end
    int temp = time(NULL) + dur;
    // Wait until the current time reaches the calculated end time
    while (temp > time(NULL))
        ;
}

// Function to generate a random boolean value (true or false)
/*LinkClass::random_Boolean_in_list_of_classes()

Generates a random boolean value (true or false).
It seeds the random number generator with the current time.
Generates a random integer between 0 and 1 using std::rand() and takes its modulo 2.
Converts the random integer to a boolean value (0 maps to false, 1 maps to true) and returns it.*/
bool LinkClass::random_Boolean_in_list_of_classes()
{
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // Generate a random integer between 0 and 1
    int randomInt = std::rand() % 2;
    
    // Convert the random integer to a boolean value (0 maps to false, 1 maps to true)
    return static_cast<bool>(randomInt);
}

// Function to handle student enrollment in a class
/*LinkClass::student_enrollment_in_list_of_classes(User &obj)

Handles student enrollment in a class.
Displays the student portal message and the enrollment application portal message.
Displays the list of available classes using the print_in_list_of_classes function.
Takes input for the user's course selection and converts it to lowercase using to_Lower_Case_in_list_of_classes.
Validates the user's course selection using the course_search_in_list_of_classes function.
If the user chose to exit, the function returns.
If the user's selection is valid, it proceeds with the enrollment process.
Displays a confirmation message and generates a random boolean value to simulate the application acceptance or denial.
If the application is accepted, it finds the class associated with the chosen course selection and adds the student to the class.
Saves enrolled students' data to a file for the class.
Displays success or denial message and prompts the user to press enter to continue.*/
void LinkClass::student_enrollment_in_list_of_classes(User &obj)
{
    std::string course_selection;
    do
    {
        system("cls");
        // Display student portal message in red and cyan
        cout << RED << student_portal << CYAN << endl;
        
        // Display enrollment application portal message
        std::cout << RED << "Student Enrollment Application portal" << std::endl << std::endl;
        std::cout << BLUE << "Following Course Classes are available" << GREEN << std::endl << std::endl;
        
        // Print the list of available classes
        print_in_list_of_classes(); 
        
        // Display exit option and input prompt
        std::cout << std::endl << std::endl << BLUE << "Type 'exit' to return from the application portal." << std::endl;
        std::cout << "Choose a course from these: ";
        
        // Get the user's course selection input
        std::cout << CYAN;
        cout << YELLOW;
        cout << YELLOW;
        getline(std::cin, course_selection);
        system("cls");
        
        // Convert the user input to lowercase
        course_selection = to_Lower_Case_in_list_of_classes(course_selection);
        system("cls");
    } while (!course_search_in_list_of_classes(course_selection) && course_selection != "exit");
    
    // Check if the user chose to exit
    if (course_selection == "exit")
    {
        return;
    }
    
    // Display confirmation message and delay animation
    std::cout << RED << "Your application is received. Please is_to_delay a few minutes for the response." << std::endl;
    cout << endl << YELLOW << "{" << RED;
    for (int i = 0; i < 14; i++)
    {
        pause_in_list_of_classes(1);
        cout << "    *";
    }
    cout << YELLOW << "   }" << endl << endl;
    system("cls");
    
    // Display student portal message again
    cout << RED << student_portal << CYAN << endl;
    
    // Check if the application is accepted or denied based on random boolean
    if (random_Boolean_in_list_of_classes())
    {
        // Find the class associated with the chosen course selection
        Class *auth = confirmation_of_user_in_list_of_classes(course_selection);
        
        // Add the student to the class
        auth->add_Student_in_class(obj.gethidden_Id(), other_users_link_in_list_of_classes);
        
        // Display class details
        auth->display_Class_Details_in_class();
        
        // Save enrolled students' data to a file
        auth->save_Enrolled_in_class_Students_To_File_in_class();
        
        // Display success message
        cout << GREEN << "Your application is accepted and you are admitted to the course : " << course_selection << endl;
    }
    else
    {
        // Display denial message
        cout << RED << "Your application is denied and you are not admitted to the course : " << course_selection << endl;
    }
    
    // Prompt the user to press enter to continue
    cout << YELLOW << "Press enter to continue: ";
    cin.ignore();
    cout << endl << endl;
}

// Function to display student grades
/*LinkClass::student_grades_in_list_of_classes(User &obj)

Displays the student's grades for all classes.
Iterates through each class and displays the student's grades for each class.
Reads grades from file for each class using the read_Grades_From_File_in_class function.
Displays a message if there is no more grade information available.*/
void LinkClass::student_grades_in_list_of_classes(User &obj)
{
    // Iterate through each class and display student's grades
    Class *current = start_Class_in_list_of_classes;
    while (current != nullptr)
    {
        // Read grades from file
        current->read_Grades_From_File_in_class(*current);
        string place = obj.gethidden_Id();
        // Display student's grades
        current->display_Student_Grades_in_class(place);
        std::cout << std::endl;
        current = current->Link;
    }
    cout << RED << "No more Grade information available" << YELLOW << endl;
    cin.ignore();
    is_to_delay();
}

// Function to search for a course in the list of classes
/*LinkClass::course_search_in_list_of_classes(std::string course_selection)

Searches for a course in the list of classes.
Iterates through each class and compares the course names with the provided course_selection.
Returns true if the provided course_selection matches any class name; otherwise, returns false.*/
bool LinkClass::course_search_in_list_of_classes(std::string course_selection)
{
    // Iterate through each class and compare course names
    Class *current = start_Class_in_list_of_classes;
    while (current != nullptr)
    {
        // Check if the provided course selection matches the current class name
        if (course_selection == to_Lower_Case_in_list_of_classes(current->getClass_Name_in_class()) || course_selection == "exit")
            return true;
        // Move to the next class
        current = current->Link;
    }
    return false;
}

// Function to search for a course and student enrollment in the list of classes
/*LinkClass::student_course_search_in_list_of_classes(std::string course_selection, string StudentId)

Searches for a course and student enrollment in the list of classes.
Iterates through each class and compares the course names with the provided course_selection.
If the provided course_selection matches any class name, it iterates through the enrolled students and checks if the provided StudentId matches any enrolled student's ID.
Returns true if the provided course_selection and StudentId match any class and enrolled student; otherwise, returns false.*/
bool LinkClass::student_course_search_in_list_of_classes(std::string course_selection, string StudentId)
{
    // Iterate through each class and compare course names
    Class *current = start_Class_in_list_of_classes;
    while (current != nullptr)
    {
        // Check if the provided course selection matches the current class name
        if (course_selection == to_Lower_Case_in_list_of_classes(current->getClass_Name_in_class()) || course_selection == "exit")
        {
            // Iterate through enrolled students and check if the provided student ID matches
            for (int i = 0; i < current->num_Enrolled_Students_in_class; i++)
            {
                if (current->enrolled_Students_in_class[i] == StudentId || course_selection == "exit")
                    return true;
            }
        }
        // Move to the next class
        current = current->Link;
    }
    cout << "You cannot access as you are not enrolled in this class" << endl;
    return false;
}

// Function to search for a course and return the associated class
/*LinkClass::student_class_search_in_list_of_classes(std::string course_selection, string StudentId)

Searches for a course and returns the associated class.
Creates a new Class object and sets it to start from the beginning of the list.
Iterates through each class and compares the course names with the provided course_selection.
If the provided course_selection matches any class name, it iterates through the enrolled students and checks if the provided StudentId matches any enrolled student's ID.
Returns the found class if the provided course_selection and StudentId match any class and enrolled student; otherwise, returns nullptr.
*/
Class *LinkClass::student_class_search_in_list_of_classes(std::string course_selection, string StudentId)
{
    // Create a new Class object
    Class *current = new Class;
    // Set it to start from the beginning of the list
    current = start_Class_in_list_of_classes;
    while (current != nullptr)
    {
        // Check if the provided course selection matches the current class name
        if (course_selection == to_Lower_Case_in_list_of_classes(current->getClass_Name_in_class()) || course_selection == "exit")
        {
            // Iterate through enrolled students and check if the provided student ID matches
            for (int i = 0; i < current->num_Enrolled_Students_in_class; i++)
            {
                if (current->enrolled_Students_in_class[i] == StudentId || course_selection == "exit")
                    return current;
            }
        }
        // Move to the next class
        current = current->Link;
    }
    // Return the found class
    return current;
}

// Function to view class files
/*LinkClass::view_class_files_in_list_of_classes(User &obj)

Allows a student to view class files for the selected class.
Displays the student portal message.
Prompts the user to provide the name of the class they want to access.
Validates the user's input using the student_course_search_in_list_of_classes function.
If the user chose to exit, the function returns.
Searches for the class associated with the provided course selection and student ID using the student_class_search_in_list_of_classes function.
Manages class files for the selected class using the manage_File_Student_in_class function of the class.*/
void LinkClass::view_class_files_in_list_of_classes(User &obj)
{
    string view_class_files_in_list_of_classes;
    Class *obj_class = nullptr;
    do
    {
        // Display exit option and input prompt
        cout << "Type exit to return to previous page." << endl << endl;
        cout << "Provide Name of class you want to access" << endl;
        cout << "Your Choice :";
        cout << YELLOW;
        cin >> view_class_files_in_list_of_classes;
        view_class_files_in_list_of_classes = to_Lower_Case_in_list_of_classes(view_class_files_in_list_of_classes);
    } while (!student_course_search_in_list_of_classes(view_class_files_in_list_of_classes, obj.gethidden_Id()) && view_class_files_in_list_of_classes != "exit");
    
    // Check if the user chose to exit
    if (view_class_files_in_list_of_classes == "exit")
    {
        return;
    }
    
    // Search for the class associated with the provided course selection and student ID
    obj_class = student_class_search_in_list_of_classes(view_class_files_in_list_of_classes, obj.gethidden_Id());
    system("cls");
    
    // Display student portal message
    cout << RED << student_portal << CYAN << endl;
    
    // Manage class files for the selected class
    obj_class->manage_File_Student_in_class();
}

// Function to view assignments
/*LinkClass::assignment_view_in_list_of_classes(User &obj)

Allows a student to view assignments for the selected class.
Displays the student portal message.
Prompts the user to provide the name of the class they want to access.
Validates the user's input using the student_course_search_in_list_of_classes function.*/
void LinkClass::assignment_view_in_list_of_classes(User &obj)
{
    string view_class_assignments;
    Class *obj_class = nullptr;
    do
    {
        // Display exit option and input prompt
        cout << "Type exit to return to previous page." << endl << endl;
        cout << "Provide Name of class you want to access" << endl;
        cout << "Your Choice :";
        cout << YELLOW;
        cin >> view_class_assignments;
        view_class_assignments = to_Lower_Case_in_list_of_classes(view_class_assignments);
    } while (!student_course_search_in_list_of_classes(view_class_assignments, obj.gethidden_Id()) && view_class_assignments != "exit");
    
    // Check if the user chose to exit
    if (view_class_assignments == "exit")
    {
        return;
    }
    
    // Search for the class associated with the provided course selection and student ID
    obj_class = student_class_search_in_list_of_classes(view_class_assignments, obj.gethidden_Id());
    system("cls");
    
    // Display student portal message
    cout << RED << student_portal << CYAN << endl;
    
    // Manage assignments for the selected class
    obj_class->manage_assignment_student_in_class(obj);
}

// Function to modify a class
/*LinkClass::modify_class_in_list_of_classes()

Allows a teacher to modify a class.
Displays the teacher portal message.
Prompts the user for the class name they want to modify.
Searches for the class associated with the provided class name using the confirmation_of_user_in_list_of_classes function.
If the class is found, the function displays a menu of modification options.
The user can choose to update class details, remove specific students, add specific students, or return to the previous menu.
For updating class details, the function prompts the user for new class details and calls the update_Class_Details_in_class function.
For removing a specific student, the function prompts the user for the student ID to be removed and calls the remove_Student_in_class function.
For adding a specific student, the function prompts the user for the student ID to be added and calls
 the add_Student_in_class function, then saves the enrolled students' data to a file.
After each modification, the function introduces a delay animation using the is_to_delay function.
If no class is found for the provided class name, the function displays an error message.*/
void LinkClass::modify_class_in_list_of_classes()
{
    std::string inputName;
    cin.ignore();
    // Prompt the user for the class name to be modified
    cout << CYAN << "Provide Name of class in which you want modification : ";
    cout << CYAN;
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, inputName);
    system("cls");
    
    // Search for the class associated with the provided input name
    Class *auth = confirmation_of_user_in_list_of_classes(inputName);
    bool c = true;
    while (c)
    {
        if (auth != nullptr)
        {
            int choice_modification = 0;
            do
            {
                // Display teacher portal message
                cout << RED << teacher_portal << CYAN << endl;
                cout << endl << "CHOOSE FROM THE BELOW THAT WHAT YOU WANT TO MODIFY" << endl;
                cout << "1. Update the Class details." << endl;
                cout << "2. Remove any specific Student." << endl;
                cout << "3. Add sny specific Student." << endl;
                cout << "4. Return to previous menu." << endl;
                cout << "YOUR CHOICE: ";
                cout << YELLOW;
                cout << YELLOW;
                cin >> choice_modification;
                /* code */
                system("cls");
            } while (choice_modification != 1 && choice_modification != 2 && choice_modification != 3 && choice_modification != 4);
            string className, subject, teacher, description, Id;
            cout << RED << teacher_portal << CYAN << endl;
            if (choice_modification == 1)
            {
                cin.ignore();
                // Prompt the user for updated class details
                cout << "Provide Name of class: ";
                cout << CYAN;
                cout << YELLOW;
                cout << YELLOW;
                getline(cin, className);
                cout << "Enter subject: ";
                cout << CYAN;
                cout << YELLOW;
                cout << YELLOW;
                getline(cin, subject);
                cout << "Enter teacher's name: ";
                cout << CYAN;
                cout << YELLOW;
                cout << YELLOW;
                getline(cin, teacher);
                cout << "Enter class description: ";
                cout << CYAN;
                cout << YELLOW;
                cout << YELLOW;
                getline(cin, description);
                // Update the class details
                auth->update_Class_Details_in_class(className, subject, teacher, description);
                /* code */
            }
            else if (choice_modification == 2)
            {
                // Prompt the user for the student ID to be removed
                cout << "Provide student Id to remove from this class : ";
                cout << CYAN;
                cout << YELLOW;
                cin >> Id;
                // Remove the student from the class
                auth->remove_Student_in_class(Id);
                /* code */
                is_to_delay();
            }
            else if (choice_modification == 3)
            {
                // Prompt the user for the student ID to be added
                cout << "Provide student Id to be Added to this class : ";
                cout << CYAN;
                cout << YELLOW;
                cin >> Id;
                // Add the student to the class
                auth->add_Student_in_class(Id, other_users_link_in_list_of_classes);
                auth->save_Enrolled_in_class_Students_To_File_in_class();
                /* code */
                is_to_delay();
            }
            else
            {
                c = false;
            }

            is_to_delay();
        }
        else
        {
            cout << endl << "No class found!" << endl << endl;
            c = false;
        }
    }
}

// Function to print the details of all classes
/*LinkClass::print_in_list_of_classes()

Prints the details of all classes.
Iterates through each class and displays the class details using the display_Class_Details_in_class function.*/
void LinkClass::print_in_list_of_classes()
{
    // Iterate through each class and display class details
    Class *current = start_Class_in_list_of_classes;
    while (current != nullptr)
    {
        current->display_Class_Details_in_class();
        std::cout << std::endl;
        current = current->Link;
    }
}

// Function to confirm the user in the list of classes
/*LinkClass::confirmation_of_user_in_list_of_classes(const std::string &inputName)

Confirms the existence of a class in the list of classes based on its name.
Iterates through each class and compares the provided input name with the current class name.
If the input name matches the current class name, the function returns a pointer to the matched class; otherwise, it returns nullptr.*/
Class *LinkClass::confirmation_of_user_in_list_of_classes(const std::string &inputName)
{
    // Iterate through each class and compare class names
    Class *current = start_Class_in_list_of_classes;
    while (current != nullptr)
    {
        // Check if the provided input name matches the current class name
        if (to_Lower_Case_in_list_of_classes(current->getClass_Name_in_class()) == to_Lower_Case_in_list_of_classes(inputName))
        {
            return current;
        }
        // Move to the next class
        current = current->Link;
    }
    return nullptr;
}

// Function to save class data to a file
/*LinkClass::save_Data_To_File_in_list_of_classes(Class &classObj)

Saves class data to a file.
Opens a file named "class1.txt" in append mode.
Writes the class details to the file, including class name, subject, teacher, and description.
Writes enrolled students' grades to the file using the get_Student_Grade_in_GradeBook function.
Closes the file and displays success or error messages.*/
void LinkClass::save_Data_To_File_in_list_of_classes(Class &classObj)
{
    std::ofstream file("class1.txt", std::ios::app);
    if (file.is_open())
    {
        // Write class details to the file
        file << "Class Name: " << classObj.getClass_Name_in_class() << "\n";
        file << "subject: " << classObj.getsubject_in_class() << "\n";
        file << "Teacher: " << classObj.getTeacher_in_class() << "\n";
        file << "Description: " << classObj.getDescription_in_class() << "\n";
        
        // Write enrolled students' grades to the file
        file << "Grades_grades_in_class:\n";
        for (int i = 0; i < classObj.num_Enrolled_Students_in_class; ++i)
        {
            file << classObj.enrolled_Students_in_class[i] << " " << classObj.grades_in_class.get_Student_Grade_in_GradeBook(i) << "\n";
        }
        
        file << "\n";
        
        // Close the file and display success or error message
        file.close();
        std::cout << "Class details and grades_in_class saved to file successfully.\n";
    }
    else
    {
        std::cout << "Error saving class details and grades_in_class to file.\n";
    }
}

// Function to read data from a file and create classes
/*LinkClass::read_Data_From_File_in_list_of_classes(LinkUsers &otherlinkusers)

Reads data from a file and creates classes.
Checks if the file "class1.txt" exists in the file folder using the file_Exists_in_file_folder function of the FileManager class.
If the file exists, it opens the file and reads class data line by line.
For each class, it extracts the class name, subject, teacher, and description from the file and creates a new Class object with the extracted details.
It also reads grades data for each class using the read_Grades_From_File_in_class function.
After reading data for a class, it calls the add_Class_in_list_of_classes function to add the newly created class to the list of classes.
Finally, it closes the fil*/
void LinkClass::read_Data_From_File_in_list_of_classes(LinkUsers &otherlinkusers)
{
    FileManager fileManager;
    std::string filename = "class1.txt";
    if (fileManager.file_Exists_in_file_folder(filename))
    {
        std::ifstream file(filename);
        if (file.is_open())
        {
            Class *newClass = nullptr;
            std::string line;
            while (std::getline(file, line))
            {
                if (line.find("Class Name: ") == 0)
                {
                    if (newClass != nullptr)
                    {
                        // Add the newly created class to the list of classes
                        add_Class_in_list_of_classes(*newClass, otherlinkusers);
                    }

                    std::string className = line.substr(12);
                    std::string subject, teacher, description;
                    cout << CYAN;
                    cout << YELLOW;
                    cout << YELLOW;
                    getline(file, line);
                    subject = line.substr(9);
                    cout << CYAN;
                    cout << YELLOW;
                    cout << YELLOW;
                    getline(file, line);
                    teacher = line.substr(9);
                    cout << CYAN;
                    cout << YELLOW;
                    cout << YELLOW;
                    getline(file, line);
                    description = line.substr(13);

                    // Create a new class object with the extracted details
                    newClass = new Class(className, subject, teacher, description);
                }
                else if (line.find("Grades_grades_in_class:") == 0 && newClass != nullptr)
                {
                    // Read and populate the grades_in_class data for the class
                    newClass->read_Grades_From_File_in_class(*newClass);
                }
            }
            if (newClass != nullptr)
            {
                // Add the last class from the file
                add_Class_in_list_of_classes(*newClass, otherlinkusers);
            }

            file.close();
        }
        else
        {
            std::cout << "Error reading class data from file.\n";
        }
    }
    else
    {
        std::cout << "Class data file not found.\n";
    }
}

// Function to introduce a delay animation
/*LinkClass::is_to_delay()

Introduces a delay animation.
Displays a loading animation using yellow color.*/
void LinkClass::is_to_delay()
{
    // Display a loading animation
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
     cout<<"Press Enter to continue: ";
        cin.ignore();
        system("cls");
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << YELLOW;
    cout << endl
         << endl;
}

// Destructor to clean up dynamically allocated memory
/*LinkClass::~LinkClass()

Destructor to clean up dynamically allocated memory.
Deletes all Class objects in the list of classes using a while loop to traverse the linked list and deallocate memory for each class.*/
LinkClass::~LinkClass()
{
    // Delete all Class objects in the list of classes
    Class *current = start_Class_in_list_of_classes;
    while (current != nullptr)
    {
        Class *temp = current;
        current = current->Link;
        delete temp;
    }
}
/*The implementation includes member functions for student enrollment, viewing student grades, searching for classes, modifying classes,
 viewing class files, and viewing assignments. The class uses linked lists to
 maintain the collection of classes, and it also interacts with the LinkUsers class and Class class for various functionalities.*/

