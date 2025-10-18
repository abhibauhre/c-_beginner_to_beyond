/*
 * Solution Challenge: Simple ATM Machine
 * 
 * This program demonstrates:
 * - while loop for menu system
 * - if-else statements for decision making
 * - switch statement for menu options
 * - input validation
 * - break and continue statements
 * 
 * Challenge: Create a simple ATM that allows:
 * 1. Check Balance
 * 2. Deposit Money
 * 3. Withdraw Money
 * 4. Exit
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Initial account setup
    double balance = 1000.0;  // Starting balance
    int choice = 0;
    bool quit = false;
    
    cout << "====== WELCOME TO SIMPLE ATM ======" << endl;
    cout << "Your initial balance is: $" << fixed << setprecision(2) << balance << endl;
    cout << "====================================" << endl << endl;
    
    // Main ATM loop
    while (!quit) {
        // Display menu
        cout << "\n--- ATM MENU ---" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        // Input validation
        if (!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;  // Skip rest of loop and ask again
        }
        
        // Process menu choice
        switch (choice) {
            case 1: {
                // Check Balance
                cout << "\nYour current balance is: $" << fixed << setprecision(2) << balance << endl;
                break;
            }
            
            case 2: {
                // Deposit Money
                double deposit = 0.0;
                cout << "\nEnter amount to deposit: $";
                cin >> deposit;
                
                if (!cin || deposit <= 0) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid amount! Please enter a positive number." << endl;
                    break;  // Exit this case
                }
                
                balance += deposit;
                cout << "Deposit successful!" << endl;
                cout << "New balance: $" << fixed << setprecision(2) << balance << endl;
                break;
            }
            
            case 3: {
                // Withdraw Money
                double withdraw = 0.0;
                cout << "\nEnter amount to withdraw: $";
                cin >> withdraw;
                
                if (!cin || withdraw <= 0) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid amount! Please enter a positive number." << endl;
                    break;  // Exit this case
                }
                
                if (withdraw > balance) {
                    cout << "Insufficient funds! Your balance is: $" << fixed << setprecision(2) << balance << endl;
                } else {
                    balance -= withdraw;
                    cout << "Withdrawal successful!" << endl;
                    cout << "New balance: $" << fixed << setprecision(2) << balance << endl;
                }
                break;
            }
            
            case 4: {
                // Exit
                cout << "\nThank you for using Simple ATM!" << endl;
                cout << "Final balance: $" << fixed << setprecision(2) << balance << endl;
                cout << "Have a great day!" << endl;
                quit = true;  // This will exit the while loop
                break;
            }
            
            default: {
                // Invalid menu choice
                cout << "\nInvalid choice! Please select 1-4." << endl;
                break;
            }
        }
    }
    
    return 0;
}

/*
 * STEP-BY-STEP EXPLANATION:
 * 
 * 1. VARIABLES SETUP:
 *    - balance: stores current account balance
 *    - choice: stores user's menu selection
 *    - quit: boolean flag to control main loop
 * 
 * 2. MAIN WHILE LOOP:
 *    - Runs while (!quit) - continues until user chooses to exit
 *    - Shows menu options every iteration
 * 
 * 3. INPUT VALIDATION:
 *    - Checks if cin failed (non-numeric input)
 *    - Uses continue to skip rest of loop and ask again
 * 
 * 4. SWITCH STATEMENT:
 *    - Handles each menu option (1-4)
 *    - Uses break to exit each case
 *    - Default case handles invalid choices
 * 
 * 5. NESTED IF-ELSE:
 *    - Inside cases 2 and 3 for amount validation
 *    - Checks for positive amounts and sufficient funds
 * 
 * 6. BREAK vs CONTINUE:
 *    - break: exits current case or loop
 *    - continue: skips rest of loop iteration
 * 
 * CONCEPTS DEMONSTRATED:
 * ✓ while loop with condition
 * ✓ if-else statements
 * ✓ switch-case with break
 * ✓ input validation
 * ✓ continue for error handling
 * ✓ break for exit conditions
 * ✓ formatted output with setprecision
 * ✓ boolean flags for loop control
 */
