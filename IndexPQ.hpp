#include <vector>

#ifndef INDEXPQ_HPP
#define INDEXPQ_HPP

template <class T>
class IndexPQ
{
private:
    int N;
    std::vector<int> pq;
    std::vector<T> keys;
    std::vector<int> qp;

public:
    IndexPQ(int max) : pq(max + 1), keys(max + 1), qp(max + 1, -1), N(0) {}

    bool contains(int k)
    {
        return qp[k] != -1;
    }
    void insert(int k, T key)
    {
        // 此处默认keys中是在k的位置存储key 实际上应该不是必须的
        N++;
        pq[N] = k;
        qp[k] = N;
        keys[k] = key;

        swim(N);
    }

    T min() // 返回key对应的value
    {
        return keys[pq[1]];
    }

    int delMin()
    {
        int indexOfMin = pq[1];
        exch(1, N--);
        sink(1);

        // pq[N+1]得到的是k
        qp[pq[N + 1]] = -1;
        return indexOfMin;
    }

    void swim(int k)
    {
        while (k > 1 && keys[pq[k]] < keys[pq[k / 2]])
        {
            exch(k, k / 2);
            k = k / 2;
        }
    }

    void sink(int k)
    {
        while (2 * k <= N)
        {
            int j = 2 * k;
            if (j < N && keys[pq[j]] > keys[pq[j + 1]])
                j++;
            if (keys[pq[k]] < keys[pq[j]])
                break;
            exch(k, j);
            k = j;
        }
    }

    // i, j是pq数组的索引
    void exch(int i, int j)
    {
        std::swap(pq[i], pq[j]);
        qp[pq[i]] = i;
        qp[pq[j]] = j;
    }

    void change(int k, T key)
    {
        if (!contains(k))
            throw "index is not in the priority queue";
        keys[k] = key;
        swim(qp[k]);
        sink(qp[k]);
    }

    bool isEmpty()
    {
        return N == 0;
    }
};

#endif