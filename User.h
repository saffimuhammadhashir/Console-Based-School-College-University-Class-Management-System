#pragma once
#include<iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#include "FileManager.h" // Includes the FileManager header file
#include <string>
using namespace std;

// UserData class represents basic user data with username and password
class UserData {
private:
    std::string username;
    std::string password;
    
public:
    // Constructor
    UserData(){} // Default constructor

    // Parameterized constructor
    UserData(const std::string& uname, const std::string& pass) : username(uname), password(pass) {}
    
    // Getter for username
    std::string getUsername() const {
        return username;
    }
    
    // Setter for username
    void setUsername(const std::string& uname) {
        username = uname;
    }
    
    // Getter for password (Note: In real applications, passwords should be securely handled)
    std::string getPassword() const {
        return password;
    }
    
    // Setter for password (Note: In real applications, passwords should be securely handled)
    void setPassword(const std::string& pass) {
        password = pass;
    }
    
    // Other member functions related to user data can be added here
};

// User class inherits from UserData class and represents additional user-specific data
class User :public UserData{
private:
    string my_name;
    string my_email;
    string my_role;
    string hidden_Id;
    string Password_personal;
    string my_personal_contactInfo;
    bool Teaching_ability;
    FileManager fileManager; // FileManager object to manage file operations
public:
    User* Link; // Pointer to another User object

    // Default constructor
    User();

    // Parameterized constructor
    User(string& my_name, string& my_email, string& my_role,
         string& hidden_Id, string& Password_personal, string& my_personal_contactInfo);

    // Function to convert input string to lowercase
    string toLowerCase(const std::string& input);

    // Getter methods for class members
    string getmy_name();
    string getmy_Email();
    string getmy_Role();
    string gethidden_Id();
    string getmy_personal_ContactInfo();
    string getPassword_personal();
    
    // Setter method for hidden_Id using count
    void sethidden_Id(int count);
    
    // Getter for Teaching_ability
    bool getTeaching_ability() const;

    // Function to check if the input password matches the user's password
    bool confirmation_of_User(string& inputPassword_personal);

    // Function to save user data to a file using the FileManager
    void save_in_file();

    // Function to print all user data
    void print_all_data();
};

// You may add comments here explaining the purpose of each function, or any additional comments if needed.
