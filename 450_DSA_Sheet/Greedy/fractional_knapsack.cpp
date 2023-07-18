class Solution {
public:
    // Comparator function to sort items in descending order of per unit value
    static bool cmp(pair<double, Item>& a, pair<double, Item>& b) {
        return a.first > b.first;
    }
    
    // Function to calculate the maximum total value in the knapsack
    double fractionalKnapsack(int W, Item arr[], int n) {
        vector<pair<double, Item>> V; // Vector to store the per unit value and corresponding item
        for (int i = 0; i < n; i++) {
            double perUnitValue = (1.0 * arr[i].value) / arr[i].weight;
            pair<double, Item> p = make_pair(perUnitValue, arr[i]);
            V.push_back(p);
        }
        
        sort(V.begin(), V.end(), cmp); // Sort the items in descending order of per unit value
        
        double totalValue = 0.0; // Variable to store the total value in the knapsack
        
        for (int i = 0; i < n; i++) {
            if (V[i].second.weight > W) {
                // If the current item cannot be fully included, take a fraction of it
                totalValue += W * V[i].first;
                W = 0;
            } else {
                // If the current item can be fully included, include it completely
                totalValue += V[i].second.value;
                W -= V[i].second.weight;
            }
            
            if (W == 0) {
                break; // If the knapsack is full, exit the loop
            }
        }
        
        return totalValue; // Return the maximum total value in the knapsack
    }
};