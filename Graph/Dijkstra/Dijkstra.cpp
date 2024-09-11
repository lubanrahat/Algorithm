#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
#define PI 3.1415926535897932384626
#define rep(i,n) for(int i = 0; i < n; i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)

vector<pair<int,int>> adj[100005];
int dis[100005];

class cmp {
public:
    bool operator()(pair<int,int> a,pair<int,int> b) {
        return a.second > b.second;
    }
};

void dijkstra(int src) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({src,0});
    dis[src] = 0;
    
    while(!pq.empty()) {
        auto prent = pq.top();
        pq.pop();
        int node = prent.first;
        int cost = prent.second;

        for(auto child: adj[node]) {
            int childNode = child.first;
            int childCost = child.second;

            if(cost+childCost < dis[childNode]) {
                dis[childNode] = cost+childCost;
                pq.push({childNode,dis[childNode]});
            }
        }
    }
}
 
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertex,edge;
    cin>>vertex>>edge;

    rep(i,edge) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    rep(i,vertex) {
        dis[i] = INT_MAX;
    }

    dijkstra(0);

    rep(i,vertex) {
        cout<<i<<" -> "<<dis[i]<<endl;
    }

    return 0;
}