class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int maxFruits = INT_MIN;
        unordered_map<int,int> f;
        int n = fruits.size();

        for(int high = 0; high < n; high++){
            f[fruits[high]]++;

            while(f.size() > 2){
                f[fruits[low]]--;
                if(f[fruits[low]] == 0){
                    f.erase(fruits[low]);
                }
                low++;
            }

            int currFruits = high-low+1;
            maxFruits = max(maxFruits, currFruits);

        }
    return maxFruits;
    }
};