#include <algorithm>
#include <exception>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int get_median(vector<int>& v, size_t start, size_t end) {
    if (start == end) return v[start];
    size_t m = start + (end - start) / 2;
    if (0 == (end - start + 1) % 2)
        return (v[m] + v[m + 1]) / 2;
    else
        return v[m];
}

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // makesure nums2 is larger, nums1 is smaller
        size_t s_len = nums1.size();
        size_t l_len = nums2.size();
        if (s_len > l_len) return this->findMedianSortedArrays(nums2, nums1);

        size_t half_len = (s_len + l_len + 1) / 2;
        size_t s_idx, l_idx;
        size_t start = 0;
        size_t end = s_len;
        while (start <= end) {
            s_idx = (start + end) / 2;
            l_idx = half_len - s_idx;

            int s_left =
                s_idx == 0 ? numeric_limits<int>::min() : nums1[s_idx - 1];
            int s_right =
                s_idx == s_len ? numeric_limits<int>::max() : nums1[s_idx];
            int l_left =
                l_idx == 0 ? numeric_limits<int>::min() : nums2[l_idx - 1];
            int l_right =
                l_idx == l_len ? numeric_limits<int>::max() : nums2[l_idx];
            if (s_left <= l_right && s_right >= l_left) {
                if ((s_len + l_len) % 2 == 0)
                    return (double)(max(s_left, l_left) +
                                    min(s_right, l_right)) /
                           2;
                else
                    return max(s_left, l_left);
            } else if (s_left > l_right)
                end = s_idx - 1;
            else
                start = s_idx + 1;
        }
        throw invalid_argument("Not sorted array!");
    }
};

int main(int argc, char const* argv[]) {
    vector<int> s1, s2;
    for (int i = 1; i < 3; i++) s1.push_back(i);
    for (int i = 0; i < 2; i++) s2.push_back(i);
    double res = Solution().findMedianSortedArrays(s1, s2);
    cout << "Median of s1, s2:" << res << endl;
    return 0;
}
