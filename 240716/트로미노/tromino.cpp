#include <iostream>
#include <vector>
using namespace std;

int main() {
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
    int answer=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m-2;j++){
            int sum=0;
            for(int k=0;k<3;k++){
                sum+=numlist[i][j+k];
            }
            if(answer<sum){
                answer=sum;
            }
        }
    }

    for(int i=0;i<n-2;i++){
        for(int j=0;j<m;j++){
            int sum=0;
            for(int k=0;k<3;k++){
                sum+=numlist[i+k][j];
            }
            if(answer<sum){
                answer=sum;
            }
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            int sum=0;
            int minnum=9999;
            for(int a=0;a<2;a++){
                for(int b=0;b<2;b++){
                    sum+=numlist[i+a][j+b];
                    if(minnum>numlist[i+a][j+b]){
                        minnum=numlist[i+a][j+b];
                    }
                }
            }

            sum-=minnum;
            if(answer<sum){
                answer=sum;
            }









        }
    }

    cout<<answer;
    return 0;
}