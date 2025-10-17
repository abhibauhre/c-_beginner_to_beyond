#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <string>
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
    
    // ========================================
    // CHALLENGE 2: MENU-DRIVEN CALCULATOR WITH HISTORY
    // ========================================
    cout << "\n\n";
    cout << "=== CHALLENGE 2: SMART CALCULATOR ===" << endl;
    cout << "Features: Basic operations + History + Statistics" << endl;
    cout << "=====================================" << endl;
    
    vector<double> calculation_history;
    vector<string> operation_history;
    double memory = 0.0;
    int total_calculations = 0;
    
    while (true) {
        // Display menu
        cout << "\n--- CALCULATOR MENU ---" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Power (x^y)" << endl;
        cout << "6. Show History" << endl;
        cout << "7. Show Statistics" << endl;
        cout << "8. Clear History" << endl;
        cout << "9. Memory Operations" << endl;
        cout << "0. Exit Calculator" << endl;
        cout << "Memory: " << memory << endl;
        cout << "----------------------" << endl;
        
        int choice;
        cout << "Choose operation (0-9): ";
        cin >> choice;
        
        // Input validation
        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number 0-9." << endl;
            continue;
        }
        
        // Exit condition
        if (choice == 0) {
            cout << "Calculator closing. Thanks for using!" << endl;
            break;
        }
        
        // Handle menu choices
        switch (choice) {
            case 1: case 2: case 3: case 4: case 5: {
                // Basic arithmetic operations
                double num1, num2, result;
                string operation_symbol;
                string operation_name;
                
                cout << "Enter first number: ";
                cin >> num1;
                if (!cin) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid number!" << endl;
                    break;
                }
                
                cout << "Enter second number: ";
                cin >> num2;
                if (!cin) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid number!" << endl;
                    break;
                }
                
                // Perform calculation based on choice
                bool valid_operation = true;
                switch (choice) {
                    case 1:
                        result = num1 + num2;
                        operation_symbol = "+";
                        operation_name = "Addition";
                        break;
                    case 2:
                        result = num1 - num2;
                        operation_symbol = "-";
                        operation_name = "Subtraction";
                        break;
                    case 3:
                        result = num1 * num2;
                        operation_symbol = "*";
                        operation_name = "Multiplication";
                        break;
                    case 4:
                        if (num2 == 0) {
                            cout << "Error: Division by zero!" << endl;
                            valid_operation = false;
                        } else {
                            result = num1 / num2;
                            operation_symbol = "/";
                            operation_name = "Division";
                        }
                        break;
                    case 5: {
                        // Simple power calculation (positive integer powers only)
                        if (num2 < 0 || num2 != (int)num2) {
                            cout << "Error: Only positive integer powers supported!" << endl;
                            valid_operation = false;
                        } else {
                            result = 1;
                            for (int i = 0; i < (int)num2; ++i) {
                                result *= num1;
                            }
                            operation_symbol = "^";
                            operation_name = "Power";
                        }
                        break;
                    }
                }
                
                if (valid_operation) {
                    cout << "\n" << operation_name << ": " << num1 << " " << operation_symbol 
                         << " " << num2 << " = " << result << endl;
                    
                    // Store in history
                    calculation_history.push_back(result);
                    operation_history.push_back(to_string(num1) + " " + operation_symbol + " " + to_string(num2) + " = " + to_string(result));
                    total_calculations++;
                    
                    // Ask if user wants to store in memory
                    char store_choice;
                    cout << "Store result in memory? (y/n): ";
                    cin >> store_choice;
                    if (store_choice == 'y' || store_choice == 'Y') {
                        memory = result;
                        cout << "Result stored in memory!" << endl;
                    }
                }
                break;
            }
            
            case 6: {
                // Show History
                cout << "\n--- CALCULATION HISTORY ---" << endl;
                if (operation_history.empty()) {
                    cout << "No calculations performed yet!" << endl;
                } else {
                    for (size_t i = 0; i < operation_history.size(); ++i) {
                        cout << (i + 1) << ". " << operation_history[i] << endl;
                    }
                }
                cout << "---------------------------" << endl;
                break;
            }
            
            case 7: {
                // Show Statistics
                cout << "\n--- CALCULATOR STATISTICS ---" << endl;
                cout << "Total calculations: " << total_calculations << endl;
                
                if (!calculation_history.empty()) {
                    // Find min and max results
                    auto minmax = minmax_element(calculation_history.begin(), calculation_history.end());
                    cout << "Smallest result: " << *minmax.first << endl;
                    cout << "Largest result: " << *minmax.second << endl;
                    
                    // Calculate average
                    double sum = 0;
                    for (double result : calculation_history) {
                        sum += result;
                    }
                    cout << "Average result: " << (sum / calculation_history.size()) << endl;
                } else {
                    cout << "No calculations to analyze!" << endl;
                }
                cout << "Current memory: " << memory << endl;
                cout << "-----------------------------" << endl;
                break;
            }
            
            case 8: {
                // Clear History
                char confirm;
                cout << "Are you sure you want to clear all history? (y/n): ";
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    calculation_history.clear();
                    operation_history.clear();
                    total_calculations = 0;
                    cout << "History cleared!" << endl;
                } else {
                    cout << "History preserved." << endl;
                }
                break;
            }
            
            case 9: {
                // Memory Operations
                cout << "\n--- MEMORY OPERATIONS ---" << endl;
                cout << "Current memory: " << memory << endl;
                cout << "1. Use memory value in calculation" << endl;
                cout << "2. Add to memory" << endl;
                cout << "3. Clear memory" << endl;
                cout << "4. Back to main menu" << endl;
                
                int mem_choice;
                cout << "Choose option (1-4): ";
                cin >> mem_choice;
                
                switch (mem_choice) {
                    case 1:
                        cout << "Memory value " << memory << " can be used as input in next calculation." << endl;
                        break;
                    case 2: {
                        double add_value;
                        cout << "Enter value to add to memory: ";
                        cin >> add_value;
                        if (cin) {
                            memory += add_value;
                            cout << "New memory value: " << memory << endl;
                        }
                        break;
                    }
                    case 3:
                        memory = 0.0;
                        cout << "Memory cleared!" << endl;
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Invalid option!" << endl;
                }
                break;
            }
            
            default:
                cout << "Invalid choice! Please select 0-9." << endl;
                break;
        }
    }
    
    // Final calculator statistics
    cout << "\n=== FINAL CALCULATOR REPORT ===" << endl;
    cout << "Total calculations performed: " << total_calculations << endl;
    cout << "Final memory value: " << memory << endl;
    cout << "===============================" << endl;
    
    return 0;
}
