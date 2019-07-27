    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define inf 1<<30
     
    typedef pair<int , int> ii;
    typedef pair<int, ii> iii;
     
    int n,r;
    vector <ii> adj[5005];
    int dist[3][5005];
    bool vis[3][5005];
     
    void dia(){
        priority_queue <iii,vector<iii>,greater<iii>> pq;
        pq.push(iii(1,ii(0,1)));
        dist[1][1] = 0;
        while(!pq.empty()){
            int t = pq.top().first;
            int u = pq.top().second.second;
            pq.pop();
            if(vis[t][u])
                continue;
            else
                vis[t][u] = true;
            for(int i=0; i<adj[u].size(); i++){
                int v = adj[u][i].first;
                int w = adj[u][i].second;
               
                int alt = dist[t][u] + w;
               
                if(alt < dist[1][v]){
                    dist[2][v] = dist[1][v];
                    pq.push(iii(2,ii(dist[2][v],v)));
                    dist[1][v] = alt;
                    pq.push(iii(1,ii(dist[1][v],v)));
                }
                else if(alt > dist[1][v] && alt < dist[2][v]){
                    dist[2][v] = alt;
                    pq.push(iii(2,ii(dist[2][v],v)));
                }
            }
        }
    }
     
    int main(){
        //freopen("input.txt","r",stdin);
        int T,a,b,w;
        cin >> T;
        for(int t=1; t<=T; t++){
            cin >> n >> r;
            for(int i=0; i<r; i++){
                cin >> a >> b >> w;
                adj[a].push_back(ii(b,w));
                adj[b].push_back(ii(a,w));
            }
            for(int i=1; i<=n; i++){
                dist[1][i] = inf;
                dist[2][i] = inf;
                vis[1][i] = false;
                vis[2][i] = false;
            }
            dia();
            cout << "Case " << t << ": " << dist[2][n] << endl;
            for(int i=1; i<=n; i++)
                adj[i].clear();
        }
        return 0;
    }
