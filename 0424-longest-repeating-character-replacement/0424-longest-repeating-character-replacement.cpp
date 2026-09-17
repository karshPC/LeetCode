class Solution {
public:

    int find(vector<int> f){
        return *max_element(f.begin(), f.end());
    }

    int characterReplacement(string s, int k) {
        int low = 0;
        int n = s.size();

        // unordered_map<char,int> f;
        // Whenever a string question, make a vector as it will be constant space
        // Because max number of char is 26 O(26) is a constant operation
        
        vector<int> f(256,0); // total 256 characters
        int maxRes = 0;

        for(int high = 0; high < n; high++){
            f[s[high]]++;
            int len = high-low+1;
            int maxCnt = find(f);
            int diff = len-maxCnt;

            while(diff > k){
                f[s[low]]--;
                low++;

                len = high-low+1;
                maxCnt = find(f);
                diff= len-maxCnt;
            }

            len = high - low +1;
            maxRes = max(maxRes, len);
        }

    return maxRes;
    }
};