#include<iostream>
using namespace std;

int main(){
    cout << "Abhi carpet cleaning service" << endl;
    cout << "How many small rooms do you have: ";
    int small_room{0};
    cin >> small_room;
    
    cout << "How many large rooms do you have: ";
    int large_room{0};
    cin >> large_room;

    // Cost per room
    int small_room_cost{25}, large_room_cost{35};
    
    // Calculate room cost
    int room_cost = (small_room * small_room_cost) + (large_room * large_room_cost);
    cout << "Room cost: $" << room_cost << endl;
    
    // Calculate tax
    double tax = room_cost * 0.06;
    cout << "Tax: $" << tax << endl;
    
    // Calculate total cost
    double total_cost = room_cost + tax;
    cout << "Total cost: $" << total_cost << endl;

    return 0;
}