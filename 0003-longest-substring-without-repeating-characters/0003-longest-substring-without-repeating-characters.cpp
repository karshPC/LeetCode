class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int maxRes = INT_MIN;
        unordered_map<int,int> f;
        int n = s.size();

        for(int high = 0; high<n; high++){
            f[s[high]]++;
            int k = high-low+1;

            while(f.size() < k){
                f[s[low]]--;
                if(f[s[low]] == 0){
                    f.erase(s[low]);
                }
                low++;
                k = high-low+1;
            }

            // Whatever code goes below has f.size() == k, which means the size of the hashmap and the size
            // of the string are same, i.e. no repeating/duplicate characters;

            int len = high-low+1;
            maxRes = max(maxRes, len);
        }
    return (maxRes == INT_MIN) ? 0 : maxRes;
    }
};