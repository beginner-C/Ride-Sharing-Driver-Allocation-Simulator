#include "UserProfileRating.h"

// UserProfile class constructors and member functions
UserProfile::UserProfile() {
    userID = 0;
    userName = "";
    email = "";
    phoneNumber = "";
}

UserProfile::UserProfile(int id, string name, string userEmail, string phone) {
    userID = id;
    userName = name;
    email = userEmail;
    phoneNumber = phone;
}

void UserProfile::updateProfile(string name, string userEmail, string phone) {
    userName = name;
    email = userEmail;
    phoneNumber = phone;
}

void UserProfile::displayProfile() const {
    cout << "User ID: " << userID << endl;
    cout << "User Name: " << userName << endl;
    cout << "Email: " << email << endl;
    cout << "Phone Number: " << phoneNumber << endl;
}

int UserProfile::getUserID() const {
    return userID;
}

// Rating class constructors and member functions
Rating::Rating() {
    ratingID = 0;
    userID = 0;
    score = 0;
    feedback = "";
}

Rating::Rating(int rID, int uID, int ratingScore, string review) {
    ratingID = rID;
    userID = uID;
    if (ratingScore >= 1 && ratingScore <= 5) {
        score = ratingScore;
    } else {
        score = 0;
    }
    feedback = review;
}

void Rating::setRating(int ratingScore, string review) {
    if (ratingScore >= 1 && ratingScore <= 5) {
        score = ratingScore;
        feedback = review;
    } else {
        cout << "Rating must be between 1 and 5." << endl;
    }
}

void Rating::displayRating() const {
    cout << "Rating ID: " << ratingID << endl;
    cout << "User ID: " << userID << endl;
    cout << "Score: " << score << "/5" << endl;
    cout << "Feedback: " << feedback << endl;
}
