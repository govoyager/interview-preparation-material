#include <bits/stdc++.h>
using namespace std;




int digSum(int n) 
{ 
    int sum = 0; 
     
    // Loop to do sum while 
    // sum is not less than 
    // or equal to 9 
    while(n > 0 || sum > 9) 
    { 
        if(n == 0) 
        { 
            n = sum; 
            sum = 0; 
        } 
        sum += n % 10; 
        n /= 10; 
    } 
    return sum; 
}


int main(){

string n;
cin>>n;
int len = n.length();
string s = n.substr(0,len/2);
int n1 = stoi(s);

int flag = 1;
    while(n1>10){

        long long int a,b,c;
        a = n1%10;
        b = ((n1%100)/10);
        b = digSum(pow(b,2));
        c = digSum(n1/10);
        

        if( a == c || a == b){

        }
        else{
            flag = 0;
        }
        n1 = n1/10;

    }

    if(flag == 1){
        cout<<"The given number is a Magic Palindrome.";
    }
    else{
        cout<<"The given number is not a Magic Palindrome.";
    }

}

