//2. Given a number, the task is to check if a number is divisible by 8 or not. 
//The input number may be large and it may not be possible to store even if we use 
//long long int.

#include <iostream>
using namespace std;

bool check(string str)
{
	int n = str.length()-1;
    int x = 0 , res;
    string temp = "";
    for(int i=0 ; i<3 && n>=0 ; i++) {
        temp = str[n--] + temp;
        x++;
    }

    for(int i=0 ; i<x ; i++) {
        res = res*10 + (temp[i]-'0');
    }

    return res%8 == 0;
}

int main()
{
	string str = "76952";
	check(str)? cout << "Yes" : cout << "No ";
	return 0;
}


A number is divisible by 8 if number formed by last three digits of it is divisible by 8.
