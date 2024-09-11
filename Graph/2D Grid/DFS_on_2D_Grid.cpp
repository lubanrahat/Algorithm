#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
#define PI 3.1415926535897932384626
#define rep(i,n) for(int i = 0; i < n; i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)

int n,m;
char a[10005][10005];
bool visited[10005][10005];
vector<pair<int,int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};

bool isValid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    return true;
}

void DFS(int si,int sj) {
    cout<<si<<" "<<sj<<endl;
    visited[si][sj] = true;
    for(int i = 0; i < 4; i++) {
        int ci = si + dir[i].first;
        int cj = sj + dir[i].second;
        
        if(isValid(ci,cj) && !visited[ci][cj]) {
            DFS(ci,cj);
        }
    }
} 

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
        }
    }

    int si,sj;
    cin>>si>>sj;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }

    DFS(si,sj);

    return 0;
}