#include <iostream>
#include <vector>
#include <string>

#ifndef SORT_HPP
#define SORT_HPP

template <class T>
class Select
{
public:
    void sort(std::vector<T> &a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            int min = i; // 注意此处不可以为i+1 要保证当没找到更小的时候和自己交换！
            for (int j = i + 1; j < a.size(); j++)
            {
                if (a[j] < a[min])
                {
                    min = j;
                }
            }
            std::swap(a[i], a[min]);
        }
    }
};

template <class T>
class Insert
{
public:
    void sort(std::vector<T> &a)
    {
        for (int i = 1; i < a.size(); i++)
        {
            // 此处注意小于判断必须写在for循环的条件里面，保证算法可以在有序时立即终止
            for (int j = i; j > 0 && a[j] < a[j - 1]; j--)
            {
                std::swap(a[j - 1], a[j]);
            }
        }
    }
};

template <class T>
class Merge
{
public:
    void merge(std::vector<T> &a, int lo, int mid, int hi)
    {
        int i = lo;
        int j = mid + 1;

        std::vector<T> aux(a);

        for (int k = lo; k <= hi; k++)
        {
            if (i > mid)
                a[k] = aux[j++];
            else if (j > hi)
                a[k] = aux[i++];
            else if (aux[i] <= aux[j]) // 保证稳定 当左侧小于等于右侧时取左面
                a[k] = aux[i++];
            else
                a[k] = aux[j++];
        }
    }

    void sort(std::vector<T> &a, int lo, int hi)
    {
        if (hi <= lo)
            return;
        int mid = (lo + hi) / 2;
        sort(a, lo, mid);
        sort(a, mid + 1, hi);
        merge(a, lo, mid, hi);
    }

    void sort(std::vector<T> &a)
    {
        sort(a, 0, a.size() - 1);
    }
};

template <class T>
class Quick
{
public:
    int partition(std::vector<T> &a, int lo, int hi)
    {
        int i = lo, j = hi + 1; // 此处是一个技巧
        T v = a[lo];

        while (true)
        {
            while (a[++i] < v)
                if (i == hi)
                    break;
            while (a[--j] > v)
                if (j == lo)
                    break;
            if (i >= j) // 终止条件
                break;
            std::swap(a[i], a[j]);
        }
        std::swap(a[lo], a[j]);
        return j;
    }

    void sort(std::vector<T> &a, int lo, int hi)
    {
        if (hi <= lo)
            return;
        int j = partition(a, lo, hi);
        sort(a, lo, j - 1);
        sort(a, j + 1, hi);
    }

    void sort(std::vector<T> &a)
    {
        sort(a, 0, a.size() - 1);
    }
};

template <class T>
class HeapSort
{
public:
    // 建立大顶堆得到的是从小到大排序
    void sink(std::vector<T> &a, int k, int N)
    {
        while (2 * k <= N)
        {
            int j = 2 * k;
            if (j < N && a[j] < a[j + 1])
                j++;
            if (a[k] >= a[j])
                break;
            else
            {
                std::swap(a[k], a[j]);
                k = j;
            }
        }
    }
    void sort(std::vector<T> &a)
    {
        int N = a.size();

        std::vector<T> heap(a.size() + 1, 0);
        for (int i = 0; i < a.size(); i++)
        {
            heap[i + 1] = a[i];
        }

        for (int i = N / 2; i >= 1; i--) // 注意有等于号
        {
            sink(heap, i, N);
        }
        while (N > 1)
        {
            std::swap(heap[1], heap[N--]);
            sink(heap, 1, N);
        }

        for (int i = 0; i < a.size(); i++)
        {
            a[i] = heap[i + 1];
        }
    }
};

class LSD
{
public:
    void sort(std::vector<std::string> &a, int W)
    {
        int N = a.size();
        int R = 256;
        std::vector<std::string> aux(a);

        for (int d = W - 1; d >= 0; d--)
        {
            std::vector<int> count(R + 1, 0); // 注意把第一个留空
            for (int i = 0; i < N; i++)
            {
                count[a[i].at(d) + 1]++; // 注意要加1
            }

            for (int i = 0; i < R; i++)
            {
                count[i + 1] += count[i];
            }

            for (int i = 0; i < N; i++)
            {
                aux[count[a[i].at(d)]++] = a[i];
            }

            for (int i = 0; i < N; i++)
            {
                a[i] = aux[i];
            }
        }
    }
};

#endif