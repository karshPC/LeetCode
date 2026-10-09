class Solution {
public:

    int find(vector<int> &freq){
        return *max_element(freq.begin(), freq.end());
    }

    int characterReplacement(string s, int k) {
        int low = 0;
        int maxCnt = INT_MIN;
        int n = s.size();
        vector<int> freq(256,0);

        for(int high = 0; high < n; high++){
            freq[s[high]]++;
            int len = high - low + 1;
            int maxFreq = find(freq);
            int diff = len-maxFreq;

            while(diff > k){
                freq[s[low]]--;
                low++;
                len = high-low+1;
                maxFreq = find(freq);
                diff = len-maxFreq;
            }

        maxCnt = max(maxCnt, len);        
        }
    
    return maxCnt;
    }   
};