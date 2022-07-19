// #include<iostream>
// #include<string>
// #include<vector>
// #include<math.h>
// using namespace std;

// int powerSum(int X, int N,int a=1) 
// {
//     if(X<0||X<pow(a,N))
//     return 0;
//     if(X==0 || X==pow(a,N))
//     return 1;
//     return powerSum(X-pow(a,N),N,a+1)+powerSum(X,N,a+1);//first call includes element; second call excludes element
// }

// int main()
// {
//     short int n,x,a;
//     cin >> x;
//     cin >> n;

//     cout<<powerSum(x,n,a);
//     return 0;
// }

#include<bits/stdc++.h>

using namespace std;

int fn(int x, int n, int c)
{
    if(pow(c,n)<x)
    {
        return fn(x,n,c+1)+ fn(x-pow(c,n), n, c+1);
    }
    else if(pow(c,n)==x)
    {
        return 1;
    }

    else                    // Better approach with case wise distinction
    {
        return 0;
    }
    {
        return 0;
    }

}

int main()
{

    int x;
    int n;
    int c=1;
    int res;//for result

    cin>>x>>n;

    res=fn(x,n,c);

    cout<<res;

    return 0;
}