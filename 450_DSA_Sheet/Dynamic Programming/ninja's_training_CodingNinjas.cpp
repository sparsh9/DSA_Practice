// Approach 1 (Using Recursion)
int helper(int day, int last, vector<vector<int>> &points){
    if(day == 0){
        int maxi = 0;
        for(int i=0; i<3; i++){
            maxi = max(maxi, points[day][i]);
        }
        return maxi;
    }
    // otherwise
    int maxi = 0;
    for(int i=0; i<3; i++){
        if(i!=last){
            maxi = max(maxi, points[day][i] + helper(day-1, i, points));
        }
    }

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return helper(n-1, -1, points);
}




// Approach 2 (Using Recursion + Memoization)
int helper(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        for(int i=0; i<3; i++){
            maxi = max(maxi, points[day][i]);
        }
        return maxi;
    }
    // check if previously calculated
    if(dp[day][last] != -1)
        return dp[day][last];
    
    // otherwise
    int maxi = 0;
    for(int i=0; i<3; i++){
        if(i!=last){
            maxi = max(maxi, points[day][i] + helper(day-1, i, points, dp));
        }
    }
    dp[day][last] = maxi;
    return maxi;

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return helper(n-1, 3, points, dp);
}



// Approach 3 (Using Tabulation)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    // base case or day 0
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(dp[0][0], max(dp[0][1], dp[0][2])); // max of all the 3


    // for rest of the days
    for(int day = 1; day<n; day++){
        for(int last = 0; last<4; last++){
            int maxi = 0;
            for(int task = 0; task<3; task++){
                if(task != last){
                    maxi = max(maxi, points[day][task] + dp[day-1][task]);
                }
            }
            dp[day][last] = maxi;
        }
    }

    return dp[n-1][3];
    // we are returning [3] because we want to return the max of all the 3 tasks
}



// Approach 4 (Using Tabulation + Space Optimization)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, -1); 

    // base case or day 0
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0], max(points[1], points[2])); // max of all the 3


    // for rest of the days
    for(int day = 1; day<n; day++){
        vector<int> cur(4, -1);
        for(int last = 0; last<4; last++){
            int maxi = 0;
            for(int task = 0; task<3; task++){
                if(task != last){
                    maxi = max(maxi, points[day][task] + prev[task]);
                }
            }
            cur[last] = maxi; // update the current day's array
        }
        prev = cur; // update the previous day's array
    }

    return prev[3];
    // we are returning [3] because we want to return the max of all the 3 tasks
}