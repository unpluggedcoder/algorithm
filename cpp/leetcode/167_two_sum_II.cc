#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // sorted numbers
        int i = 0, sum;
        int j = numbers.size() - 1;
        vector<int> result;
        while (i < j) {
            sum = numbers[i] + numbers[j];
            if (sum > target)
                j--;
            else if (sum < target)
                i++;
            else {
                result.push_back(i + 1);
                result.push_back(j + 1);
                return result;
            }
        };
        return result;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> arr = {2, 7, 11, 15, 18, 23, 45, 78};
    vector<int> res = Solution().twoSum(arr, 56);
    if (res.size()) {
        cout << "Find result: [" << res[0] << ", " << res[1] << "]" << endl;
    } else
        cout << "Cannot find!" << endl;
    return 0;
}
