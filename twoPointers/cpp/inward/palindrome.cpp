#include<iostream>
#include<vector>
#include<string>
#include<cctype>

using namespace std;

bool checkPalindrome(string str){
    int start = 0;
    int end = str.size() - 1;

    while(start < end){
        while(start < end && !isalnum(str[start])){
            start++;
        } 
        while(start < end && !isalnum(str[end])){
            end--;
        }
        if(tolower(str[start]) != tolower(str[end])){
            return false;
        }

        start++;
        end--;
    }
    return true;
}

int main(){
    string str = "a dog! a panic in a paagoda";
    cout<<checkPalindrome(str);
    return 0;
}