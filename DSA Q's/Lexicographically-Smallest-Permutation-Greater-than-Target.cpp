#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);

        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }

        string ans = "";
        string prefix = "";

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';
            int bigger = -1;

            for (int j = x + 1; j < 26; j++) {
                if (count[j] > 0) {
                    bigger = j;
                    break;
                }
            }

            if (bigger != -1) {
                count[bigger]--;

                string temp = prefix;
                temp += char('a' + bigger);

                for (int j = 0; j < 26; j++) {
                    for (int k = 0; k < count[j]; k++) {
                        temp += char('a' + j);
                    }
                }

                ans = temp;
                count[bigger]++;
            }

            if (count[x] == 0) {
                break;
            }

            prefix += target[i];
            count[x]--;
        }

        return ans;
    }
};