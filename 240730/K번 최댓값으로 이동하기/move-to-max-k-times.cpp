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
    int stx,sty;
    cin>>stx>>sty;
    stx--;
    sty--;
    int curx=stx,cury=sty;
    int answer=0;
    int ansx,ansy;
    for(int i=0;i<k;i++){
        queue<pair<int,int>> q;
        q.push({curx,cury});
        answer=0;

        vector<vector<bool>> visited(n,vector<bool>(n,false));
        visited[curx][cury]=true;

        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            auto x = cur.first;
            auto y = cur.second;
            // cout<<i<<" "<<x<<" "<<y<<endl;
            if(numlist[x][y]<numlist[curx][cury]&&answer<numlist[x][y]){
                answer=numlist[x][y];
                ansx=x;
                ansy=y;
            }else if(answer==numlist[x][y]){
                if(ansx>x){
                    ansx=x;
                    ansy=y;
                }else if(ansx==x){
                    if(ansy>y){
                        ansy=y;
                    }
                }
            }

            if(x+1<n&&!visited[x+1][y]&&numlist[x+1][y]<numlist[curx][cury]){
                q.push({x+1,y});
                visited[x+1][y]=true;
            }
            if(y+1<n&&!visited[x][y+1]&&numlist[x][y+1]<numlist[curx][cury]){
                q.push({x,y+1});
                visited[x][y+1]=true;
            }
            if(x-1>=0&&!visited[x-1][y]&&numlist[x-1][y]<numlist[curx][cury]){
                q.push({x-1,y});
                visited[x-1][y]=true;
            }
            if(y-1>=0&&!visited[x][y-1]&&numlist[x][y-1]<numlist[curx][cury]){
                q.push({x,y-1});
                visited[x][y-1]=true;
            }
        }
        curx=ansx;
        cury=ansy;
        // cout<<curx<<" "<<cury<<endl;
        //cout<<numlist[curx][cury]<<endl;
    }
    cout<<curx+1<<" "<<cury+1;
    return 0;
}