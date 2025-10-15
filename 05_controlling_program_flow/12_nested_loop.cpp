#include <iostream>
using namespace std;

int main() {
    cout << "=== NESTED LOOPS EXPLAINED ===" << endl;
    cout << "A nested loop is a loop inside another loop" << endl;
    cout << "The inner loop runs COMPLETELY for each iteration of the outer loop" << endl << endl;

    // PROGRAM 1: MULTIPLICATION TABLE (Basic Example)
    cout << "PROGRAM 1: MULTIPLICATION TABLE (2x2 to 5x5)" << endl;
    cout << "Step by step:" << endl;
    cout << "1. Outer loop: controls which table (2, 3, 4, 5)" << endl;
    cout << "2. Inner loop: multiplies by 1, 2, 3, 4, 5" << endl;
    cout << "3. For each table, inner loop runs 5 times" << endl << endl;
    
    for (int table = 2; table <= 5; table++) {           // Outer loop: table number
        cout << "Table of " << table << ":" << endl;
        
        for (int multiply = 1; multiply <= 5; multiply++) { // Inner loop: multiplier
            cout << table << " x " << multiply << " = " << (table * multiply) << endl;
        }
        cout << "---" << endl; // Separator between tables
    }

    cout << endl << "HOW IT WORKS:" << endl;
    cout << "- When table=2: inner loop runs 5 times (2x1, 2x2, 2x3, 2x4, 2x5)" << endl;
    cout << "- When table=3: inner loop runs 5 times again (3x1, 3x2, 3x3, 3x4, 3x5)" << endl;
    cout << "- And so on..." << endl << endl;

    // PROGRAM 2: PATTERN PRINTING (Advanced Example)
    cout << "PROGRAM 2: STAR PATTERN (Triangle)" << endl;
    cout << "Step by step:" << endl;
    cout << "1. Outer loop: controls number of rows (1 to 5)" << endl;
    cout << "2. Inner loop: prints stars for each row" << endl;
    cout << "3. Row 1 has 1 star, Row 2 has 2 stars, etc." << endl << endl;

    for (int row = 1; row <= 5; row++) {          // Outer loop: row number
        cout << "Row " << row << ": ";
        
        for (int star = 1; star <= row; star++) {  // Inner loop: print stars
            cout << "* ";
        }
        cout << endl; // Move to next line after each row
    }

    cout << endl << "EXECUTION BREAKDOWN:" << endl;
    cout << "Row 1: inner loop runs 1 time  -> *" << endl;
    cout << "Row 2: inner loop runs 2 times -> * *" << endl;
    cout << "Row 3: inner loop runs 3 times -> * * *" << endl;
    cout << "Row 4: inner loop runs 4 times -> * * * *" << endl;
    cout << "Row 5: inner loop runs 5 times -> * * * * *" << endl << endl;

    // BONUS: Show execution count
    cout << "TOTAL ITERATIONS:" << endl;
    int total_iterations = 0;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            total_iterations++;
        }
    }
    cout << "The nested loop executed " << total_iterations << " times total" << endl;
    cout << "(1 + 2 + 3 + 4 + 5 = 15 iterations)" << endl;

    return 0;
}
