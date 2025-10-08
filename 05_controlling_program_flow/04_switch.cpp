#include<iostream>

using namespace std;
int main(){
    char letter_grade{};
    cout<<"Enter a lettere grade which are you expecting:"<<endl;
    cin>>letter_grade;
    switch(letter_grade){
        case 'a':
        case 'A':
        cout<<"you need 90 or above"<<endl;
        break;
        case 'b':
        case 'B':
        cout<<"you need 80 or above : "<<endl;
        break;
        case 'c':
        case 'C':
        cout<<"you need 70 or above :"<<endl;
        break;
        case 'd':
        case 'D':
        cout<<"you need 60 or above :"<<endl;
        break;
        case 'f':
        case 'F':
        {
            char confirm{};
            cout << "Are you sure? Type Y or N: ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y')// if single statement after if no bracket needed
                cout << "You didn't do study hard enough!" << endl;
            else if (confirm == 'n' || confirm == 'N')
                cout << "Go and study harder!" << endl;
            else
                cout << "Please type valid input (Y/N)" << endl;
            break;
        }
        default :
            cout << "Please input valid grade (A, B, C, D, F)!" << endl;
    }
    
    return 0;
}