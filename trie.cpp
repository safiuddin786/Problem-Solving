#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
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

        // search word in the trie
        bool search(string word){
            TrieNode *temp = root;
            int i = 0;
            int n = word.length();
            while(i < n){
                if((temp->nextNodes).find(word[i]) == (temp->nextNodes).end()){
                     cout<<"Not found";
                     return false;
                }
                else temp = (temp->nextNodes)[word[i]];
                i++;
            }
            if(temp->isEndOfWord) return true;
            else return false;
        }
};


int main(){
    Trie *t = new Trie();
    t->addWord("abca");
    t->addWord("dad");
    t->addWord("dada");
    cout<<t->search("aba")<<endl;
    return 0;
}