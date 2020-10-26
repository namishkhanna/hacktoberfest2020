#include <bits/stdc++.h>

using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
vector<int> topoSort(int v, vector<int> adj[]) {
    // Your code here
    int indegree[v]={0};
    queue<int>q;
    vector<int>ans;
    for(int i=0;i<v;i++)
    {
        for(auto x: adj[i])
        {
            indegree[x]+=1;
        }
    }
    
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    
    // for(int i=0;i<v;i++)
    //     cout<<indegree[i]<<" ";
    
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        ans.push_back(u);
        for(auto x: adj[u])
        {
            indegree[x]-=1;
            if(indegree[x]==0)
            {
                q.push(x);
            }
        }
    }
    return ans;
}

