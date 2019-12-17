#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int i;
        size_t len = s.size();
        size_t maxlen = 0;
        int max_len_start = -1;
        for (i = 0; i < len; i++) {
            if (m.find(s[i]) != m.end() && max_len_start < m[s[i]]) {
                max_len_start = m[s[i]];
            }
            if (i - max_len_start > maxlen) maxlen = i - max_len_start;
            m[s[i]] = i;
        }
        return maxlen;
    }
};

int main(int argc, char const* argv[]) {
    string s = "abcabced";
    int idx = Solution().lengthOfLongestSubstring(s);
    cout << "Longest substring:" << idx << endl;
    return 0;
}
