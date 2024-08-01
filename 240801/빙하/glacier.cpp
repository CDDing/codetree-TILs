#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n,m;
void count(vector<vector<int>>& numlist){
    queue<pair<int,int>> q;
    q.push({0,0});
    numlist[0][0]=2;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        auto x = cur.first;
        auto y = cur.second;

        if(x+1<n&&numlist[x+1][y]==0){
            q.push({x+1,y});
            numlist[x+1][y]=2;
        }
        if(x-1>=0&&numlist[x-1][y]==0){
            q.push({x-1,y});
            numlist[x-1][y]=2;
        }
        if(y+1<m&&numlist[x][y+1]==0){
            q.push({x,y+1});
            numlist[x][y+1]=2;
        }
        if(y-1>=0&&numlist[x][y-1]==0){
            q.push({x,y-1});
            numlist[x][y-1]=2;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(numlist[i][j]==1){
                bool check=false;
                if(i+1<n&&numlist[i+1][j]==2){
                    check=true;
                }
                if(j+1<m&&numlist[i][j+1]==2){
                    check=true;
                }
                if(i-1>=0&&numlist[i-1][j]==2){
                    check=true;
                }
                if(j-1>=0&&numlist[i][j-1]==2){
                    check=true;
                }

                if(check){
                    numlist[i][j]=0;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(numlist[i][j]==2){
                numlist[i][j]=0;
            }
        }
    }
}
int main() {
    cin>>n>>m;
    vector<vector<int>> numlist(n,vector<int>(m,0));
    for(int i=0;i<n;i++){   
        for(int j=0;j<m;j++){
            int num;
            cin>>num;
            numlist[i][j]=num;
        }
    }
    int cnt=0;
    while(true){
        int before=0,after=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(numlist[i][j]==1){
                    before++;
                }
            }
        }
    count(numlist);
        cnt++;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(numlist[i][j]==1){
                    after++;
                }
            }
        }
        if(after==0){
            cout<<cnt<<" "<<before;
            break;
        }
    }

    return 0;
}