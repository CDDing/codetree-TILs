#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> numlist(n,0);
    // numlist[0]=
    for(int i=0;i<n;i++){
        int num=0;
        cin>>num;
        numlist[i]=num;
    }
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        int maxdp = dp[i];
        for(int j=0;j<i;j++){
            auto index = j+numlist[j];
            if(numlist[i] > numlist[j]&&maxdp <= dp[j] + 1){
                maxdp = dp[j] + 1;
            }
        }
        dp[i] = maxdp;
    }
    int answer =0 ;
    for(int i=0;i<n;i++){
        if(answer<dp[i]){
            answer=dp[i];
        }
        // cout<<dp[i]<<" ";
    }
    cout<<answer;
    return 0;
}