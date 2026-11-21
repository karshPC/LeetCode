class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cb = costBoth;
        long long n1 = need1;
        long long n2 = need2;

        long long overlap = min(n1,n2);
        long long totalCost = overlap * min(cb,c1+c2);

        long long rem1 = n1 - overlap;
        totalCost += rem1 * min(c1,cb);

        long long rem2 = n2 - overlap;
        totalCost += rem2 * min(c2,cb);

        return totalCost;


    }
};