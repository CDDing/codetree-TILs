#include <iostream>
#include <vector>
#include <utility>
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
    vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{0,0}));
    dp[0][0]={numlist[0][0],numlist[0][0]};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0){
                
            }
            else if(i==0){
                auto minnum = min(numlist[i][j],dp[i][j-1].first);
                auto maxnum = max(numlist[i][j],dp[i][j-1].second);
                dp[i][j] ={minnum,maxnum};
            }
            else if(j==0){
                auto minnum = min(numlist[i][j],dp[i-1][j].first);
                auto maxnum = max(numlist[i][j],dp[i-1][j].second);
                dp[i][j] = {minnum,maxnum};
            }
            else{
                auto minnum = min(numlist[i][j],dp[i-1][j].first);
                auto maxnum = max(numlist[i][j],dp[i-1][j].second);

                auto minnum2 = min(numlist[i][j],dp[i][j-1].first);
                auto maxnum2 = max(numlist[i][j],dp[i][j-1].second);

                if(abs(minnum-maxnum)>abs(minnum2-maxnum2)){
                    
                    dp[i][j] = {minnum2,maxnum2};
                    
                }
                else{
                    dp[i][j] = {minnum,maxnum};
                }
                
                // dp[i][j] = numlist[i][j] +max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // cout<<"("<<dp[i][j].first<<","<<dp[i][j].second<<")"<<" ";
        }
        // cout<<endl;
    }

    cout<<abs(dp[n-1][n-1].first - dp[n-1][n-1].second);
    return 0;
}