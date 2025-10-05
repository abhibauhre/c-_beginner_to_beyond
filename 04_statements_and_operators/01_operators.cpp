#include<iostream>
#include<string>
using namespace std;

int main(){
    cout << "=== C++ OPERATORS COMPLETE GUIDE ===" << endl << endl;
    
    // ===============================
    // 1. ARITHMETIC OPERATORS (+, -, *, /, %)
    // ===============================
    cout << "1. ARITHMETIC OPERATORS:" << endl;
    int a = 15, b = 4;
    
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b = " << (a + b) << " (Addition)" << endl;
    cout << "a - b = " << (a - b) << " (Subtraction)" << endl;
    cout << "a * b = " << (a * b) << " (Multiplication)" << endl;
    cout << "a / b = " << (a / b) << " (Division)" << endl;
    cout << "a % b = " << (a % b) << " (Modulus - Remainder)" << endl;
    cout << endl;
    
    // ===============================
    // 2. ASSIGNMENT OPERATORS (=, +=, -=, *=, /=, %=)
    // ===============================
    cout << "2. ASSIGNMENT OPERATORS:" << endl;
    int x = 10;
    cout << "Initial x = " << x << endl;
    
    x += 5;  // x = x + 5
    cout << "After x += 5: " << x << endl;
    
    x -= 3;  // x = x - 3
    cout << "After x -= 3: " << x << endl;
    
    x *= 2;  // x = x * 2
    cout << "After x *= 2: " << x << endl;
    
    x /= 4;  // x = x / 4
    cout << "After x /= 4: " << x << endl;
    cout << endl;
    
    // ===============================
    // 3. COMPARISON/RELATIONAL OPERATORS (==, !=, <, >, <=, >=)
    // ===============================
    cout << "3. COMPARISON OPERATORS:" << endl;
    int num1 = 10, num2 = 20;
    
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    cout << "num1 == num2: " << (num1 == num2) << " (Equal to)" << endl;
    cout << "num1 != num2: " << (num1 != num2) << " (Not equal to)" << endl;
    cout << "num1 < num2: " << (num1 < num2) << " (Less than)" << endl;
    cout << "num1 > num2: " << (num1 > num2) << " (Greater than)" << endl;
    cout << "num1 <= num2: " << (num1 <= num2) << " (Less than or equal)" << endl;
    cout << "num1 >= num2: " << (num1 >= num2) << " (Greater than or equal)" << endl;
    cout << endl;
    
    // ===============================
    // 4. LOGICAL OPERATORS (&&, ||, !)
    // ===============================
    cout << "4. LOGICAL OPERATORS:" << endl;
    bool p = true, q = false;
    
    cout << "p = " << p << ", q = " << q << endl;
    cout << "p && q: " << (p && q) << " (Logical AND)" << endl;
    cout << "p || q: " << (p || q) << " (Logical OR)" << endl;
    cout << "!p: " << (!p) << " (Logical NOT)" << endl;
    cout << "!q: " << (!q) << " (Logical NOT)" << endl;
    cout << endl;
    
    // ===============================
    // 5. INCREMENT/DECREMENT OPERATORS (++, --)
    // ===============================
    cout << "5. INCREMENT/DECREMENT OPERATORS:" << endl;
    int count = 5;
    
    cout << "Initial count = " << count << endl;
    cout << "Pre-increment ++count: " << (++count) << " (count becomes 6 first, then used)" << endl;
    cout << "Post-increment count++: " << (count++) << " (count used first as 6, then becomes 7)" << endl;
    cout << "Current count = " << count << endl;
    
    cout << "Pre-decrement --count: " << (--count) << " (count becomes 6 first, then used)" << endl;
    cout << "Post-decrement count--: " << (count--) << " (count used first as 6, then becomes 5)" << endl;
    cout << "Final count = " << count << endl;
    cout << endl;
    
    // ===============================
    // 6. BITWISE OPERATORS (&, |, ^, ~, <<, >>)
    // ===============================
    cout << "6. BITWISE OPERATORS:" << endl;
    int bit1 = 12;  // Binary: 1100
    int bit2 = 10;  // Binary: 1010
    
    cout << "bit1 = " << bit1 << " (Binary: 1100)" << endl;
    cout << "bit2 = " << bit2 << " (Binary: 1010)" << endl;
    cout << "bit1 & bit2 = " << (bit1 & bit2) << " (Bitwise AND)" << endl;
    cout << "bit1 | bit2 = " << (bit1 | bit2) << " (Bitwise OR)" << endl;
    cout << "bit1 ^ bit2 = " << (bit1 ^ bit2) << " (Bitwise XOR)" << endl;
    cout << "~bit1 = " << (~bit1) << " (Bitwise NOT)" << endl;
    cout << "bit1 << 1 = " << (bit1 << 1) << " (Left shift)" << endl;
    cout << "bit1 >> 1 = " << (bit1 >> 1) << " (Right shift)" << endl;
    cout << endl;
    
    // ===============================
    // 7. CONDITIONAL/TERNARY OPERATOR (? :)
    // ===============================
    cout << "7. CONDITIONAL (TERNARY) OPERATOR:" << endl;
    int age = 18;
    string status = (age >= 18) ? "Adult" : "Minor";
    
    cout << "Age = " << age << endl;
    cout << "Status: " << status << " (Using ternary operator)" << endl;
    
    int max_num = (num1 > num2) ? num1 : num2;
    cout << "Maximum of " << num1 << " and " << num2 << " is: " << max_num << endl;
    cout << endl;
    
    // ===============================
    // 8. SIZEOF OPERATOR
    // ===============================
    cout << "8. SIZEOF OPERATOR:" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << "Size of bool: " << sizeof(bool) << " byte" << endl;
    cout << endl;
    
    // ===============================
    // 9. POINTER OPERATORS (*, &)
    // ===============================
    cout << "9. POINTER OPERATORS:" << endl;
    int value = 42;
    int* ptr = &value;  // & = address-of operator
    
    cout << "value = " << value << endl;
    cout << "Address of value (&value): " << &value << endl;
    cout << "ptr = " << ptr << " (stores address)" << endl;
    cout << "*ptr = " << *ptr << " (* = dereference operator)" << endl;
    cout << endl;
    
    // ===============================
    // 10. MEMBER ACCESS OPERATORS (., ->)
    // ===============================
    cout << "10. MEMBER ACCESS OPERATORS:" << endl;
    string text = "Hello C++";
    cout << "String: " << text << endl;
    cout << "Length using dot operator: " << text.length() << endl;
    cout << "First character: " << text[0] << endl;
    cout << endl;
    
    // ===============================
    // REAL WORLD EXAMPLE
    // ===============================
    cout << "=== REAL WORLD EXAMPLE: CALCULATOR ===" << endl;
    double num_a, num_b;
    char operation;
    
    cout << "Enter first number: ";
    cin >> num_a;
    cout << "Enter operator (+, -, *, /): ";
    cin >> operation;
    cout << "Enter second number: ";
    cin >> num_b;
    
    double result = 0;
    bool valid = true;
    
    // Using switch with operators
    switch(operation) {
        case '+':
            result = num_a + num_b;
            break;
        case '-':
            result = num_a - num_b;
            break;
        case '*':
            result = num_a * num_b;
            break;
        case '/':
            result = (num_b != 0) ? (num_a / num_b) : 0;
            if(num_b == 0) {
                cout << "Error: Division by zero!" << endl;
                valid = false;
            }
            break;
        default:
            cout << "Invalid operator!" << endl;
            valid = false;
    }
    
    if(valid) {
        cout << num_a << " " << operation << " " << num_b << " = " << result << endl;
    }
    
    return 0;
}
