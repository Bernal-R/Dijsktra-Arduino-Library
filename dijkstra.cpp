#include "Arduino.h"
#include "dijkstra.h"

int Dijsktra::minDistance(int dist[], bool sptSet[]) {
  int min = INFINITY, min_index;

  for (int v = 0; v < V; v++)
    if (sptSet[v] == false &&
        dist[v] <= min)
      min = dist[v], min_index = v;
  return min_index;
}


void Dijsktra::printPath(int parent[], int j) {
  if (parent[j] == - 1)
    return;
  printPath(parent, parent[j]);
  Serial.println(j);
}

int Dijsktra::printSolution(int dist[], int n,  int parent[]) {
  int src = 0;
  Serial.println("Vertex - Distance - Path");
  for (int i = 1; i < V; i++) {
    Serial.print(src);
    Serial.print(" -> ");
    Serial.print(i);
    Serial.print("  ");
    Serial.print(dist[i]);
    Serial.print("  ");
    Serial.print(src);
    printPath(parent, i);
  }
}

void Dijsktra::shortPath(int graph[V][V], int src) {

  int dist[V];
  bool sptSet[V];
  int parent[V];

  for (int i = 0; i < V; i++) {
    parent[0] = -1;
    dist[i] = INFINITY; //Iniciar vector con infinto
    sptSet[i] = false;
  }

  dist[src] = 0;

  for (int count = 0; count < V - 1; count++) {
    int u = minDistance(dist, sptSet); //Calcular distancia minima
    sptSet[u] = true;

    for (int v = 0; v < V; v++){
      if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]){
        parent[v] = u;
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  printSolution(dist, V, parent);
}
