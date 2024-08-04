#include <iostream>
#include <vector>
using namespace std;
vector<long> memory;
long pibo(long n){
    if(memory[n]!=-1){
        return memory[n];
    }
    if(n==1||n==2){
        return 1;
    }
    else{
        memory[n]=pibo(n-1)+pibo(n-2);
        return memory[n];
    }
}
int main() {
    long n;
    memory = vector<long>(46,-1);
    cin>>n;
    cout<<pibo(n);
    return 0;
}