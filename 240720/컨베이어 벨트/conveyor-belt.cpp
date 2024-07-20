#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,t;
    cin>>n,t;


    t%=2*n;

    vector<int> numlist(2*n,0);
    for(int i=0;i<2*n;i++){
        int num;
        cin>>num;
        numlist[i]=num;

    }

    for(int i=n;i<n+t;i++){
        cout<<numlist[i]<<" ";

    }
    for(int i=0;i<n-t;i++){
        cout<<numlist[i]<<" ";
    }

    cout<<endl;

    for(int i=n+t;i<2*n;i++){
        cout<<numlist[i]<<" ";
    }
    for(int i=n-1;i>=n-t;i--){
        cout<<numlist[i]<<" ";
    }

    return 0;
}