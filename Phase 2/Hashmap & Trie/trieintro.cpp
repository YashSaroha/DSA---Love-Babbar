#include<iostream>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;

    TrieNode(char ch){
        data = ch;
        isTerminal = false;
        for(int i=0 ; i<26 ; i++)
            children[i] = NULL;
    }
};

class Trie {
    public:
    TrieNode* root;
    // constructor
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root , string word){
        // base case : agr word ki length 0 hogyi mtlb sare string ke characters insert kr liye to last char ko terminal bna dia
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        // find index to insert in children array (index is basically mapping of 0-25 index for character A-Z)
        // assumption : word will be in CAPS
        int index = word[0] - 'A';

        TrieNode *child ;

        // if child of root is present
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }

        // child not present to insert kro child ko and aage bdh jao
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }   

        // RECURSION
        insertUtil(child , word.substr(1));
        // child node is the root node now and remaining word after inserting first char is substr(1)
    }

    void insertWord(string word){
        insertUtil(root , word);
    }

};


int main()
{
    Trie* t = new Trie();
    t -> insertWord("abcd");
}