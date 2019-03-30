//#define _SORT
//#define _PRIO_Q
#define _PARTITION

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
#ifdef _SORT
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
#elif defined _PRIO_Q
        priority_queue <int> q_nums(nums.begin(), nums.end());
        
        for (int i = 0; i < k-1; i++) {
            q_nums.pop();
        }
        
        return q_nums.top();
#elif defined _PARTITION  
        int l = 0; 
        int r = nums.size() - 1;
        while (1) {
            int pivot = partition(nums, l, r);
            if (pivot == (k-1)) return nums[pivot];
            if (pivot > (k-1)) {
                r = pivot - 1;  
            }else {
                l = pivot + 1;
            }
        }
#endif
    }

#ifdef _PARTITION
    int partition(vector<int>& nums, int left, int right) {
        int p = nums[left];
        int l = left + 1;
        int r = right;
        while (l <= r) {
            if ((nums[l] < p) && (nums[r] > p)) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            if (nums[l] >= p) l++;
            if (nums[r] <= p) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
#endif 
};
