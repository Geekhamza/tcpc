#include <bits/stdc++.h>
#define EPS 1e-9


using namespace std;
typedef long long ll;
typedef pair<string,ll> ii;
typedef pair<ll,ii> isi;
typedef vector<isi> vii;
vii actions;
bool can (double f){

double full_tank=f;
///simulate
ll current_cons=actions[0].second.second,current_leak=0;
for(ll i=0;i<actions.size()-1;i++){

    ///check if consomaition per kilometer changed
     if(actions[i].second.first=="Fuel")
    current_cons=actions[i].second.second ;

    ///if gas than refuel
    if(actions[i].second.first=="Gas")
    f=full_tank;

    ///if mechanicien than correct all leaks
    if(actions[i].second.first=="Mechanic")
    current_leak=0;

    if(actions[i].second.first=="Leak")
    current_leak++;

    double distance=((actions[i+1].first-actions[i].first)/100.0);
    f-=((distance/1.0*current_cons));
    f-=(actions[i+1].first-actions[i].first)*current_leak;


    if(f<0)
    return false;

}

return true;


}

int main()
{
    freopen("in.in","r",stdin);
    string s;
   while(getline(cin,s)){
    actions.clear();
    if(s=="0 Fuel consumption 0")
    return 0;
    //cout<<" s "<<s<<endl;
    stringstream ss;
    ss.str(s);
    string token;
    isi tmp;
    vector<string > v;
    while(getline(ss,token,' ')){
    v.push_back(token);
    }
    tmp.first=(ll)(atoi)(v[0].c_str());
    tmp.second.first=v[1];
     if(v.size()==4)
    tmp.second.second=(ll)(atoi)(v[3].c_str());
    actions.push_back(tmp);



    while(getline(cin,s)){
    //cout<<" s "<<s<<endl;
    ///split the string
    stringstream ss;
    ss.str(s);
    string token;
    isi tmp;
    vector<string > v;
    while(getline(ss,token,' ')){
    v.push_back(token);
    }
    tmp.first=(ll)(atoi)(v[0].c_str());
    tmp.second.first=v[1];
    if(v.size()==4)
    tmp.second.second=(ll)(atoi)(v[3].c_str());
    actions.push_back(tmp);
    if(s.find("Goal")!=std::string::npos)
    break;
    }

//    for(ll i=0;i<actions.size();i++)
//    cout<<actions[i].first<<" "<<actions[i].second.first<<" "<<actions[i].second.second<<endl;
    double low=0.000;
    double hight=10000.000;
    double ans=0.000;
    for(int i=0;i<25;i++){
       double mid=(hight+low)/2.0;
       //cout<<" new mid "<<mid<<endl;
       if(can(mid))
        hight=mid,ans=mid;
        else
        low=mid;

    }
    printf("%.3f\n",ans);

    }
    return 0;
}
