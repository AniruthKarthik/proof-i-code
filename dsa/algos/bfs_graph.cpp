#include "graphs.hpp"

int main() {
    Graph g(5, true);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.display();

    g.BFS(2);

    return 0;
}
