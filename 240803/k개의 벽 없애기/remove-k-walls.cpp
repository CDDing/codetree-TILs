#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n,k;
int r1,c1,r2,c2;
int answer=-1;
void back(vector<vector<int>>& numlist, vector<pair<int,int>>& wall,vector<bool>& wallvisit,int cnt){
    if(cnt == k){

        queue<pair<int,int>> q;
        q.push({r1,c1});

        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[r1][c1]=1;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            auto x = cur.first;
            auto y = cur.second;

            if(x+1<n&&(visited[x+1][y]>visited[x][y]+1||!visited[x+1][y])&&!numlist[x+1][y]){
                q.push({x+1,y});
                visited[x+1][y]=true;
                visited[x+1][y]=visited[x][y]+1;
            }
            if(y+1<n&&(visited[x][y+1]>visited[x][y]+1||!visited[x][y+1])&&!numlist[x][y+1]){
                q.push({x,y+1});
                visited[x][y+1]=true;
                visited[x][y+1]=visited[x][y]+1;
            }
            if(x-1>=0&&(visited[x-1][y]>visited[x][y]+1||!visited[x-1][y])&&!numlist[x-1][y]){
                q.push({x-1,y});
                visited[x-1][y]=true;
                visited[x-1][y]=visited[x][y]+1;
            }
            if(y-1>=0&&(visited[x][y-1]>visited[x][y]+1||!visited[x][y-1])&&!numlist[x][y-1]){
                q.push({x,y-1});
                visited[x][y-1]=true;
                visited[x][y-1]=visited[x][y]+1;
            }
        }

        if(visited[r2][c2]!=0){
            if(visited[r2][c2]<answer||answer==-1){
                answer=visited[r2][c2];
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<visited[i][j];
        //     }
        //     cout<<endl;
        // }
    }
    else{
        for(int i=0;i<wall.size();i++){
            if(!wallvisit[i]){
                wallvisit[i]=true;
                auto x = wall[i].first;
                auto y = wall[i].second;
                numlist[x][y]=0;
                back(numlist,wall,wallvisit,cnt+1);
                numlist[x][y]=1;
                wallvisit[i]=false;
            }
        }
    }
}

int main() {
    cin>>n>>k;
    vector<vector<int>> numlist(n,vector<int>(n,0));
    vector<pair<int,int>> wall;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            if(num==1){
                wall.push_back({i,j});
            }
            numlist[i][j]=num;
        }
    }
    cin>>r1>>c1>>r2>>c2;
    r1--;c1--;c2--;r2--;
    vector<bool> wallvisit(wall.size(),false);
    back(numlist,wall,wallvisit,0);

    cout<<answer-1;
    return 0;
}