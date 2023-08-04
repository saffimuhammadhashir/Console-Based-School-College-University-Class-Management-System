#pragma once

#include <iostream>

#include "Class.h"

using namespace std;
using std::cin;
using std::cout;
using std::getline;
/*                  Explaination                */

/*Title: Class and Assignment Management System - Code Explanation

Introduction:
In this document, we will explain the C++ code for a Class and Assignment Management System. The code provides functionalities to manage classes,
 students, and assignments, designed for teachers and students. The system allows teachers to create classes, add students, and assign assignments to
  students. Students can view assigned assignments and submit their work.

Explanation:
1. Header Files and Namespace:
The code starts by including necessary header files such as <iostream> and "Class.h". The "Class.h" file presumably contains the declaration of
 the "LinkUsers" class and other required classes. The code also uses the "std" namespace and specific items from it, such as "cin" and "cout".

2. Constructors:
There are two constructors for the "Class" class. The first constructor, "Class::Class(LinkUsers &other)", is used to create a new class object.
 It prompts the user to enter class details like class name, subject, teacher's name, description, and the number of students to add to the class.
  It then allows the user to input the student IDs and adds those students to the class.

The second constructor, "Class::Class(const string &class_Name_in_class, const string &subject_in_class, const string &teacher_in_class,
 const string &description_in_class)", is an alternative constructor that initializes a "Class" object using the provided class name, subject,
  teacher's name, and description. It does not add any students to the class.

3. Getter Methods:
Several getter methods are provided to retrieve class details, such as the class name, subject, teacher, and description.

4. Student Management:
The code includes methods to add and remove students from the class roster. The "remove_Student_in_class()" method removes a student from the
 class roster based on their student ID.

5. Class Details Management:
The code includes a method called "update_Class_Details_in_class()" to update class details such as class name, subject, teacher's name, and description.

6. Display Class Details:
The "display_Class_Details_in_class()" method displays the details of the current class object, including class name, subject, teacher's name, description,
 and the list of enrolled students.

7. Assignment Management:
The code includes methods to manage assignments for both teachers and students. For teachers, the "manage_assignment_in_class()" method allows them to perform
 various actions related to assignments, such as creating new assignments, displaying all assigned assignments in the class, searching for specific assignments, and returning to the previous menu.

8. Assignment Submission:
For students, the "manage_assignment_student_in_class()" method allows them to view all assigned assignments, search for specific assignments, and submit
 their work. The "submit_assignment_in_class()" method is used for students to upload their work for a particular assignment.

*/

/*Constructor: There are two constructors provided, one to create a new class object and another to initialize a class object with specific details.*/
/*Class::Class(LinkUsers &other): This is a constructor for the "Class"
 class that  takes a reference to a "LinkUsers" object as a parameter. It is used to
 create a new class object. When a new class is created, the user is prompted to enter
class details such as the class name, subject, teacher's name, description, and the number
 of students to add to the class. It then allows the user to input the student
 IDs and adds those students to the class. The class details are saved to a file.
*/
Class::Class(LinkUsers &other)
{

    system("cls");

    cout << RED << teacher_portal << CYAN << endl;
    cout << "********** Create Class **********\n";
    cin.ignore();
    cout << "Enter class name: ";
    cout << YELLOW;
    getline(std::cin, class_Name_in_class);
    cout << "Enter subject: ";
    cout << YELLOW;
    getline(cin, subject_in_class);
    cout << "Enter teacher's name: ";
    cout << YELLOW;
    getline(cin, teacher_in_class);
    cout << "Enter class description: ";
    cout << YELLOW;
    getline(cin, description_in_class);

    int numStudents;
    cout << "Enter the number of students to add to the class: ";
    cout << YELLOW;
    cin >> numStudents;
    cout << "Enter the student IDs:\n";
    cin.ignore(); // Ignore the newline character from previous input
    for (int i = 0; i < numStudents; ++i)
    {
        string studentID;
        cout << YELLOW;
        getline(cin, studentID);
        add_Student_in_class(studentID, other);
    }
    system("cls");
    Link = nullptr;
    num_Enrolled_Students_in_class++;
    save_Data_To_File_in_class(*this); // Save class details to file
}
/*Class::Class(const string &class_Name_in_class, const string &subject_in_class,
const string &teacher_in_class, const string &description_in_class): This is an
 alternative constructor that  creates a "Class" object using the provided class
 name, subject, teacher's name, and description. It does not add any students to the
  class.*/
Class::Class(const string &class_Name_in_class,
             const string &subject_in_class,
             const string &teacher_in_class,
             const string &description_in_class) : class_Name_in_class(class_Name_in_class),
                                                   subject_in_class(subject_in_class),
                                                   teacher_in_class(teacher_in_class),
                                                   description_in_class(description_in_class),
                                                   num_Enrolled_Students_in_class(0)
{
    Link = nullptr;
}
/*Getter Methods: Various getter methods are provided to retrieve
 the class details such as name, subject, teacher, and description.*/
// Getter methods
/*string Class::getClass_Name_in_class(): Getter method that
 returns the class name of the current class object.*/
string Class::getClass_Name_in_class()
{
    return class_Name_in_class;
}
/*string Class::getsubject_in_class() const: Getter method that
returns the subject of the current class object.*/
string Class::getsubject_in_class() const
{
    return subject_in_class;
}
/*string Class::getTeacher_in_class() const: Getter method that   returns the teacher's
 name of the current class object.*/
string Class::getTeacher_in_class() const
{
    return teacher_in_class;
}
/*string Class::getDescription_in_class() const: Getter method that   returns the
 description of the current class object.*/
string Class::getDescription_in_class() const
{
    return description_in_class;
}

// Method to add a student to the class roster
void Class::add_Student_in_class(const string & studentID, LinkUsers & otherlinkusers) {
    User * current = otherlinkusers.start_Users_in_User_list;
    while (current != nullptr) {
        if (current -> gethidden_Id() == studentID) {
            if (num_Enrolled_Students_in_class < maximum_number_of_students_in_class_for_grading) {
                enrolled_Students_in_class[num_Enrolled_Students_in_class] = studentID;
                num_Enrolled_Students_in_class++;

                current -> save_in_file();

            } else {
                std::cout << "Class roster is full. Cannot add more students.\n";
            }
        }
        current = current -> Link;
    }
}
// Method to remove a student from the class roster
/*void Class::remove_Student_in_class(const string &studentID): Method to remove a
student from the class roster. It takes a student ID as a parameter and removes the
student from the list of enrolled students in the class.*/
void Class::remove_Student_in_class(const string &studentID)
{
    int foundIndex = -1;
    for (int i = 0; i < num_Enrolled_Students_in_class; ++i)
    {
        if (enrolled_Students_in_class[i] == studentID)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
    {
        // Shift elements to the left to remove the student
        for (int j = foundIndex; j < num_Enrolled_Students_in_class - 1; ++j)
        {
            enrolled_Students_in_class[j] = enrolled_Students_in_class[j + 1];
        }
        num_Enrolled_Students_in_class--;
    }
    else
    {
        cout << "Student not found in the class roster.\n";
    }
}

// Method to update class details
/*void Class::update_Class_Details_in_class(const string &newClass_Name_in_class,
const string &newsubject_in_class, const string &newTeacher_in_class, const string
&newDescription_in_class): Method to update the class details such as class name,
subject, teacher's name, and description. It takes these new values as parameters
and updates the corresponding class attributes.*/
void Class::update_Class_Details_in_class(const string &newClass_Name_in_class,
                                          const string &newsubject_in_class,
                                          const string &newTeacher_in_class,
                                          const string &newDescription_in_class)
{
    class_Name_in_class = newClass_Name_in_class;
    subject_in_class = newsubject_in_class;
    teacher_in_class = newTeacher_in_class;
    description_in_class = newDescription_in_class;
}

// Method to display class details
/*void Class::display_Class_Details_in_class() const: Method to display the details of the
current class object, including class name, subject, teacher's name, description, and the
 list of enrolled students.*/
void Class::display_Class_Details_in_class() const
{

    cout << RED << "********** Class Details **********\n"
         << YELLOW;
    cout << "Class Name: " << class_Name_in_class << "\n";
    cout << "Subject: " << subject_in_class << "\n";
    cout << "Teacher: " << teacher_in_class << "\n";
    cout << "Description: " << description_in_class << "\n";

    cout << "********** Enrolled Students **********\n";
    if (num_Enrolled_Students_in_class == 0)
    {
        cout << RED << "No students enrolled in this class.\n"
             << RESET;
    }
    else
    {
        for (int i = 0; i < num_Enrolled_Students_in_class; ++i)
        {
            cout << "Student " << (i + 1) << ": " << enrolled_Students_in_class[i] << "\n";
        }
    }
}
/*Managing Assignments: The manage_assignment_in_class() function provides options for
adding new assignments, displaying all assigned assignments, searching for a specific
 assignment, and retrieving to the previous menu.*/
/*void Class::manage_assignment_in_class(): Method to manage assignments in the class.
 It allows the teacher to perform various actions related to assignments, such as creating
  new assignments, displaying all assigned assignments in the class, searching for specific
   assignments, and retrieving to the previous menu.*/
void Class::manage_assignment_in_class()
{
    bool e = true;
    read_Assignments_From_File_in_class(*this);
    while (e)
    {
        int management_choice = 0;
        do
        {
            system("cls");
            cout << RED << teacher_portal << CYAN << endl;
            cout << "CHOOSE FROM THE FOLLOWING IN ASSIGNMENTS MANAGEMENT PORTAL." << endl;
            cout << "1. Assign new Assignments to student." << endl;
            cout << "2. Display All Assigned Assignments in the class." << endl;
            cout << "3. Search for specifc Announced Assignment." << endl;
            cout << "4. Retrieve to Previous menu" << endl;
            cout << "YOUR CHOICE:  ";
            cout << YELLOW;
            cin >> management_choice;
            /* code */
            system("cls");
            cout << RED << teacher_portal << CYAN << endl;
        } while (management_choice != 1 && management_choice != 2 && management_choice != 3 && management_choice != 4);
        if (management_choice == 1)
        {
            add_assignment_in_class();
            /* code for Class::assignments_in_class */
        }
        else if (management_choice == 2)
        {
            all_assignments_in_class();
            /* code */
            cin.ignore();
            is_to_delay();
        }
        else if (management_choice == 3)
        {
            search_assignment_in_class();
            /* code */
            cin.ignore();
            is_to_delay();
        }
        else
        {
            e = false;
        }
    }
}
/*void Class::add_assignment_in_class(): Method to add a new assignment to the class.
It prompts the teacher to enter assignment details such as title, description, deadline,
 attached files, and point value.*/
void Class::add_assignment_in_class()
{
    assignments_in_class.adding_Assignment_in_assignment_list();
}
/*void Class::all_assignments_in_class(): Method to display all assigned assignments in
 the class.*/
void Class::all_assignments_in_class()
{
    assignments_in_class.print_in_assignment_list();
}
/*Managing Student Assignments: The manage_assignment_student_in_class() function provides
 options for students to view assigned assignments and submit their work.*/
/*void Class::manage_assignment_student_in_class(User &obj): Method to manage assignments
for students in the class. It allows students to view all assigned assignments, search for
 specific assignments, and submit their work.*/
void Class::manage_assignment_student_in_class(User &obj)
{
    bool e = true;
    read_Assignments_From_File_in_class(*this);
    while (e)
    {
        int management_choice = 0;
        do
        {
            system("cls");
            cout << RED << student_portal << CYAN << endl;
            cout << "CHOOSE FROM THE FOLLOWING OPTIONS TO MANAGE ASSIGNMENTS." << endl;

            cout << "1. Display All Assigned Assignments in class." << endl;
            cout << "2. Look for specifc Assignment, and upload your work!. " << endl;
            cout << "3. Retrieve to Previous menu" << endl;
            cout << "YOUR CHOICE:  ";
            cout << YELLOW;
            cin >> management_choice;
            /* code */
            system("cls");
            cout << RED << student_portal << CYAN << endl;
        } while (management_choice != 1 && management_choice != 2 && management_choice != 3);

        if (management_choice == 1)
        {
            all_assignments_in_class();
            /* code */
            cout << "No more Files Found!" << endl;
            cin.ignore();
            is_to_delay();
        }
        else if (management_choice == 2)
        {
            if (search_assignment_students_in_class())
            {
                /* code */
                submit_assignment_in_class(obj.gethidden_Id());
            }
            else
            {
                cout << "No such Files Found!" << endl;
            }
            cin.ignore();
            is_to_delay();
        }
        else
        {
            e = false;
        }
    }
}

/*              Explaination            */
/*The provided code contains several methods that manage various aspects of a Class and Assignment Management System.
 Below is an explanation of each method:

1. `submit_assignment_in_class(string Id)`: This method is used by students to submit their assignments.
 It takes the student's ID as a parameter and saves the submission to a file. The `Submission` class is utilized

 to manage and save the submissions.

2. `search_assignment_in_class()`: This method is used by teachers to search for a specific announced
assignment in the class. It prompts the teacher to enter the assignment title and then allows the teacher to update or delete
 the assignment details. The teacher can choose to update the assignment's title, description, deadline, attached files, and
  point value. If the teacher chooses to delete the assignment, it is removed from the class's assignment list.

3. `search_assignment_students_in_class()`: This method is used by students to search for a specific
 assignment. It prompts the student to enter the assignment title and then displays the assignment details if found. It returns
  `true` if the assignment is found and `false` otherwise.

4. `manage_grades_in_class()`: This method allows the teacher to manage grades in the class. It provides
 options for the teacher to grant grades to students, display the class average, generate grade reports for individual students,
  and generate the grade report for the whole class. The teacher can enter the grade weightage for assignments, update student
  grades, and view various grade reports.



5. `manage_File_Student_in_class()`: This method is used by students to manage files related to the
 class. It allows students to view the files uploaded by the teacher. The `file_in_class` object manages the files and their
  operations.

6. `manage_File_in_class()`: This method is used by the teacher to manage files related to the class.
 It allows the teacher to upload, display, download, and delete files. The teacher can choose from various options to perform
  file-related operations.

Overall, the code demonstrates a class and assignment management system with functionalities for teachers
 and students to manage classes, assignments, grades, and files efficiently. The methods are well-organized and encapsulated within
  the Class class, promoting modularity and reusability of code. However, without the complete context of the entire project and the
   implementation of other classes and functions, it's challenging to assess the overall efficiency and correctness of the system.

*/

/*void Class::submit_assignment_in_class(string Id): Method for students to submit their
 assignments. It takes the student's ID as a parameter and saves the submission to a
  file.*/
void Class::submit_assignment_in_class(string Id)
{
    Submission newSubmission(getClass_Name_in_class());
    string place = getClass_Name_in_class();
    newSubmission.save_submissions_to_new_file_and_replace(Id, place);
    cout << "Submission saved Successfully" << endl;
    is_to_delay();
}
/*void Class::search_assignment_in_class(): Method for teachers to search for a specific
 announced assignment in the class. It prompts the teacher to enter the assignment title
  and then allows the teacher to update or delete the assignment.*/
void Class::search_assignment_in_class()
{
    string Input_Title_in_class;
    cin.ignore();
    cout << "Enter the Title of the Assignment : ";
    cout << YELLOW;
    getline(cin, Input_Title_in_class);
    Assignment *auth = assignments_in_class.confirmation_of_user_in_assignment_list(Input_Title_in_class);
    bool d = true;
    string place;
    if (auth != nullptr)
        while (d)
        {
            int assignment_choice;
            do
            {
                system("cls");
                cout << RED << teacher_portal << CYAN << endl;
                cout << "CHOOSE WHAT DO YOU WANT TO DO WITH THE SEARCHED ASSIGNMENT." << endl;
                cout << "1. Update Already Announced Assignment Details." << endl;
                cout << "2. Delete any Already Announced Assignment." << endl;
                cout << "3. Retrieve to Previous menu" << endl;
                cout << "YOUR CHOICE:  ";
                cout << YELLOW;
                cin >> assignment_choice;
                /* code */
                system("cls");
            } while (assignment_choice != 1 && assignment_choice != 2 && assignment_choice != 3);
            string title, assignmentDescription_in_class, deadline, attachedFiles;
            int pointValue;
            if (assignment_choice == 1)
            {
                cout << RED << teacher_portal << CYAN << endl;
                cout << "********** Update Assignment **********\n";
                cin.ignore();
                cout << "Enter assignment title: ";
                cout << YELLOW;
                getline(cin, title);
                cout << "Enter assignment description_in_class: ";
                cout << YELLOW;
                getline(cin, assignmentDescription_in_class);
                cout << "Enter assignment deadline: ";
                cout << YELLOW;
                getline(cin, deadline);
                cout << "Enter attached files: ";
                cout << YELLOW;
                getline(cin, attachedFiles);
                cout << "Enter assignment point value: ";
                cout << YELLOW;
                cin >> pointValue;
                auth->update_Assignment_Details__in_Assignment(title, assignmentDescription_in_class, deadline, attachedFiles, pointValue);
                system("cls");
            }
            else if (assignment_choice == 2)
            {
                place = auth->getTitle_in_Assignment();
                assignments_in_class.deleteAssignment_in_assignment_list(place);
                cin.ignore();
                is_to_delay();
            }
            else
            {
                d = false;
            }
        }
    else
        cout << "No Such Assignment found!" << endl
             << endl;
}
/*bool Class::search_assignment_students_in_class(): Method for students to search for a
 specific assignment. It prompts the student to enter the assignment title and then
  displays the assignment details if found.*/
bool Class::search_assignment_students_in_class()
{
    string Input_Title_in_class;
    cin.ignore();
    system("cls");
    cout << RED << student_portal << CYAN << endl;
    cout << "Enter the Title of the Assignment : ";
    cout << YELLOW;
    getline(cin, Input_Title_in_class);
    Assignment *auth = assignments_in_class.confirmation_of_user_in_assignment_list(Input_Title_in_class);
    bool d = true;
    if (auth != nullptr)
    {
        auth->display_Assignment_Details_in_Assignment();
        return true;
    }
    else
        cout << "No Such Assignment found!" << endl
             << endl;
    return false;
    cin.ignore();
    is_to_delay();
}
/*Managing Grades: The manage_grades_in_class() function allows the teacher to grant
 grades to students, display class average, generate grade reports for individual
  students, and the whole class.*/
/*void Class::manage_grades_in_class(): Method to manage grades in the class.
 It allows the teacher to grant grades to students, display the class average, display
  grade reports for individual students, and display the grade report for the whole
  class.*/
void Class::manage_grades_in_class()
{

    bool f = true;
    while (f)
    {
        int grades_choice = 0;
        do
        {
            system("cls");
            cout << RED << teacher_portal << CYAN << endl;

            cout << "CHOOSE FROM THE FOLLOWING OPTIONS IN GRADES MANAGEMENT PORTAL." << endl;
            cout << "1. Grant grades to students." << endl;
            cout << "2. Display class average.." << endl;
            cout << "3. Display Grade Report for one student in class." << endl;
            cout << "4. Display Grade Report for whole class." << endl;
            cout << "5. Retrieve to Previous menu" << endl;
            cout << "YOUR CHOICE:  ";
            cout << YELLOW;
            cin >> grades_choice;
            /* code */
            system("cls");
            cout << RED << teacher_portal << CYAN << endl;
        } while (grades_choice != 1 && grades_choice != 2 && grades_choice != 3 && grades_choice != 4 && grades_choice != 5);
        int grade;
        string Id;
        if (grades_choice == 1)
        {
            system("cls");
            cout << RED << teacher_portal << CYAN << endl;
            cout << "********** GradeBook **********\n";
            cout << "Enter the grade weightage (out of 100): ";
            cout << YELLOW;
            cin >> grades_in_class.grade_Weightage__in_GradeBook;
            cin.ignore();

            for (int i = 0; i < num_Enrolled_Students_in_class - 1; i++)
            {
                cout << "Enter student Id: ";
                cout << YELLOW;
                getline(cin, Id);
                string place = getClass_Name_in_class();
                Submission::get_submissions_from_already_created_files(Id, place);

                cout << "Enter student grades: ";
                cout << YELLOW;
                cin >> grade;
                grades_in_class.update_Student_Grade_in_GradeBook(Id, grade);
            }

            is_to_delay();
        }
        else if (grades_choice == 2)
        {
            system("cls");
            cout << RED << teacher_portal << CYAN << endl;
            grades_in_class.update_Class_Average_in_GradeBook();
            cout << endl
                 << "Class Average is : " << grades_in_class.get_Average_in_GradeBook() << endl
                 << endl;
            cin.ignore();
            is_to_delay();
        }
        else if (grades_choice == 3)
        {
            system("cls");
            cout << RED << teacher_portal << CYAN << endl;
            cin.ignore();
            cout << "Enter student Id: ";
            cout << YELLOW;
            getline(cin, Id);
            grades_in_class.generate_Grade_Report_in_GradeBook(Id);
            is_to_delay();
        }
        else if (grades_choice == 4)
        {
            grades_in_class.generate_Class_Grade_Report_in_GradeBook();
            cin.ignore();
            is_to_delay();
        }
        else
        {
            f = false;
        }

        save_Grades_To_File_in_class(*this);
    }
}
/*void Class::manage_File_Student_in_class(): Method for students to manage files related
to the class. It allows students to view the files uploaded by the teacher.*/
void Class::manage_File_Student_in_class()
{
    bool g = true;
    while (g)
    {
        int File_choice = 0;
        do
        {
            system("cls");
            cout << RED << student_portal << CYAN << endl;
            cout << "CHOOSE FROM THE FOLLOWING OPTIONS TO MANAGE FILES." << endl;
            cout << "1. Show Files." << endl;
            cout << "2. Retrieve to Previous menu" << endl;
            cout << "YOUR CHOICE:  ";
            cout << YELLOW;
            cin >> File_choice;
            system("cls");
        } while (File_choice != 1 && File_choice != 2);
        string place;
        if (File_choice == 1)
        {
            place = this->getClass_Name_in_class();
            file_in_class.print_in_file_list(place); // Display all the files for the class.

            cout << "No more files found!" << endl;
            is_to_delay();
        }
        else
        {
            g = false;
        }
    }
}
/*void Class::manage_File_in_class(): Method for the teacher to manage files related to
 the class. It allows the teacher to upload, display, download, and delete files.*/
void Class::manage_File_in_class()
{

    bool g = true;
    while (g)
    {
        int File_choice = 0;
        do
        {
            system("cls");
            cout << RED << teacher_portal << CYAN << endl;

            cout << "CHOOSE FROM THE FOLLOWING OPTIONS TO MANAGE FILES." << endl;
            cout << "1. To Upload File in Record." << endl;
            cout << "2. To Display File form the Record." << endl;
            cout << "3. To Download File from Record." << endl;
            cout << "4. To Display all Files in Record." << endl;
            cout << "5. To Delete File from Record." << endl;
            cout << "6. Retrieve to Previous menu" << endl;
            cout << "YOUR CHOICE:  ";
            cout << YELLOW;
            cin >> File_choice;
            system("cls");
            cout << RED << teacher_portal << CYAN << endl;
            /* code */
        } while (File_choice != 1 && File_choice != 2 && File_choice != 3 && File_choice != 4 && File_choice != 5 && File_choice != 6);
        string place;
        if (File_choice == 1)
        {
            file_in_class.adding_File_in_file_list(this->getClass_Name_in_class());
            // file.display_file();
            is_to_delay();
        }
        else if (File_choice == 2)
        {
            file_in_class.display_file__in_file_list();
            is_to_delay();
        }
        else if (File_choice == 3)
        {
            file_in_class.download_file__in_file_list();
            is_to_delay();
        }
        else if (File_choice == 4)
        {
            place = this->getClass_Name_in_class();
            file_in_class.print_in_file_list(place);
            is_to_delay();
        }
        else if (File_choice == 5)
        {
            file_in_class.delete_file__in_file_list();
            is_to_delay();
        }
        else
        {
            g = false;
        }
    }
}

/*          EXPLAINATION            */
/*The provided code includes additional methods related to managing notifications, saving and reading class data
 and grades to/from files, and managing enrolled students. Here's an explanation of these new methods:

1. `manage_Notifications_in_class()`: This method allows the teacher to manage notifications in the class. The
 teacher can send notifications to all class members, view specific notifications previously sent to all class
  members, and display all notifications sent in the class. The `notification_in_class` object is used to manage the notifications.

2. `save_Grades_To_File_in_class(Class &classObj)`: This method saves the class details and grades to a file.
 It takes a reference to a "Class" object as a parameter and writes the class details and grades to a file.
  The grades are written in the format of "<studentID> <grade>". The file is named "<Class_Name>_grades.txt".

3. `read_Grades_From_File_in_class(Class &classObj)`: This method reads grades for the class from a file and
updates the grades in the "classObj" based on the data read from the file. The method assumes each line in the file
 contains the format "<studentID> <grade>". The file is named "<Class_Name>_grades.txt".

4. `save_Data_To_File_in_class(Class &classObj)`: This method saves the class details and grades to a file. It
 takes a reference to a "Class" object as a parameter and writes the class details and grades to a file. The method
  appends the data to an existing file named "class1.txt".

5. `read_Assignments_From_File_in_class(Class &obj)`: This method reads assignments for the class from a file
 and populates the "assignments_in_class" container with assignments based on the data read from the file. The
  method assumes each assignment's details are separated by a line containing "--------------------------". The file is named "<Class_Name> assignment.txt".

6. `save_Enrolled_in_class_Students_To_File_in_class()`: This method saves the list of enrolled students in the
 class to a file. The file is named "<Class_Name>_enrolled_students.txt".

7. `read_Enrolled_Students_From_File_in_class()`: This method reads the list of enrolled students in the class from
 a file and saves them in the "enrolled_Students_in_class" array. The file is named "<Class_Name>_enrolled_students.txt".

8. `display_Student_Grades_in_class(string &studentID)`: This method displays all subjects and grades of a specific
 student based on their unique ID. It iterates through the enrolled students and retrieves the student's grades from the
  "grades_in_class" container.

These methods enhance the functionality of the class management system, allowing the teacher to manage notifications,
 save and read class data and grades from files, and view students' grades. However, the implementation of some functions is
  incomplete, and further details regarding the other classes and their interactions
 are necessary to fully understand the overall functionality and correctness of the system.*/

/*void Class::manage_Notifications_in_class(): Method to manage notifications in the
 class. It allows the teacher to send notifications to all class members and view
  previously sent notifications.*/
void Class::manage_Notifications_in_class()
{

    bool h = true;
    while (h)
    {
        int Notification_choice = 0;
        do
        {
            system("cls");
            cout << RED << teacher_portal << CYAN << endl;

            cout << "CHOOSE FROM THE FOLLOWING OPTIONS TO MANAGE NOTIFICATIONS" << endl;
            cout << "1. Send Notification to all Class Members" << endl;
            cout << "2. Display specific Notification sent to all Class Members." << endl;
            cout << "3. Display all Notifications sent in Class." << endl;
            cout << "4. Retrieve to Previous menu" << endl;
            cout << "YOUR CHOICE:  ";
            cout << YELLOW;
            cin >> Notification_choice;
            system("cls");
            /* code */
            cout << RED << teacher_portal << CYAN << endl;
        } while (Notification_choice != 1 && Notification_choice != 2 && Notification_choice != 3 && Notification_choice != 4);
        if (Notification_choice == 1)
        {
            notification_count_in_class++;
            notification_in_class.adding_Notification_in_Notification_list(class_Name_in_class, notification_count_in_class);
        }
        else if (Notification_choice == 2)
        {
            notification_in_class.display_Notification_in_Notification_list();
            is_to_delay();
        }
        else if (Notification_choice == 3)
        {
            notification_in_class.print_in_Notification_list();
            is_to_delay();
        }
        else
        {
            h = false;
        }
    }
}
/*void Class::save_Grades_To_File_in_class(Class &classObj): Method to save grades for
the class to a file. It takes a reference to a "Class" object as a parameter and writes
 the class details and grades to a file.*/
void Class::save_Grades_To_File_in_class(Class &classObj)
{
    ofstream file(classObj.getClass_Name_in_class() + "_grades.txt");
    if (file.is_open())
    {
        file << "Class Name: " << classObj.getClass_Name_in_class() << "\n";
        file << "subject: " << classObj.getsubject_in_class() << "\n";
        file << "Teacher: " << classObj.getTeacher_in_class() << "\n";
        file << "Description: " << classObj.getDescription_in_class() << "\n";
        file << "Grades:\n";

        // Iterate over studentGrades array
        for (int i = 0; i < classObj.num_Enrolled_Students_in_class; ++i)
        {
            string studentID = classObj.enrolled_Students_in_class[i + 1];
            int grade = classObj.grades_in_class.get_Student_Grade_in_GradeBook(i);
            file << studentID << " " << grade << "\n";
        }

        file.close();
        cout << "Grades saved to file successfully.\n";
    }
    else
    {
        cout << "Error saving grades to file.\n";
    }
}

// Function to read grades from a file and update the GradeBook
/*void Class::read_Grades_From_File_in_class(Class &classObj): Method to read grades for
 the class from a file. It takes a reference to a "Class" object as a parameter and updates
  the grades in the object based on the data read from the file.*/
void Class::read_Grades_From_File_in_class(Class &classObj)
{
    ifstream file(classObj.getClass_Name_in_class() + "_grades.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            // Assuming each line has the format: "<studentID> <grade>"
            istringstream iss(line);
            string studentID;
            int grade;
            if (iss >> studentID >> grade)
            {

                classObj.grades_in_class.update_Student_Grade_in_GradeBook(studentID, grade);
            }
        }

        file.close();
        cout << GREEN << "Grades read from file and updated successfully.\n";
    }
    else
    {
        cout << "Error reading grades from file.\n";
    }
}
/*void Class::save_Data_To_File_in_class(Class &classObj): Method to save class details
and grades to a file. It takes a reference to a "Class" object as a parameter and writes
 the class details and grades to a file.*/
void Class::save_Data_To_File_in_class(Class &classObj)
{
    ofstream file("class1.txt", ios::app); // Open in append mode
    if (file.is_open())
    {
        file << "Class Name: " << classObj.getClass_Name_in_class() << "\n";
        file << "Subject: " << classObj.getsubject_in_class() << "\n";
        file << "Teacher: " << classObj.getTeacher_in_class() << "\n";
        file << "Description: " << classObj.getDescription_in_class() << "\n";

        // Save enrolled students to the file
        file << "Grades:\n";
        for (int i = 0; i < classObj.num_Enrolled_Students_in_class; ++i)
        {
            file << classObj.enrolled_Students_in_class[i] << " " << classObj.grades_in_class.get_Student_Grade_in_GradeBook(i) << "\n";
        }

        file << "\n"; // Add a separator between class and grades data

        file.close();
        cout << "Class details and grades saved to file successfully.\n";
    }
    else
    {
        cout << "Error saving class details and grades to file.\n";
    }
}
/*void Class::read_Assignments_From_File_in_class(Class &obj): Method to read assignments
 for the class from a file. It takes a reference to a "Class" object as a parameter and
 populates the "assignments_in_class" container with assignments based on the data read
 from the file.*/
void Class::read_Assignments_From_File_in_class(Class &obj)
{
    string filename = obj.getClass_Name_in_class() + " assignment.txt";
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        string subject_in_class, title, description_in_class, deadline, attachedFiles;
        int pointValue;

        while (getline(file, line))
        {
            if (line.find("Subject: ") == 0)
            {
                subject_in_class = line.substr(9);
            }
            else if (line.find("Title: ") == 0)
            {
                title = line.substr(7);
            }
            else if (line.find("Description: ") == 0)
            {
                description_in_class = line.substr(13);
            }
            else if (line.find("Deadline: ") == 0)
            {
                deadline = line.substr(10);
            }
            else if (line.find("Attached Files: ") == 0)
            {
                attachedFiles = line.substr(16);
            }
            else if (line.find("Point Value: ") == 0)
            {
                pointValue = stoi(line.substr(13));
            }
            else if (line.find("--------------------------") == 0)
            {
                // Create a new Assignment object and add it to the assignments container
                Assignment *created = new Assignment(subject_in_class, title, description_in_class, deadline, attachedFiles, pointValue);
                obj.assignments_in_class.adding_Assignment_in_assignment_list(created);
            }
        }

        file.close();
        cout << "Assignments read from file successfully.\n";
    }
    else
    {
        cout << "Error reading assignments from file.\n";
    }
}
/*void Class::save_Enrolled_in_class_Students_To_File_in_class(): Method to save the list
 of enrolled students in the class to a file.*/
void Class::save_Enrolled_in_class_Students_To_File_in_class()
{
    ofstream file(class_Name_in_class + "_enrolled_students.txt");
    if (file.is_open())
    {
        for (int i = 0; i < num_Enrolled_Students_in_class; ++i)
        {
            file << enrolled_Students_in_class[i] << "\n";
        }
        file.close();
        cout << "Enrolled students saved to file successfully.\n";
    }
    else
    {
        cout << "Error saving enrolled students to file.\n";
    }
}

// Function to read enrolled students from a file and save them in the program
/*void Class::read_Enrolled_Students_From_File_in_class(): Method to read the list of
 enrolled students in the class from a file and save them in the "enrolled_Students_in_class"
  array.*/
void Class::read_Enrolled_Students_From_File_in_class()
{
    FileManager fileManager;
    string fileName = (class_Name_in_class + "_enrolled_students.txt");
    ifstream file(fileName);
    if (file.is_open())
    {
        string studentID;
        int index = 0;
        while (getline(file, studentID))
        {
            enrolled_Students_in_class[index] = studentID;
            index++;
            if (index >= maximum_number_of_students_in_class_for_grading)
            {
                cout << "Warning: Maximum number of enrolled students reached.\n";
                break;
            }
        }
        num_Enrolled_Students_in_class = index;
        file.close();
        cout << "Enrolled students read from file and saved to program successfully.\n";
    }
    else
    {
        cout << "Error reading enrolled students from file or the file does not exist.\n";
    }
}
// Function to display all subjects_in_class and grades of a student against their unique ID
/*void Class::display_Student_Grades_in_class(string &studentID): Method to display all
subjects and grades of a specific student based on their unique ID.*/
void Class::display_Student_Grades_in_class(string &studentID)
{
    for (int i = 0; i < num_Enrolled_Students_in_class; i++)
    {
        if (studentID == enrolled_Students_in_class[i])
        {
            cout << MAGENTA << "Subject: " << YELLOW << class_Name_in_class << MAGENTA << " Grade: " << YELLOW << grades_in_class.generate_student_Grade_Report_in_GradeBook(studentID) << endl;
        }
    }
}
