#include <iostream>
#include <vector>
using namespace std;

int n;
void prop(vector<vector<int>>& visited, int cnt,int k,int x,int y){
    visited[x][y]=cnt;
    if(cnt<k){
        int arr1=visited[x-1][y];
        int arr2=visited[x][y-1];
        int arr3=visited[x+1][y];
        int arr4=visited[x][y+1];
        if(x-1>=0&&(visited[x-1][y]==-1||visited[x-1][y]>cnt+1)){
            prop(visited,cnt+1,k,x-1,y);
        }
        if(y-1>=0&&(visited[x][y-1]==-1||visited[x][y-1]>cnt+1)){
            prop(visited,cnt+1,k,x,y-1);
        }
        if(x+1<n&&(visited[x+1][y]==-1||visited[x+1][y]>cnt+1)){
            prop(visited,cnt+1,k,x+1,y);
        }
        if(y+1<n&&(visited[x][y + 1]==-1||visited[x][y+1]>cnt+1)){
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

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vector<vector<int>> visited(n,vector<int>(n,-1));
                int goldcnt=0;
                prop(visited,0,k,i,j);
                for(int a=0;a<n;a++){
                    for(int b=0;b<n;b++){
                        if(visited[a][b]!=-1&&numlist[a][b]==1){
                            goldcnt++;
                        }
                    }
                }
                //cout<<"K"<<k<<i<<","<<j<< "gold : "<<goldcnt<<"\n";
                if(goldcnt*m>=k*k + (k+1)*(k+1)){
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