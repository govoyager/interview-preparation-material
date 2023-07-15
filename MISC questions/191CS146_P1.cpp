#include <bits/stdc++.h>
using namespace std;


bool edgeValid(int vertex1, int vertex2, bool isInMST[]) {
    if(vertex1 == vertex2) return false;
    if(isInMST[vertex1] && isInMST[vertex2]) return false;
    if(!isInMST[vertex1] && !isInMST[vertex2]) return false;
    return true;
}




int main() {
    cout << "Prim's algorithm on weighted, undirected graph\n";
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    int cost[n][n];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cost[i][j] = INT32_MAX;
        }
    }
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;
    while(m--) {
        cout << "Enter vertex A, vertex B and the cost respectively: ";
        int a, b, w;
        cin >> a >> b >> w;
        cost[a][b] = w;
        cost[b][a] = w;
    }
    
    bool isInMST[n];
    for(int i = 0; i < n; ++i) isInMST[i] = false;
    isInMST[0] = true;
    int edges_in_MST = 0, MSTcost = 0;
    cout << "\nThe spanning tree consists of the following edges\n";
    while(edges_in_MST < n - 1) {
        int minEdge = INT32_MAX, vertex1 = -1, vertex2 = -1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(cost[i][j] < minEdge && edgeValid(i, j, isInMST)) {
                    minEdge = cost[i][j];
                    vertex1 = i;
                    vertex2 = j;
                }
            }
        }
        if(vertex1 != -1 && vertex2 != -1) {
            cout << "Edge #" << edges_in_MST << ": (" << vertex1 << " " << vertex2 << ") with cost: " << minEdge << endl;
            edges_in_MST++;
            MSTcost += minEdge;
            isInMST[vertex1] = true;
            isInMST[vertex2] = true;
        }
    }
    cout << "The cost of the minimum spanning tree is: " << MSTcost << endl;
    return 0;
}