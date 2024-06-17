class Solution {
public:
    void dfs(string word, string& target, vector<string>& curr,unordered_map<string,int>& mp,
    unordered_set<string>& st,vector<vector<string>>& ans){
        
        curr.push_back(word);
        if(word == target){
            reverse(curr.begin(),curr.end());
            ans.push_back(curr);
            reverse(curr.begin(),curr.end());
            curr.pop_back();
            return;
        }
        
        int curlvl = mp[word];
        for(int i=0;i<word.size();i++){
            char og = word[i];
            for(char j='a';j<='z';j++){
                word[i] = j;
                if(st.count(word) && mp[word] == curlvl-1){
                    dfs(word,target,curr,mp,st,ans);
                }
            }
            word[i] = og;
        }
        curr.pop_back();
        
    }
    
    void bfs(string bWord,string eWord, unordered_set<string> st, unordered_map<string,int>& mp){
        
        queue<string> q;
        q.push(bWord);
        st.erase(bWord);
        mp[bWord] = 0;
        int level = 1;
        
        while(!q.empty()){
            int n = q.size();
            while(n-- > 0){
                string word = q.front();
                q.pop();
                
                for(int i=0;i<word.size();i++){
                    char og = word[i];
                    for(char j='a';j<='z';j++){
                        word[i] = j;
                        if(st.count(word)){
                            mp[word] = level;
                            q.push(word);
                            st.erase(word);
                            if(word==eWord)
                                return;
                        }
                    }
                    word[i] = og;
                }
                
            }
            level++;
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        unordered_map<string,int> mp;
        vector<vector<string>> ans;
        vector<string> curr;
        bfs(beginWord,endWord,st,mp);
        st.insert(beginWord);
        dfs(endWord,beginWord,curr,mp,st,ans);
        return ans;
    }
};