#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<vector<int>> numlist(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            int num;
            cin>>num;
            numlist[i][j]=num;
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[0][n-1]=numlist[0][n-1];

    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(i==0&&j==n-1){
                
            }
            else if(i==0){
                dp[i][j] =numlist[i][j] + dp[i][j+1];
            }
            else if(j==n-1){
                dp[i][j] = numlist[i][j] +dp[i-1][j];
            }
            else{
                dp[i][j] = numlist[i][j] +min(dp[i-1][j],dp[i][j+1]);
            }
        }
    }

    cout<<dp[n-1][0];
    return 0;
}