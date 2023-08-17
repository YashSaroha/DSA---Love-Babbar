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
        // base case
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child ;

        // child present
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }

        // child absent
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }   

        insertUtil(child , word.substr(1));
    }


    void insertWord(string word){
        insertUtil(root , word);
    }


    bool searchUtil(TrieNode* root , string word){
        // base case
        if(word.length() == 0){
            return root -> isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child; 

        // present
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            // absent
            return false;
        }

        return searchUtil(child , word.substr(1));

    }

    bool searchWord(string word){
        return searchUtil(root , word);
    }



    void deleteUtil(TrieNode* root , string word){
        // base case
        if(word.length() == 0){
            root -> isTerminal = false;
            cout << "deleted successfully" << endl;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child; 

        // present
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            // absent
            cout << "already absent" << endl;
        }

        return deleteUtil(child , word.substr(1));
        
    }

    void deleteWord(string word){
        deleteUtil(root , word);
    }


};


int main()
{
    Trie* t = new Trie();
    t -> insertWord("ARM");
    t -> insertWord("DO");
    t -> insertWord("TIME");

    cout << "present or not : " << t -> searchWord("DO") << endl;

    t -> deleteWord("DO");
    
    cout << "present or not : " << t -> searchWord("DO") << endl;

    return 0;
    
}