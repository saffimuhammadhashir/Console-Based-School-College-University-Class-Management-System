// Include necessary header files
#pragma once

#include <iostream>
/*              EXPLAINATION          */
/*The provided code defines the implementation of the `GradeBook` class. This class appears to represent a grade book for
 managing student grades in a class. Here's a summary of the functionalities provided by the `GradeBook` class:

1. Constructors:
   - `GradeBook()`: Default constructor that initializes the number of students, class average, and grade weightage to 0.
   - `GradeBook(double grade_Weightage__in_GradeBook)`: Parameterized constructor that allows setting the grade weightage.

2. Member Functions:
   - `get_Average_in_GradeBook()`: Returns the class average.
   - `update_Class_Average_in_GradeBook()`: Updates the class average based on the grades of students.
   - `get_Student_Grade_in_GradeBook(int i)`: Returns the grade of the student at the given index `i`.
   - `generate_student_Grade_Report_in_GradeBook(string &studentID)`: Generates the grade report for an individual student based on their ID.
   - `update_Student_Grade_in_GradeBook(string &studentID, int grade)`: Updates the grade of a specific student identified by their ID.
   - `generate_Grade_Report_in_GradeBook(string &studentID)`: Generates the grade report for an individual student.
   - `generate_Class_Grade_Report_in_GradeBook()`: Generates the class grade report, displaying all students' grades and the class average.

The class maintains an array of student IDs (`student_IDs_in_GradeBook`) and their corresponding grades (`student_Grades_in_GradeBook`)
. It also keeps track of the number of students (`num_Students_in_GradeBook`) and the class average (`class_Average_in_GradeBook`).

Note: The code snippet you provided does not include the declaration of member variables or the definition of constants like 
`maximum_number_of_students_in_class_for_grading`, so it's assumed they are defined elsewhere. Also, the code uses certain variables like
 `student_IDs_in_GradeBook` and `student_Grades_in_GradeBook`, which are not defined in the provided snippet.

Overall, the `GradeBook` class appears to be designed for managing student grades, calculating the class average, and generating grade reports
 for individual students and the entire class. It is part of a larger system that likely includes other classes for handling different aspects 
 of a classroom management system.
*/
// Define text color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

// Include the GradeBook header file
#include "GradeBook.h"

using namespace std;

// Initialize GradeBook class

// Default constructor
/*Default Constructor:

GradeBook(): Initializes the num_Students_in_GradeBook, class_Average_in_GradeBook, and grade_Weightage__in_GradeBook member variables to 0.*/
GradeBook::GradeBook() : num_Students_in_GradeBook(0), class_Average_in_GradeBook(0.0), grade_Weightage__in_GradeBook(0.0) {}

// Parameterized constructor with grade weightage
/*Parameterized Constructor:

GradeBook(double grade_Weightage__in_GradeBook): Initializes the num_Students_in_GradeBook,
 class_Average_in_GradeBook, and grade_Weightage__in_GradeBook member variables. The parameter grade_Weightage__in_GradeBook allows setting the grade weightage.*/
GradeBook::GradeBook(double grade_Weightage__in_GradeBook) : num_Students_in_GradeBook(0), class_Average_in_GradeBook(0.0), grade_Weightage__in_GradeBook(grade_Weightage__in_GradeBook) {}

// Get the class average
/*get_Average_in_GradeBook():

Returns the class average (class_Average_in_GradeBook).*/
double GradeBook::get_Average_in_GradeBook()
{
    return class_Average_in_GradeBook;
}

// Update the class average
/*update_Class_Average_in_GradeBook():

Checks if there are students in the class and updates the class_Average_in_GradeBook based on the grades of students.*/
void GradeBook::update_Class_Average_in_GradeBook()
{
    // Check if there are students in the class
    if (num_Students_in_GradeBook == 0)
    {
        class_Average_in_GradeBook = 0.0;
        return;
    }

    double totalGrade = 0.0;
    // Calculate the total grades of all students
    for (int i = 0; i < num_Students_in_GradeBook; ++i)
    {
        totalGrade += student_Grades_in_GradeBook[i];
    }

    // Calculate and update the class average
    class_Average_in_GradeBook = totalGrade / num_Students_in_GradeBook;
}

// Get student's grade
/*get_Student_Grade_in_GradeBook(int i):

Returns the grade of the student at the given index i in the student_Grades_in_GradeBook array.*/
double GradeBook::get_Student_Grade_in_GradeBook(int i)
{
    return student_Grades_in_GradeBook[i];
}

// Generate student's grade report
/*generate_student_Grade_Report_in_GradeBook(string &studentID):

Generates the grade report for an individual student identified by their ID (studentID)
 and returns their grade. If the student is not found, it displays a message indicating that the student is not in the gradebook and returns 0.*/
int GradeBook::generate_student_Grade_Report_in_GradeBook(string &studentID)
{
    for (int i = 0; i < num_Students_in_GradeBook; ++i)
    {
        if (student_IDs_in_GradeBook[i] == studentID)
        {
            return student_Grades_in_GradeBook[i];
        }
    }
    cout << "Student not found in the gradebook.\n";
    return 0;
}

// Update student's grade
/*update_Student_Grade_in_GradeBook(string &studentID, int grade):

Updates the grade of a specific student identified by their ID (studentID). If the student 
is found in the gradebook, their grade is updated with the provided grade. If the student is not found and there is 
space available, the student and their grade are added to the gradebook.*/
void GradeBook::update_Student_Grade_in_GradeBook(string &studentID, int grade)
{
    // Find the student in the gradebook
    for (int i = 0; i < num_Students_in_GradeBook; ++i)
    {
        if (student_IDs_in_GradeBook[i + 1] == studentID)
        {
            student_Grades_in_GradeBook[i] = grade;
            update_Class_Average_in_GradeBook();
            return;
        }
    }

    // Add student and grade if space is available
    if (num_Students_in_GradeBook < maximum_number_of_students_in_class_for_grading)
    {
        student_IDs_in_GradeBook[num_Students_in_GradeBook] = studentID;
        student_Grades_in_GradeBook[num_Students_in_GradeBook] = grade;
        num_Students_in_GradeBook++;
        update_Class_Average_in_GradeBook();
    }
    else
    {
        cout << "Maximum number of students reached. Cannot add more students.\n";
    }
}

// Generate individual student's grade report
/*generate_Grade_Report_in_GradeBook(string &studentID):

Generates the grade report for an individual student identified by their ID (studentID) and
 displays their grade. If the student is not found in the gradebook, it displays a message indicating the same.*/
void GradeBook::generate_Grade_Report_in_GradeBook(string &studentID)
{
    bool foundStudent = false;

    // Search for the student's grade
    for (int i = 0; i < num_Students_in_GradeBook; ++i)
    {
        if (student_IDs_in_GradeBook[i] == studentID)
        {
            // Display student's grade report
            cout << "Grade Report for Student ID: " << studentID << "\n";
            cout << "Grade: " << student_Grades_in_GradeBook[i] << "\n";
            cout << "--------------------------\n";
            foundStudent = true;
            break;
        }
    }

    // Display a message if student not found
    if (!foundStudent)
    {
        cout << "Student not found in the gradebook.\n";
    }
}

// Generate class grade report
/*generate_Class_Grade_Report_in_GradeBook():

Generates the class grade report by displaying all students' IDs and their corresponding grades.
 It also calculates and displays the class average based on the grades of all students.*/
void GradeBook::generate_Class_Grade_Report_in_GradeBook()
{
    // Check if there are students in the class
    if (num_Students_in_GradeBook == 0)
    {
        cout << "No students in the class.\n";
    }
    else
    {
        double totalGrade = 0.0;

        // Display class grade report
        cout << "Class Grade Report\n";
        for (int i = 0; i < num_Students_in_GradeBook; ++i)
        {
            cout << "Student ID: " << student_IDs_in_GradeBook[i] << "\n";
            cout << "Grade: " << student_Grades_in_GradeBook[i] << "\n";
            cout << "--------------------------\n";

            totalGrade += student_Grades_in_GradeBook[i];
        }

        // Calculate and display class average
        double classAverage = totalGrade / num_Students_in_GradeBook;
        cout << "Class Average: " << classAverage << "\n";
        cout << "--------------------------\n";
    }
}

/*The GradeBook class uses member variables num_Students_in_GradeBook, class_Average_in_GradeBook,
 grade_Weightage__in_GradeBook, student_IDs_in_GradeBook, and student_Grades_in_GradeBook to store information about 
 the students and their grades in the class. The code snippet provided does not include the declaration of these member variables, 
 so it's assumed that they are declared in the GradeBook class or elsewhere in the codebase.*/
