#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
using namespace std;
int answer=-1;
int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> numlist(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num;
            cin>>num;
            numlist[i][j]=num;
        }

    }

    queue<pair<int,int>> q;
    q.push({0,0});

    vector<vector<int>> visited(n,vector<int>(m,-1));
    visited[0][0]=1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        auto x = cur.first;
        auto y = cur.second;

        auto curcnt = visited[x][y];
        
        if(x+1<n&&(curcnt+1<visited[x+1][y] || visited[x+1][y]==-1)&&numlist[x+1][y]){
            visited[x+1][y]=curcnt+1;
            q.push({x+1,y});

        }
        if(y+1<m&&(curcnt+1<visited[x][y+1]||visited[x][y+1]==-1)&&numlist[x][y+1]){
            visited[x][y+1]=curcnt+1;
            q.push({x,y+1});
        }
        if(x-1>=0&&(curcnt+1<visited[x-1][y]||visited[x-1][y]==-1)&&numlist[x-1][y]){
            q.push({x-1,y});
            visited[x-1][y]=curcnt+1;
        }
        if(y-1>=0&&(curcnt+1<visited[x][y-1]||visited[x][y-1]==-1)&&numlist[x][y-1]){
            visited[x][y-1]=curcnt+1;
            q.push({x,y-1});
        }

    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<visited[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }



    cout<<visited[n-1][m-1]-1;


    return 0;
}