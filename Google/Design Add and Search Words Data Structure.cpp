class Trie{
private:
    std::unique_ptr<Trie> children_[26] = {nullptr};
    bool end_ = false;
public:

    void addWord(const std::string& word){
        auto curr = this;
        for(auto c : word){
            if(curr->children_[c - 'a'] == nullptr){
                curr->children_[c - 'a'] = std::make_unique<Trie>();
            }
            curr = curr->children_[c - 'a'].get();            
        }
        curr->end_ = true;
    }

    bool search(const string::const_iterator curr, const string::const_iterator end) {
        if(curr == end){
            return end_;
        }

        if(*curr != '.'){
            return children_[*curr - 'a'] ? 
                children_[*curr - 'a']->search(curr + 1, end) : false;
        }

        for(char c = 'a'; c <= 'z'; c++){
            if(children_[c - 'a'] && children_[c - 'a']->search(curr + 1, end)){
                return true;
            }
        }
        return false;
    }

};




class WordDictionary {
public:
    Trie t;
    WordDictionary() {
        
    }
    
    void addWord(const string& word) {
        t.addWord(word);
    }
    
    bool search(const string& word) {
        return t.search(word.begin(), word.end());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
