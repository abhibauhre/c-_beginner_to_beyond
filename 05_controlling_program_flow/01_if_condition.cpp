#include<iostream>
using namespace std;

int main(){
    int min{10}, max{100}; 
    int num{0};
    
    cout << "Enter a value between " << min << " and " << max << ": ";
    cin >> num;

    if(num >= min){
        cout<<num<<" "<<"is greater than "<<min<<endl;

        int diff{num - min};
        cout<<"Difference between "<<num<<" and "<<min<<" is "<<diff<<endl;
    }
    if(num <= max){
        cout << num << " is less than equal to " << max << endl;
        
        int diff{max - num};  
        cout << "Difference between " << max << " and " << num << " is " << diff << endl;
    }
    if(num >= min && num <= max){
        cout<<num<<" "<<"is in range"<<endl;
    }
    if(num < min || num > max){
        cout<<num<<" "<<"is out of range"<<endl;
    }

}