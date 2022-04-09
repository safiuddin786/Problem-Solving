#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <stack>
using namespace std;

// trie node
class TrieNode{
    public:
        unordered_map<char, TrieNode*> nextNodes;
        bool isEndOfWord;
};

//  with only add and search
class Trie{
    public:
        TrieNode *root;

        Trie(){
            this->root = new TrieNode();
        }

        //  add word in the trie
        void addWord(string word){
            TrieNode *temp = root;
            int i = 0;
            int n = word.length();
            while(i < n){
                if((temp->nextNodes).find(word[i]) == (temp->nextNodes).end()){
                    (temp->nextNodes)[word[i]] = new TrieNode();
                    for(i=i+1;i<n;i++){
                        temp = (temp->nextNodes)[word[i-1]];
                        (temp->nextNodes)[word[i]] = new TrieNode();
                    }
                    (temp->nextNodes)[word[i-1]]->isEndOfWord = true;
                    break;
                }
                else temp = (temp->nextNodes)[word[i]];
                i++;
            }
        }

        // dfs traverse
        bool dfs(TrieNode* temp, string &word, int i, int &n){
            for(i; i<n; i++){
                if(word[i] == '.'){
                    bool check = false;
                    for(auto a : temp->nextNodes){
                        check = dfs(a.second, word, i+1, n);
                        if(check) return true;
                    }
                    return false;
                }
                if((temp->nextNodes).find(word[i]) != (temp->nextNodes).end()){
                    temp = temp->nextNodes[word[i]];
                }
                else{
                    return false;
                }
            }
            if(temp->isEndOfWord) return true;
            else return false;
        }

        // search word in the trie
        bool search(string word){
            TrieNode *temp = root;
            int i = 0;
            int n = word.length();
            stack<TrieNode> s;
            for(i;i<n;i++){
                //  if its a dot
                if(word[i] == '.'){
                    return dfs(temp, word, i, n);
                }
                if((temp->nextNodes).find(word[i]) != (temp->nextNodes).end()){
                    temp = (temp->nextNodes)[word[i]];
                }else{
                    return false;
                }
            }
            if(temp->isEndOfWord) return true;
            else return false;
        }
};


int main(){
    Trie *t = new Trie();
    t->addWord("bad");
    t->addWord("dad");
    t->addWord("mad");
    cout<<t->search("pad")<<endl<<t->search("bad")<<endl<<t->search(".ad")<<endl<<t->search("b..");
    return 0;
}