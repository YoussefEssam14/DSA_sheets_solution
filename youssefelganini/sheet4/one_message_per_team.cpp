#include <iostream>
#include <vector>

using namespace std;

// The input is n^2 so if you get an solution with n^2 it will be accepated
// The solution basicaly says the neighbour of my neighbour is my neighbour :)
// I mean x <--> y <--> z is the same y <-->x <-->z
// He needs to sum all neighbours tasks and if it is even it will cost you 1 ow it costs 0
// It is basiclly dfs problem 
// To make the solution written in an easy way i will use adj list (I can solve it without it)
int dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector <int>&tasks) {
    visited[u] = true;
    int result = 0;
    for(auto v : adj[u]){
        if (!visited[v]){
            result += dfs(v, adj, visited);
        }
    }

    return result + tasks[u];
}
int countBalancedTeams(vector<int> tasks, vector<vector<int>> relationships) {


    int num_empl = tasks.size();

    vector<vector<int>> adj(num_empl);   
    vector<bool> visited(num_empl);

    int r = relationships.size();

    for (int i = 0; i < r; i++) {
        int u = relationships[i][0];
        int v = relationships[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cost = 0;
    for(int i = 0; i < num_empl; i++){
        if(!visited[i] ){
            dfs(i, adj, visited, tasks) % 2 ? :cost++; 
        }
    }
    return cost;

}