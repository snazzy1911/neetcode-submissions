class Solution {
public:
    int lowN(vector<int>& weights){
        int maxi = INT_MIN;
        for(int i = 0; i < weights.size(); i++){
            maxi = max(maxi, weights[i]);
        }
        return maxi;
    }

    int highN(vector<int>& weights){
        int sum = 0;
        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];
        }
        return sum;
    }

    int ans(vector<int>& weights, int s){
        int day = 1;
        int weight = weights[0];

        for(int i = 1; i < weights.size(); i++){
            if(weight + weights[i] <= s){
                weight += weights[i];
            }else{
                day++;
                weight = weights[i];
            }
        }

        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = lowN(weights);
        int high = highN(weights);
        int res = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(ans(weights, mid) <= days){
                res = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return res;
    }
};