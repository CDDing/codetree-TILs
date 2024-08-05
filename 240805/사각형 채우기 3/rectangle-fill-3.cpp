#include <iostream>
#include <vector>
using namespace std;
vector<long> answer(1001,0);
long dp(long n){
    if(answer[n]!=0){
        return answer[n];
    }
    if(n==1){
        return 2;
    }
    else if(n==2){
        return 7;
    }
    else{
        answer[n] = dp(n-1)*2+3*dp(n-2);
        for(int i=n-3;i>=0;i--){
            answer[n] += 2*dp(i);
        }
        answer[n]%=1000000007;
        return answer[n];
    }
}
int main() {
    int n;
    cin>>n;
    answer[0]=1;
    answer[1]=2;
    answer[2]=7;
    answer[3]=22;
    dp(n);
    cout<<answer[n];
    return 0;
}