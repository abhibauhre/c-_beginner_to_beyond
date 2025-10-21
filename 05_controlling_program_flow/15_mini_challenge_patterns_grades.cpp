/*
    MINI CHALLENGE: Pattern Generator & Grade Analyzer
    
    Create a program that combines two mini-challenges:
    
    PART A - PATTERN GENERATOR:
    1. Ask user for a number (1-10)
    2. Generate different patterns based on user choice:
       - Right triangle (*)
       - Inverted triangle (*)
       - Number pyramid
       - Diamond pattern
    
    PART B - GRADE ANALYZER:
    1. Ask user how many students' grades to enter
    2. Input grades and calculate:
       - Average grade
       - Highest and lowest grades
       - Letter grade distribution (A, B, C, D, F)
       - Pass/fail count (60+ is passing)
    
    Use nested loops, if-else chains, and switch statements
    
    BONUS:
    - Add input validation
    - Allow user to repeat either section
    - Add more complex patterns
*/

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Function prototypes (we'll keep it simple with main only)
void displayPatternMenu();
void generateRightTriangle(int size);
void generateInvertedTriangle(int size);
void generateNumberPyramid(int size);
void generateDiamond(int size);
void analyzeGrades();

int main() {
    
    int mainChoice = 0;
    bool continueProgram = true;
    
    cout << "=== Pattern Generator & Grade Analyzer ===" << endl;
    cout << "Welcome to the dual-purpose program!" << endl << endl;
    
    while (continueProgram) {
        
        // Main menu
        cout << "--- Main Menu ---" << endl;
        cout << "1. Pattern Generator" << endl;
        cout << "2. Grade Analyzer" << endl;
        cout << "3. Exit Program" << endl;
        cout << "Choose an option (1-3): ";
        cin >> mainChoice;
        cout << endl;
        
        switch (mainChoice) {
            case 1: {
                // Pattern Generator Section
                int patternChoice, size;
                bool validInput = false;
                
                cout << "=== PATTERN GENERATOR ===" << endl;
                
                // Get pattern size with validation
                do {
                    cout << "Enter pattern size (1-10): ";
                    cin >> size;
                    
                    if (size >= 1 && size <= 10) {
                        validInput = true;
                    } else {
                        cout << "Invalid size! Please enter 1-10." << endl;
                    }
                } while (!validInput);
                
                // Pattern menu
                cout << "\nChoose pattern type:" << endl;
                cout << "1. Right Triangle" << endl;
                cout << "2. Inverted Triangle" << endl;
                cout << "3. Number Pyramid" << endl;
                cout << "4. Diamond Pattern" << endl;
                cout << "Enter choice (1-4): ";
                cin >> patternChoice;
                cout << endl;
                
                // Generate selected pattern
                switch (patternChoice) {
                    case 1:
                        cout << "Right Triangle Pattern:" << endl;
                        for (int i = 1; i <= size; i++) {
                            for (int j = 1; j <= i; j++) {
                                cout << "* ";
                            }
                            cout << endl;
                        }
                        break;
                        
                    case 2:
                        cout << "Inverted Triangle Pattern:" << endl;
                        for (int i = size; i >= 1; i--) {
                            for (int j = 1; j <= i; j++) {
                                cout << "* ";
                            }
                            cout << endl;
                        }
                        break;
                        
                    case 3:
                        cout << "Number Pyramid Pattern:" << endl;
                        for (int i = 1; i <= size; i++) {
                            // Print spaces
                            for (int j = 1; j <= (size - i); j++) {
                                cout << " ";
                            }
                            // Print numbers
                            for (int k = 1; k <= i; k++) {
                                cout << k << " ";
                            }
                            cout << endl;
                        }
                        break;
                        
                    case 4:
                        cout << "Diamond Pattern:" << endl;
                        // Upper half
                        for (int i = 1; i <= size; i++) {
                            for (int j = 1; j <= (size - i); j++) {
                                cout << " ";
                            }
                            for (int k = 1; k <= i; k++) {
                                cout << "* ";
                            }
                            cout << endl;
                        }
                        // Lower half
                        for (int i = size - 1; i >= 1; i--) {
                            for (int j = 1; j <= (size - i); j++) {
                                cout << " ";
                            }
                            for (int k = 1; k <= i; k++) {
                                cout << "* ";
                            }
                            cout << endl;
                        }
                        break;
                        
                    default:
                        cout << "Invalid pattern choice!" << endl;
                        break;
                }
                break;
            }
            
            case 2: {
                // Grade Analyzer Section
                cout << "=== GRADE ANALYZER ===" << endl;
                
                int numStudents;
                cout << "How many students' grades to analyze? ";
                cin >> numStudents;
                
                if (numStudents <= 0) {
                    cout << "Invalid number of students!" << endl;
                    break;
                }
                
                vector<double> grades(numStudents);
                double sum = 0, highest = 0, lowest = 100;
                int aCount = 0, bCount = 0, cCount = 0, dCount = 0, fCount = 0;
                int passCount = 0, failCount = 0;
                
                // Input grades
                for (int i = 0; i < numStudents; i++) {
                    cout << "Enter grade for student " << (i + 1) << ": ";
                    cin >> grades[i];
                    
                    // Validate grade range
                    if (grades[i] < 0 || grades[i] > 100) {
                        cout << "Invalid grade! Using 0." << endl;
                        grades[i] = 0;
                    }
                    
                    sum += grades[i];
                    
                    // Track highest and lowest
                    if (grades[i] > highest) highest = grades[i];
                    if (grades[i] < lowest) lowest = grades[i];
                    
                    // Count letter grades using if-else chain
                    if (grades[i] >= 90) {
                        aCount++;
                    } else if (grades[i] >= 80) {
                        bCount++;
                    } else if (grades[i] >= 70) {
                        cCount++;
                    } else if (grades[i] >= 60) {
                        dCount++;
                    } else {
                        fCount++;
                    }
                    
                    // Count pass/fail
                    if (grades[i] >= 60) {
                        passCount++;
                    } else {
                        failCount++;
                    }
                }
                
                // Calculate and display results
                double average = sum / numStudents;
                
                cout << endl << "=== ANALYSIS RESULTS ===" << endl;
                cout << fixed << setprecision(2);
                cout << "Average Grade: " << average << endl;
                cout << "Highest Grade: " << highest << endl;
                cout << "Lowest Grade: " << lowest << endl;
                cout << endl;
                
                cout << "Letter Grade Distribution:" << endl;
                cout << "A (90-100): " << aCount << " students" << endl;
                cout << "B (80-89):  " << bCount << " students" << endl;
                cout << "C (70-79):  " << cCount << " students" << endl;
                cout << "D (60-69):  " << dCount << " students" << endl;
                cout << "F (0-59):   " << fCount << " students" << endl;
                cout << endl;
                
                cout << "Pass/Fail Summary:" << endl;
                cout << "Passed (60+): " << passCount << " students" << endl;
                cout << "Failed (<60): " << failCount << " students" << endl;
                cout << "Pass Rate: " << (passCount * 100.0 / numStudents) << "%" << endl;
                
                break;
            }
            
            case 3:
                continueProgram = false;
                cout << "Thank you for using the program!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please select 1-3." << endl;
                break;
        }
        
        // Pause before showing menu again
        if (continueProgram) {
            cout << endl << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            cout << endl;
        }
    }
    
    return 0;
}

/*
    SOLUTION EXPLANATION:
    
    This dual-purpose challenge demonstrates advanced control flow:
    
    1. NESTED LOOPS:
       - Pattern generation uses nested for loops
       - Outer loop controls rows, inner loops control columns/spaces
       - Different nesting patterns create various shapes
    
    2. LOOP VARIATIONS:
       - For loops with different increments (i++, i--)
       - Multiple inner loops for complex patterns
       - Loops with conditional logic inside
    
    3. DATA PROCESSING:
       - Grade analysis uses loops for input and calculation
       - Running totals and comparisons within loops
       - Array/vector processing with loops
    
    4. INPUT VALIDATION:
       - Do-while loops for input validation
       - Range checking with if-else statements
       - Error handling and user feedback
    
    5. SWITCH STATEMENTS:
       - Menu-driven program structure
       - Multiple switch levels (main menu + submenu)
       - Case-by-case pattern selection
    
    6. CONDITIONAL LOGIC:
       - If-else chains for grade categorization
       - Comparison operations for min/max tracking
       - Boolean logic for pass/fail determination
    
    CONTROL FLOW CONCEPTS COVERED:
    - Nested for loops (2-3 levels deep)
    - Do-while loops for validation
    - Switch statements with multiple levels
    - If-else chains for categorization
    - Break and continue concepts
    - Loop counters and accumulators
    
    DIFFICULTY: Intermediate
    - Complex nested loop patterns
    - Data analysis and statistics
    - Multiple program sections
    - Input validation and error handling
*/