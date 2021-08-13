#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
int flag = 0;
int minimum(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

int distanceToClosest(int a[], int g, int size){
    int min = 99999;
    for(int i = 0;i < 5; i++){
        min = minimum(min, abs(a[i]-g));
    }
    return min;
}

int main(){
    int guess, prev_guess_d = 99999,guess_d = 99999, prev_guess;
    int num_arr[5];
    for (int i = 0; i < 5; i++){
        num_arr[i]=rand() % 1000 + 1;
    }
    const int Size = 5;
    sort(num_arr, num_arr + 5);
    cout << "Hello, please try and guess one of my numbers between 1 and 1000.\n";
    
    for(int i = 0;i < 5; i++){
    //cout<<num_arr[i]<<" "; //< this shows what numbers are generated, can be used to check.
    }
    
    cout<<"Please make a guess: ";
    cin >> guess;
    prev_guess_d = distanceToClosest(num_arr, guess,Size );
    if(prev_guess_d == 0){
        cout << "Success!!";
    }
    else{
        while(true){
            prev_guess = guess;
            
            cout << "Enter guess again: ";
            cin >> guess;
            
            if (guess < 0 || guess > 1000){
                
                cout << "Error. Enter a number between 1 and 1000.";
                continue;
            }
            guess_d = distanceToClosest(num_arr, guess,Size);
            if (guess_d == 0){
                cout<<"Success!";
                break;
            }
            else{
                if(prev_guess_d<guess_d){
                    cout<<"colder"<<endl;
                }
                else{
                    cout<<"warmer"<<endl;
                }
                prev_guess_d = guess_d;
            }
            
        }
        
    }
    
    return 0;
}

