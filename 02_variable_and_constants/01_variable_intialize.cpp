#include<iostream>
using namespace std;

int main(){
    int length_room {0};
    int width_room {0};
    
    cout << "Enter the length of room: ";
    cin >> length_room;
    
    cout << "Enter the width of room: ";
    cin >> width_room;
    
    cout << "The total area of room is " << length_room * width_room << " square feet" << endl;
    
    return 0;
}