#include <iostream>
#include <vector>
using namespace std;

int main() {
    int answer=-1;

    

    int n,m;
    cin>>n>>m;
    vector<vector<int>> numlist(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num;
            cin>>num;
            numlist[i][j]=num;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            

            for(int a=1;a<=n;a++){
                for(int b=1;b<=m;b++){
                    if(i+a<=n&&b+j<=m){
                        bool check=true;
                        for(int x=i;x<i+a;x++){
                            for(int y=j;y<j+b;y++){
                                if(numlist[x][y]<=0){
                                    check=false;
                                }
                            }
                        }

                        if(check&& answer<a*b){
                            answer=a*b;
                        }



                    }
                }
            }




        }
    }
    cout<<answer;
    return 0;
}