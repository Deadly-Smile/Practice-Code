// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    public:

    static bool compare(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    void helperDFS (vector<int> graph[], int root, int disc[], int value[],
                    bool isPresent[], std::stack<int> &stac,
                    vector<vector<int>> &record) {

        static int timer{1};
        disc[root] = timer;
        value[root] = timer;
        timer++;
        stac.push(root);
        isPresent[root] = true;

        for (auto i : graph[root]) {
            if(!disc[i]) {
                helperDFS(graph, i, disc, value, isPresent, stac, record);
                value[root] = std::min(value[root], value[i]);
            } else if(isPresent[i]) {
                value[root] = std::min(value[root], disc[i]); 
            }
        }

        if(disc[root] == value[root]) {
            vector<int> temp;
            while(true) {
                temp.push_back(stac.top());
                isPresent[stac.top()] = false;
                if(stac.top() == root) {
                    stac.pop();
                    break;
                }
                stac.pop();
            }
            std::sort(temp.begin(), temp.end());
            record.push_back(temp);
        }
    }

    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int size, vector<int> graph[]) {
        //code here
        vector<vector<int>> record;
        int disc[size+1] = {0};
        int value[size+1] = {0};
        bool isPresent[size+1] = {0};
        std::stack<int> stac;

        for (int i = 0; i < size; i++) {
            if(!disc[i]) {
                helperDFS(graph, i, disc, value, isPresent, stac, record);
            }
        }
        std::sort(record.begin(), record.end(), compare);
        return record;
    }
};

// { Driver Code Starts.


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends

/*
5 5
1 0
0 2
2 1
0 3
3 4

4,3,0 1 2
*/