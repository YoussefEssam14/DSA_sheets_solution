#include <iostream>
#include <vector>

using namespace std;

// n <= 1e5, so we need O(n + m). n^2 will TLE
// The question basicaly says the neighbour of my neighbour is my neighbour :)
// I mean x <--> y <--> z is the same y <-->x <-->z
// He needs to sum all neighbours tasks and if it is even it counts as 1 message ow 0
/* It is basiclly dfs problem
You see first the root then the neighbours then the neighbours of ur neighbours and so on
it is the definitaion of recursive
Stopping condation: the neighbour is already visited (so we don't loop forever on x <--> y)
*/
// To make the solution written in an easy way i will use adj list
int dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector <int>&tasks) {
    /*
     Take care it may leads to stack overflow (You can increase your stack depth and capcity (search on it if intersted))
     or you can solve it itrative DFS
    */
    visited[u] = true;
    int result = 0;
    for(auto v : adj[u]){
        if (!visited[v]){
            result += dfs(v, adj, visited,tasks);
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