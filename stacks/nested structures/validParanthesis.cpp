#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool checkValidBrackets(string s){
    stack<char> st;
    unordered_map<char, char> mp = {
        {'[', ']'}, {'(', ')'}, {'{', '}'}};

    for (auto bracket : s){
        if (mp.find(bracket) != mp.end()){
            st.push(bracket);
        }
        else{
            if (st.empty()){
                return false;
            }
            if (bracket == mp[st.top()]){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    string s = "(){()}]";
    bool valid = checkValidBrackets(s);
    cout << valid;

    return 0;
}