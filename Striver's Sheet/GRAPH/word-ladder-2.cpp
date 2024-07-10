//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        
        set<string> st (wordList.begin(),wordList.end()) ;
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        vector<string>levelRemove;
        st.erase(beginWord);
        
        vector<vector<string>>ans;
        
        while(!q.empty()){
            
            int n=q.size();
            //to keep track of levels
           
            
            while(n--){
                
                 vector<string> top=q.front();
                 q.pop();
                 
                 string word=top.back();
                
                
                //shortest sequences so..
                
                if(word==endWord){
                    if(ans.size()==0) ans.push_back(top); //first possible ans
                    
                    else if(top.size() ==ans.back().size()){
                        ans.push_back(top);
                        //more than 1 ,check its size -cos we need shortest answers
                        //BFS will always give shortest answers
                    }
                }
                
                
                for(int i=0;i<word.size();i++){
                    
                    char original=word[i];
                    
                    for(char ptr='a' ; ptr<='z' ; ptr++){
                        word[i]=ptr;
                        
                        if(st.count(word) > 0){
                            //present
                            
                            top.push_back(word);
                            q.push(top);
                            levelRemove.push_back(word); //words need to be removed once the level is over
                            top.pop_back();
                        }
                    }
                    
                    word[i]=original; 
                }
                
            }
            
            
            
            
            //level is over 
            for(auto it : levelRemove){
                st.erase(it);
            }
            levelRemove.clear();
            
        }
        
        
    return ans;
    
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends