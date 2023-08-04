// Include necessary header files
#pragma once
#include <iostream>

// Define color codes for console output
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#include <string>
using namespace std;

// Maximum number of students in class for grading
const int maximum_number_of_students_in_class_for_grading = 50;

class GradeBook {
private:
    // Array to store student IDs
    string student_IDs_in_GradeBook[maximum_number_of_students_in_class_for_grading];
    // Array to store student grades
    int student_Grades_in_GradeBook[maximum_number_of_students_in_class_for_grading];
    // Average grade for the class
    double class_Average_in_GradeBook;
public:
    // Weightage of the grade in the class
    double grade_Weightage__in_GradeBook;
    // Number of students in the class
    int num_Students_in_GradeBook = 0;
    
    // Constructors
    GradeBook();
    GradeBook(double);

    // Function to get the average grade of the class
    double get_Average_in_GradeBook();

    // Function to update a student's grade
    void update_Student_Grade_in_GradeBook(string&, int);

    // Function to update the class average
    void update_Class_Average_in_GradeBook();

    // Function to get a specific student's grade
    double get_Student_Grade_in_GradeBook(int i);

    // Function to generate a report for a specific student's grade
    int generate_student_Grade_Report_in_GradeBook(string&);

    // Function to generate a report for a specific student
    void generate_Grade_Report_in_GradeBook(string&);

    // Function to generate a report for the entire class
    void generate_Class_Grade_Report_in_GradeBook();
};
