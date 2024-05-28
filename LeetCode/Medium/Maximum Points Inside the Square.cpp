https://leetcode.com/problems/maximum-points-inside-the-square/description/


class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        map<int,vector<char>> mp;
        int size = points.size();
        for(int i=0;i<size;i++){
            int index = max(abs(points[i][0]),abs(points[i][1]));
            mp[index].push_back(s[i]);
        }

        set<char> allChar;
        int res = 0;
        for(auto it:mp){
            set<char> eachLevel;
            for(char c:it.second){
                if(eachLevel.count(c)>0 || allChar.count(c)>0){
                    return res;
                }else{
                    eachLevel.insert(c);
                }
            }

            for(char c: eachLevel){
                res++;
                allChar.insert(c);
            }

        }

        return res;

    }
};
