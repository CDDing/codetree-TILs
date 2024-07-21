#include <iostream>
#include <vector>
using namespace std;

int main() { 
    int n;
    cin>>n;

    vector<int> numlist;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        numlist.push_back(num);
    }

    int s1,s2,e1,e2;
    cin>>s1>>e1;
    s1--;
    e1--;
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(i<s1||i>e1){
            temp.push_back(numlist[i]);
        }
    }
    numlist=temp;

    temp=vector<int>();
    cin>>s2>>e2;
    s2--;
    e2--;
    for(int i=0;i<numlist.size();i++){
        if(i<s2||i>e2){
            temp.push_back(numlist[i]);
        }
    }

    cout<<temp.size()<<endl;
    for(auto num:temp){
        cout<<num<<endl;
    }
    
    return 0;
}