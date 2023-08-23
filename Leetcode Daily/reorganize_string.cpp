class Solution {
public:
    string reorganizeString(string S) {
        // count frequency
        unordered_map<char, int> charCount;
        for (char c : S) {
            charCount[c]++;
        }

        // check if frequency of any character is greater than (n + 1) / 2
        for (const auto& entry : charCount) {
            if (entry.second > (S.length() + 1) / 2) {
                return "";
            }
        }


        auto comp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second; // We want to prioritize characters with higher frequencies
        };

        // max heap for sorting characters by frequency
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> maxHeap(comp);

        for (const auto& entry : charCount) {
            maxHeap.push(entry);
        }

        string result = "";
        char prevChar = '\0';
        // here concept of prevChar is used to store the previous char which we popped from the heap
        // so that we can again push it back to the heap if it is able to be used

        // start result by including the character with highest frequency till heap is empty
        while (!maxHeap.empty()) {
            auto current = maxHeap.top();
            maxHeap.pop();
            result += current.first; // Add the character to the result
            charCount[current.first]--; // Decrease its frequency

            // If the previous character exists and its frequency is greater than 0, add it back to the heap
            // here we are checking the prev char which we popped that if it is now again able to be used or not
            // if it is able to be used then we will push it back to the heap
            if (prevChar != '\0' && charCount[prevChar] > 0) {
                maxHeap.push({prevChar, charCount[prevChar]});
            }
            // we try to use all the char with highest frequency first and then followed by the next highest frequency char
            
            prevChar = current.first; // Update the previous character
        }

        // If the length of the result is not equal to the length of the input string, then it is not possible to reorganize the string
        return result.length() == S.length() ? result : "";
    }
};
