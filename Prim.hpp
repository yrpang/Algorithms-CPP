#include <vector>
#include <queue>
#include "IndexPQ.hpp"
#include "WeightGraph.h"

#ifndef PRIM_HPP
#define PRIM_HPP

class Prim
{
private:
    std::vector<Edge> edgeTo;   // 最小距离对应的边
    std::vector<double> distTo; // 树到它的最小距离
    std::vector<bool> marked;
    IndexPQ<double> pq; // 到达未访问过的点的最小距离

public:
    Prim(WeightGraph &G) : edgeTo(G.getV()), distTo(G.getV(), __DBL_MAX__), marked(G.getV(), false), pq(G.getV())
    {
        distTo[0] = 0.0;
        pq.insert(0, 0.0);
        while (!pq.isEmpty())
        {
            visit(G, pq.delMin()); // get到的是V
        }
    }

    void visit(WeightGraph &G, int v)
    {
        marked[v] = true; // 放进去

        for (Edge e : G.getAdj(v))
        {
            int w = e.other(v);
            //如果已经在里面则失效
            if (marked[w])
                continue;
            if (e.getWeight() < distTo[w])
            {
                edgeTo[w] = e;

                distTo[w] = e.getWeight();
                if (pq.contains(w))
                    pq.change(w, distTo[w]);
                else
                    pq.insert(w, distTo[w]);
            }
        }
    }

    std::queue<Edge> edges()
    {
        std::queue<Edge> mst;
        for (int i = 1; i < edgeTo.size(); i++)
        {
            mst.push(edgeTo[i]);
        }
        return mst;
    }

    double getWeight()
    {
        double res=0.0;
        for (int i = 1; i < edgeTo.size(); i++)
        {
            res += edgeTo[i].getWeight();
            
        }
        return res;
    }
};

#endif