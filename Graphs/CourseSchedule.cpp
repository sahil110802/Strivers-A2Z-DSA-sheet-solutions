


// BFS or Kahn's Algo.. for topological sort== Directed Acyclic Graph
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0];
            int v=pre[i][1];
            adj[u].push_back(v);
        }

        // find indegree
        vector<int>indegree(n);
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }

        // push if indegree is 0
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }

        vector<int>ans;

        // do bfs
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        return (ans.size()==n); //true if NO cycle
    }
};




//DFS TOPOSORT




// DFS
class Solution {
public:
    bool dfs(unordered_map<int,list<int>>&adj,vector<int>&visited,int node){
        if(visited[node]==1)return 1;
        if(visited[node]==0){
            visited[node]=1;
            for(auto it:adj[node]){
                if(dfs(adj,visited,it))return 1;
            }
        }

        visited[node]=2;
        return 0;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        unordered_map<int,list<int>>adj;
        vector<int>visited(n,0);
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0];
            int v=pre[i][1];
            adj[u].push_back(v);
        }

        for(int i=0;i<n;i++){
            
                bool cycleFound=dfs(adj,visited,i);
                if(cycleFound){
                    return 0;
                }
            
        }
        return 1;
        
    }
};
