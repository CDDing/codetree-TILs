#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> numlist(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num;
            cin>>num;
            numlist[i][j]=num;
        }
    }
    int answer=-99999999;
    for(int i1=0;i1<n;i1++){
        for(int j1=0;j1<m;j1++){//첫번째 사각형 시작점

            for(int length1=1;length1<=n;length1++){
                for(int length2=1;length2<=m;length2++){//첫번째 사각형 길이 정의

                    for(int i2=0;i2<n;i2++){
                        for(int j2=0;j2<m;j2++){//두번째 사각형 시작점

                            for(int length3=1;length3<=n;length3++){
                                for(int length4=1;length4<=m;length4++){//두번째 사각형 길이 정의

                                    if(i1+length1<=n&&i2+length3<=n && j1 +length2 <= m && j2+length4 <=m){
                                    vector<vector<bool>> visited(n,vector<bool>(m,false));
                                    bool possible=true;
                                    int area1=0,area2=0;
                                    for(int x=i1;x<i1+length1;x++){
                                        for(int y=j1;y<j1+length2;y++){
                                            visited[x][y]=true;
                                            area1+=numlist[x][y];
                                        }
                                    }
                                    for(int x=i2;x<i2+length3;x++){
                                        for(int y=j2;y<j2+length4;y++){
                                            if(!visited[x][y]){
                                                visited[x][y]=true;
                                                area2+=numlist[x][y];
                                            }else{
                                                possible=false;
                                            }
                                        }
                                    }

                                    if(possible){
                                        
                                        if(area1+area2>answer){
                                            answer=area1+area2;
                                        }
                                    }
                                
                                    }





                                }
                            }
                        }
                    }
                }
            }

        }
    }
    cout<<answer;
    return 0;
}