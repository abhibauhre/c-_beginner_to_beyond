#include<iostream>
using namespace std;

int main(){

    
    
    cout << " Age Check:" << endl;
    int age = 20;
    string status = (age >= 18) ? "Adult" : "Minor";
    cout << "Age: " << age << " - Status: " << status << endl;
    cout << "Logic: (age >= 18) ? \"Adult\" : \"Minor\"" << endl;
    cout << endl;
    
    cout << "Find Maximum:" << endl;
    int a = 15, b = 25;
    int max = (a > b) ? a : b;
    cout << "Numbers: " << a << " and " << b << endl;
    cout << "Maximum: " << max << endl;
    cout << "Logic: (a > b) ? a : b" << endl;
    cout << endl;
    
    cout << "Interactive Example:" << endl;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    string result = (num % 2 == 0) ? "Even" : "Odd";
    cout << "Number " << num << " is " << result << endl;
    
    return 0;

}
