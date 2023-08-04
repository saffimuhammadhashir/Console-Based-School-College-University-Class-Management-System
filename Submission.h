// This pragma once ensures that this header file is included only once during compilation to prevent multiple definitions.
#pragma once

// Standard library includes
#include <iostream>
#include <string>
#include <fstream>

// Define color codes for console output (optional, used for styling)
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Submission class definition
class Submission {
private:
    // Private data members
    string subject_of_submission;
    string title_of_submission;
    string description_of_submission;
    string deadline_of_submission;
    string attachedFiles_of_submission;
    int pointValue_of_submission;
    bool evaluationStatus_of_submission;
    string feedback_of_submission;

public:
    // Constructors

    // Default constructor
    Submission() {}

    // Parameterized constructor with subject as a parameter
    Submission(string sub);

    // Parameterized constructor with all necessary parameters
    Submission(string& subject_of_submission, string& title_of_submission, string& description_of_submission, string& deadline_of_submission, string& attachedFiles_of_submission, int pointValue_of_submission, bool evaluationStatus_of_submission = false, string feedback_of_submission = " ")
        : subject_of_submission(subject_of_submission), title_of_submission(title_of_submission), description_of_submission(description_of_submission), deadline_of_submission(deadline_of_submission),
        attachedFiles_of_submission(attachedFiles_of_submission), pointValue_of_submission(pointValue_of_submission), evaluationStatus_of_submission(evaluationStatus_of_submission), feedback_of_submission(feedback_of_submission) {}

    // Getter methods to access private data members
    string getsubject_of_submission();
    string getTitle_of_submission();
    string getDescription_of_submission();
    string getDeadline_of_submission();
    string getAttachedFiles_of_submission();
    int getPointValue_of_submission();
    bool getEvaluationStatus_of_submission();
    string getFeedback_of_submission();

    // Method to evaluate the submission and provide feedback
    void evaluation_of_submission(string& feedback_of_submissionText, string id, string name);

    // Method to save submissions to a new file and replace the old one
    void save_submissions_to_new_file_and_replace(string& studentID, string& classname);

    // Static method to get submissions from already created files
    static Submission get_submissions_from_already_created_files(string& studentID, string& title_of_submission);
};
