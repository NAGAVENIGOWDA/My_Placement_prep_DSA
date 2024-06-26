//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

struct node
{
    int key,val,cnt;
    node* prev;
    node* next;
    
    node(int k,int v)
    {
        key=k;
        val=v;
        cnt=1;
        prev=NULL;
        next=NULL;
    }
};


class List
{
    public:
    
    int size;
    node* head;
    node* tail;
    
    List()
    {
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
        head->prev=tail->next=NULL;
        size=0;
    }
    
    void addfront(node * temp)
    {
        temp->next=head->next;
        head->next->prev=temp;
        head->next=temp;
        temp->prev=head;
        size++;
    }
    
    void remove_node(node * temp)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        size--;
    }
    
};

class LFUCache {
public:
    
    int cap,minfreq;
    map<int,node*>keyval;
    map<int,List*>freqlist;
    
    LFUCache(int capacity) {
        cap=capacity; 
        minfreq=0;
    }
    
    int get(int key) {
          //if key is not present in the cache return -1
        if(keyval.find(key)==keyval.end())
        return -1;
        
        //if key is present in the cache
        node* cur=keyval[key];
        int value=cur->val;
        
        updatelist(cur);
        
        return value;
        
    }
    
    void put(int key, int value) {
        
        if(cap==0)
        return;
        
       //if key is already present in the cache, just we need to change the value and update it
        if(keyval.find(key)!=keyval.end())
        {
            node* cur=keyval[key];;
            cur->val=value;
            updatelist(cur);
            
        }
        else
        {   //if cache capacity is full, we remove LFU node from cache
           if(keyval.size()==cap)
           {
               //permanent removal of least frequently used node
                List * curlist=freqlist[minfreq];
                node* del=curlist->tail->prev;
                
                keyval.erase(del->key);
                curlist->remove_node(del); 
            }
            
              //Inserting the given key and value pair into cache
                minfreq=1;
                node* newnode=new node(key,value);
                keyval[key]=newnode;
                
                List* newlist=new List();
                
                if(freqlist.find(1)!=freqlist.end())
                newlist=freqlist[1];
                
                newlist->addfront(newnode);
                freqlist[1]=newlist;
   
        }
    }
    
// to update the node according to it's frequency in the list
    void updatelist(node* temp)
    {
      //removing the node from it's current frequency list
        List * curlist=freqlist[temp->cnt];
        curlist->remove_node(temp);
        
        if(temp->cnt==minfreq && curlist->size==0)
        minfreq++;
        
       //updating the node to it's new frequency list
        temp->cnt++;
        List* nextlist=new List();
        
        if(freqlist.find(temp->cnt)!=freqlist.end())
            nextlist=freqlist[temp->cnt];
        
        nextlist->addfront(temp);
        freqlist[temp->cnt]=nextlist;
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//{ Driver Code Starts.

int main(){
    int t = 1;
    cin >> t;

    while(t--){
        int capacity; cin >> capacity;
        LFUCache* obj = new LFUCache(capacity);

        int runs; cin >> runs;
        for(int i = 0;i<runs;i++){
            int s; cin >> s;
            if(s==1){
                int key; cin >> key;
                int param_1 = obj->get(key);
                cout << param_1 << endl;
            }else{
                int key,value;
                cin >> key >> value;
                obj->put(key,value);
            }
            
            
            
        }
        


    }
}

// } Driver Code Ends