// class Solution {
// public:
//     int characterReplacement(string s, int k) {
        
//         int maxx = 0;
//         for (int i = 0; i < s.size(); i++) {
//             // if (i > 0) {
//             //     count[s[i-1]-'A']--;
//             // }
//             vector<int> count(26);
//             count[s[i]-'A']++;
//             for (int j = i+1; j < s.size(); j++) {
//                 count[s[j]-'A']++;
//                 auto max_value = *std::ranges::max_element(count);
//                 if (j-i+1-max_value <= k) {
//                     maxx = max(maxx, j-i+1);
//                 }
//             }
//         }
//         return maxx;

//     }
// };

/*
    Given a string s & an int k, can change any char k times:
    Return length of longest substring containing same letter
    Ex. s = "ABAB" k = 2 -> 4 "AAAA", s = "AABABBA" k = 1 -> 4

    Sliding window, expand if can change char, contract if > k

    Time: O(n)
    Space: O(26)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int maxCount = 0;
        
        int i = 0;
        int j = 0;
        
        int result = 0;
        
        while (j < s.size()) {
            cout << "Current i is " << i << " and current j is " << j << endl;
            count[s[j] - 'A']++;
            maxCount = max(maxCount, count[s[j] - 'A']);
            if (j - i + 1 - maxCount > k) {
                count[s[i] - 'A']--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        
        return result;
    }
};

