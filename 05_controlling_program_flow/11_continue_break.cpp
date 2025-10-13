#include <iostream>
using namespace std;

int main() {
    cout << "=== CONTINUE and BREAK Statements Examples ===" << endl;
    
    // Example 1: Basic BREAK - Exit loop when condition is met
    cout << "\n1. BREAK Example - Find first number > 7:" << endl;
    for (int i = 1; i <= 15; i++) {
        if (i > 7) {
            cout << "Found number > 7: " << i << ", breaking loop!" << endl;
            break;  // Exit the loop immediately
        }
        cout << i << " ";
    }
    cout << "\nLoop ended due to break." << endl;
    
    // Example 2: Basic CONTINUE - Skip certain iterations
    cout << "\n2. CONTINUE Example - Skip even numbers:" << endl;
    cout << "Odd numbers from 1 to 10: ";
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {  // If number is even
            continue;      // Skip rest of loop body, go to next iteration
        }
        cout << i << " ";  // This only prints for odd numbers
    }
    cout << endl;
    
    // Example 3: CONTINUE in input validation
    cout << "\n3. CONTINUE for Input Validation:" << endl;
    cout << "Enter 3 positive numbers (negative numbers will be skipped):" << endl;
    int count = 0;
    int number;
    
    while (count < 3) {
        cout << "Enter number " << (count + 1) << ": ";
        cin >> number;
        
        if (number <= 0) {
            cout << "Negative number ignored. Try again." << endl;
            continue;  // Skip incrementing count, ask for input again
        }
        
        cout << "Valid number: " << number << endl;
        count++;  // Only increment for valid positive numbers
    }
    
    // Example 4: BREAK in menu system
    cout << "\n4. BREAK in Menu System:" << endl;
    int choice;
    
    while (true) {  // Infinite loop
        cout << "\n--- Simple Calculator ---" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice (1-3): ";
        cin >> choice;
        
        if (choice == 3) {
            cout << "Goodbye!" << endl;
            break;  // Exit the infinite loop
        }
        
        if (choice == 1) {
            cout << "Addition selected (demo only)" << endl;
        } else if (choice == 2) {
            cout << "Subtraction selected (demo only)" << endl;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
    
    // Example 5: Combined CONTINUE and BREAK
    cout << "\n5. Combined Example - Process numbers until 0, skip negatives:" << endl;
    cout << "Enter numbers (0 to stop, negative numbers ignored):" << endl;
    
    int sum = 0;
    int num;
    
    while (true) {
        cout << "Enter number: ";
        cin >> num;
        
        if (num == 0) {
            cout << "Zero entered. Stopping..." << endl;
            break;  // Exit loop when 0 is entered
        }
        
        if (num < 0) {
            cout << "Negative number ignored." << endl;
            continue;  // Skip processing, go to next iteration
        }
        
        // This code only runs for positive numbers
        sum += num;
        cout << "Added " << num << " to sum. Current sum: " << sum << endl;
    }
    
    cout << "Final sum of positive numbers: " << sum << endl;
    
    // Example 6: Nested loops with BREAK and CONTINUE
    cout << "\n6. Nested Loops Example - Finding pairs:" << endl;
    cout << "Finding first pair (i,j) where i+j=10:" << endl;
    
    bool found = false;
    
    for (int i = 1; i <= 10 && !found; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i + j == 10) {
                cout << "Found pair: (" << i << "," << j << ")" << endl;
                found = true;
                break;  // Break inner loop
            }
        }
        // break only affects the innermost loop
    }
    
    return 0;
}
