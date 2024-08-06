#include <iostream>
#include <vector>
using namespace std;
vector<int> numlist(1001,0);
int main() {
    int n;
    cin>>n;

    numlist[1]=0;
    numlist[2]=1;
    numlist[3]=1;
    for(int i=4;i<=n;i++){
        numlist[i]=numlist[i-2]+numlist[i-3];
        numlist[i]%=10007;
    }

    cout<<numlist[n];

    return 0;
}