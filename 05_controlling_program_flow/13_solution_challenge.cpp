/*
    MINI PROJECT: Student Gradebook
    ------------------------------
    Write a program that:
    1. Asks the user how many students are in the class.
    2. For each student, asks for their name and score (0-100).
    3. Stores names and scores, calculates the average score.
    4. Finds and displays the student(s) with the highest score.
    5. Handles invalid input gracefully.
*/

#include <vector>
#include <string>

void student_gradebook() {
    int n;
    cout << "\n=== Student Gradebook ===" << endl;
    cout << "How many students? ";
    while (!(cin >> n) || n <= 0) {
        cout << "Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<string> names(n);
    vector<int> scores(n);
    int total = 0;
    int highest = -1;
    for (int i = 0; i < n; ++i) {
        cout << "Enter name for student " << (i+1) << ": ";
        cin >> names[i];
        cout << "Enter score (0-100) for " << names[i] << ": ";
        while (!(cin >> scores[i]) || scores[i] < 0 || scores[i] > 100) {
            cout << "Invalid score. Enter a value between 0 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        total += scores[i];
        if (scores[i] > highest) highest = scores[i];
    }

    double average = static_cast<double>(total) / n;
    cout << "\nClass average: " << average << endl;
    cout << "Highest score: " << highest << " by: ";
    for (int i = 0; i < n; ++i) {
        if (scores[i] == highest) cout << names[i] << " ";
    }
    cout << endl;
}

// To run this project, call student_gradebook(); from main or separately.
/*
    MINI PROJECT: Simple ATM Simulator
    ----------------------------------
    Write a program that simulates a simple ATM with the following features:
    1. User starts with a balance (e.g., 1000 units)
    2. Show a menu: Check Balance, Deposit, Withdraw, Exit
    3. Perform the selected operation, loop until user chooses Exit
    4. Validate input (no negative deposits/withdrawals, no overdraft)
    5. Display messages for invalid actions
*/

void simple_atm() {
    double balance = 1000.0;
    int choice;
    double amount;
    cout << "\n=== Simple ATM Simulator ===" << endl;
    do {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "Invalid choice. Please enter 1-4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (choice) {
            case 1:
                cout << "Current balance: " << balance << endl;
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                while (!(cin >> amount) || amount <= 0) {
                    cout << "Invalid amount. Enter a positive number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                balance += amount;
                cout << "Deposited: " << amount << ". New balance: " << balance << endl;
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                while (!(cin >> amount) || amount <= 0) {
                    cout << "Invalid amount. Enter a positive number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (amount > balance) {
                    cout << "Insufficient funds! Current balance: " << balance << endl;
                } else {
                    balance -= amount;
                    cout << "Withdrawn: " << amount << ". New balance: " << balance << endl;
                }
                break;
            case 4:
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
        }
    } while (choice != 4);
}

// To run this project, call simple_atm(); from main or separately.
/*
    CHALLENGE: Number Guessing Game
    
    Create a simple number guessing game with the following requirements:
    
    1. Generate a random number between 1 and 100
    2. Ask the user to guess the number
    3. Provide hints: "Too high!", "Too low!", or "Correct!"
    4. Keep track of the number of attempts
    5. Allow a maximum of 7 attempts
    6. Use appropriate control flow structures (if/else, loops, etc.)
    7. Display encouraging messages based on performance:
       - 1-3 attempts: "Amazing! You're a guessing master!"
       - 4-5 attempts: "Great job! Well done!"
       - 6-7 attempts: "Good effort! You got it!"
       - Failed (all attempts used): "Better luck next time!"
    
    BONUS CHALLENGES:
    - Ask if the user wants to play again
    - Keep track of wins/losses across multiple games
    - Add input validation (handle non-numeric input)
*/

#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

int main() {
    
    // Seed the random number generator
    srand(time(nullptr));
    
    // Game variables
    int secretNumber = rand() % 100 + 1;  // Random number between 1-100
    int guess = 0;
    int attempts = 0;
    const int MAX_ATTEMPTS = 7;
    bool hasWon = false;
    
    // Game introduction
    cout << "=== Welcome to the Number Guessing Game! ===" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    cout << "You have " << MAX_ATTEMPTS << " attempts to guess it!" << endl;
    cout << "Good luck!" << endl << endl;
    
    // Main game loop
    while (attempts < MAX_ATTEMPTS && !hasWon) {
        cout << "Attempt " << (attempts + 1) << " of " << MAX_ATTEMPTS << endl;
        cout << "Enter your guess: ";
        cin >> guess;
        
        attempts++;
        
        // Check the guess using if-else statements
        if (guess == secretNumber) {
            hasWon = true;
            cout << "🎉 Congratulations! You guessed it!" << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try a higher number." << endl;
        } else {
            cout << "Too high! Try a lower number." << endl;
        }
        
        // Show remaining attempts (if not won and not last attempt)
        if (!hasWon && attempts < MAX_ATTEMPTS) {
            cout << "Attempts remaining: " << (MAX_ATTEMPTS - attempts) << endl;
        }
        
        cout << endl;
    }
    
    // Game results using switch statement based on performance
    if (hasWon) {
        cout << "You won in " << attempts << " attempts!" << endl;
        
        // Performance-based messages using switch
        switch (attempts) {
            case 1:
            case 2:
            case 3:
                cout << "Amazing! You're a guessing master! 🌟" << endl;
                break;
            case 4:
            case 5:
                cout << "Great job! Well done! 👏" << endl;
                break;
            case 6:
            case 7:
                cout << "Good effort! You got it! 👍" << endl;
                break;
        }
    } else {
        cout << "Game Over! You've used all " << MAX_ATTEMPTS << " attempts." << endl;
        cout << "The number was: " << secretNumber << endl;
        cout << "Better luck next time! 🍀" << endl;
    }
    
    // Statistics
    cout << endl << "=== Game Statistics ===" << endl;
    cout << "Secret Number: " << secretNumber << endl;
    cout << "Your Last Guess: " << guess << endl;
    cout << "Total Attempts Used: " << attempts << endl;
    cout << "Success Rate: " << (hasWon ? "100%" : "0%") << endl;
    
    return 0;
}

/*
    MINI SOLUTION CHALLENGE: Even or Odd Counter
    --------------------------------------------
    Write a program that:
    1. Asks the user how many numbers they want to enter.
    2. Reads that many numbers from the user (one at a time).
    3. Counts how many are even and how many are odd.
    4. Displays the counts at the end.
    5. Handles invalid (non-integer) input gracefully.
*/

#include <limits>

int even_odd_counter() {
    int n;
    cout << "\n=== Even or Odd Counter ===" << endl;
    cout << "How many numbers will you enter? ";
    while (!(cin >> n) || n <= 0) {
        cout << "Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int even_count = 0, odd_count = 0, value;
    for (int i = 1; i <= n; ++i) {
        cout << "Enter number " << i << ": ";
        while (!(cin >> value)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (value % 2 == 0)
            ++even_count;
        else
            ++odd_count;
    }
    cout << "\nYou entered " << even_count << " even and " << odd_count << " odd numbers." << endl;
    return 0;
}

// To run this challenge, call even_odd_counter(); from main or separately.

/*
    SOLUTION EXPLANATION:
    
    This challenge demonstrates multiple control flow concepts:
    
    1. LOOPS: 
       - while loop for the main game logic
       - Loop continues until max attempts reached OR player wins
    
    2. CONDITIONAL STATEMENTS:
       - if-else chain to check guess accuracy
       - Nested if statements for game state management
    
    3. SWITCH STATEMENT:
       - Used for performance-based feedback messages
       - Demonstrates fall-through behavior (cases 1-3, 4-5, 6-7)
    
    4. BOOLEAN LOGIC:
       - hasWon flag to control game state
       - Compound conditions in while loop (!hasWon && attempts < MAX_ATTEMPTS)
    
    5. VARIABLES & CONSTANTS:
       - const int for MAX_ATTEMPTS (good practice)
       - Multiple variable types (int, bool)
    
    6. RANDOM NUMBERS:
       - srand() to seed random generator
       - rand() % 100 + 1 for numbers 1-100
    
    POSSIBLE EXTENSIONS FOR PRACTICE:
    - Add do-while loop for "play again" feature
    - Use continue/break statements for input validation
    - Add nested loops for multiple rounds
    - Implement a for loop to display game history
*/
