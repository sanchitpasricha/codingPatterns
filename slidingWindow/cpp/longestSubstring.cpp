#include<iostream>
#include<vector>

using namespace std;

int longestSubString(string s){
    unordered_map<char, int> mp;
    int maxLength = 0;
    int left = 0;
    int right = 0;

    /*
    cabcdeca
    [a=1, b=2, c=3, d=4, e=5] maxLength sub string
    */
   
    while(right < s.size()){
        if(mp.find(s[right]) != mp.end() && mp[s[right]] >= left){
            left = mp[s[right]] + 1;
        }
        maxLength = max(maxLength, (right - left + 1));
        mp[s[right]] = right;
        right++;
    }
    return maxLength;
}

int main(){
    string s = "cabcdeca";
    int count = longestSubString(s);
    cout<<"Longest substring length : "<<count;
}