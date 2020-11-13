#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BellmanFord(int graph[][3], int V, int E, int src) {

    std::vector<int> dis;
    for (int i = 0; i < V; i++)
        dis.push_back(INT_MAX);

    dis[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
        }
    }

    for (int i = 0; i < E; i++) {
        int x = graph[i][0]; int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != INT_MAX && dis[x] + weight < dis[y])
            cout << "Graphul contine un ciclu de negativ!"<<endl;
    }

    cout << "Distanta de la virful sursa: " << endl;

    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dis[i] << endl;
}

int main() {
 
    int graph[][3] = {

    { 0, 1, 10 },
    { 0, 2, 20 },
    { 1, 3, 50 },
    { 1, 4, 10 },
    { 2, 3, 20 },
    { 2, 4, 33 },
    { 3, 4, -20},
    { 3, 5, -2 },
    { 4, 5, 1 }

    };

    int V = 6;
    int E = sizeof(graph) / sizeof(graph[0]);

    BellmanFord(graph, V, E, 0);
    
    return 0;
}