#include <vector>
#include <stack>
#include "IndexPQ.hpp"
#include "DirectedWeightGraph.hpp"

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

class Dijkstra
{
private:
    std::vector<DirectedEdge> edgeTo; // 最小距离对应的边
    std::vector<double> distTo;       // 树到它的最小距离
    IndexPQ<double> pq;               // 到达未访问过的点的最小距离

public:
    Dijkstra(DirectedWeightGraph &G, int s) : edgeTo(G.getV()), distTo(G.getV(), __DBL_MAX__), pq(G.getV())
    {
        distTo[s] = 0;
        pq.insert(s, 0.0);
        while (!pq.isEmpty())
        {
            relax(G, pq.delMin());
        }
    }

    void relax(DirectedWeightGraph &G, int v)
    {
        for (DirectedEdge e : G.getAdj(v))
        {
            int w = e.to();
            if (distTo[w] > distTo[v] + e.getWeight())
            {
                distTo[w] = distTo[v] + e.getWeight();
                edgeTo[w] = e;

                if (pq.contains(w))
                    pq.change(w, distTo[w]);
                else
                    pq.insert(w, distTo[w]);
            }
        }
    }

    double getDistTo(int v)
    {
        return distTo[v];
    }
    bool hasPathTo(int v)
    {
        return distTo[v] < __DBL_MAX__;
    }
    std::stack<DirectedEdge> pathTo(int v)
    {
        if (!hasPathTo(v))
            throw "error!";
        std::stack<DirectedEdge> path;
        for (DirectedEdge e = edgeTo[v]; e.from() != -1; e = edgeTo[e.from()])
            path.push(e);
        return path;
    }
};

#endif