#include <iostream>
#include <vector>
using namespace std;

    int n;

int dfs(vector<vector<int>>& numlist,vector<vector<bool>>& visited,int curx,int cury){
    int num=1;
    if(curx+1<n&&!visited[curx+1][cury]&&numlist[curx][cury]==numlist[curx+1][cury]){
        visited[curx+1][cury]=true;
        num+=dfs(numlist,visited,curx+1,cury);
    }
    if(cury+1<n&&!visited[curx][cury+1]&&numlist[curx][cury]==numlist[curx][cury+1]){
        visited[curx][cury+1]=true;
        num+=dfs(numlist,visited,curx,cury+1);
    }
    if(curx-1>=0&&!visited[curx-1][cury]&&numlist[curx][cury]==numlist[curx-1][cury]){
        visited[curx-1][cury]=true;
        num+=dfs(numlist,visited,curx-1,cury);
    }
    if(cury-1>=0&&!visited[curx][cury-1]&&numlist[curx][cury]==numlist[curx][cury-1]){
        visited[curx][cury-1]=true;
        num+=dfs(numlist,visited,curx,cury-1);
    }
    return num;
}
int main() {
    cin>>n;

    vector<vector<int>> numlist(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            numlist[i][j]=num;
        }
    }
    int cnt=0;
    int answer=0;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                visited[i][j]=true;
                int size = dfs(numlist,visited,i,j);
                if(size>=4){
                    cnt++;
                    if(answer<size){
                        answer=size;
                    }
                }
            }
        }
    }

    cout<<cnt<<" "<<answer;
    return 0;
}