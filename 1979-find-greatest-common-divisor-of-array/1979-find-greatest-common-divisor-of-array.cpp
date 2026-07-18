class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(),nums.end());
        
        int n = nums.size();
        
        vector<int> possible(n,-1);

        for(int i = 1; i <= minValue; i++){
            if ((minValue % i == 0) && (maxValue % i == 0)){
                possible.push_back(i);
            }
            else{
                continue;
            }
        }

        int gcd = *max_element(possible.begin(), possible.end());
    
    return gcd;
    }
};