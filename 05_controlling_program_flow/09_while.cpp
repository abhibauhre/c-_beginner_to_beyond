#include<iostream>
#include<limits>
using namespace std;
int main(){
    // int num{};
    // cout<<"Enter a positive number :"<<endl;
    // cin>>num;
    // while(num > 0){
    //     cout<<num<<endl;
    //     --num;
    // }
    // cout<<"blast of "<<endl;

    // int num{};
    // int i{1};
    // cout<<"Enter a number "<<endl;
    // cin>>num;
    // while(num >= i){
    //     cout<<i<<endl;
    //     ++i;
    bool done{false};
    int number{0};
    while(!done){
        cout << "Enter a number between 1 and 5 (inclusive): " << endl;
        cin >> number;

       
        if (number <= 1 || number >= 5) {
            cout << "Out of range. Try again." << endl;
        } else {
            cout << "Done, thanks. You entered: " << number << endl;
            done = true;
        }
    }

    return 0;
}