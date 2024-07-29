#include <iostream>
#include <vector>
#include <utility>

#include <queue>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> numlist(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num;
            cin>>num;
            numlist[i][j]=num;
        }
    }

    queue<pair<int,int>> q;
    q.push({0,0});
    vector<vector<int>> visited(n,vector<int>(m,false));
    visited[0][0]=true;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        auto x = cur.first;
        auto y = cur.second;

        if(x+1<n&&!visited[x+1][y]&&numlist[x+1][y]){
            q.push({x+1,y});
            visited[x+1][y]=true;
        }
        if(y+1<m&&!visited[x][y+1]&&numlist[x][y+1]){
            q.push({x,y+1});
            visited[x][y+1]=true;
        }
        if(x-1>=0&&!visited[x-1][y]&&numlist[x-1][y]){
            q.push({x-1,y});
            visited[x-1][y]=true;
        }
        if(y-1>=0&&!visited[x][y-1]&&numlist[x][y-1]){
            q.push({x,y-1});
            visited[x][y-1]=true;
        }


    }

    cout<<visited[n-1][m-1];
    return 0;
}