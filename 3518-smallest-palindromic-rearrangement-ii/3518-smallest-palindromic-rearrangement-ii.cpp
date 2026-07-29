class Solution {
public:
    static const int CAP = 1000001;

    long long binomCap(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        long long res = 1;
        for (int i = 1; i <= r; i++) {
            long long a = n - r + i;
            long long b = i;

            long long g = gcd(a, b);
            a /= g;
            b /= g;

            g = gcd(res, b);
            res /= g;
            b /= g;

            __int128 cur = (__int128)res * a;
            if (cur >= CAP) return CAP;
            res = (long long)cur;
            res /= b;

            if (res >= CAP) return CAP;
        }
        return min<long long>(res, CAP);
    }

    long long countWays(vector<int> &cnt) {
        long long ways = 1;
        int rem = 0;

        for (int c : cnt) {
            if (c == 0) continue;
            long long choose = binomCap(rem + c, c);

            __int128 cur = (__int128)ways * choose;
            if (cur >= CAP) return CAP;

            ways = (long long)cur;
            rem += c;

            if (ways >= CAP) return CAP;
        }
        return ways;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char ch : s) freq[ch - 'a']++;

        vector<int> half(26, 0);
        char mid = 0;
        int len = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];
            if (freq[i] & 1) mid = char('a' + i);
        }

        if (countWays(half) < k) return "";

        string left;

        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                } else {
                    k -= ways;
                    half[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid) return left + string(1, mid) + right;
        return left + right;
    }
};