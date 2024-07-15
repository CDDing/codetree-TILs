#include <iostream>
#include <vector>
using namespace std;

int check(vector<vector<int>>& arr,int m, int stx,int sty){
    for(int i=stx;i<stx+m;i++){
        
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            arr[i][j]=num;
        }
    }
    int answer=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-m+1;j++){
            int num=arr[i][j];
            bool flag= true;
            for(int k=j;k<j+m;k++){
                if(arr[i][k]!=num){
                    flag=false;
                    break;
                }
            }
            if(flag){
                answer++;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-m+1;j++){
            int num=arr[j][i];
            bool flag= true;
            for(int k=j;k<j+m;k++){
                if(arr[k][i]!=num){
                    flag=false;
                    break;
                }
            }
            if(flag){
                answer++;
                break;
            }
        }
    }
    cout<<answer;
    return 0;
}