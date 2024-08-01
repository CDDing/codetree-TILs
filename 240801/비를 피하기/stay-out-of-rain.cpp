#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n,m,h;
int main() {
    cin>>n>>h>>m;

    vector<vector<int>> numlist(n,vector<int>(n,0));
    vector<vector<int>> visited(n,vector<int>(n,-1));
    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            numlist[i][j]=num;
            if(num==3){
                q.push({i,j});
                visited[i][j]=0;
            }
        }
    }


    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        auto x = cur.first;
        auto y = cur.second;

        if(x+1<n&&(visited[x+1][y]==-1||visited[x][y]+1<visited[x+1][y])&&numlist[x+1][y]!=1){
            visited[x+1][y]=visited[x][y]+1;
            q.push({x+1,y});
        }
        if(y+1<n&&(visited[x][y+1]==-1||visited[x][y]+1<visited[x][y+1])&&numlist[x][y+1]!=1){
            visited[x][y+1]=visited[x][y]+1;
            q.push({x,y+1});
        }
        if(x-1>=0&&(visited[x-1][y]==-1||visited[x][y]+1<visited[x-1][y])&&numlist[x-1][y]!=1){
            visited[x-1][y]=visited[x][y]+1;
            q.push({x-1,y});
        }
        if(y-1>=0&&(visited[x][y-1]==-1|visited[x][y]+1<visited[x][y-1])&&numlist[x][y-1]!=1){
            visited[x][y-1]=visited[x][y]+1;
            q.push({x,y-1});
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(numlist[i][j]==2){
                cout<<visited[i][j]<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}