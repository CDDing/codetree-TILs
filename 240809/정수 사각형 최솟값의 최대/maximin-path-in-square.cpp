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
    dp[0][0]=numlist[0][0];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0){
                
            }
            else if(i==0){
                dp[i][j] =min(numlist[i][j], dp[i][j-1]);
            }
            else if(j==0){
                dp[i][j] = min(numlist[i][j],dp[i-1][j]);
            }
            else{
                dp[i][j] = min(numlist[i][j],max(dp[i-1][j],dp[i][j-1]));
            }
        }
    }

    cout<<dp[n-1][n-1];
    return 0;
}