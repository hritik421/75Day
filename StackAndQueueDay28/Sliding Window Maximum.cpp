// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
// You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[i]>nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }

        int n = nums.size();
        vector<int> res;
        for(int i=k;i<n;i++){
            res.push_back(nums[dq.front()]);
            while(!dq.empty() && dq.front()<=(i-k)) dq.pop_front();
            while(!dq.empty() && nums[i]>nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);

        return res;
    }
};
