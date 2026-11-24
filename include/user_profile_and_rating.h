
#ifndef USER_PROFILE_RATING_H
#define USER_PROFILE_RATING_H

#include <iostream>
#include <string>
using namespace std;

// Class 1: UserProfile
class UserProfile {
private:
    int userID;
    string userName;
    string email;
    string phoneNumber;

public:
    // Default constructor
    UserProfile() {
        userID = 0;
        userName = "";
        email = "";
        phoneNumber = "";
    }

    // Parameterized constructor
    UserProfile(int id, string name, string userEmail, string phone) {
        userID = id;
        userName = name;
        email = userEmail;
        phoneNumber = phone;
    }

    // Member function to update user information
    void updateProfile(string name, string userEmail, string phone) {
        userName = name;
        email = userEmail;
        phoneNumber = phone;
    }

    // Member function to display user information
    void displayProfile() const {
        cout << "User ID: " << userID << endl;
        cout << "User Name: " << userName << endl;
        cout << "Email: " << email << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }

    int getUserID() const {
        return userID;
    }
};

// Class 2: Rating
class Rating {
private:
    int ratingID;
    int userID;
    int score;
    string feedback;

public:
    // Default constructor
    Rating() {
        ratingID = 0;
        userID = 0;
        score = 0;
        feedback = "";
    }

    // Parameterized constructor
    Rating(int rID, int uID, int ratingScore, string review) {
        ratingID = rID;
        userID = uID;
        score = ratingScore;
        feedback = review;
    }

    // Member function to set rating
    void setRating(int ratingScore, string review) {
        if (ratingScore >= 1 && ratingScore <= 5) {
            score = ratingScore;
            feedback = review;
        } else {
            cout << "Rating must be between 1 and 5." << endl;
        }
    }

    // Member function to display rating
    void displayRating() const {
        cout << "Rating ID: " << ratingID << endl;
        cout << "User ID: " << userID << endl;
        cout << "Score: " << score << "/5" << endl;
        cout << "Feedback: " << feedback << endl;
    }
};

#endif
