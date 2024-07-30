#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
int n,k,r,c,m;
    vector<vector<int>> numlist;
    vector<vector<bool>> visit;
    queue<pair<int,int>> q;
    int answer=0;
void back(vector<pair<int,int>>& stone,vector<bool>& visited,int cnt){
    if(cnt==m){
        int ttt = 0;
        auto temp = q;
        vector<vector<bool>> numvisit=visit;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<numlist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        while(!temp.empty()){
            auto cur = temp.front();
            temp.pop();
            auto x = cur.first;
            auto y= cur.second;
            ttt++;
            // cout<<x<<" "<<y<<endl;
            if(x+1<n&& !numvisit[x+1][y]&&!numlist[x+1][y]){
                temp.push({x+1,y});
                numvisit[x+1][y]=true;
            }
            if(y+1<n&& !numvisit[x][y+1]&&!numlist[x][y+1]){
                temp.push({x,y+1});
                numvisit[x][y+1]=true;
            }
            if(x-1>=0&&!numvisit[x-1][y]&&!numlist[x-1][y]){
                temp.push({x-1,y});
                numvisit[x-1][y]=true;
            }
            if(y-1>=0&&!numvisit[x][y-1]&&!numlist[x][y-1]){
                temp.push({x,y-1});
                numvisit[x][y-1]=true;
            }

        }


        if(answer<ttt){
            answer=ttt;
        }

    }else{
        for(int i=0;i<stone.size();i++){
            if(!visited[i]){
                visited[i]=true;
                auto cur = stone[i];
                auto x = cur.first;
                auto y = cur.second;
                numlist[x][y]=0;
                back(stone,visited,cnt+1);
                numlist[x][y]=1;
                visited[i]=false;
            }
        }
    }
}
int main() {
    cin>>n>>k>>m;
    vector<pair<int,int>> stone;
    numlist = vector<vector<int>>(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            numlist[i][j]=num;
            if(num){
                stone.push_back({i,j});
            }
        }
    }
    vector<bool> visited(stone.size(),false);
    visit = vector<vector<bool>>(n,vector<bool>(n,false));
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        q.push({x,y});
        visit[x][y]=true;
    }
    back(stone,visited,0);
    cout<<answer;
    return 0;
}