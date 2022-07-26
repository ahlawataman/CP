class Trie {
public:

    Trie* children[26] = {};
    bool isEnd = false;;
    
    Trie() {}
    
    void insert(string word) {
        Trie* node = this;
        for(char &c: word) {
            char ch = c - 'a';
            if(!node->children[ch]) { node->children[ch] = new Trie(); }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char &c: word) {
            char ch = c - 'a';
            if(!node->children[ch]) { return false; }
            node = node->children[ch];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char &c: prefix) {
            char ch = c - 'a';
            if(!node->children[ch]) { return false; }
            node = node->children[ch];
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
