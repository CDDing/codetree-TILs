#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> numlist(100,0);
    cin>>n;
    numlist[0]=1;
    numlist[1]=1;
    numlist[2]=2;
    numlist[3]=5;

    for(int i=4;i<=n;i++){

        for(int j=0;j<i;j++){
            numlist[i]+=numlist[j]*numlist[i-j-1];
        }

    }

    cout<<numlist[n];

    return 0;
}