#include<iostream>
#include<iomanip> 
using namespace std;

int main(){
    float usd_per_eur{1.09};
    
    cout << "Welcome to EUR to USD Converter!" << endl;
    cout << "Current exchange rate: 1 EUR = " << usd_per_eur << " USD" << endl;
    cout << "Enter euros to convert: ";
    
    float euro{0.0};
    float dollar{0.0};

    cin >> euro;

    dollar = euro * usd_per_eur;
    
   
    cout << fixed << setprecision(2);  
    cout << euro << " EUR = " << dollar << " USD" << endl;
    
    return 0;  
}