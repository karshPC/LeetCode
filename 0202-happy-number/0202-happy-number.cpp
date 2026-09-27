class Solution {
public:
    int fun(int n){
        int sum = 0;
        while(n > 0){
            int unit = n%10;
            sum += unit*unit;
            n /= 10;
        }
    return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while(fast != 1){
            slow = fun(slow);
            fast = fun(fun(fast));

            if(slow == fast && slow != 1){
                return false;
            }

        }
    return true;
    }
};