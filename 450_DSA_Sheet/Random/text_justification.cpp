class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int start = 0;

        while (start <words.size()) {
            int end = start;
            int lineLength = words[end].length();

            while (end + 1 < words.size() && lineLength + words[end + 1].length() + (end + 1 - start) <= maxWidth) {
                ++end;
                lineLength += words[end].length();
            }

            string line = words[start];
            int numWords = end - start;

            if (end == words.size() - 1 || numWords == 0) { // Left justify for last line or single word line
                for (int i = start + 1; i <= end; ++i) {
                    line += " " + words[i];
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                int totalSpaces = maxWidth - lineLength;
                int spacesBetweenWords = totalSpaces / numWords;
                int extraSpaces = totalSpaces % numWords;

                for (int i = start + 1; i <= end; ++i) {
                    int spaces = spacesBetweenWords + (extraSpaces-- > 0 ? 1 : 0);
                    line += string(spaces, ' ') + words[i];
                }
            }

            result.push_back(line);
            start = end + 1;
        }

        return result;
    }
};





class Solution {
public:
    int MAX_WIDTH;
    string getFinalWord(int i, int j, int eachWordSpace, int extraSpace, vector<string>& words) {
        string s;

        for(int k = i; k < j; k++) {
            s += words[k];

            if(k == j-1)
                continue;

            for(int space = 1; space <= eachWordSpace; space++)
                s += " ";

            if(extraSpace > 0) {
                s += " ";
                extraSpace--;
            }
        }

        while(s.length() < MAX_WIDTH) {
            s += " ";
        }
        
        return s;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n     = words.size();
        MAX_WIDTH = maxWidth;
        int i     = 0;
        
        while(i < n) {
            int lettersCount = words[i].length(); // total count of letters in words in a line
            int j            = i+1; // index of next word
            int spaceSlots   = 0; // total spaces in between words
            //        total spaces in between + curr word space +  next word + 1 space before next word
            
            while(j < n && spaceSlots + lettersCount + (words[j].length() + 1) <= maxWidth) {
                lettersCount += words[j].length();
                spaceSlots   += 1;
                j++;
            }

            // after adding possible words in a line and spaces between them,
            // the remaining slots are to be filled with spaces
            int remainingSlots = maxWidth - lettersCount; 
            
            // total space left is divided equally among the space slots in between words
            // if space slots is not 0, then divide equally , else no need to divide
            int eachWordSpace = spaceSlots == 0 ? 0 : remainingSlots / spaceSlots;

            // if there is any extra space left or it is odd, then add it to the first few slots
            int extraSpace    = spaceSlots == 0 ? 0 : remainingSlots % spaceSlots;
            
            // if we are on last line, then left justify
            if(j == n) { //Means we are on last line - Left justfied
                eachWordSpace = 1;
                extraSpace    = 0;
            }
            
            // we passing information to form the line with words from i to j
            result.push_back(getFinalWord(i, j, eachWordSpace, extraSpace, words));
            // now line is formed, then start from next word and next line for which i = j
            i = j;
        }
        
        return result;
    }
};
