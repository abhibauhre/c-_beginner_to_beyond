//Arrays is a collection of elements of the same type placed in contiguous memory locations
#include<iostream>
using namespace std;
int main(){
    char vowels[] {'a','e','i','o','u'};//its possible to initialize an array like this
    cout << "The first vowel is: " << vowels[0] << endl;
    cout<<"The last vowel is: "<<vowels[4]<<endl;

    float temps[]{99.2,82.3,35.2,22.2};
    cout<<"the first element is :"<<temps[0]<<endl;
    temps[0] = 100.2;//its possible to update the elements of an array
    cout<<"the first element after updating :"<<temps[0]<<endl;

    int test_score[]{100,59,34,133,232};
    cout<<"the first test score is :"<<test_score[0]<<endl;
    cout<<"the last test score is :"<<test_score[4]<<endl;
    
    cout<<"enter 5 highes test score:"<<endl;
    cin>>test_score[0];//this method is use to take input from the user
    cin>>test_score[1];
    cin>>test_score[2];
    cin>>test_score[3];
    cin>>test_score[4];

    cout<<"the updated first test score is :"<<test_score[0]<<endl;
    cout<<"the updated last test score is :"<<test_score[4]<<endl;


    cout<<"what the value of an array :"<<test_score<<endl;//this gives the address of the first element of the array
    


  
    
    return 0;
}