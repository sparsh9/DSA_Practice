// Approach 1 (using backtracking algorithm and sets as datastructure to avoid duplicates)
void Permute(int level , string S , set<string>&st)
{
    if(level == S.length()) // reached the end level / bottom part of the tree
    {
        st.insert(S);
        return;
    }
    
    for(int i = level ; i < S.length() ; i++)
    {
        swap(S[level],S[i]); // Changing the level(th) index with other characters
        Permute(level+1,S,st); // continuing as dfs for a particular combination
        swap(S[level],S[i]); // Changing back to original condition for other combinations on same level
    }
}


vector<string>find_permutation(string S)
{
    vector<string>ans;
    set<string>st;
    Permute(0,S,st);
    // Converting back to vector form
    for(auto it : st)
    {
        ans.push_back(it);
    }
    return ans;
}
