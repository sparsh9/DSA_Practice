class Solution {
public:
    // Recursive function to perform binary exponentiation (x^k)
    double bin(double x, long long k) {
        if (k == 1) {
            return x; // Base case: x^1 = x
        }
        double a = bin(x, k / 2); // Recursive call for x^(k/2)
        if (k & 1) {
            return a * a * x; // If k is odd, return a*a*x
        } else {
            return a * a; // If k is even, return a*a
        }
    }

    // Function to calculate x raised to the power n (x^n)
    double myPow(double x, int n) {
        if (n == 0) {
            return 1; // Base case: x^0 = 1
        }
        long long k = long(abs(n)); // Take the absolute value of n (to handle negative n)
        double ans = bin(x, k); // Calculate x^k using binary exponentiation function bin(x, k)
        if (n < 0) {
            return 1 / ans; // If n is negative, return 1/(x^k)
        } else {
            return ans; // If n is positive, return x^k
        }
    }
};
