#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // Sort the dictionary to ensure smallest lexicographical word comes first
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b) {
            return a.size() == b.size() ? a < b : a.size() > b.size();
        });

        for (const string& word : dictionary) {
            if (isSubsequence(s, word)) {
                return word;
            }
        }

        return "";
    }

private:
    bool isSubsequence(const string& s, const string& word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) {
                j++;
            }
            i++;
        }
        return j == word.size();
    }
};
