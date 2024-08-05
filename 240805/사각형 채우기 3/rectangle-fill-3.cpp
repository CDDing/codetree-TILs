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
        answer[n] = 2*dp(n-1)+4*dp(n-2);
        answer[n]%=1000000007;
        return answer[n];
    }
}
int main() {
    int n;
    cin>>n;
    answer[1]=2;
    answer[2]=7;
    dp(n);
    cout<<answer[n];
    return 0;
}