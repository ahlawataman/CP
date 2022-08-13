class Trie
{
    Trie* children[26] = {};
    bool isEnd = false;
public:
    Trie(){}
    void addWord(string word, Trie* node);
    bool searchWord(string word, Trie* node);
    bool startsWith(string word, Trie* node);
};

void Trie::addWord(string word, Trie* node) {
    for(char &c: word) {
        int x = c - 'a';
        if(!node->children[x]) { node->children[x] = new Trie(); }
        node = node->children[x];
    }
    node->isEnd = true;
}

bool Trie::searchWord(string word, Trie* node) {
    for(char &c: word) {
        int x = c - 'a';
        if(!node->children[x]) { return false; }
        node = node->children[x];
    }
    return node->isEnd;
}

bool Trie::startsWith(string word, Trie* node) {
    for(char &c: word) {
        int x = c - 'a';
        if(!node->children[x]) { return false; }
        node = node->children[x];
    }
    return true;
}

int main() {
    Trie* root = new Trie();
    cout<<"Add word : abcd";
    root->addWord("abcd", root);
    cout<<"\nSearch Word : abcd - "<<root->searchWord("abcd", root);
    cout<<"\nStarts with ab - "<<root->startsWith("ab", root);
}
