#include <vector>

#ifndef UF_HPP
#define UF_HPP

class UF
{
protected:
    std::vector<int> id;
    int counts;

public:
    UF(int N) : id(N, 0), counts(N)
    {
        for (int i = 0; i < N; i++)
        {
            id[i] = i;
        }
    }

    int count()
    {
        return counts;
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }
    virtual int find(int p) = 0;
    virtual void Union(int p, int q) = 0;
};

class QuickFind : public UF
{
public:
    QuickFind(int N) : UF(N) {}

    virtual int find(int p)
    {
        return id[p];
    }
    virtual void Union(int p, int q)
    {
        int pID = find(p);
        int qID = find(q);

        // 注意此处不能忘掉
        if (pID == qID)
            return;

        for (int i = 0; i < id.size(); i++)
        {
            if (id[i] == pID)
                id[i] = qID;
        }
        counts--;
    }
};

class QuickUnion : public UF
{
public:
    QuickUnion(int N) : UF(N) {}

    virtual int find(int p)
    {
        while (p != id[p])
            p = id[p];
        return p;
    }
    virtual void Union(int p, int q)
    {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot)
            return;

        id[pRoot] = qRoot;
        counts--;
    }
};

class WeightQuickUnion : public UF
{
private:
    std::vector<int> sz;

public:
    WeightQuickUnion(int N) : UF(N), sz(N, 1) {}

    virtual int find(int p)
    {
        while (p != id[p])
            p = id[p];
        return p;
    }
    virtual void Union(int p, int q)
    {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot)
            return;

        if (sz[pRoot] < sz[qRoot])
        {
            id[pRoot] = qRoot;
            sz[pRoot] += sz[qRoot];
        }
        else
        {
            id[qRoot] = pRoot;
            sz[qRoot] += sz[pRoot];
        }
        counts--;
    }
};

#endif