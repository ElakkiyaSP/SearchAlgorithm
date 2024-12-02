class Solution {
public:
    vector<int> search(string& pat, string& txt) {
        vector<int> result; // To store indices of occurrences
        int m = pat.size();
        int n = txt.size();

        // Step 1: Compute the LPS array
        vector<int> lps(m, 0);
        int len = 0; // Length of previous longest prefix suffix
        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Step 2: Search for the pattern
        i = 0; // Index for txt
        int j = 0; // Index for pat
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == m) { // Found a match
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && txt[i] != pat[j]) { // Mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result; // Return the indices
    }
};
