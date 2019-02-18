#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        string es = "$#";
        for (auto it = s.begin(); it != s.end(); it++) {
            es += *it + "#";
        }
        int *RL = new int[s.size()];
        int maxRight = 0;
        int maxLen = 0;
        int pos = 0;
        size_t len = es.size();
        for (int i = 0; i < len; i++) {
            if (i >= maxRight)
                RL[i] = 1;
            else
                RL[i] = min(RL[2 * pos - i], maxRight - i);
            while (i - RL[i] >= 0 && i + RL[i] < len &&
                   s[i - RL[i]] == s[i + RL[i]])
                RL[i]++;
            if ((RL[i] + i - 1) > maxRight) {
                maxRight = RL[i] + i - 1;
                pos = i;
            }
            maxLen = max(maxLen, RL[i]);
        }
        delete[] RL;
        return maxLen - 1;
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}
