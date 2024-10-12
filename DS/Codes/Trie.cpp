#include <iostream>
#include <vector>
using namespace std;

const int Alphabets = 26;

struct Trienode{
    struct Trienode* child[Alphabets];
    bool isEndOfWord;
};

struct Trienode* getnode(){
    struct Trienode* node = new Trienode;
    for(int i=0;i<Alphabets;i++){
        node->child[i]=NULL;
    }
    node->isEndOfWord = false;
    return node;
}

void insert(struct Trienode* root,string s){
    struct Trienode* temp=root;
    for(int i=0;i<s.size();i++){
        if(!temp->child[s[i]-'a']){
            temp->child[s[i]-'a']=getnode();
        }
        temp = temp->child[s[i]-'a'];
    }
    temp->isEndOfWord = true;
}

struct Trienode* search(struct Trienode* root,string s){
    struct Trienode* temp=root;
    for(int i=0;i<s.size();i++){
        temp = temp->child[s[i]-'a'];
        if(!temp) break;
    }
    return temp;
}

void autosuggest(struct Trienode* node,string s,vector <string> &res){
   for(int i=0;i<Alphabets;i++){
      if(node->child[i]){
         string temp=s;
         temp.push_back('a'+i);
         autosuggest(node->child[i],temp,res);
      }
   }
   if(node->isEndOfWord){
     res.push_back(s);
   }
}

int main(){
   struct Trienode* root=getnode();
   int n;cin>>n;
   while(n--){
     string s;cin>>s;
     insert(root,s);
   }
   int q;cin>>q;
   while (q--)
   {
     string s;cin>>s;
     struct Trienode* node = search(root,s);
     if(node){
        vector <string> res;
        autosuggest(node,s,res);
        sort(res.begin(),res.end());
        for(auto z:res) cout<<z<<"\n";
     }
     else{
        cout<<"No Suggestions\n";
     }
   }
   
}