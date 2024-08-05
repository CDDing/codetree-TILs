#include <iostream>
#include <vector>
using namespace std;
vector<int> answer(1001,0);
int dp(int n){
    if(answer[n]!=0){
        return answer[n];
    }
    if(n==1){
        return 1;
    }
    else if(n==2){
        return 2;
    }
    else{
        answer[n] = dp(n-1)+dp(n-2);
        answer[n]%=10007;
        return answer[n];
    }
}
int main() {
    int n;
    cin>>n;
    answer[1]=1;
    answer[2]=2;
    answer[3]=3;
    dp(n);
    cout<<answer[n];
    return 0;
}