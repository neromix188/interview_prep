#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "pwwkew";
    int i = 0;
    int j = 0;
    set<char> cnt;
    int ans = 0;
    while (i < s.length() && j < s.length()) {
        if (cnt.count(s[j])) {
            cnt.erase(s[i]);
            i++;
        } else {
            cnt.insert(s[j]); 
            j++;
        }
        ans = max(ans, j - i);
    }
    cout << ans;
    return 0;
}