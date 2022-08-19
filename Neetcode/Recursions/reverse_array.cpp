#include<iostream>
#include<string>
#include<vector>
using namespace std;

reverseArray(int left,int right){
    if(n==0){
        return;
    }
    reverseArray(arr,n-1);
    cout<<arr[n-1]<<" ";
}


int main()
{
    cout<<"Enter the size of the array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The reversed array is :"<<endl;

    return 0;
}