#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define V 6 // Number of vertices in the graph

int minKey(const vector<int>& key, const vector<bool>& mstSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(const vector<int>& parent, const vector<vector<int>>& graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}

void primMST(const vector<vector<int>>& graph, int startVertex) {
    vector<int> parent(V); // Array to store constructed MST
    vector<int> key(V, INT_MAX); // Key values used to pick minimum weight edge in cut
    vector<bool> mstSet(V, false); // To represent set of vertices included in MST

    // Initialize the startVertex as the root of MST
    key[startVertex] = 0;
    parent[startVertex] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    vector<vector<int>> graph = {
        { 0, 3, 0, 0, 0, 1 },
        { 3, 0, 2, 1, 10, 0},
        { 0, 2, 0, 3, 0, 5 },
        { 0, 1, 3, 0, 5, 0 },
        { 0, 10, 0, 5, 0, 4 },
        { 1, 0, 0, 5, 4, 0 }
    };

    primMST(graph, 0);

    return 0;
}