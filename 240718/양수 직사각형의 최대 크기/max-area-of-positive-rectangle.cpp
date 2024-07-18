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
            int maxx=n-1,maxy=m-1;
            if(numlist[i][j]>0){
                for(int a=n-1;a>=i;a--){
                    for(int b=m-1;b>=j;b--){
                        if(numlist[i][j]<=0){
                            if(maxx>a){
                                maxx=a;
                            }

                            if(maxy>b){
                                maxy=b;
                            }




                            
                        }
                    }
                }

                if(answer<(maxx-i)*(maxy-j)){
                    answer = (maxx-i+1)*(maxy-j+1);
                }

            }




        }
    }
    cout<<answer;
    return 0;
}