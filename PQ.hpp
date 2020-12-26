#include <vector>

#ifndef PQ_HPP
#define PQ_HPP

template <class T>
class PQ
{
private:
    std::vector<T> data;
    int N;

public:
    PQ(int max) : data(max + 1), N(0) {}

    void insert(T e)
    {
        data[++N] = e;
        swim(N);
    }

    void swim(int k)
    {
        // 此处其实是k/2>=1 或许更好理解
        while (k > 1 && data[k] < data[k / 2])
        {
            std::swap(data[k], data[k / 2]);
            k = k / 2;
        }
    }

    T delMin()
    {
        T min = data[1];
        std::swap(data[1], data[N--]);
        sink(1);
        return min;
    }

    void sink(int k)
    {
        while (2 * k <= N)
        {
            int j = 2 * k;
            if (j < N && data[j] > data[j + 1])
                j++;
            if (!(data[k] > data[j]))
                break;
            std::swap(data[k], data[j]);
            k = k * 2;
        }
    }

    bool isEmpty()
    {
        return N == 0;
    }
};

#endif