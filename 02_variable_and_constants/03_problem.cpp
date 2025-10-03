#include<iostream>
using namespace std;

int main(){
    int room{0}; 

    cout << "Hello welcome to abhi carpet cleaning service" << endl;
    cout << "How many rooms do you want clean: ";
    cin >> room;
    cout<<"the number of room :"<<room<<endl;
    cout<<"the cost of room cleaning :"<<30 * room <<endl;
    cout<<"Tax :"<<30 * room *0.06<<endl;
    cout<<"The total cost is :"<<(30 * room ) + (30 * room * 0.06)<<endl;
    return 0;
}