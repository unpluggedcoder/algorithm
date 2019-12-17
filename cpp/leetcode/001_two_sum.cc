#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // learn from
        // https://github.com/haoel/leetcode/blob/master/algorithms/cpp/twoSum/twoSum.cpp
        // but zero-based index
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            // not found the second one
            if (m.find(numbers[i]) == m.end()) {
                // store the first one poisition into the second one's key
                m[target - numbers[i]] = i;
            } else {
                // found the second one
                result.push_back(m[numbers[i]]);
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> arr = {28, -3, 1,  23, 65, 2,  43, 51, 14,
                       12, 67, 66, 29, 45, 66, 90, 20};
    vector<int> res = Solution().twoSum(arr, 6);
    if (res.size()) {
        cout << "Find result: [" << res[0] << ", " << res[1] << "]" << endl;
    } else
        cout << "Cannot find!" << endl;
    return 0;
}
