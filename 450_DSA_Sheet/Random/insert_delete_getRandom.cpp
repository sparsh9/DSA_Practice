class RandomizedSet {
public:
    RandomizedSet() {
        ans.clear();
        mp.clear();
        return ;
    }
    
    bool insert(int val) {
        // check if exists or not
        if(mp.find(val)!=mp.end())
        {
            return false;
        }    
        // if not present, then add it
        ans.push_back(val); // ans vector has elements
        mp[val]=ans.size()-1; // map has {key=val, value=index}
        return true;
    }
    
    bool remove(int val) {
        // check if exists or not
        if(mp.find(val)==mp.end())
        {
            return false;
        }
        // if present, then remove it
        
        // swap with last element
        int last=ans.back(); // get the last element
        mp[last]=mp[val]; // update the index of last element
        ans[mp[val]]=last; // update the last element
        ans.pop_back(); // remove the last element
        mp.erase(val); // remove the element from map
        return true;
    }
    
    int getRandom() {
        return ans[rand()%ans.size()];
    }
};