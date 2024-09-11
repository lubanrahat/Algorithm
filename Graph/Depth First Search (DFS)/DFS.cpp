#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
#define PI 3.1415926535897932384626
#define rep(i,n) for(int i = 0; i < n; i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)

vector<int> adj[100005];
vector<int> visited(100005,false);

void DFS(int source) {
    visited[source] = true;

    cout<<source<<" ";

    for(auto child: adj[source]) {
        if(!visited[child]) {
            visited[child] = true;
            DFS(child);
        }
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertex,edge;
    cin>>vertex>>edge;

    rep(i,edge) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source;
    cin>>source;

    DFS(source);

    return 0;
}