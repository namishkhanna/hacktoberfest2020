#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h>
using namespace std;
 
string generate_secret_number() {
    // Generates a 4-digit secret number (between 1000 and 9999)
    srand(time(0));
    int secret_number = rand() % 9000 + 1000;
    return to_string(secret_number);
}
 
string get_user_input() {
    int guess = 0;
    cin >> guess;
 
    // Checks if guess is a 4-digit number (between 1000 and 9999)
    while (guess < 1000 || guess > 9999) {
        cout << "Invalid input!" << endl;
        cin >> guess;
    }
 
    return to_string(guess);
}
 
int count_bulls(string secret_string, string guess_string, bool secret_digit_used[], bool guess_digit_used[]) {
    int count = 0;
 
    // Iterate over the 4 digits and count the number of equal digits
    for (int i = 0; i < 4; i++) {
        if (secret_string[i] == guess_string[i]) {
            count++;
            // Mark digits used
            secret_digit_used[i] = true;
            guess_digit_used[i] = true;
        }
    }
 
    return count;
}
 
int count_cows(string secret_string, string guess_string, bool secret_digit_used[], bool guess_digit_used[]) {
    int count = 0;
 
    // Iterate over all possible position pairs and increase count if digits are equal
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // Don't use an alredy used digit
            if (secret_digit_used[i] || guess_digit_used[j])
                continue;
 
            if (secret_string[i] == guess_string[j]) {
                count++;
                // Mark digits used
                secret_digit_used[i] = true;
                guess_digit_used[j]  = true;
            }
        }
    }
 
    return count;
}
 
int main() {
    // Generate secret number
    string secret_string = generate_secret_number();
    cout << "Secret number chosen (between 1000 and 9999)." << endl;
    // cout << secret_string << endl; // For debugging ...
    cout << "Start guessing! ... " << endl;
 
    int nturns = 0;
    while (true) {
        // Input guess number
        string guess_string = get_user_input();
        nturns++;
 
        // For marking which digits have been "used"
        bool secret_digit_used[4] = {false, false, false, false};
        bool guess_digit_used[4]  = {false, false, false, false};
 
        // Count bulls
        int bulls = count_bulls(secret_string, guess_string, secret_digit_used, guess_digit_used);
 
        // Check if guess is correct
        if (bulls == 4) {
            cout << "Congratulations, you did it!" << endl;
            cout << "You took " << nturns << " to guess the number" << endl;
            break;
        }
 
        // Count cows
        int cows = count_cows(secret_string, guess_string, secret_digit_used, guess_digit_used);
 
        // Output the information
        cout << "Turn " << nturns << ": Your guess " << guess_string << " has " << bulls << " bulls and " << cows << " cows." << endl;
    }
 
    // Output secret number once game is over
    cout << "Secret number is " << secret_string << endl;

    return 0;
}
