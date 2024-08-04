#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;

    queue<int> q;
    q.push(n);

    vector<int> visited(1000001,1000001);
    visited[n]=0;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        if(cur+1<=1000000&&visited[cur]+1<visited[cur+1]){
            q.push(cur+1);
            visited[cur+1]=visited[cur]+1;
        }
        if(cur-1>=0&&visited[cur]+1<visited[cur-1]){
            q.push(cur-1);
            visited[cur-1]=visited[cur]+1;
        }
        if(cur%2==0&&cur!=0&&visited[cur]+1<visited[cur/2]){
            q.push(cur/2);
            visited[cur/2]=visited[cur]+1;
        }
        if(cur%3==0&&cur!=0&&visited[cur]+1<visited[cur/3]){
            q.push(cur/3);
            visited[cur/3]=visited[cur]+1;
        }
    }
    cout<<visited[1];
    return 0;
}