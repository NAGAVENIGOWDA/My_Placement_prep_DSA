//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    // Function to count the number of substrings with at most k distinct characters
    long long int countSubstringsWithAtMostKDistinctChars(string &s, int k) {
        int left = 0, right = 0, n = s.size(), distinctCount = 0;
        long long int substringCount = 0;

        // Vector to store the frequency of characters in the current substring
        vector<int> charFrequency(26, 0);

        while (right < n) {
            int charIndex = s[right] - 'a';
            charFrequency[charIndex]++;

            // If the frequency becomes 1, it means a new distinct character is added
            if (charFrequency[charIndex] == 1) {
                distinctCount++;
            }

            // While the number of distinct characters exceeds k, move the left pointer
            while (distinctCount > k) {
                charFrequency[s[left] - 'a']--;

                // If the frequency becomes 0, it means a distinct character is removed
                if (charFrequency[s[left] - 'a'] == 0) {
                    distinctCount--;
                }

                left++;
            }

            // Add the count of substrings with at most k distinct characters
            substringCount += (right - left + 1);

            // Move the right pointer to expand the window
            right++;
        }

        return substringCount;
    }

    long long int substrCount(string s, int k) {
        // Count substrings with at most k distinct characters
        long long int countAtMostK = countSubstringsWithAtMostKDistinctChars(s, k);

        // Count substrings with at most (k-1) distinct characters
        long long int countAtMostKMinus1 = countSubstringsWithAtMostKDistinctChars(s, k - 1);

        // The difference gives the count of substrings with exactly k distinct characters
        return countAtMostK - countAtMostKMinus1;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends