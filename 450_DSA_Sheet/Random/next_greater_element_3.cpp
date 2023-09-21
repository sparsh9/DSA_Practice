class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> bits;
        long long temp = n;
        while(n){
            int rem = n%10;
            bits.push_back(rem);
            n /= 10;
        }
        reverse(bits.begin(), bits.end());

        // from here we apply concept of next permutation
        // first check where does the array starts to decrease from start
        int ind = -1;
        for(int i=bits.size()-1; i>0; i--){
            if(bits[i] > bits[i-1]){
                ind = i-1;
                break;
            }
        }
        // now we have the index from where the array starts to decrease
        // now we have to get next greater element in the right side of ind in the array where
        // bits[i] < bits[ind] and bits[i] > bits[ind-1] and i < bits.size()

        if(ind == -1){
            reverse(bits.begin(), bits.end());
        }

        else{
            int i = ind+1;
            while(i < bits.size() && bits[i] > bits[ind]){
                i++;
            }
            i--;
            swap(bits[i], bits[ind]);
            reverse(bits.begin()+ind+1, bits.end());
        }

        long long ans = 0;
        for(int i=0; i<bits.size(); i++){
            ans = ans*10 + bits[i];
        }

        if (ans > INT_MAX || ans <= temp) { // Corrected condition here
            return -1;
        }

        return ans;

    }
};