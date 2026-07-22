#include<iostream>

using namespace std;

int uniformSubstring(string s, int k){
    unordered_map<char, int> freqMap;
    int max_len = 0;
    int left = 0;
    int right = 0;
    int maxFreq = 0;

    while(right < s.size()){
        freqMap[s[right]]++;
        maxFreq = max(maxFreq, freqMap[s[right]]);
        int charToRemove = (right - left + 1) - maxFreq;
        if(charToRemove > k){
            freqMap[s[left]]--;
            left++;
        }
        max_len = right - left + 1;
        right++;
    }
    return max_len;
}

int main(){
    string s = "aabcdcca";
    int max_len = uniformSubstring(s, 2);
    cout<<max_len;
    return 0;
}