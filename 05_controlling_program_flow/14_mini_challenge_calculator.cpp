/*
    MINI CHALLENGE: Simple Menu-Driven Calculator
    
    Create a calculator program with the following requirements:
    
    1. Display a menu with options:
       - Addition (+)
       - Subtraction (-)
       - Multiplication (*)
       - Division (/)
       - Exit
    
    2. Keep showing the menu until user chooses to exit
    3. Perform the selected operation on two user-input numbers
    4. Handle division by zero error
    5. Display the result and ask if user wants to continue
    6. Use appropriate control flow structures
    
    BONUS:
    - Add input validation for menu choices
    - Keep a running total/history of calculations
    - Add more operations (power, modulus, etc.)
*/

#include <iostream>
#include <iomanip>  // for formatting output

using namespace std;

int main() {
    
    // Program variables
    int choice = 0;
    double num1, num2, result;
    bool continueProgram = true;
    int calculationsCount = 0;
    
    cout << "=== Simple Calculator ===" << endl;
    cout << "Welcome to the menu-driven calculator!" << endl << endl;
    
    // Main program loop
    while (continueProgram) {
        
        // Display menu
        cout << "--- Calculator Menu ---" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        
        cin >> choice;
        cout << endl;
        
        // Process menu choice using switch statement
        switch (choice) {
            case 1:  // Addition
            case 2:  // Subtraction  
            case 3:  // Multiplication
            case 4:  // Division
                {
                    // Get numbers from user
                    cout << "Enter first number: ";
                    cin >> num1;
                    cout << "Enter second number: ";
                    cin >> num2;
                    
                    // Perform calculation based on choice
                    if (choice == 1) {
                        result = num1 + num2;
                        cout << fixed << setprecision(2);
                        cout << num1 << " + " << num2 << " = " << result << endl;
                    } else if (choice == 2) {
                        result = num1 - num2;
                        cout << fixed << setprecision(2);
                        cout << num1 << " - " << num2 << " = " << result << endl;
                    } else if (choice == 3) {
                        result = num1 * num2;
                        cout << fixed << setprecision(2);
                        cout << num1 << " * " << num2 << " = " << result << endl;
                    } else if (choice == 4) {
                        // Handle division by zero
                        if (num2 != 0) {
                            result = num1 / num2;
                            cout << fixed << setprecision(2);
                            cout << num1 << " / " << num2 << " = " << result << endl;
                        } else {
                            cout << "Error: Division by zero is not allowed!" << endl;
                            break;  // Skip incrementing calculation count
                        }
                    }
                    
                    calculationsCount++;
                    cout << endl;
                }
                break;
                
            case 5:  // Exit
                continueProgram = false;
                cout << "Thank you for using the calculator!" << endl;
                break;
                
            default:  // Invalid choice
                cout << "Invalid choice! Please select 1-5." << endl;
                break;
        }
        
        // Add spacing between operations
        if (continueProgram && choice >= 1 && choice <= 4) {
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            cout << endl;
        }
    }
    
    // Display final statistics
    cout << endl << "=== Session Summary ===" << endl;
    cout << "Total calculations performed: " << calculationsCount << endl;
    
    if (calculationsCount > 0) {
        if (calculationsCount == 1) {
            cout << "Great start! Try more operations next time." << endl;
        } else if (calculationsCount <= 5) {
            cout << "Good practice with basic calculations!" << endl;
        } else {
            cout << "Excellent! You're getting comfortable with the calculator." << endl;
        }
    }
    
    cout << "Goodbye!" << endl;
    
    return 0;
}

/*
    SOLUTION EXPLANATION:
    
    This mini challenge demonstrates:
    
    1. WHILE LOOP:
       - Main program loop that continues until user exits
       - Boolean flag (continueProgram) controls loop execution
    
    2. SWITCH STATEMENT:
       - Menu-driven program structure
       - Multiple cases with fall-through for similar operations
       - Default case for error handling
    
    3. IF-ELSE CHAINS:
       - Nested inside switch cases for specific operations
       - Division by zero validation
       - Result formatting and display
    
    4. BREAK STATEMENTS:
       - Used to exit switch cases
       - Early exit from case when division by zero occurs
    
    5. INPUT/OUTPUT:
       - Menu display and user input handling
       - Formatted output using setprecision
    
    6. VARIABLES & SCOPE:
       - Local variables within switch case blocks
       - Counter for tracking calculations
    
    CONTROL FLOW FEATURES USED:
    - while loop for program continuation
    - switch statement for menu selection
    - if-else for operation logic
    - break for case exits
    - Boolean flags for program control
    
    DIFFICULTY: Beginner to Intermediate
    - Simple menu system
    - Basic arithmetic operations
    - Error handling concepts
    - Program state management
*/