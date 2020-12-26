#ifndef DIRECTEDEDGE_H
#define DIRECTEDEDGE_H

#include <iostream>

class DirectedEdge
{
private:
    int v; // 一个顶点
    int w; // 另一个顶点
    double weight;

public:
    DirectedEdge()
    {
        v = -1;
        w = -1;
        weight = -1;
    }
    DirectedEdge(int v, int w, double weight)
    {
        this->v = v;
        this->w = w;
        this->weight = weight;
    }

    double getWeight()
    {
        return weight;
    }
    int from()
    {
        return v;
    }
    int to()
    {
        return w;
    }
    void toString()
    {
        std::cout << v << "-" << w << " " << weight << std::endl;
    }
    bool operator<(DirectedEdge &e)
    {
        return weight < e.weight;
    }
    bool operator>(DirectedEdge &e)
    {
        return weight > e.weight;
    }
};

#endif