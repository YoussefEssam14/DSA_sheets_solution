#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

/*
 It is topilogical sort problem
 For all the compenets you need the max depth it will be the max number of steps
 The only way that the factory cannot finish every task is that there is a compentet has a cycle
 To dedicat cycle i will use the methode of white, gray and black (see it on the refrance)
*/

int dfs(int u, vector<vector<int>>& adj, vector<int>& visited, vector<int>& dp) {

    visited[u] = 1;

    int depth = 0;

    for (int v : adj[u]) {

        if (visited[v] == 1)
            return -1;

        int childDepth;

        if (visited[v] == 2)
            childDepth = dp[v];
        else
            childDepth = dfs(v, adj, visited, dp);

        if (childDepth == -1)
            return -1;

        depth = max(depth, childDepth);
    }

    visited[u] = 2;
    return dp[u] = depth + 1;
}



int minimumRounds(int n, vector<vector<int>> dependencies) {
    vector<vector<int>> adj(n);

    for(int i = 0;  i< dependencies.size();i++){
        int a = dependencies[i][0];
        int b = dependencies[i][1];
        adj[a].push_back(b);
    }

    vector<int> visited(n, 0);
    vector<int> depth(n, 0);
    int cycle = 1;
    for(int i = 0; i <n;i++){
        if(!visited[i]){
            cycle = dfs(i, adj, visited, depth);
            if (cycle == -1) return -1;
        }
    }
    return *max_element(depth.begin(), depth.end());
}