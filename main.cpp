/*

Title: Advanced Console-based Classroom Management System

Introduction:
Alex, a student, undertakes the development of a Console-based Classroom Management System as a personal project.
 The system aims to replicate the functionalities of popular virtual classroom platforms like Google Classroom using C++
  programming language and object-oriented programming (OOP) concepts. The main goal is to create a user-friendly, efficient, and
  comprehensive system to handle user management, class organization, assignment management, submission and grading, gradebook management, file handling, notification delivery, user interface interactions, data persistence, and exception handling.

User Management:
In the User Management system, Alex creates classes to represent users with attributes such as name, email, role,
 unique ID, password, and contact information. OOP concepts like inheritance are used to handle different user roles
 (teachers and students), while polymorphism is used for authentication and user registration. File handling techniques are employed
 to save and retrieve user profiles, ensuring that user data is persisted even when the program is closed. Password management features
 like encryption and validation are also implemented to enhance security.

Class Management:
The Class Management system allows users to create and organize virtual classrooms. Each class is represented as a
 class object with attributes like class name, subject, teacher, description, and a roster of enrolled students. Alex uses
  aggregation and composition relationships to manage the association between classes and users. The system enables users to create,
   update, and delete classes, and view class details. Enrolled students can be added or removed from class rosters. Class data is stored
    persistently using file handling techniques, ensuring that information is saved between program runs.

Assignment Management:
Alex develops the Assignment Management system to handle assignments within classes. Each assignment is represented
 as an assignment object with attributes like title, description, deadline, attached files, and point value. Encapsulation
 and abstraction ensure data integrity and modularity in the system. The system supports functionalities for creating, updating, and
  deleting assignments. Validations prevent the creation of assignments with past deadlines. File handling techniques are employed to
  store and retrieve assignment data, including details and attached files.

Submission and Grading:
The Submission and Grading system allows students to submit assignments, and teachers can review and grade them.
Submissions are represented as submission objects with attributes like submission timestamp, attached files, evaluation status,
 and feedback. OOP concepts like inheritance and polymorphism handle different submission types, such as text or file uploads. Validations
  are included to prevent late submissions. File handling techniques are used to store and manage submission and grading data, including
   student submissions, grades, and feedback.

Gradebook:
The Gradebook system provides an overview of student grades and class averages. A gradebook class calculates and updates
 student grades based on assignment scores and weightage. The gradebook includes attributes such as cumulative grades, class
 averages, and weightage settings. Encapsulation and abstraction ensure accurate grade calculations and easy retrieval. The system
 allows for generating grade reports or transcripts for individual students or the entire class. File handling techniques are employed to store
  and retrieve gradebook data, including individual student grades, class averages, and weightage settings.

File Management:
The File Management system handles files related to classes, assignments, and submissions. A file manager class handles
 file upload, download, and deletion operations. The system enforces file size limits and appropriate formats. Encapsulation and
  abstraction ensure modularity, and file handling techniques efficiently store and manage file data, ensuring organized file retrieval and storage.

Notification System:
Alex implements a Notification System to keep users informed about important updates and deadlines. Notifications are
 generated for new assignments, upcoming deadlines, and graded submissions. Users can customize their notification preferences,
 and notifications can be displayed in the console. Polymorphism and abstraction handle different notification types. File handling
 techniques are used to store notification data, including settings, timestamps, and delivery status.

User Interface:
To provide a user-friendly experience, Alex develops a console-based User Interface (UI). The UI features menus, prompts,
 and dialogues for easy interaction with the system. Encapsulation and abstraction are used to encapsulate UI components and ensure
  modularity. Proper error handling and informative prompts guide users through the system's functionalities. User interface preferences,
   such as window size and layout customization, are saved using file handling techniques.

Data Persistence:
To ensure data longevity and reliability, Alex employs robust file handling techniques for data persistence. User profiles,
 class information, assignment details, submissions, grades, and notifications are stored in files. This ensures that data is saved
 and retrieved even when the program is closed or reopened. File reading and writing operations are used to maintain data integrity and
 facilitate easy data retrieval.

Exception Handling:
To handle runtime errors and exceptional conditions gracefully, Alex incorporates comprehensive exception handling mechanisms.
 Custom exceptions provide meaningful error messages and handle scenarios like file I/O errors or invalid user input. Exception handling
 prevents program crashes and provides error logs for troubleshooting, ensuring a stable system.

Conclusion:
In this case study, Alex, a student, successfully developed an Advanced Console-based Classroom Management System using C++ programming
language and OOP concepts. The system encompasses essential functionalities for user management, class organization, assignment handling,
submission and grading, gradebook management, file handling, notification delivery, and user interface interactions. Alex's proficient use of
 inheritance, polymorphism, encapsulation, abstraction, and file handling techniques demonstrates their understanding of key OOP principles and
 software development best practices. This project serves as an excellent example of building a user-friendly and efficient application while
 addressing data persistence and error handling. With potential future enhancements, the Console-based Classroom Management System could become
 a valuable tool for real-world classroom management, benefiting both teachers and students in their academic journeys.




*/
#include<iostream>
#include"UI.cpp"
int main(){
UI run;
run.StartProgram();

}