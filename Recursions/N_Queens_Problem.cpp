#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    // N queens problem
    int n;
    cin>>n;
    int grid[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    int sol[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sol[i][j]=0;
        }
    }
    if(solveMaze(grid,sol,0,0)==false)
    {
        cout<<"No solution";
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}