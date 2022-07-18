#include<iostream>
#include<string>
#include<vector>
using namespace std;

// parametrization method
void sumOfNNumbers(int n,int sum){
if(n<1){
    cout<<sum;
    return;
}
sumOfNNumbers(n-1,sum+1);
}

// functional method
int sumofnNumbers(int n){
    if(n==0){
        return 0;
    }
    return n+sumofnNumbers(n-1);
}


int main()
{
    cout << "Enter any number"<< endl;
    int n;
    cin>>n;
    sumOfNNumbers(n,0);
    cout<<endl;
    cout<<sumofnNumbers(n)<<endl;
    return 0;
}