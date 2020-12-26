#ifndef WEIGHTGRAPH_H
#define WEIGHTGRAPH_H

#include <vector>
#include "Edge.h"
#include <iostream>

class WeightGraph
{
private:
    int V;
    int E;
    std::vector<std::vector<Edge>> adj;

public:
    WeightGraph(int V) : adj(V)
    {
        this->V = V;
        this->E = 0;
    }

    void addEdge(Edge e)
    {
        int v = e.either(), w = e.other(v);
        adj[v].emplace_back(e);
        adj[w].emplace_back(e);
        E++;
    }
    int getV()
    {
        return V;
    }
    int getE()
    {
        return E;
    }
    std::vector<Edge> getAdj(int v)
    {
        return adj[v];
    }
    std::vector<Edge> edges()
    {
        std::vector<Edge> res;
        for (int v = 0; v < getV(); v++)
        {
            for (Edge e : getAdj(v))
            {
                if (e.other(v) > v)
                    res.emplace_back(e);
            }
        }
        return res;
    }
    void toString()
    {
        for (Edge e : edges())
        {
            e.toString();
        }
    }
    friend std::istream &operator>>(std::istream &input, WeightGraph &G);
};

std::istream &operator>>(std::istream &input, WeightGraph &G)
{
    int nums;
    input >> nums;

    int v, w;
    double weight;
    for (int i = 0; i < nums; i++)
    {
        input >> v >> w >> weight;
        G.addEdge(Edge(v, w, weight));
    }
    return input;
}

#endif