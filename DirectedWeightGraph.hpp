#ifndef DIRECTEDWEIGHTGRAPH_H
#define DIRECTEDWEIGHTGRAPH_H

#include <iostream>
#include <vector>
#include "DirectedEdge.hpp"

class DirectedWeightGraph
{
private:
    int V;
    int E;
    std::vector<std::vector<DirectedEdge>> adj;

public:
    DirectedWeightGraph(int V) : adj(V)
    {
        this->V = V;
        this->E = 0;
    }

    void addEdge(DirectedEdge e)
    {
        adj[e.from()].emplace_back(e);
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
    std::vector<DirectedEdge> getAdj(int v)
    {
        return adj[v];
    }
    std::vector<DirectedEdge> edges()
    {
        std::vector<DirectedEdge> res;
        for (int v = 0; v < getV(); v++)
        {
            for (DirectedEdge e : getAdj(v))
            {
                res.emplace_back(e);
            }
        }
        return res;
    }
    void toString()
    {
        for (DirectedEdge e : edges())
        {
            e.toString();
        }
    }
    friend std::istream &operator>>(std::istream &input, WeightGraph &G);
};

std::istream &operator>>(std::istream &input, DirectedWeightGraph &G)
{
    int nums;
    input >> nums;

    int v, w;
    double weight;
    for (int i = 0; i < nums; i++)
    {
        input >> v >> w >> weight;
        G.addEdge(DirectedEdge(v, w, weight));
    }
    return input;
}

#endif