#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<vector<int>> numlist(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            numlist[i][j]=num;
        }
    }

    int answer=0;
    for(int i=2;i<n;i++){
        for(int j=2;j<n;j++){

            for(int x=0;x<n;x++){
                for(int y=0;y<n;y++){
                    
                    bool possible=true;


                    int cnt=0;
                    for(int a=0;a<i;a++){
                        if(x+a<n&&y-a>=0){ //왼쪽 위 선
                            cnt+=numlist[x+a][y-a];
                        }else{
                            possible=false;
                        }

                        if(x + j - 1 + a <n && y + j - 1 - a >=0){ //오른쪽 아래 선
                            cnt+=numlist[x+j-1+a][y+j-1-a];
                        }
                        else{
                            possible=false;
                        }
                    }

                    for(int a=0;a<j;a++){
                        if(x+a<n&&y+a<n){//오른쪽 위 선
                            cnt+=numlist[x+a][y+a];
                        }else{
                            possible=false;
                        }

                        if(x + i - 1 + a <n && y - i + 1 + a <n){//왼쪽 아래 선
                            cnt+=numlist[x+i-1+a][y-i+1+a];
                        }else{
                            possible=false;
                        }
                    }


                    if(possible){
                        cnt-=numlist[x][y];
                        cnt-=numlist[x+i-1][y-i+1];
                        cnt-=numlist[x+i+j-2][y-i+j];
                        cnt-=numlist[x+j-1][y+j-1];
                        if(answer<cnt){
                            //cout<<"왼길이 : "<<i<<"오른길이 : "<<j<<" x :"<<x<<"y:"<<y<<"cnt:"<<cnt<<"answer:"<<answer<<"\n";
                            answer=cnt;
                        }
                    }



                }
            }






        }
    }
    cout<<answer;
    return 0;
}