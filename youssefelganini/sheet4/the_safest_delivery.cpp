#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
using namespace std;

/*
 It is a basic dijkstra problem (UCS)
 Also you have to return the max edge in your route that is all
 As alaways make your adj list
*/

int ucs(vector<vector<pair<int, int>>> adj, vector<bool> & visited, int start, int target){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0, start});
    

    while(!pq.empty()){
        auto [cost, u] = pq.top(); pq.pop();
        visited[u] = 1;
        if(u == target) return cost;
        for(auto [vcost, v]:adj[u]){
            if(!visited[v]){
                pq.push({max(cost, vcost),v});
            }
        }

    }
    return -1;
}


int minimumRisk(int n, vector<vector<int>> roads, int start, int target) {

    vector<vector<pair<int, int>>> adj(n);

    for(int i = 0; i <roads.size();i++){
        int u = roads[i][0]; 
        int v = roads[i][1]; 
        int cost = roads[i][2]; 

        adj[u].push_back({cost, v});
        adj[v].push_back({cost, u});
    }
    vector<bool> visited(n);
    int cost = ucs(adj, visited, start, target);

    return cost;



}