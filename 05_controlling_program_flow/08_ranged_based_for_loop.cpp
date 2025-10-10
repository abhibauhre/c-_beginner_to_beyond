#include<iostream>
#include<vector>

using namespace std;
int main(){

    int scores[] {10,39,47};
    for(auto score: scores)
    cout<<score<<endl; 

    vector <double> temperature{89.3,24.4,78.4};
    double average_temp{};
    double total {};

    for (auto temp: temperature)
    total += temp;

    if (temperature.size() != 0 )
    average_temp = total / temperature.size();
    cout<<average_temp<<"is average temp"<<endl;
    

    for(auto score:{34,57,98})
    cout<<score<<endl;

    for(auto c: "Hey their i am abhi ")
    cout<<c<<endl;
    

    
}