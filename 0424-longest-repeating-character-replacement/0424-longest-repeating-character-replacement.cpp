class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, maxLen = 0, maxFreq = 0;

        vector <int> freq(26,0);

        while (right < s.size()){
            freq[s[right]-'A']++;
            maxFreq = max(maxFreq, freq[s[right]-'A']);

            while ((right-left+1) - maxFreq > k){
                freq[s[left]-'A']--;
                left++;
            }
            
            maxLen = max(right-left+1,maxLen);
            right++;
        }
    return maxLen;
    }
};