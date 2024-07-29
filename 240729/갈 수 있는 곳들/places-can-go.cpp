#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main() {
    int n,k;

    cin>>n>>k;

    vector<vector<int>> numlist(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            numlist[i][j]=num;
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    queue<pair<int,int>> q;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        q.push({x,y});
        visited[x][y]=true;
    }

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        auto x = cur.first;
        auto y = cur.second;

        if(x+1<n&&!visited[x+1][y]&&!numlist[x+1][y]){
            q.push({x+1,y});
            visited[x+1][y]=true;
        }
        if(y+1<n&&!visited[x][y+1]&&!numlist[x][y+1]){
            q.push({x,y+1});
            visited[x][y+1]=true;
        }
        if(x-1>=0&&!visited[x-1][y]&&!numlist[x-1][y]){
            q.push({x-1,y});
            visited[x-1][y]=true;
        }
        if(y-1>=0&&!visited[x][y-1]&&!numlist[x][y-1]){
            q.push({x,y-1});
            visited[x][y-1]=true;
        }
    }
    int answer=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]){
                answer++;
            }
        }
    }
    cout<<answer;
    return 0;
}