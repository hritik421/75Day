class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int res = INT_MIN;
        int n = heights.size();
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                int top = s.top();
                s.pop();
                int multiplier = s.empty() ? i : i - s.top()-1;
                int value = heights[top] * multiplier;
                res = max(res,value);
            }
            s.push(i);
        }

        while(!s.empty()){
            int top = s.top();
            s.pop();
            int multiplier = s.empty() ? n : n - s.top()-1;
            int value = heights[top] * multiplier;
            res = max(res,value);
        }

        return res;
    }
};
