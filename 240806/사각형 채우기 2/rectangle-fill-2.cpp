#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> numlist(2000,0);

    numlist[2]=3;

    numlist[1]=1;

    for(int i=3;i<=n;i++){
        numlist[i]=numlist[i-1]+numlist[i-2]*2;
    }
    cout<<numlist[n];
    return 0;
}