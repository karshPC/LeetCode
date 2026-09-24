class Solution {
public:

    int find(vector<int> f){
        return *max_element(f.begin(), f.end());
    }

    int characterReplacement(string s, int k) {
        int low = 0;
        int n = s.size();
        int maxCnt = INT_MIN;
        vector<int> f(256,0);

        for(int high = 0; high < n; high++){
            f[s[high]]++;
            int len = high-low+1;
            int maxCurr = find(f);
            int diff = len - maxCurr;

            while(diff > k){
                f[s[low]]--;
                low++;
                len = high-low+1;
                maxCurr = find(f);
                diff = len-maxCnt;
            }

            len = high-low+1;
            maxCnt = max(len,maxCnt);
        }
    return maxCnt;
    }   
};