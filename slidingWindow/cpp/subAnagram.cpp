#include <iostream>
#include <vector>

using namespace std;

int substringAnagram(string s, string t) {
    int n = s.size();
    int m = t.size();

    if (m > n)
        return 0;

    vector<int> freqT(26, 0);
    vector<int> freqWindow(26, 0);

    for (char c : t)
        freqT[c - 'a']++;

    for (int i = 0; i < m; i++)
        freqWindow[s[i] - 'a']++;

    int count = 0;

    if (freqT == freqWindow)
        count++;

    for (int i = m; i < n; i++) {
        freqWindow[s[i] - 'a']++;        
        freqWindow[s[i - m] - 'a']--;       

        if (freqT == freqWindow)
            count++;
    }

    return count;
}

int main() {
    string s = "caabab";
    string t = "aba";

    cout << substringAnagram(s, t) << endl;

    return 0;
}