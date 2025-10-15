#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cout << "=== NUMBER GUESSING GAME WITH STATISTICS ===" << endl;
    cout << "Challenge: Guess numbers between 1-100 and track your performance!" << endl;
    cout << "Instructions:" << endl;
    cout << "- Enter numbers between 1-100" << endl;
    cout << "- Type 0 to quit and see statistics" << endl;
    cout << "- Type -1 to see current statistics without quitting" << endl;
    cout << "=============================================" << endl << endl;

    // Game variables
    int secret_number = 42;  // The secret number to guess
    vector<int> all_guesses;  // Store all valid guesses
    int total_attempts = 0;
    int closest_guess = 0;
    int closest_distance = 101;  // Max possible distance is 100
    bool game_won = false;
    
    while (true) {
        int user_guess;
        
        // Input validation loop
        while (true) {
            cout << "Enter your guess (1-100, 0 to quit, -1 for stats): ";
            cin >> user_guess;
            
            // Handle invalid input
            if (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number." << endl;
                continue;
            }
            
            // Valid input received, break the validation loop
            break;
        }
        
        // Handle special commands
        if (user_guess == 0) {
            cout << "\nGame ended by user choice." << endl;
            break;
        }
        
        if (user_guess == -1) {
            // Show current statistics without ending game
            cout << "\n--- CURRENT STATISTICS ---" << endl;
            cout << "Total attempts: " << total_attempts << endl;
            
            if (total_attempts > 0) {
                cout << "All your guesses: ";
                for (size_t i = 0; i < all_guesses.size(); ++i) {
                    cout << all_guesses[i];
                    if (i < all_guesses.size() - 1) cout << ", ";
                }
                cout << endl;
                cout << "Closest guess: " << closest_guess << " (distance: " << closest_distance << ")" << endl;
            } else {
                cout << "No guesses made yet!" << endl;
            }
            cout << "-------------------------" << endl << endl;
            continue;
        }
        
        // Validate range for actual guesses
        if (user_guess < 1 || user_guess > 100) {
            cout << "Out of range! Please enter a number between 1-100." << endl;
            continue;
        }
        
        // Process valid guess
        total_attempts++;
        all_guesses.push_back(user_guess);
        
        // Calculate distance from secret number
        int distance = abs(user_guess - secret_number);
        
        // Update closest guess tracking
        if (distance < closest_distance) {
            closest_distance = distance;
            closest_guess = user_guess;
        }
        
        // Check if guess is correct
        if (user_guess == secret_number) {
            cout << "\n🎉 CONGRATULATIONS! You guessed it! 🎉" << endl;
            cout << "The secret number was indeed " << secret_number << "!" << endl;
            game_won = true;
            break;
        }
        
        // Provide hints using nested conditions
        cout << "Attempt #" << total_attempts << ": ";
        if (user_guess < secret_number) {
            if (distance <= 5) {
                cout << "Very close! Try a little higher." << endl;
            } else if (distance <= 15) {
                cout << "Close! Go higher." << endl;
            } else {
                cout << "Too low! Go much higher." << endl;
            }
        } else {
            if (distance <= 5) {
                cout << "Very close! Try a little lower." << endl;
            } else if (distance <= 15) {
                cout << "Close! Go lower." << endl;
            } else {
                cout << "Too high! Go much lower." << endl;
            }
        }
        
        // Show progress every 5 attempts
        if (total_attempts % 5 == 0) {
            cout << ">>> After " << total_attempts << " attempts, your closest guess is " 
                 << closest_guess << " (distance: " << closest_distance << ")" << endl;
        }
    }
    
    // Final statistics
    cout << "\n=== FINAL GAME STATISTICS ===" << endl;
    cout << "Secret number: " << secret_number << endl;
    cout << "Total attempts: " << total_attempts << endl;
    cout << "Game result: " << (game_won ? "WON!" : "Quit without winning") << endl;
    
    if (total_attempts > 0) {
        cout << "\nYour guessing journey: ";
        for (size_t i = 0; i < all_guesses.size(); ++i) {
            cout << all_guesses[i];
            if (i < all_guesses.size() - 1) cout << " → ";
        }
        cout << endl;
        
        cout << "Closest guess: " << closest_guess << " (distance: " << closest_distance << ")" << endl;
        
        // Find highest and lowest guesses
        auto minmax = minmax_element(all_guesses.begin(), all_guesses.end());
        cout << "Lowest guess: " << *minmax.first << endl;
        cout << "Highest guess: " << *minmax.second << endl;
        
        // Performance rating
        if (game_won) {
            if (total_attempts <= 3) {
                cout << "Performance: EXCELLENT! 🌟" << endl;
            } else if (total_attempts <= 7) {
                cout << "Performance: GOOD! 👍" << endl;
            } else if (total_attempts <= 12) {
                cout << "Performance: AVERAGE 👌" << endl;
            } else {
                cout << "Performance: KEEP PRACTICING! 💪" << endl;
            }
        }
    } else {
        cout << "No attempts were made." << endl;
    }
    
    cout << "\nThanks for playing!" << endl;
    cout << "============================" << endl;
    
    return 0;
}
