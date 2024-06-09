//{ Driver Code Starts

/*

A Techfest is underway, and each participant is given a ticket with a unique number. 
Organizers decide to award prize points to everyone who has a ticket ID between a and b (inclusive).
The points given to a participant with ticket number x will be the sum of powers of the prime factors of x.

For instance, if points are to be awarded to a participant with ticket number 12, the amount of points 
given out will be equal to the sum of powers in the prime factorization of 12 (22 × 31), 
which will be 2 + 1 = 3.

Given a and b, determine the sum of all the points that will be awarded to the participants with 
ticket numbers between a and b (inclusive).


 */
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

int solve(int n, const std::vector<int>& spf) {
    int count = 0;
    while (n != 1) {
        count++;
        n = n / spf[n];
    }
    return count;
}

int sumOfPowers(int a, int b) {
    // Initialize SPF array
    std::vector<int> spf(b + 1);
    for (int i = 2; i <= b; ++i) {
        spf[i] = i;
    }

    // Sieve of Eratosthenes to find smallest prime factors
    for (int i = 2; i * i <= b; ++i) {
        if (spf[i] == i) { // Check if 'i' is a prime
            for (int j = i * i; j <= b; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    int count = 0;

    // Calculate the sum of the counts of prime factors for each number in range [a, b]
    for (int i = a; i <= b; ++i) {
        if (i <= b) {
            count += solve(i, spf);
        } 
    }

    return count;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends