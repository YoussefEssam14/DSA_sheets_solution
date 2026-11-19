#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
  When i saw that question says 2 types i thought of bipartite
  but it is not exactly bipartite: the type is on the EDGE not on the node,
  so one node can be reached by type 0 or type 1.
  So i split every node into 2 states: (node, type of the next jump)
  An edge of type t goes from (u, t) to (v, t ^ 1) -- the type flips every jump.
  It would work for n-types too if i keep the last type in the state :)
*/

/*
 Return -1 when:
 ---> target is isolated (and target != 0)
 ---> node 0 has no outgoing edges
 ---> routes exist but the types can't alternate somewhere in the middle
*/

/*
 BFS is enough because every jump costs 1, first time we reach a state is the shortest.
*/

int bfs(int startType, vector<vector<int>> &adjtype0, vector<vector<int>> &adjtype1, int n, int target) {

    vector<vector<int>> dist(n, vector<int>(2, -1));
    queue<pair<int,int>> q;
    dist[0][startType] = 0;
    q.push({0, startType});

    while (!q.empty()) {
        auto [u, type] = q.front(); q.pop();
        auto &adj = type ? adjtype1[u] : adjtype0[u];
        for (int v : adj) {
            if (dist[v][type ^ 1] != -1) continue;
            dist[v][type ^ 1] = dist[u][type] + 1;
            q.push({v, type ^ 1});
        }
    }

    int a = dist[target][0], b = dist[target][1];
    if (a == -1) return b;
    if (b == -1) return a;
    return min(a, b);
}

int minimumJumps(int n, vector<vector<int>> jumps, int target) {

    if(target == 0) return 0;
    vector<vector<int>> adjtype0(n);
    vector<vector<int>> adjtype1(n);

    for(int i = 0; i <jumps.size(); i++){
   
        int u = jumps[i][0];
        int v = jumps[i][1];
        int type = jumps[i][2];

        if(type){
            adjtype1[u].push_back(v);
            adjtype1[v].push_back(u);
        }
        else {
            adjtype0[u].push_back(v);
            adjtype0[v].push_back(u);
        }
     
        
    }
    int r0 = bfs(0, adjtype0, adjtype1, n, target); 
    int r1 = bfs(1, adjtype0, adjtype1, n, target); 
    if (r0 == -1) return r1;
    if (r1 == -1) return r0;
    return min(r0, r1);
    



}

