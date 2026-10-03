class MyHashSet {
    private:
    vector<bool> hash;
public:
    MyHashSet() {
        hash.resize(1000001,false);
    }
    
    void add(int key) {
        hash[key]=true;
    }
    
    void remove(int key) {
        hash[key]=false;
    }
    
    bool contains(int key) {
        return hash[key];
    }
};

