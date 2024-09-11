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
vector<int> prentArray(100005,-1);
bool flag = false;

void BFS(int source) {
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while(!q.empty()) {
        int prent = q.front();
        q.pop();

        cout<<prent<<" ";

        for(auto child: adj[prent]) {
            if(visited[child] && prentArray[prent] != child) {
                flag = true;
            }
            if(!visited[child]) {
                visited[child] = true;
                prentArray[child] = prent;
                q.push(child);
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
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source;
    cin>>source;

    BFS(source);

    if(flag) {
        cout<<"Cycle Detect!"<<endl;
    } else {
        cout<<"Cycle not Detect!"<<endl;
    }

    return 0;
}