class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int high = 0;
        int n = fruits.size();
        unordered_map<int,int> f;
        int maxSize = INT_MIN;

        while(high<n){
            f[fruits[high]]++;

            while(f.size() > 2){
                f[fruits[low]]--;
                
                if(f[fruits[low]] == 0){
                    f.erase(fruits[low]);
                }
                
                low++;
            }

            int len = high-low+1;
            maxSize = max(len,maxSize);
        high++;
        }
    return maxSize;
    }
};