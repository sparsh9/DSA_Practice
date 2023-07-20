class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size(); // Get the size of the input vector ast
        stack<int> s; // Create a stack to simulate the collision process

        // Iterate through each asteroid in the input vector ast
        for (int i = 0; i < n; i++) {
            if (ast[i] > 0 || s.empty()) {
                // If the current asteroid is positive (moving to the right) or the stack is empty, push it into the stack
                s.push(ast[i]);
            } else {
                // If the current asteroid is negative (moving to the left) and there are asteroids in the stack

                while (!s.empty() && s.top() > 0 && s.top() < abs(ast[i])) {
                    // While there are positive asteroids in the stack and they are smaller in size than the current negative asteroid
                    s.pop(); // Pop the positive asteroids from the stack as they will be destroyed due to collision
                }

                if (!s.empty() && s.top() == abs(ast[i])) {
                    // If there is a positive asteroid in the stack with the same size as the current negative asteroid
                    s.pop(); // Pop the positive asteroid as it will be destroyed due to collision
                } else {
                    if (s.empty() || s.top() < 0) {
                        // If the stack is empty or the top asteroid is also negative, push the current negative asteroid into the stack
                        s.push(ast[i]);
                    }
                }
            }
        }

        // Finally, we are returning the elements that remain in the stack after the collision process.
        // We have to return them in reverse order to maintain the correct order of asteroids.
        vector<int> res(s.size());
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            res[i] = s.top(); // Store the top element of the stack in the result vector
            s.pop(); // Pop the top element from the stack
        }

        return res; // Return the resulting vector with the remaining asteroids after collision
    }
};
