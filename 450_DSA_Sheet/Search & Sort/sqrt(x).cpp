// Method 1 using Binary Search
// class Solution {
//     long long int binarySearch(long long int a){
//         long long int s=0,e=a;
//         long long int mid = s+(e-s)/2;
//         long long int ans = -1;
//         while(s<=e){
//             long long int sq = mid*mid;
//             if(sq == a)
//                 return mid;
//             else if(sq > a)
//                 e = mid-1;
//             else {
//                 s = mid + 1;
//                 ans = mid;
//             }
            
//             mid = s+(e-s)/2;
//         }
//         return ans;
//     }
// public:
//     int mySqrt(int x) {
//         return binarySearch(x);
//     }
// };



// Method 2 

// #include <bits/stdc++.h>
// using namespace std;

// // Function to return the square root of
// // a number using Newtons method
// double squareRoot(double n, float l)
// {
// 	// Assuming the sqrt of n as n only
// 	double x = n;

// 	// The closed guess will be stored in the root
// 	double root;

// 	// To count the number of iterations
// 	int count = 0;

// 	while (1) {
// 		count++;

// 		// Calculate more closed x
// 		root = 0.5 * (x + (n / x));

// 		// Check for closeness
// 		if (abs(root - x) < l)
// 			break;

// 		// Update root
// 		x = root;
// 	}

// 	return root;
// }

// // Driver code
// int main()
// {
// 	double n = 327;
// 	float l = 0.00001;

// 	cout << squareRoot(n, l);

// 	return 0;
// }
