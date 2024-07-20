#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,t;
    cin>>n>>t;



    vector<int> numlist(2*n,0);
    for(int i=0;i<2*n;i++){
        int num;
        cin>>num;
        numlist[i]=num;

    }
    while(t--){
        vector<int> temp(2*n,0);

        temp[0]=numlist[2*n-1];
        for(int i=1;i<2*n;i++){
            temp[i]=numlist[i-1];
        }
        numlist=temp;


    }
    
        for(int i=0;i<n;i++){
            cout<<numlist[i]<<" ";
        }
        cout<<endl;
        for(int i=n;i<2*n;i++){
            cout<<numlist[i]<<" ";
        }
    return 0;
}