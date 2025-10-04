#include<iostream>
#include<vector>//dont forget to include vector header file
using namespace std;
int main(){
    // vector<char> vowels;//its an empty vector of char type
    // vector<char> vowels(5);//its an empty vector of char type with size 5
       vector <char> vowels {'a','e','i','o','u'};
       cout<<vowels[0]<<endl;
       cout<<vowels[4]<<endl;

       vector <int> test_score{100, 98 , 343};
       cout<<test_score[0]<<endl;//this is an array syntax method to access the elements of vector
       cout<<test_score[1]<<endl;
       cout<<test_score[2]<<endl;

       cout<<test_score.at(0);//this is a vector method to access the elements of vector
       cout<<test_score.at(1);
       cout<<test_score.at(2)<<endl;
       cout<<"there are "<<test_score.size()<<" scores in the vector"<<endl;//size function to get the size of vector

       cout<<"enter a test score to add the vecto :"<<endl;
       int score_to_add{0};
       cin>>score_to_add;
       test_score.push_back(score_to_add);//push_back function to add an element at the end of vector
       cout<<"one more test score to add :"<<endl;
         cin>>score_to_add;
         test_score.push_back(score_to_add);

        cout<<"test score are now"<<endl;
        cout<<test_score.at(0)<<endl;
        cout<<test_score.at(1)<<endl;
        cout<<test_score.at(2)<<endl; 
        cout<<test_score.at(3)<<endl;
        cout<<test_score.at(4)<<endl;

        cout<<"there are "<<test_score.size()<<" scores in the vector"<<endl;

       // 2D vectors
        vector <vector<int>> movie_ratings
        {
          {1,2,3,4},  
          {5,6,7,8},
          {9,10,11,12}
        };

        cout<<"movie rating from reviewer 1 for movie 1 is :"<<movie_ratings[0][0]<<endl;
        cout<<"movie rating from reviewer 2 for movie 4 is :"<<movie_ratings[1][3]<<endl;
        cout<<"movie rating from reviewer 3 for movie 2 is :"<<movie_ratings.at(2).at(1)<<endl;


}