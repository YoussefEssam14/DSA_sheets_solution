#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
It lookslikes toplogical sort but it is not ig
My approach is very intative just make your adj list 
The broken node will be in connected compenent just print them sorted in non decresing order
It can also solved by BFS but for me writting DFS is much easier
*/
void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &result){

    visited[u] = true;
    result.push_back(u);


    for(auto v: adj[u]){
        if(!visited[v])
        dfs(v, adj, visited, result);
    }
}

vector<int> blockedPackages(int n, vector<vector<int>> dependencies, int broken) {

    vector<vector<int>> adj(n);

    for(int i = 0; i <dependencies.size();i++){
        int u = dependencies[i][0];
        int v = dependencies[i][1];

        adj[v].push_back(u);
    }

    vector<int> result;
    vector<bool> visited(n, false);
    dfs(broken, adj,visited ,result);

    sort(result.begin(), result.end());
    return result;

}
