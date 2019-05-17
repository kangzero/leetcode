class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret(2, -1);
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r) {
            if ((numbers[l] + numbers[r]) > target) {
                r--;
            } else if ((numbers[l] + numbers[r]) < target) {
                l++;
            } else {
                ret[0] = l+1;
                ret[1] = r+1;
                break;
            }
        }
        return ret;
    }
};
