#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
vector<int> dx = {1,1,-1,-1,2,2,-2,-2};
vector<int> dy = {2,-2,2,-2,1,-1,1,-1};
int main() {
    int n,r1,c1,r2,c2;
    cin>>n>>r1>>c1>>r2>>c2;
    r1--;c1--;r2--;c2--;
    queue<pair<int,int>> q;
    q.push({r1,c1});

    vector<vector<int>> visited(n,vector<int>(n,-1));
    visited[r1][c1]=0;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        auto x = cur.first;
        auto y = cur.second;

        for(int i=0;i<8;i++){
            auto afterx = x+dx[i];
            auto aftery = y+dy[i];

            if(afterx>=0&& afterx<n&&aftery>=0&&aftery<n&&(visited[x][y]+1<visited[afterx][aftery]||visited[afterx][aftery]==-1)){
                visited[afterx][aftery]= visited[x][y]+1;
                q.push({afterx,aftery});
            }
        }
    }
    cout<<visited[r2][c2];
    return 0;
}