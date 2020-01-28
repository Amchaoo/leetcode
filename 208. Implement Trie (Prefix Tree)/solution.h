#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    bool isWord = false;
    map<char, TrieNode*> next;
    TrieNode() {
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curNode = root;

        for (auto ch : word) {

            if (!curNode -> next[ch]) {
                curNode = curNode -> next[ch] = new TrieNode();
            }
            else {
                curNode = curNode -> next[ch];
            }
        }

        curNode -> isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curNode = root;

        for (auto ch : word) {
            curNode = curNode -> next[ch];

            if (!curNode) {
                return false;
            }
        }

        return curNode -> isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curNode = root;

        for (auto ch : prefix) {
            curNode = curNode -> next[ch];

            if (!curNode) {
                return false;
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */