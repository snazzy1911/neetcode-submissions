class Solution {
public:
    int hours(vector<int>& piles , int h , int s ){
        int hours = 0 ;
        for(int i =0 ; i<piles.size() ; i++){
            hours += (piles[i]+s-1)/s ;

        }
        return hours ;


    }
    int highN(vector<int>& piles){
        int maxi = INT_MIN ;
        for(int i = 0 ; i<piles.size() ; i++){
            maxi = max(maxi,piles[i]) ;
        }
        return maxi ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 ;
        int high = highN(piles) ;
        int ans = -1 ;
        while(low<=high){
            int mid = (low+high)>>1 ;
            if(hours(piles,h,mid)<=h){
                ans = mid ;
                high = mid -1 ;
            }else{
                low = mid+1 ;
            }
        }
        return ans ;
        

        
    }
};
