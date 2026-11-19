#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
 It is very basic bellman-ford question ;)
*/
const int MAX = 1e9;


void bellman_ford(int n, vector<vector<pair<int, int>>>&adj, vector<int> &distance){


    
    for(int i = 0; i < n-1; i++){
        for(int v = 0; v <n ;v++){

            if(distance[v] == MAX) continue;

            for(auto [cost, u] : adj[v]){
                if (distance[u] > distance[v] + cost){
                    distance[u] = distance[v] + cost;
                }
            }
        }
    }

}


vector<string> minimumCosts(int n, vector<vector<int>> routes) {
    vector<vector<pair<int, int>>> adj(n);

    for(auto i = 0; i < routes.size(); i++){
        int a = routes[i][0];
        int b = routes[i][1];
        int cost = routes[i][2];
        adj[a].push_back({cost, b});
    }

    vector<int> distance(n, MAX);
    distance[0] = 0;
    bellman_ford(n, adj, distance);

    vector<string> res;
    res.push_back("0");

    for(int i = 1; i <n;i++){
        if(distance[i] == MAX) res.push_back("INF");
        else res.push_back(to_string(distance[i]));
    }

    return res;




}