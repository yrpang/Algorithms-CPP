#include <vector>
#include <queue>
#include "PQ.hpp"
#include "WeightGraph.h"

#ifndef LAZYPRIM_HPP
#define LAZYPRIM_HPP

class LazyPrim
{
private:
    std::vector<bool> marked;
    std::queue<Edge> mst;
    PQ<Edge> pq;
    double weight;

public:
    LazyPrim(WeightGraph &G) : marked(G.getV(), false), pq(G.getV()), weight(0.0)
    {
        visit(G, 0);
        while (!pq.isEmpty())
        {
            Edge e = pq.delMin();

            int v = e.either(), w = e.other(v);
            if (marked[v] && marked[w])
                continue;
            mst.push(e);
            weight += e.getWeight();
            if (!marked[v])
                visit(G, v);
            if (!marked[w])
                visit(G, w);
        }
    }

    void visit(WeightGraph &G, int v)
    {
        marked[v] = true;

        for (Edge e : G.getAdj(v))
        {
            if (!marked[e.other(v)])
                pq.insert(e);
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