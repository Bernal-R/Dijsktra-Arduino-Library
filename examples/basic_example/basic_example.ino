#include <dijkstra.h>

Dijsktra dijsktra;

//Definir matriz de grafo
int graph[V][V] = {
    {0, 2, 1, 0},
    {2, 0, 3, 1},
    {1, 3, 0, 2},
    {0, 1, 2, 0}
  };

void setup() {
  Serial.begin(9600);
  dijsktra.shortPath(graph, 0); //Calcular camino mas corto
}




void loop() {

}
