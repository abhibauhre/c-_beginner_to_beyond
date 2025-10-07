#include<iostream>
using namespace std;

int main(){
    cout << "=== STUDENT GRADE CALCULATOR ===" << endl;
    
    int marks;
    cout << "Enter your marks (0-100): ";
    cin >> marks;
    
    
    if(marks < 0 || marks > 100) {
        cout << "Invalid marks! Please enter between 0-100." << endl;
    }
    else if(marks >= 90) {
        cout << "Grade: A+ (Excellent!)" << endl;
        cout << "Congratulations! Outstanding performance!" << endl;
    }
    else if(marks >= 80) {
        cout << "Grade: A (Very Good)" << endl;
        cout << "Great job! Keep it up!" << endl;
    }
    else if(marks >= 70) {
        cout << "Grade: B (Good)" << endl;
        cout << "Good work! Try to improve more." << endl;
    }
    else if(marks >= 60) {
        cout << "Grade: C (Average)" << endl;
        cout << "You passed, but there's room for improvement." << endl;
    }
    else if(marks >= 50) {
        cout << "Grade: D (Below Average)" << endl;
        cout << "You need to work harder next time." << endl;
    }
    else {
        cout << "Grade: F (Fail)" << endl;
        cout << "Sorry, you failed. Please study more and try again." << endl;
    }
    

    if(marks >= 60) {
        cout << "Status: PASSED ✓" << endl;
    }
    else if(marks >= 0) {
        cout << "Status: FAILED ✗" << endl;
    }
    
    cout << "\nYour marks: " << marks << "/100" << endl;
    
    return 0;
}