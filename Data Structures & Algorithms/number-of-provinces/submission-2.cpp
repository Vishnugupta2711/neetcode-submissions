class Solution {
public: 
    void dfs(int st , vector<vector<int>>& isConnected,vector<int>& vis){
        int n = isConnected.size();
        vis[st] = 1;
        for(int i = 0 ; i<n;i++){
            if(isConnected[st][i] == 1 && !vis[i]){
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,isConnected,vis);
            }
        }
        return cnt;
    }
};