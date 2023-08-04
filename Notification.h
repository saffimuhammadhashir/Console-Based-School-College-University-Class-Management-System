// Include necessary header files
#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Class definition for Notification
class Notification {
private:
    // Private data members
    string name_in_Notifications;          // Name of the notification
    string message_in_Notifications;       // Message content of the notification
    string recipient_in_Notifications;     // Recipient of the notification
    bool isDelivered_in_Notifications;     // Flag to indicate if the notification is delivered
    time_t timestamp_in_Notifications;     // Timestamp of the notification

public:
    Notification* Link = nullptr;         // Link to the next Notification object in the list

    // Constructors
    Notification() : isDelivered_in_Notifications(false), timestamp_in_Notifications(time(nullptr)), Link(nullptr) {}
    Notification(string& newname_in_Notifications, string& message_in_Notifications, string& recipient_in_Notifications)
        : name_in_Notifications(newname_in_Notifications), message_in_Notifications(message_in_Notifications),
          recipient_in_Notifications(recipient_in_Notifications), isDelivered_in_Notifications(false),
          timestamp_in_Notifications(time(nullptr)) {}

    // Function to pause execution and wait for user input (Windows specific)
    void is_to_delay() {
        cout << "Press Enter to continue: ";
        cin.ignore();
        system("cls");
    }

    // Function to mark the notification as delivered
    void markAsDelivered() {
        isDelivered_in_Notifications = true;
    }

    // Function to check if the notification is delivered
    bool isNotificationDelivered_in_Notifications() {
        return isDelivered_in_Notifications;
    }

    // Getter methods
    string getMessage_in_Notifications() {
        return message_in_Notifications;
    }

    string getName_in_Notifications() {
        return name_in_Notifications;
    }

    string getRecipient_in_Notifications() {
        return recipient_in_Notifications;
    }

    time_t getTimestamp_in_Notifications() {
        return timestamp_in_Notifications;
    }

    // Setter method to set the name of the notification
    void setName_in_Notifications_in_Notifications(string newName_in_Notifications) {
        name_in_Notifications = newName_in_Notifications;
    }

    // Function to display the notification details
    void display_notification() {
        cout << "********** Display Notification **********\n"<< "Notification Message: " << getMessage_in_Notifications() << "\n"<< "Recipient: " << getRecipient_in_Notifications() << "\n"<< "Timestamp: " << getTimestamp_in_Notifications() << "\n"<< "Is Delivered: " << (isNotificationDelivered_in_Notifications() ? "Yes" : "No") << "\n";
    }
};
