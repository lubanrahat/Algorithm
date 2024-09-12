#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
#define PI 3.1415926535897932384626
#define rep(i,n) for(int i = 0; i < n; i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)

class Edge {
public:
    int u,v,w;
    Edge(int u,int v,int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int dis[100005];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertex,edge;
    cin>>vertex>>edge;

    vector<Edge> edgeList;

    rep(i,edge) {
        int u,v,w;
        cin>>u>>v>>w;
        edgeList.push_back(Edge(u,v,w));
    }

    rep(i,vertex) {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;

    for(int i = 1; i <= vertex-1; i++) {
        for(Edge j: edgeList) {
            int u = j.u,v = j.v, w = j.w;
            if(dis[u] < INT_MAX && dis[u]+w < dis[v]) {
                dis[v] = dis[u]+w;
            }
        }
    }

    bool flag = false;

    for(Edge j: edgeList) {
        int u = j.u,v = j.v, w = j.w;
        if(dis[u] < INT_MAX && dis[u]+w < dis[v]) {
            flag = true;
        }
    }

    for(int i = 0; i < vertex; i++) {
        cout<<i<<" -> "<<dis[i]<<" "<<endl;
    }

    if(flag) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }

    return 0;
}