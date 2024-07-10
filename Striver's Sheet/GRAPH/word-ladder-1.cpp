//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        queue<pair<string,int>> q;
        
        set<string>st(wordList.begin(),wordList.end());
        q.push({startWord,1});
        st.erase(startWord); 
        
        while(!q.empty()){
            
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            
            if(word==targetWord) return step;
            
            for(int i=0;i<word.size();i++){
                
                char original=word[i];
                
                for(char ptr='a' ; ptr<='z' ;ptr++){
                    word[i]=ptr;
                    
                    if(st.count(word) > 0){
                        //means present in the set
                        q.push({word,step+1});
                        st.erase(word); // we need to find out shortest transformation
                    }
                    
                    word[i]=original; //set it back to original -we need to change only 1 char
                }
            }
        }
        
        
    return 0;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends