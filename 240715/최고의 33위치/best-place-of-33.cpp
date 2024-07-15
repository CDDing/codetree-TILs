#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            arr[i][j]=num;
        }
    }
    int answer=0;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n-2;j++){
            int cnt=0;
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    auto x = i + k;
                    auto y = j + l;
                    cnt+=arr[x][y];

                }
            }
            if(answer<cnt){
                answer=cnt;
            }
        }
    }
    cout<<answer;
    return 0;
}