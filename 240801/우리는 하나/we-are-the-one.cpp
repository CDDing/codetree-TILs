#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n,k,u,d;
int answer=0;
vector<vector<int>> numlist;
bool cmp(int x,int y){
    return ((x-y)>=u &&(x-y)<=d) ||((y-x)>=u&&(y-x)<=d);
}
void back(vector<bool>& visit,int cnt){
    if(cnt == k){
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        for(int i=0;i<n*n;i++){
            if(visit[i]){
                int x = i/n;
                int y=  i%n;
                q.push({x,y});
                visited[x][y]=true;
            }
        }
        int cnt=0;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            auto x = cur.first;
            auto y = cur.second;
        cnt++;
            if(x+1<n&&!visited[x+1][y]&&cmp(numlist[x][y],numlist[x+1][y])){
                q.push({x+1,y});
                visited[x+1][y]=true;
                
            }
            if(y+1<n&&!visited[x][y+1]&&cmp(numlist[x][y],numlist[x][y+1])){
                q.push({x,y+1});
                visited[x][y+1]=true;
            }
            if(x-1>=0&&!visited[x-1][y]&&cmp(numlist[x-1][y],numlist[x][y])){
                q.push({x-1,y});
                visited[x-1][y]=true;
            }
            if(y-1>=0&&!visited[x][y-1]&&cmp(numlist[x][y-1],numlist[x][y])){
                q.push({x,y-1});
                visited[x][y-1]=true;
            }

        }
        if(answer<cnt){
            answer=cnt;
        }



    }else{
    for(int i=0;i<n*n;i++){
        if(!visit[i]){
            visit[i]=true;
            back(visit,cnt+1);
            visit[i]=false;
        }
    }
    }
}
int main() {
    cin>>n>>k>>u>>d;
    numlist = vector<vector<int>>(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            numlist[i][j]=num;
        }
    }
    vector<bool> visited(n*n,false);
    back(visited,0);
    cout<<answer;
    return 0;
}