// Approach 1 using the Set and checking if the ith element of the AP from
// starting is there in the series or not
// if not, then we immediately return false, else return true.
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        unordered_set<int> set(arr.begin(),arr.end());
        int max = *max_element(arr.begin(),arr.end());
        int min = *min_element(arr.begin(),arr.end());
        int diff = (max-min)/(arr.size()-1);
        for(int i=1;i<arr.size();i++){
            if(!set.count(min + i * diff)){
                return false;
            }
        }
        return true;
    }
};



// Approach 2 using similar approach without using space
class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int>& arr)
    {
        if (arr.size() <= 2) return true;
        int min = INT_MAX, max = INT_MIN;
        for (int num : arr) {
            min = std::min(min, num);
            max = std::max(max, num);
        }
        if ((max - min) % (arr.size() - 1) != 0) return false;
        int d = (max - min) / (arr.size() - 1);

        int i = 0;
        while (i < arr.size()) {
            if (arr[i] == min + i * d) i++;
            else if ((arr[i] - min) % d != 0) return false;
            else {
                int pos = (arr[i] - min) / d;
                if (arr[pos] == arr[i]) return false;
                std::swap(arr[i], arr[pos]);
            }
        }
        return true;
    }
};