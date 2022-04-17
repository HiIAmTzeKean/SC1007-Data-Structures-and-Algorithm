# Graph summary

Graph contains a few features

- Having finite set of vertices
- Having finite set of edges that connects vertices

## Types of graph

- Trees are graphs with no cycles
- Undirected graphs contains edges with no direction
- Weighted graphs contains edges with weights
- Directed graphs contains edges with direction
- Complete graphs are where each vertex is connected to every other vertex

## Terminology

- Path: if some node is linked to goal node via some edges and vertices
- Cycle: if there at least 3 distinct vertices creates a path such that the starting vertex and last vertex is the same
- Connected: if there is a path from any vertex to any other vertex (undirected graph)
- Strongly connected: if there is a path from any vertex to any other vertex (directed graph)
- Cyclic: one or more cycles exist, else acyclic
- Complete: simple undirected graph that contains one edge between every distinct vertices (then total edges = V*(V-1)/2)