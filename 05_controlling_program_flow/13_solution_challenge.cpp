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
