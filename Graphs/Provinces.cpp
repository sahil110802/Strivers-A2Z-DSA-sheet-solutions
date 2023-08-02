

// DFS Solution...
void dfs(vector<vector<int>>& M, vector<bool>& vis, int i){
    vis[i]=1;
    for(int j=0;j<M.size();j++){
        if(M[i][j]==1 and !vis[j])dfs(M,vis,j);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0,n=isConnected.size();
        if(n==0)return 0;
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(isConnected,vis,i);
            }
        }
        return ans;
    }



// BFS Solution...
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int c=0;
        int node;
        for(int i=0;i<n;i++){
            if(isConnected[i][i]!=1)continue;
            queue<int>Q;
            Q.push(i);
            while(!Q.empty()){
                node=Q.front();
                Q.pop();
                isConnected[node][node]=2;
                for(int j=0;j<n;j++){
                    if(isConnected[node][j]==1){
                        Q.push(j);
                        isConnected[node][j]=2;
                        isConnected[j][node]=2;
                    }
                }
            }c++;
        }
        return c;
    }
};
