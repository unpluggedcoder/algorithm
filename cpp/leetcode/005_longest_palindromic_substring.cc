#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        string es = "$#";
        for (auto it = s.begin(); it != s.end(); it++) {
            es += *it;
            es += "#";
        }
        int *RL = new int[es.length()];
        int maxRight = 0;
        int pos = 0;
        int maxLen = 0;
        int maxPos = 0;
        size_t len = es.length();
        for (int i = 0; i < len; i++) {
            if (i >= maxRight)
                RL[i] = 1;
            else
                RL[i] = min(RL[2 * pos - i], maxRight - i);
            while (i - RL[i] >= 0 && i + RL[i] < len &&
                   es[i - RL[i]] == es[i + RL[i]])
                RL[i]++;
            if ((RL[i] + i - 1) > maxRight) {
                maxRight = RL[i] + i - 1;
                pos = i;
            }
            if (RL[i] > maxLen) {
                maxLen = RL[i];
                maxPos = i;
            }
        }
        delete[] RL;
        maxPos = (maxPos / 2) - 1;
        return s.substr(maxPos - (maxLen / 2) + 1, maxLen - 1);
    }
};

int main(int argc, char const *argv[]) {
    string s = "bbababc";
    string pal = Solution().longestPalindrome(s);
    cout << s << " longest palindrome length: " << pal << endl;
    return 0;
}
