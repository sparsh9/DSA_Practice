class Solution {
public:
    bool wordPattern(string pattern, string s) {

        // split the string s into words
        vector<string> words;
        string word = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }
        words.push_back(word);

        // if the number of words is not equal to the number of characters in pattern
        // then return false
        if (words.size() != pattern.size())
            return false;

        // create two maps to store the mapping of characters to words and vice versa
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        // iterate through the pattern and check if the mapping is correct
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            // if the character is already mapped to a word
            // and the word is not the same as the current word
            // then return false
            if (charToWord.find(c) != charToWord.end() && charToWord[c] != w)
                return false;

            // if the word is already mapped to a character
            // and the character is not the same as the current character
            // then return false
            if (wordToChar.find(w) != wordToChar.end() && wordToChar[w] != c)
                return false;

            // otherwise, update the maps
            charToWord[c] = w;
            wordToChar[w] = c;
        }

        // if all the checks are passed, then return true
        return true;
    }
};