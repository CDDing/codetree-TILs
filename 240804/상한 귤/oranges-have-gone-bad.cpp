#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;

    vector<vector<int>> gul(n,vector<int>(n,0));
    vector<vector<int>> visited(n,vector<int>(n,-1));
    
    queue<pair<int,int>> q;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            gul[i][j]=num;
            if(num==2){
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

        if(x+1<n&&(visited[x][y]+1<visited[x+1][y] || visited[x+1][y]==-1)&&gul[x+1][y]){
            q.push({x+1,y});
            visited[x+1][y]=visited[x][y]+1;
        }
        if(y+1<n&&(visited[x][y]+1<visited[x][y+1]||visited[x][y+1]==-1)&&gul[x][y+1]){
            q.push({x,y+1});
            visited[x][y+1]=visited[x][y]+1;
        }
        if(x-1>=0&&(visited[x][y]+1<visited[x-1][y]||visited[x-1][y]==-1)&&gul[x-1][y]){
            q.push({x-1,y});
            visited[x-1][y]=visited[x][y]+1;
        }
        if(y-1>=0&&(visited[x][y]+1<visited[x][y-1]||visited[x][y-1]==-1)&&gul[x][y-1]){
            q.push({x,y-1});
            visited[x][y-1]=visited[x][y]+1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}