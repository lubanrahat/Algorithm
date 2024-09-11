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
int dis[10005][10005];

bool isValid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    return true;
}

void BFS(int si,int sj) {
    queue<pair<int,int>> q;
    q.push({si,sj});
    visited[si][sj] = true;
    dis[si][sj] = 0;

    while(!q.empty()) {
        auto prent = q.front();
        q.pop();
        cout<<prent.first<<" "<<prent.second<<endl;
        for(int i = 0; i < 4; i++) {
            int ci = prent.first + dir[i].first;
            int cj = prent.second + dir[i].second;

            if(isValid(ci,cj) && !visited[ci][cj]) {
                visited[ci][cj] = true;
                q.push({ci,cj});
                dis[ci][cj] = dis[prent.first][prent.second]+1;
            }
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

     for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dis[i][j] = -1;
        }
    }

    BFS(si,sj);

    cout<<dis[0][3]<<endl;

    return 0;
}