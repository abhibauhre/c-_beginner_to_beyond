#include <iostream>
#include <limits>
using namespace std;

int main() {
  

    
    // EXAMPLE 1: BASIC - Simple countdown
    int count = 5;
    do {
        cout << "Countdown: " << count << endl;
        --count;
    } while (count > 0);
    cout << "Blast off!" << endl << endl;

    
    // EXAMPLE 2: MENU SYSTEM - Classic use case
    
    char choice;
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "a) Say Hello" << endl;
        cout << "b) Show Time" << endl;  
        cout << "c) Exit" << endl;
        cout << "Enter your choice (a, b, or c): ";
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':
                cout << "Hello there!" << endl;
                break;
            case 'b':
            case 'B':
                cout << "Current program execution time..." << endl;
                break;
            case 'c':
            case 'C':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 'c' && choice != 'C');
    cout << endl;

    
    // EXAMPLE 3: INPUT VALIDATION - Number guessing
    
    cout << "Example 3: Number Guessing Game (with validation)" << endl;
    int secret_number = 42;
    int guess;
    int attempts = 0;
    
    cout << "I'm thinking of a number between 1 and 100!" << endl;
    
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        
        // Handle invalid input
        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number!" << endl;
            attempts--; // Don't count invalid attempts
            continue;
        }
        
        if (guess < secret_number) {
            cout << "Too low! Try higher." << endl;
        } else if (guess > secret_number) {
            cout << "Too high! Try lower." << endl;
        } else {
            cout << "Congratulations! You guessed it in " << attempts << " attempts!" << endl;
        }
        
    } while (guess != secret_number);
    cout << endl;

    // EXAMPLE 4: ADVANCED - Password validator
    
    cout << "Example 4: Password Validation (advanced input handling)" << endl;
    string password;
    bool valid_password = false;
    
    cout << "Create a password (must be at least 6 characters):" << endl;
    
    do {
        cout << "Enter password: ";
        cin >> password;
        
        if (password.length() < 6) {
            cout << "Password too short! Must be at least 6 characters." << endl;
            valid_password = false;
        } else if (password == "123456" || password == "password") {
            cout << "Password too common! Choose something more secure." << endl;
            valid_password = false;
        } else {
            cout << "Password accepted! Your password has " << password.length() << " characters." << endl;
            valid_password = true;
        }
        
    } while (!valid_password);

    cout << endl;
    cout << "=== SUMMARY ===" << endl;
    cout << "• do-while runs the body FIRST, then checks condition" << endl;
    cout << "• Perfect for menus, input validation, and 'try again' scenarios" << endl;
    cout << "• while-loop checks condition FIRST, may never execute" << endl;
    cout << "• do-while guarantees at least ONE execution" << endl;

    return 0;
}
