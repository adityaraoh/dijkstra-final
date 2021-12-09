#include "stdc++.h"

using namespace std;

#define int long long

const int N=5e5;



vector<int> length(N),parent(N),path;


vector<pair<int,int>> graph[N];



int n,m,a,b,c,x;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> priorityqueue;



void Path(int idx) {
    if (parent[idx] == -1) return;
    Path(parent[idx]);
    path.push_back(idx);
}


void Mem()
{
    for(int i=0;i<N;i++) length[i]=INT_MAX;
    for(int i=0;i<N;i++) parent[i]=-1;
    for(auto i : graph) i.clear();
}



void DSPA()
{
    length[0]=0;
    priorityqueue.push({0,0});
    while(!priorityqueue.empty())
    {
        pair<int,int> p=priorityqueue.top();
        priorityqueue.pop();
        if(length[p.second]<p.first) continue;
        int u=p.second;
        for(auto i : graph[u])
        {
            int v=i.first;
            int w=i.second;
            if(length[v]>length[u]+w)
            {
                length[v]=length[u]+w;
                parent[v]=u;
                x=v;
                priorityqueue.push({length[v],v});
            }
        }
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    Mem();

    freopen("input1.txt","r",stdin);

    freopen("out.dot","w",stdout);

    clock_t start=clock();

    cin>>n>>m;

    for(int i=0;i<m;i++)

    {
        cin>>a>>b>>c;

        graph[a].push_back(make_pair(b,c));

        graph[b].push_back(make_pair(a,c));

    }
    
    DSPA();

    Path(x);

    cout<<"digraph a {\n";

    int sz=path.size();

    for (int i=0;i<sz-1;i++)
    {

        cout<<path[i]<<" -> "<<path[i+1]<<"\n";
    
    }
    
    cout<<"}\n";

    clock_t stop=clock();
}
