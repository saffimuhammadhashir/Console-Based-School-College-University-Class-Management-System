
#pragma once
#include <iostream>
#include <string>

#include <limits>

#include "User.cpp"

#include "Class.cpp"

#include "Assignment.cpp"

#include "Submission.cpp"

#include "GradeBook.cpp"

#include "FileManager.cpp"

#include "Notification.cpp"

#include "UI.h"

#include "linking.cpp"

#include "Linking_CLass.cpp"

#include <windows.h>

using namespace std;

/*The code includes multiple header files, each representing different classes
 (e.g., User, Class, Assignment, etc.).
 These header files are included to access the class declarations.*/

/*                     EXPLAINATION                 */
/*

The code includes various C++ header files, custom header files (such as "User.cpp," "Class.cpp," etc.),
and defines preprocessor directives for text color codes.

It defines a few utility functions like is_to_delay, is_to_dealy, loadcntrl, load, fakeLoadingcntrl, and
fakeLoading. These functions are used to create delay, loading animations, and clearing the console screen.

The main function presents a main menu with options for user registration, student portal, teacher portal,
and program exit. Based on the user's choice, it provides different functionalities:

If the user selects "Registration for New Users" (option 1), they can register as a new user. Their details
are added to the LinkUsers object (users).

If the user selects "Classroom Portal for Students" (option 2), they are prompted to enter their username and
password for authentication. If successful, they are redirected to a student-specific menu with options like

 enrollment application, viewing grades, submitting files, and managing files for their classes.

If the user selects "Classroom Portal for Teachers" (option 3), they are prompted to enter their username and
password for authentication. If successful and if the user has teaching ability, they are redirected to a teacher-specific
 menu with options like creating & announcing a new class, managing assignments, grades, files, and notifications for their classes.

If the user selects "Exit the program" (option 4), the program terminates, ending the main loop.

The program uses classes such as UI, User, LinkUsers, Class, LinkClass, and other classes for managing users,
classes, assignments, grades, files, and notifications.

The program utilizes different functions to manage class-specific functionalities like enrollment, grading,
assignment management, file management, and notification management.

Please note that the code snippets you've provided are just a part of a larger program, and the complete implementation
of classes and their functionalities is not present. Additionally, the code contains some C++ features that can be improved and some
 functions with spelling errors (e.g., is_to_dealy instead of is_to_delay). The program might require additional implementation for some
  functions and header files to function correctly.*/
  
/*The code defines some macros for text colors.
 These macros will be used later to display colored text in the console.*/
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
LinkUsers users;
LinkClass classes(users);
/*The main() function starts the main execution of the program.
 It displays the main menu
options and waits for the user to select an option.*/
void UI::StartProgram()
{
    load(10);
    system("cls");
    cout << endl;
    bool a = true;
    UI ui; /*The UI class is instantiated as ui, and
      LinkUsers and LinkClass objects
      are created as users and classes, respectively.*/
    LinkUsers users;
      is_to_delay(1);
    LinkClass classes(users);
       is_to_delay(1);
    //  std::string fileName = "1.txt";
    // std::ofstream file(fileName);
     
     fakeLoading(5);
    
    // file.close();
    //   users.print_in_user_list();
    cout << "   }" << endl
         << endl;
          system("cls");
    // system("cls");
    /*Within the main function, there are various functions and loops for
     different functionalities like enrollment, grading, managing assignments,
     and managing files for both students and teachers.*/
    while (a)
    {
        int choice = 0;
        do
        { /*The main menu is presented with four options: Registration for New Users,
         Classroom
          Portal for Students, Classroom Portal for Teachers, and Exit the program.*/
            cout << endl
                 << RED << mainmenu << endl;
            cout << MAGENTA << "CHOOSE FROM THE FOLLOWING." << endl;
            cout << GREEN << "1. Registration for the New Users." << endl;
            cout << GREEN << "2. Classroom Portal for Students." << endl;
            cout << GREEN << "3. Classroom Portal for Teacher." << endl;
            cout << GREEN << "4. Display data for all Registered Users." << endl;
            cout << RED << "5. Exit the program." << endl;
            cout << CYAN "YOUR CHOICE: " << YELLOW;
            cout << YELLOW;
            cin >>
                choice;

            system("cls");
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice!=5);
        string inputName, inputPassword;
        User *auth;

        if (choice == 1)
        { /*If the user selects option 1, they are prompted to
          register as a new user. The user details are added to the
           LinkUsers object (users).*/
            users.adding_User_in_user_list();
            is_to_dealy();
        }
        else if (choice == 2)
        {
            /*If the user selects option 2 (Student Portal), they are prompted to enter their username and
             password for authentication. If successful, the student is redirected to a student-specific menu with options such as Enrollment
             Application Portal, View Grades, Submission of Files, and Manage Files of the Class.*/
            cout << RED << student_portal << endl;
            cout << MAGENTA << "Enter your Username to access your data: " << YELLOW;
            cout << YELLOW;
            cin.ignore();
            cout << YELLOW;
            getline(cin, inputName);
            auth = users.confirmation_of_user_in_user_list(inputName);
            if (auth != nullptr)
            {
                cout << MAGENTA << "Enter your Password to login: " << YELLOW;
                cout << YELLOW;
                cout << YELLOW;
                getline(cin, inputPassword);
                if (auth->confirmation_of_User(inputPassword))
                {
                    system("cls");
                    cout << RED << "Authentication successful. Welcome, " << CYAN << auth->getmy_name() << "!\n\n\n\n";
                    load(4);
                    system("cls");
                    bool k = true;
                    while (k)
                    {
                        int student_choice;
                        do
                        {

                            cout << RED << student_portal << CYAN << endl;
                            cout << CYAN << "1. Enrollment application portal for students." << endl;
                            cout << "2. View my Grades." << endl;
                            cout << "3. Submission of files ." << endl;
                            cout << "4. Manage files of my class." << endl;
                            cout << "5. Return to Previous Menu." << endl;
                            cout << RED << "Your Choice: " << YELLOW;
                            cout << YELLOW;
                            cout << YELLOW;
                            cin >> student_choice;

                            system("cls");

                        } while (student_choice != 1 && student_choice != 2 && student_choice != 3 && student_choice != 4 && student_choice != 5);
                        cout << RED << student_portal << endl;

                        if (student_choice == 1)
                        {
                            cout << GREEN;
                            classes.student_enrollment_in_list_of_classes(*auth);
                        }
                        else if (student_choice == 2)
                        {
                            cout << YELLOW;
                            classes.student_grades_in_list_of_classes(*auth);
                        }
                        else if (student_choice == 3)
                        {
                            cout << BLUE;
                            classes.assignment_view_in_list_of_classes(*auth);
                            is_to_dealy();
                        }
                        else if (student_choice == 4)
                        {
                            cout << CYAN;
                            classes.view_class_files_in_list_of_classes(*auth);
                            is_to_dealy();
                        }
                        else
                        {
                            k = false;
                        }
                    }
                }
                else
                {
                    cout << "Authentication failed. Please try again.\n";
                }
            }
            else
            {
                cout << "Authentication failed. Please try again.\n";
            }
        }
        else if (choice == 3)
        { /*If the user selects option 3 (Teacher Portal), they are prompted to enter
          their username and password for authentication. If successful and if the user
           has teaching ability, the teacher is redirected to a teacher-specific menu with
            options such as Create & Announce a New Class, Display All Announced Class Details,
             Modification in Announced Class,
         Manage Assignments, Grade Management, File Management, and Notification Management*/
            cout << RED << teacher_portal << CYAN << endl;
            cout << MAGENTA << "Enter your Username to access your data: " << YELLOW;
            cout << YELLOW;
            cin.ignore();
            cout << YELLOW;
            getline(cin, inputName);
            auth = users.confirmation_of_user_in_user_list(inputName);
            if (auth != nullptr)
            {
                cout << MAGENTA << "Enter your Password to login: " << YELLOW;
                cout << YELLOW;
                cout << YELLOW;
                getline(cin, inputPassword);
                system("cls");
                if (auth->confirmation_of_User(inputPassword) && auth->getTeaching_ability())
                {
                    cout << "Authentication successful. Welcome, " << auth->getmy_name() << "!\n";

                    bool b = true;
                    while (b)
                    {
                        int teacher_choice = 0;
                        do
                        {
                            cout << RED << teacher_portal << CYAN << endl;
                            cout << "CHOOSE FROM FOLLOWING CLASS MANAGING OPTIONS." << endl;
                            cout << "1. Create & Announce a new class" << endl;
                            cout << "2. Display all announced class details" << endl;
                            cout << "3. Modification in already announced class" << endl;
                            cout << "4. Manage Assignments in the specific class." << endl;
                            cout << "5. Grades Management and Access." << endl;
                            cout << "6. File Management portal for the class. " << endl;
                            cout << "7. Send Notification in particlar class. " << endl;
                            cout << "8. Return to Previous Menu" << endl;
                            cout << "Your Choice : ";
                            cout << YELLOW;
                            cin >>
                                teacher_choice;
                            system("cls");
                        } while (teacher_choice != 1 && teacher_choice != 2 && teacher_choice != 3 && teacher_choice != 4 && teacher_choice != 5 && teacher_choice != 6 && teacher_choice != 7 && teacher_choice != 8);
                        std::string inputNameforassignment;
                        cout << RED << teacher_portal << CYAN << endl;
                        if (teacher_choice == 1)
                        {
                            classes.add_Class_in_list_of_classes(users);
                        }
                        else if (teacher_choice == 2)
                        {
                            classes.print_in_list_of_classes();
                            cin.ignore();
                            is_to_dealy();
                        }
                        else if (teacher_choice == 3)
                        {
                            classes.modify_class_in_list_of_classes();
                        }
                        else if (teacher_choice == 4)
                        {
                            cout << "MANAGE ASSIGNMENTS:" << endl
                                 << endl;
                            cout << "Provide the name of class whose assignment you want to access." << endl;
                            cout << "Your Choice : ";
                            cin.ignore();
                            cout << YELLOW;
                            cout << YELLOW;
                            getline(cin, inputNameforassignment);
                            system("cls");
                            classes.confirmation_of_user_in_list_of_classes(inputNameforassignment)->manage_assignment_in_class();
                        }
                        else if (teacher_choice == 5)
                        {
                            cout << "Grade Portal:" << endl
                                 << endl;
                            cout << "Provide the name of class whose grades you want to access." << endl;
                            cout << "Your Choice : ";
                            cin.ignore();
                            cout << YELLOW;
                            cout << YELLOW;
                            getline(cin, inputNameforassignment);
                            system("cls");
                            classes.confirmation_of_user_in_list_of_classes(inputNameforassignment)->manage_grades_in_class();
                        }
                        else if (teacher_choice == 6)
                        {
                            cout << "MANAGE File:" << endl
                                 << endl;
                            cout << "Provide the name of class whose assignment you want to access." << endl;
                            cout << "Your Choice : ";
                            cin.ignore();
                            cout << YELLOW;
                            cout << YELLOW;
                            getline(cin, inputNameforassignment);
                            system("cls");
                            classes.confirmation_of_user_in_list_of_classes(inputNameforassignment)->manage_File_in_class();
                        }
                        else if (teacher_choice == 7)
                        {
                            cout << "MANAGE Notification:" << endl
                                 << endl;
                            cout << "Provide the name of class whose notification you want to access." << endl;
                            cout << "Your Choice : ";
                            cin.ignore();
                            cout << YELLOW;
                            cout << YELLOW;
                            getline(cin, inputNameforassignment);
                            system("cls");
                            classes.confirmation_of_user_in_list_of_classes(inputNameforassignment)->manage_Notifications_in_class();
                        }
                        else
                        {
                            b = false;
                        }
                    }
                }
                else
                {
                    cout << "Authentication failed. Please try again.\n";
                }
            }
            else
            {
                cout << "Authentication failed. Please try again.\n";
            }
        }
        else if (choice==4){
            users.print_in_user_list();
            cout<<YELLOW<<"Press Enter to continue";
           
            cin.ignore(); cin.ignore();
            system("cls");

        }
        else if (choice == 5)
        { /*If the user selects option 4, the program exits, ending the main loop.*/
            exit(0);
        }
        system("cls");
    }
}
