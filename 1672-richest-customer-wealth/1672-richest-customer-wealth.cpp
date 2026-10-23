class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int max_Sum = 0;

        for(int i = 0; i < accounts.size(); i++)
        {
            int current_Sum = 0;

            for(int j = 0; j < accounts[i].size(); j++)
            {
                current_Sum = current_Sum + accounts[i][j];
            }

            if(current_Sum > max_Sum)
            {
                max_Sum = current_Sum;
            }
        }

        return max_Sum;
    }
};