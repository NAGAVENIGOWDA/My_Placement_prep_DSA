//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
   void findParent(Node*root,unordered_map<Node*,Node*>&parent){
       queue<Node*>q;
       q.push(root);
       
       while(!q.empty()){
           Node* node=q.front();
           q.pop();
           
           if(node->left){
               parent[node->left]=node;
               q.push(node->left);
           }
           if(node->right){
               parent[node->right]=node;
               q.push(node->right);
           }
       }
   }
   
   void findTargetNode(Node* root, Node*& tarNode, int target) {
    if (root == NULL) return;
    if (root->data == target) {
        tarNode = root;
        return;
    }
    findTargetNode(root->left, tarNode, target);
    findTargetNode(root->right, tarNode, target);
}

    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*>parent;
        findParent(root,parent);
        
        //target data is given not the node-so find the node first
        
        Node*tarNode=NULL;
        findTargetNode(root,tarNode,target);
        
        if(tarNode==NULL) return {};
        
        //find nodes at distance k
        
        queue<Node*>q ;
        unordered_map<Node*,bool>visited;
        visited[tarNode]=true;
        q.push(tarNode);
        int dis=0;
        
       while (!q.empty() ) {
           
           
        int n = q.size();
        for (int i = 0; i < n; i++) {
        Node* node = q.front();
        q.pop();

        // up
        if (parent[node] && !visited[parent[node]]) {
            q.push(parent[node]);
            visited[parent[node]] = true;
        }

        // left
        if (node->left && !visited[node->left]) {
            q.push(node->left);
            visited[node->left] = true;
        }

        // right
        if (node->right && !visited[node->right]) {
            q.push(node->right);
            visited[node->right] = true;
        }
    }
    if(!q.empty()) dis++;
    
    }

         
      
    
    return dis;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends