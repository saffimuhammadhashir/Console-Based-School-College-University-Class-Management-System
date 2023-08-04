// Preprocessor directives for text color codes and standard C++ libraries
#pragma once
#include <iostream>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
/*      EXPLAINATION            */
/*The provided code appears to be the implementation of the `User` class, which is used for user registration and handling user-related 
information in the class management system. Here'
s an explanation of the key components and functionalities of the `User` class:

1. **Constructor and Parameterized Constructor:** The class has two constructors. The first constructor is used for user registration, 
where the user is prompted to enter their name, email, role (teacher or student), password, and contact information. The second constructor
 is a parameterized constructor that initializes the user object with the provided information.

2. **`toLowerCase()` Function:** This function converts a given string to lowercase. It is used to standardize the role input as either 
"teacher" or "student" (regardless of case) to determine if the user has teaching ability.

3. **Getter Functions:** These functions are used to retrieve user information such as name, email, role, hidden ID, personal contact
 information, and password.

4. **`sethidden_Id()` Function:** This function sets the hidden ID of the user. It takes an integer `count` as an argument, converts it 
to a string, and assigns it to the `hidden_Id`.

5. **`getTeaching_ability()` Function:** This function returns a boolean value indicating whether the user has teaching ability. It checks 
if the role of the user is "teacher" and returns `true` in that case, otherwise `false`.

6. **`confirmation_of_User()` Function:** This function checks if the provided password matches the user's personal password. It takes a 
reference to the input password as an argument and returns `true` if the input password matches the stored password, otherwise `false`.

7. **`save_in_file()` Function:** This function saves the user's information to a file named `<hidden_Id>.txt`. It opens the file, writes the user's 
information to it, and then closes the file.

8. **`print_all_data()` Function:** This function prints all user data to the console, including name, email, role, hidden ID, and personal contact
 information.

Please note that there is an ASCII art variable `user_registration`, which is currently represented by "..." in the provided code. The actual ASCII 
art might be defined elsewhere in the code and could be a graphical representation of the user registration process.

Overall, the `User` class handles user-related operations and information, such as registration, authentication, data retrieval, and data saving to a
 file. It is likely part of a broader class management system that includes other classes for managing classes, assignments, grades, notifications, files, etc.*/

// Including necessary header files
#include "User.h"
#include "FileManager.cpp"
#include <fstream>
#include <cctype>

// Using the standard namespace to avoid writing std:: before each standard function or object
using namespace std;

// A multiline string representing some ASCII art of user registration, colored in red
string user_registration = "#     #                         ######\n#     #  ####  ###### #####     #     # ######  ####  #  ####  ##### #####    ##   ##### #  ####  #    #\n#     # #      #      #    #    #     # #      #    # # #        #   #    #  #  #    #   # #    # ##   # \n#     #  ####  #####  #    #    ######  #####  #      #  ####    #   #    # #    #   #   # #    # # #  # \n#     #      # #      #####     #   #   #      #  ### #      #   #   #####  ######   #   # #    # #  # # \n#     # #    # #      #   #     #    #  #      #    # # #    #   #   #   #  #    #   #   # #    # #   ## \n #####   ####  ###### #    #    #     # ######  ####  #  ####    #   #    # #    #   #   #  ####  #    # \n";
;
/*Constructor: The class has two constructors, one default constructor, and one parameterized constructor. 
The default constructor is used for user registration and prompts the user to enter their name, email, role (teacher or student),
 password, and contact information. The parameterized constructor is used to create a User object with provided data.

toLowerCase(const std::string& input): A utility function that converts a string to lowercase.

Getter and Setter Methods: The class includes getter and setter methods for accessing and modifying user information, such as name,
 email, role, unique ID, and contact information.*/
// Constructor of the User class
User::User() {
    // Display the user registration art in red
    cout << RED << user_registration << GREEN;

    // Ignore any remaining characters in the input buffer (in case there's any)
    cin.ignore();

    // Prompt the user to enter their name and read it into the 'my_name' variable
    cout << "Enter your name: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, my_name);

    // Prompt the user to enter their email and read it into the 'my_email' variable
    cout << GREEN << "Enter your email: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, my_email);

    // Prompt the user to enter their role (teacher or student) and read it into the 'my_role' variable
    cout << GREEN << "Enter your role (teacher or student): ";
    cout << CYAN;
    cout << YELLOW;
    getline(cin, my_role);

    // Prompt the user to enter their password and read it into the 'Password_personal' variable
    cout << GREEN << "Enter your Password: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, Password_personal);

    // Prompt the user to enter their contact information and read it into the 'my_personal_contactInfo' variable
    cout << GREEN << "Enter your contact information: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, my_personal_contactInfo);

    // Determine if the user has teaching ability based on their role (teacher or not)
    Teaching_ability = ("teacher" == toLowerCase(my_role)) ? true : false;

    // Initialize the 'Link' pointer to nullptr
    Link = nullptr;

    // Clear the console screen
    system("cls");
}

// Parameterized constructor of the User class
User::User(string& my_name, string& my_email, string& my_role, string& hidden_Id, string& Password_personal, string& my_personal_contactInfo)
    : my_name(my_name), my_email(my_email), my_role(my_role), hidden_Id(hidden_Id), Password_personal(Password_personal),
    my_personal_contactInfo(my_personal_contactInfo), Link(nullptr) {
    // Determine if the user has teaching ability based on their role (teacher or not)
    Teaching_ability = ("teacher" == toLowerCase(my_role)) ? true : false;
}

// Function to convert a string to lowercase
string User::toLowerCase(const std::string& input) {
    string result;
    for (char c : input) {
        result += tolower(c);
    }
    return result;
}

// Getter functions to retrieve user information
string User::getmy_name() {
    return my_name;
}

string User::getmy_Email() {
    return my_email;
}

string User::getmy_Role() {
    return my_role;
}

string User::gethidden_Id() {
    return hidden_Id;
}

string User::getmy_personal_ContactInfo() {
    return my_personal_contactInfo;
}

string User::getPassword_personal() {
    return Password_personal;
}

// Setter function to set the hidden ID of the user
void User::sethidden_Id(int count) {
    hidden_Id = to_string(count);
}
/*
getTeaching_ability(): A function to check if the user has teaching ability based on their role.

confirmation_of_User(string& inputPassword_personal): A function to check if the provided password matches the user's personal password.

save_in_file(): A function to save the user's information to a file. The user's data is saved in a file named with their unique ID.

print_all_data(): A function to print all user data to the console.*/
// Function to check if the user has teaching ability
bool User::getTeaching_ability() const {
    return Teaching_ability;
}

// Function to check if the provided password matches the user's personal password
bool User::confirmation_of_User(string& inputPassword_personal) {
    return Password_personal == inputPassword_personal;
}

// Function to save the user's information to a file
void User::save_in_file() {
    string filemy_Name = gethidden_Id() + ".txt";
    ofstream file(filemy_Name);

    if (file.is_open()) {
        // Write user information to the file
        file << "Name: " << getmy_name() << "\n" << "Email: " << getmy_Email() << "\n" << "Role: " << getmy_Role() << "\n" << "Unique ID: " << gethidden_Id() << "\n" << "Password : " << getPassword_personal() << "\n" << "Contact Info: " << getmy_personal_ContactInfo() << "\n";
        file.close();
        cout << "User data saved successfully.\n";
    } else {
        cout << "Error saving user data.\n";
    }
}

// Function to print all user data to the console
void User::print_all_data() {
    cout << "Name: " << my_name << "\n" << "Email: " << my_email << "\n" << "Role: " << my_role << "\n" << "Unique ID: " << hidden_Id << "\n" << "Contact Info: " << my_personal_contactInfo << "\n";
}
/*Overall, the User class encapsulates user data and provides methods to manage user information. The use of getline() ensures 
that the user can input data with spaces, and the class follows the conventions of object-oriented programming. However, it's worth
 noting that the code doesn't include error handling or validation for user inputs, which is essential to ensure the program's robustness.
 Additionally, storing passwords in plain text files is not secure, and a real-world application would use more secure methods for password management.*/
 