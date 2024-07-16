#include <iostream>
#include <vector>
using namespace std;

int n;
void prop(vector<vector<bool>>& visited, int cnt,int k,int x,int y){
    if(cnt<k){
        if(x-1>=0 && !visited[x-1][y]){
            visited[x-1][y]=true;
            prop(visited,cnt+1,k,x-1,y);
        }
        if(y-1>=0&& !visited[x][y-1]){
            visited[x][y-1]=true;
            prop(visited,cnt+1,k,x,y-1);
        }
        if(x+1<n&&!visited[x+1][y]){
            visited[x+1][y]=true;
            prop(visited,cnt+1,k,x+1,y);
        }
        if(y+1<n&&!visited[x][y+1]){
            visited[x][y+1]=true;
            prop(visited,cnt+1,k,x,y+1);
        }
    }
}
int main() {
    int m;
    cin>>n>>m;
    
    vector<vector<int>> numlist(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            numlist[i][j]=num;

        }
    }

    int maxanswer=0;

    for(int k=0;k<2*n-1;k++){

        vector<vector<bool>> visited(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int goldcnt=0;
                int cost=0;
                prop(visited,0,k,i,j);

                for(int a=0;a<n;a++){
                    for(int b=0;b<n;b++){
                        if(visited[a][b]&&numlist[a][b]==1){
                            goldcnt++;
                        }
                        if(visited[a][b]){
                            cost++;
                        }
                    }
                }

                if(goldcnt*m>=cost){
                    if(maxanswer<goldcnt){
                        maxanswer=goldcnt;
                    }
                }



            }
        }




    }
    cout<<maxanswer;
    return 0;
}