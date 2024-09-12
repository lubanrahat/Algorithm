#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
#define PI 3.1415926535897932384626
#define rep(i,n) for(int i = 0; i < n; i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 vertex,edge;
    cin>>vertex>>edge;

    i64 adj[vertex][vertex];

    for(int i = 0; i < vertex; i++) {
        for(int j = 0; j < vertex; j++) {
            adj[i][j] = INT_MAX;
            if(i == j) {
                adj[i][j] = 0;
            }
        }
    }

    rep(i,edge) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u][v] = w;
    }

    for(int k = 0; k < vertex; k++) {
        for(int i = 0; i < vertex; i++) {
            for(int j = 0; j < vertex; j++) {
                if(adj[i][k]+adj[k][j] < adj[i][j]) {
                    adj[i][j] = adj[i][k]+adj[k][j];
                }
            }
        }
    }

    for(int i = 0; i < vertex; i++) {
        for(int j = 0; j < vertex; j++) {
            if(adj[i][j] == INT_MAX) cout<<"INT";
            else
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}