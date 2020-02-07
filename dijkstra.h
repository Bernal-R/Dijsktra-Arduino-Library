#ifndef Dijsktra_h
#define Dijsktra_h

#include "Arduino.h"

#define INFINITY INT_MAX
#define V 4


class Dijsktra {
  private:
    int minDistance(int dist[], bool sptSet[]);
    void printPath(int parent[], int j);
    int printSolution(int dist[], int n,  int parent[]);
  public:
    void shortPath(int graph[V][V], int src);
};

#endif
