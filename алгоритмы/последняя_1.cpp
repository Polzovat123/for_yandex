#include <iostream>
#include <queue>
#include <map>

using namespace std;

long long n, p, l, s, f;
int matrix[901][901];
int used_v[901];

bool dfs(int start){
    if(matrix[start]==0)return true;
    for(int i=0; i<=n+2; ++i){
        used_v[i]=0;
    }
    queue<int> noww;
    noww.push(start);
    while(!noww.empty()){
        int now_v = noww.front();
        noww.pop();
        if(used_v[now_v]==1){
            bool fin=false;
            int have =0;
            for(int i=0; i<n; i++){
                if(matrix[now_v][i]==1 && used_v[i]==0){
                    noww.push(i);
                    fin=true;
                }
                if(matrix[now_v][i]==1)have++;
            }
            //cout<<now_v<<" "<<have<<" "<<fin<<endl;
            if(!fin&& have!=0)return false;
            if(have==0)return true;

        }else {
            for(int i=0; i<n; i++){
                if(matrix[now_v][i]==1){
                    noww.push(i);
                }
            }
            used_v[now_v]=1;
        }
    }
    return true;
}

bool itishavecycle(){
    for(int i=0; i<n; ++i){
        if(!dfs(i)){
            return false;
        }
    }
    return true;
}

int main()
{
    cin>>n>>p;
    for(int i=0; i<901; ++i){
        for(int j=0; j<901; ++j){
            matrix[i][j]=-1;
        }
    }
    bool ch = false;
    for(int i=0; i<p; i++){
        cin>>f>>s;
        matrix[f][s] = 1;
    }
    if( itishavecycle() ){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
