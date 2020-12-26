#ifndef EDGE_H
#define EDGE_H

#include <iostream>

class Edge
{
private:
    int v; // 一个顶点
    int w; // 另一个顶点
    double weight;

public:
    Edge() {}
    Edge(int v, int w, double weight)
    {
        this->v = v;
        this->w = w;
        this->weight = weight;
    }

    double getWeight()
    {
        return weight;
    }
    int either()
    {
        return v;
    }
    int other(int k)
    {
        if (k == v)
            return w;
        else if (k == w)
            return v;
        else
        {
            throw "the specific node is not in the edge!";
        }
    }
    void toString()
    {
        std::cout << v << "-" << w << " " << weight << std::endl;
    }
    bool operator<(Edge &e)
    {
        return weight < e.weight;
    }
    bool operator>(Edge &e)
    {
        return weight > e.weight;
    }
};

#endif