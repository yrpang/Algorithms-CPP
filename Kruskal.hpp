#include <vector>
#include <queue>
#include "UF.hpp"
#include "WeightGraph.h"
#include "PQ.hpp"

#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

class Kruskal
{
private:
    std::queue<Edge> mst;
    WeightQuickUnion uf;
    PQ<Edge> pq;
    double weight;

public:
    Kruskal(WeightGraph &G) : uf(G.getV()), pq(G.getE()), weight(0.0)
    {
        for (Edge e : G.edges())
        {
            pq.insert(e);
        }

        while (!pq.isEmpty() && mst.size() < G.getV() - 1)
        {
            Edge e = pq.delMin();
            int v = e.either(), w = e.other(v);
            if (uf.connected(v, w))
                continue;
            uf.Union(v, w);
            weight += e.getWeight();
            mst.push(e);
        }
    }

    std::queue<Edge> edges()
    {
        return mst;
    }
    double getWeight()
    {
        return weight;
    }
};

#endif