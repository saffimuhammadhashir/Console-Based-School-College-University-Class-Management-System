#pragma once
/*          EXPLAINATION            */

/*The provided code defines the implementation of the `Submission` class. This class appears to represent a submission for a specific subject or assignment.
 The class definition includes the following member functions:

1. `Submission::Submission(string sub)`: Constructor that takes the subject of the submission as an argument and initializes the object. It prompts the user
 to enter details such as title, description, deadline, attached files, and sets other attributes like point value and evaluation status. The information is
  read from the user through `cin` and displayed using colored text.

2. Getters for various attributes of the submission, such as `getsubject_of_submission()`, `getTitle_of_submission()`, `getDescription_of_submission()`,
 `getDeadline_of_submission()`, `getAttachedFiles_of_submission()`, `getPointValue_of_submission()`, `getEvaluationStatus_of_submission()`, and 
 `getFeedback_of_submission()`. These functions return the respective attributes.

3. `void Submission::evaluation_of_submission(string & feedbackText, string id, string name)`: This function is used to evaluate a submission. It takes feedback
 text, student ID, and class name as arguments and sets the evaluation status and feedback for the submission. It then calls the 
 `save_submissions_to_new_file_and_replace()` method to save the submission details to a new file.

4. `void Submission::save_submissions_to_new_file_and_replace(string & studentID, string & classname)`: This function saves the submission details to a new file
 in the format `studentID_classname.txt`. It uses the `ofstream` object to write the details to the file. If the file is successfully opened, it writes
  the submission details to the file along with the evaluation status and feedback.

5. `Submission Submission::get_submissions_from_already_created_files(string & studentID, string & title_of_submission)`: This function is used to load a 
submission from an already created file. It takes the student ID and the title of the submission as arguments and reads the submission details from the 
corresponding file. It then prints the loaded details and prompts the user to provide feedback.

Overall, this `Submission` class is designed to manage and interact with submission details. It allows creating new submissions, evaluating them, saving the 
submission details to files, and loading submission details from existing files. The class makes use of colored text output to enhance the display of 
submission information.*/
#include<iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#include "Submission.h"

using namespace std;
/*Submission::Submission(string sub) (Constructor):

Initializes the evaluationStatus_of_submission to false.
Asks the user to input various details of the submission, such as title, description, deadline, attached files, etc.
Sets pointValue_of_submission to 0.
Clears the input buffer with cin.ignore().
Uses ANSI escape codes to clear the console after input is taken.*/
Submission::Submission(string sub): evaluationStatus_of_submission(false) {
    subject_of_submission = sub;
    cout << "Enter title: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, title_of_submission);
    cout << "Enter description: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, description_of_submission);
    cout << "Enter deadline_of_submission: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, deadline_of_submission);
    cout << "Enter attached files: ";
    cout << YELLOW;
    cout << YELLOW;
    getline(cin, attachedFiles_of_submission);
    pointValue_of_submission = 0;
    cin.ignore(); 
        system("cls");
}

/*Getter methods to access various attributes of the submission:

getsubject_of_submission(): Returns the subject of the submission.
getTitle_of_submission(): Returns the title of the submission.
getDescription_of_submission(): Returns the description of the submission.
getDeadline_of_submission(): Returns the deadline of the submission.
getAttachedFiles_of_submission(): Returns the attached files of the submission.
getPointValue_of_submission(): Returns the point value of the submission.
getEvaluationStatus_of_submission(): Returns the evaluation status of the submission (whether it is evaluated or not).
getFeedback_of_submission(): Returns the feedback provided for the submission.*/
string Submission::getsubject_of_submission()  {
    return subject_of_submission;
}

string Submission::getTitle_of_submission()  {
    return title_of_submission;
}

string Submission::getDescription_of_submission()  {
    return description_of_submission;
}

string Submission::getDeadline_of_submission()  {
    return deadline_of_submission;
}

string Submission::getAttachedFiles_of_submission()  {
    return attachedFiles_of_submission;
}

int Submission::getPointValue_of_submission()  {
    return pointValue_of_submission;
}

bool Submission::getEvaluationStatus_of_submission()  {
    return evaluationStatus_of_submission;
}

string Submission::getFeedback_of_submission()  {
    return feedback_of_submission;
}
/*void Submission::evaluation_of_submission(string &feedbackText, string id, string name):

Updates the evaluationStatus_of_submission to true.
Stores the provided feedbackText.
Calls the save_submissions_to_new_file_and_replace method to save the updated submission details to a file.*/
void Submission::evaluation_of_submission(string & feedbackText, string id, string name) {
    evaluationStatus_of_submission = true;
    feedback_of_submission = feedbackText;
    save_submissions_to_new_file_and_replace(id, name);
}
/*void Submission::save_submissions_to_new_file_and_replace(string &studentID, string &classname):

Opens an output file stream to save the submission details to a file in the format "studentID_classname.txt".
Writes the submission details to the file.
If the file cannot be opened, it displays an error message.*/
void Submission::save_submissions_to_new_file_and_replace(string & studentID,
    string & classname) {
    ofstream file(studentID + "_" + classname + ".txt");


if (file.is_open()) {
   file << "subject: " << subject_of_submission << "\n" << "Title_title_of_submission: " << title_of_submission << "\n" << "Description: " << description_of_submission << "\n" << "Deadline: " << deadline_of_submission << "\n" << "Attached Files: " << attachedFiles_of_submission << "\n" << "Point Value: " << pointValue_of_submission << "\n" << "Evaluation Status: " << (evaluationStatus_of_submission ? "Evaluated" : "Not Evaluated") << "\n" << (evaluationStatus_of_submission ? ("Feedback: " + feedback_of_submission + "\n") : "");
 file.close();
    cout << "Submission saved to file successfully.\n";
} else {
    cout << "Error saving submission to file.\n";
}

}
/*Submission Submission::get_submissions_from_already_created_files(string &studentID, string &title_of_submission):

Opens an input file stream to read the submission details from a file with the given "studentID_title_of_submission.txt".
Reads the submission details from the file and stores them in variables.
Displays the loaded submission details.
Asks the user to provide feedback and stores it.
Returns a new Submission object with the loaded details and the provided feedback.*/
Submission Submission::get_submissions_from_already_created_files(string & studentID,
    string & title_of_submission) {
    ifstream file(studentID + "_" + title_of_submission + ".txt");
        string subject_of_submission="", description_of_submission="", deadline_of_submission="", attachedFiles_of_submission="", feedback_of_submission="";
        int pointValue_of_submission;
    if (file.is_open()) {
        bool evaluationStatus_of_submission = false;

        string line;
        while (getline(file, line)) {
            subject_of_submission = line.find("subject: ") == 0 ? line.substr(9) : subject_of_submission;
            description_of_submission = line.find("Description: ") == 0 ? line.substr(13) : description_of_submission;
            deadline_of_submission = line.find("Deadline: ") == 0 ? line.substr(10) : deadline_of_submission;
            attachedFiles_of_submission = line.find("Attached Files: ") == 0 ? line.substr(16) : attachedFiles_of_submission;
            pointValue_of_submission = line.find("Point Value: ") == 0 ? stoi(line.substr(13)) : pointValue_of_submission;
            evaluationStatus_of_submission = line.find("Evaluation Status: ") == 0 ? line.find("Evaluated") != string::npos : evaluationStatus_of_submission;
            feedback_of_submission = line.find("Feedback: ") == 0 ? line.substr(10) : feedback_of_submission;

        }
        cout<<RED <<"Submission loaded successfully.\n"<<endl;
        cout<<CYAN  <<"Subject: "<<YELLOW<<subject_of_submission<<endl;
        cout<<CYAN  <<"Description: "<<YELLOW<<description_of_submission<<endl;
        cout<<CYAN  <<"AttachedFiles: "<<YELLOW<<attachedFiles_of_submission<<endl;
        cout<<CYAN  <<"Evaluation Status: "<<YELLOW<<evaluationStatus_of_submission<<endl;
      
        cout<<CYAN  <<"Feedback: "<<YELLOW;
        getline(cin,feedback_of_submission);
        
        file.close();
       
       
    } else 
        cout << "Error loading submission from file.\n";
        
        return Submission(subject_of_submission, title_of_submission, description_of_submission, deadline_of_submission, attachedFiles_of_submission, pointValue_of_submission, true, feedback_of_submission);
    
    }

    /*The Submission class seems to be handling the storage, loading, and evaluation status of individual student submissions. It utilizes input
     and output file streams to read and write submission details to files. Additionally, it uses ANSI escape codes for colored console output.

Please note that the class might have dependencies on other parts of the code (such as other classes or functions not included in the provided code
 snippet). To ensure the proper functioning of the Submission class, it is essential to check its usage in the overall program context.*/
