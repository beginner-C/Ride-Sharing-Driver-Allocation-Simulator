#include "UserProfileRating.h"

int main() {
    // Creating objects using parameterized constructors
    UserProfile user1(101, "Ali", "ali@example.com", "03001234567");
    Rating rating1(201, 101, 5, "Excellent service");

    cout << "===== USER PROFILE =====" << endl;
    user1.displayProfile();

    cout << "\n===== USER RATING =====" << endl;
    rating1.displayRating();

    return 0;
}
