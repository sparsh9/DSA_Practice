// Method 1 using Count Sort (making another array as a counter)

// Method 2 using maths
int *findTwoElement(int *arr, int n) {
        long long int sum = n*(n+1)/2;
        long long int square_sum = n*(n+1)*(2*n + 1)/6;
        long long int missing=0,repeating=0;
        for(int i=0;i<n;i++){
            sum -= (long long int)arr[i];
            square_sum -= (long long int)arr[i]*(long long int)arr[i];
        }
        missing = (sum + square_sum/sum)/2;
        repeating = missing - sum;
        int ans[2];
        ans[0] = missing;
        ans[1] = repeating;
        return ans;
    }

// Method 3 using absolute marking of visited
int *findTwoElement(int *arr, int n) {
        int a=0,b=0;
        for(int i = 0; i < n; i++){
            if (arr[abs(arr[i]) - 1]<0)
                a = abs(arr[i]);
            else
                arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                b = i+1;
                break;
            }
        }
        int *ans = new int[2];
        ans[0] = a;
        ans[1] = b;
        return ans;
    }