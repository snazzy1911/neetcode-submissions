class Solution {
public:
    int sumi(int n){
        int sum =0;
        while(n>0){
            int d = n%10;
            n= n/10 ;
            sum +=d*d;

        
        }
        return sum;

    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n ;
        while(true ){
            slow = sumi(slow) ;
            fast =sumi(fast) ;
            fast = sumi(fast) ;
            if(slow==fast){
                break;

            }
        }
        return slow ==1 ;
        
    }
};
