#include <iostream>
#include <vector>
using namespace std;

    int n,m;
int dfs(vector<vector<int>>& numlist, vector<vector<bool>>& visited,int curx,int cury,int k){
    int num=1;
    if(curx+1<n&&!visited[curx+1][cury]&&numlist[curx+1][cury]>k){
        visited[curx+1][cury]=true;
        num+=dfs(numlist,visited,curx+1,cury,k);
    }
    if(cury+1<m&&!visited[curx][cury+1]&&numlist[curx][cury+1]>k){

        visited[curx][cury+1]=true;
        num+=dfs(numlist,visited,curx,cury+1,k);
    }
    if(curx-1>=0&&!visited[curx-1][cury]&&numlist[curx-1][cury]>k){

        visited[curx-1][cury]=true;
        num+=dfs(numlist,visited,curx-1,cury,k);
    }
    if(cury-1>=0&&!visited[curx][cury-1]&&numlist[curx][cury-1]>k){

        visited[curx][cury-1]=true;
        num+=dfs(numlist,visited,curx,cury-1,k);
    }
    return num;
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

    int answer=0;
    int answerk=1;
    for(int k=1;k<100;k++){
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int areacnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&numlist[i][j]>k){
                    areacnt++;
                    visited[i][j]=true;
                    dfs(numlist,visited,i,j,k);
                }
            }
        }
        if(answer<areacnt){
            answer=areacnt;
            answerk=k;
        }


    }

    cout<<answerk<<" "<<answer;
    return 0;
}