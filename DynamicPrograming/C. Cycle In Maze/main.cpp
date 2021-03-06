#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll n,m,k;
ll starti,startj;
bool inbound(ll i,ll j){ return (i>=0&&j>=0&&i<n&&j<m);}
vector<string> tab;
ll dis[1010][1010];
ll xi[4]= {1,0,0,-1};
ll yi[4]= {0,-1,1,0};
string res="";
void bfs(){
dis[starti][startj]=0;
queue<ii> q;
q.push(ii(starti,startj));
while(!q.empty()){
    ii u=q.front();
    q.pop();
    for(int a=0;a<4;a++){
          ll x=u.first+xi[a];
          ll y=u.second+yi[a];
        if(inbound(x,y)&&tab[x][y]!='*'&&dis[x][y]==-1)
            dis[x][y]=1+dis[u.first][u.second],q.push(ii(x,y));
        }

}

}

void  dfs(ll i,ll j,ll dist){
///stop cond ????
    if(res.length()>=k)
    return ;


    for(int a=0;a<4;a++){
    ll x=i+xi[a];
    ll y=j+yi[a];
        if(inbound(x,y)&&tab[x][y]!='*'&&dis[x][y]<(k-dist))
            {
                if(a==0){
                     res+="D";
                     dfs(x,y,dist+1);
                     return ;

                    }
                if(a==1)
                    {
                    res+="L";
                     dfs(x,y,dist+1);
                     return ;

                    }
                if(a==2){
                    res+="R";
                     dfs(x,y,dist+1);
                     return ;

                    }
                if(a==3){
                     res+="U";
                     dfs(x,y,dist+1);
                     return ;

                    }
            }


        }
        return ;



    }


int main()
{
    //freopen("in.in","r",stdin);
    memset(dis,-1,sizeof dis);

    cin>>n>>m>>k;
    //tab.resize(n);

    for(ll i=0;i<n;i++){
        string s;
        cin>>s;
        tab.push_back(s);
        for(ll j=0;j<m;j++){
            if(tab[i][j]=='X')
                starti=i,startj=j;
        }
    }
    bfs();
    dfs(starti,startj,0);
    if(k&1)
    cout<<"IMPOSSIBLE"<<endl;
    else{
        bfs();
        dfs(starti,startj,0);
        if(res.size()!=k)
        cout<<"IMPOSSIBLE"<<endl;
        else
        cout<<res<<endl;

    }






    return 0;
}
