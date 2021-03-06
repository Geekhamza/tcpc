#include <bits/stdc++.h>

using namespace std;
//typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
int vid_nb,endpoint_nb,request_nb,cache_nb;
vi videos,cache_sizes;
int server_cache_size;
vector<vii> Endpoints;
vi Endpoint_to_server_latecy;
viii requests;
vector<set<int> > caches_servers;
int main()
{

    freopen("videos_worth_spreading.in","r",stdin);
    freopen("videos_worth_spreading.out","w",stdout);
    cin>>vid_nb>>endpoint_nb>>request_nb>>cache_nb>>server_cache_size;
    for(int i=0;i<vid_nb;i++){
        int x;
        cin>>x;
        videos.push_back(x);
    }

    ///resizze sever caches
    caches_servers.resize(cache_nb);
    cache_sizes.assign(cache_nb,server_cache_size);
    Endpoints.resize(endpoint_nb);

    for(int i=0;i<endpoint_nb;i++){

        int x;
        cin>>x;
        Endpoint_to_server_latecy.push_back(x);
        int caches;
        cin>>caches;

            for(int j=0;j<caches;j++){
                int a,b;
                cin>>a>>b;
                Endpoints[i].push_back(ii(b,a));
            }
            sort(Endpoints[i].begin(),Endpoints[i].end());


    }

    for(int i=0;i<request_nb;i++){
    int a,b,c;
    cin>>a>>b>>c;
    int  current_endpoint=b;
    int min_best_cache=-1;
    int min_lattecy=Endpoint_to_server_latecy[current_endpoint];
    ///find best cache to connect to
    for(auto k=0;k<Endpoints[current_endpoint].size();k++){
                ii current_cache=Endpoints[current_endpoint][k];
                if(current_cache.first<min_lattecy){
                         min_best_cache= current_cache.second;
                         min_lattecy= current_cache.first;

                    }

                }

    requests.push_back(iii(-1*((Endpoint_to_server_latecy[current_endpoint]-min_lattecy)),ii(b,a)));
    }
    /// solve
    sort(requests.begin(),requests.end());
    for(int i=0;i<request_nb;i++){
        iii current_request=requests[i];
        int  current_endpoint=current_request.second.first;
        int current_video=current_request.second.second;
        /// find list  of best server cache to this endpoint
        int min_lattecy=Endpoint_to_server_latecy[current_endpoint];

        for(auto k=0;k<Endpoints[current_endpoint].size();k++){
                int current_cache=Endpoints[current_endpoint][k].second;
            if(caches_servers[current_cache].find(current_video)!=caches_servers[current_cache].end())
            break;
            if(cache_sizes[current_cache]>=videos[current_video])
            {
                caches_servers[current_cache].insert(current_video);
                cache_sizes[current_cache]-=videos[current_video];
                break;
            }
        }

    }


    int  nb_used=0;
    for(int i=0;i<cache_nb;i++){
    if(cache_sizes[i]!=server_cache_size)
    nb_used++;
    }
    cout<<nb_used<<endl;
      for(int i=0;i<cache_nb;i++){
    if(cache_sizes[i]!=server_cache_size){
    cout<<i<<" ";
    for( auto j=caches_servers[i].begin();j!=caches_servers[i].end();j++){
        cout<<*j<<" ";
    }
    cout<<endl;
    }
    }




    return 0;
}
