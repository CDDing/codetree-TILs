#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,t;
    cin>>n>>t;
    vector<int> numlist;
    for(int i=0;i<3*n;i++){
        int num;
        cin>>num;
        numlist.push_back(num);

    }

    while(t--){
        vector<int> temp(3*n,0);
        temp[0]=numlist[3*n-1];

        for(int i=1;i<3*n;i++){
            temp[i]=numlist[i-1];
        }

        numlist=temp;
    }

    for(int i=0;i<3*n;i++){
        if(i%n==0&&i){
            cout<<endl;
        }
        cout<<numlist[i]<<" ";
    }
    return 0;
}