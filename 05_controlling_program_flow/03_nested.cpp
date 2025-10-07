#include<iostream>
using namespace std;

int main(){
    cout << "=== NESTED IF STATEMENT EXAMPLE ===" << endl;
    cout << "=== STUDENT SCHOLARSHIP ELIGIBILITY CHECKER ===" << endl << endl;
    
    // Variables for student data
    int age, marks, family_income;
    char category; // 'G' for General, 'S' for SC/ST, 'O' for OBC
    
    // Get student information
    cout << "Enter student age: ";
    cin >> age;
    
    cout << "Enter marks (out of 100): ";
    cin >> marks;
    
    cout << "Enter family income (in thousands): ";
    cin >> family_income;
    
    cout << "Enter category (G for General, S for SC/ST, O for OBC): ";
    cin >> category;
    
    cout << endl << "=== CHECKING ELIGIBILITY ===" << endl;
    
    // NESTED IF LOGIC STARTS HERE
    // Level 1: Check basic age requirement
    if(age >= 18) {
        cout << "✓ Age requirement met (18+)" << endl;
        
        // Level 2: Check marks requirement (nested inside age check)
        if(marks >= 60) {
            cout << "✓ Marks requirement met (60+)" << endl;
            
            // Level 3: Check income requirement (nested inside marks check)
            if(family_income <= 300) {
                cout << "✓ Income requirement met (≤3 lakh)" << endl;
                
                // Level 4: Check category-wise criteria (nested inside income check)
                if(category == 'G' || category == 'g') {
                    cout << "Category: General" << endl;
                    
                    // Level 5: Additional criteria for General category
                    if(marks >= 85) {
                        cout << "🎉 SCHOLARSHIP APPROVED! (General - High Merit)" << endl;
                        cout << "Scholarship Amount: ₹50,000" << endl;
                    }
                    else if(marks >= 75) {
                        cout << "🎉 SCHOLARSHIP APPROVED! (General - Merit)" << endl;
                        cout << "Scholarship Amount: ₹30,000" << endl;
                    }
                    else {
                        cout << "❌ SCHOLARSHIP DENIED!" << endl;
                        cout << "Reason: General category needs minimum 75 marks" << endl;
                    }
                }
                else if(category == 'S' || category == 's') {
                    cout << "Category: SC/ST" << endl;
                    
                    // Level 5: Relaxed criteria for SC/ST
                    if(marks >= 70) {
                        cout << "🎉 SCHOLARSHIP APPROVED! (SC/ST - High Merit)" << endl;
                        cout << "Scholarship Amount: ₹60,000" << endl;
                    }
                    else {
                        cout << "🎉 SCHOLARSHIP APPROVED! (SC/ST - Basic)" << endl;
                        cout << "Scholarship Amount: ₹40,000" << endl;
                    }
                }
                else if(category == 'O' || category == 'o') {
                    cout << "Category: OBC" << endl;
                    
                    // Level 5: Moderate criteria for OBC
                    if(marks >= 80) {
                        cout << "🎉 SCHOLARSHIP APPROVED! (OBC - High Merit)" << endl;
                        cout << "Scholarship Amount: ₹45,000" << endl;
                    }
                    else if(marks >= 70) {
                        cout << "🎉 SCHOLARSHIP APPROVED! (OBC - Merit)" << endl;
                        cout << "Scholarship Amount: ₹35,000" << endl;
                    }
                    else {
                        cout << "❌ SCHOLARSHIP DENIED!" << endl;
                        cout << "Reason: OBC category needs minimum 70 marks" << endl;
                    }
                }
                else {
                    cout << "❌ INVALID CATEGORY!" << endl;
                    cout << "Please enter G, S, or O" << endl;
                }
            }
            else {
                cout << "❌ SCHOLARSHIP DENIED!" << endl;
                cout << "Reason: Family income too high (>" << family_income << " thousand)" << endl;
                cout << "Maximum allowed: 300 thousand" << endl;
            }
        }
        else {
            cout << "❌ SCHOLARSHIP DENIED!" << endl;
            cout << "Reason: Marks too low (" << marks << "/100)" << endl;
            cout << "Minimum required: 60 marks" << endl;
        }
    }
    else {
        cout << "❌ SCHOLARSHIP DENIED!" << endl;
        cout << "Reason: Age too low (" << age << " years)" << endl;
        cout << "Minimum required: 18 years" << endl;
    }
    
    cout << endl << "=== PROGRAM ENDED ===" << endl;
    
    return 0;
}
