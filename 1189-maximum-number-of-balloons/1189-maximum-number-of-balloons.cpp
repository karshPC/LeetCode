class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);

        for (char c : text) {
            freq[c - 'a']++;
        }

        // "balloon" needs:
        // b -> 1
        // a -> 1
        // l -> 2
        // o -> 2
        // n -> 1

        int ans = min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });

        return ans;
    }
};