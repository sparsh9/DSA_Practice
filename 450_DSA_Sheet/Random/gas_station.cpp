// Approach (Greedy Approach)

class Solution {
public:
    bool checkIfPossible(vector<int>& gas, vector<int>& cost, int start, int tank){
        for(int i = start; i < gas.size(); i++){
            tank += gas[i];
            if(tank < cost[i]) return false;
            tank -= cost[i];
        }
        for(int i = 0; i < start; i++){
            tank += gas[i];
            if(tank < cost[i]) return false;
            tank -= cost[i];
        }
        return true;
    }


    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 0) return -1;
        if(gas.size() == 1) return gas[0] >= cost[0] ? 0 : -1;
        int start = 0, tank = 0;
            for(int i = 0; i < gas.size(); i++){
                if(gas[i] > cost[i]){
                    start = i;
                    bool possible = checkIfPossible(gas, cost, start, tank);
                    if (possible) return start;
                }
            }
            return -1;
    }
};


// Optimal Approach

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=0,total_cost=0;
        int curr_gas=0, starting_point=0;
        for(int i=0;i<n;i++)
        {
            //these two variable are to check if no case is possible
            total_gas+=gas[i];
            total_cost+=cost[i];
            //for checking the total present gas at index i
            curr_gas+=gas[i]-cost[i];
            if(curr_gas<0)
            {
               //there is a breakdown....so we will start from next point or index
                starting_point=i+1;
                //reset our fuel 
                curr_gas=0;
            }
        }
        return (total_gas<total_cost)?-1:starting_point;     
    }
};