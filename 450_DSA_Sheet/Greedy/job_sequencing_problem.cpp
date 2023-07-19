class Solution 
{
    public:
    static bool comp(Job& j1,Job& j2)
    {
        return j1.profit>j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //Step 1 ---> Do sorting
        sort(arr,arr+n,comp);
        
        int maxi = INT_MIN;
        //step 2 ----> Find the maximum deadline of a job at which they are require to submit
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,arr[i].dead);
        }
        //last step iterate for each job and checking that from deadline to day 1 at //which day it can complete
        //the job done and remember one thing if they perform a job in a day then //it can not do other job on the same day 
        int profit = 0;
        int count=0;
        vector<int> slot(maxi+1,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(slot[j]==-1)
                {
                    count++;
                    profit+=arr[i].profit;
                    slot[j] =1;
                    break;
                }
            }
        }
        return {count,profit};
    } 
};