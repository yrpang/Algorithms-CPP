#include <vector>
#include "Sort.hpp"
#include "UF.hpp"
#include "PQ.hpp"
#include "IndexPQ.hpp"
#include "LazyPrim.hpp"
#include "Prim.hpp"
#include "Kruskal.hpp"
#include "DirectedWeightGraph.hpp"
#include "Dijkstra.hpp"

using namespace std;
int main()
{
    /**********************************
    ***   Sort based on comparing   ***
    **********************************/
    int input[] = {5, 4, 3, 89, 696, 88};
    vector<int> a(input, input + 6);

    // Select<int> s;
    // Insert<int> s;
    // Merge<int> s;
    // Quick<int> s;
    // HeapSort<int> s;
    // s.sort(a);

    // for (int e : a)
    // {
    //     cout << e << " ";
    // }

    /**********************************
    ***       String Sort           ***
    **********************************/
    string newinput[] = {"dvfadb", "xcvxvx", "wqrwcs", "dscdsv", "ertyts", "343222"};
    vector<string> b(newinput, newinput + 6);

    // LSD s;
    // s.sort(b, 6);

    // for (string e : b)
    // {
    //     cout << e << " ";
    // }

    /**********************************
    ***         UF block            ***
    **********************************/
    // WeightQuickUnion u(20);
    // u.Union(0, 10);
    // cout << u.count() << " ";
    // cout << u.connected(0, 10) << " ";
    // cout << u.connected(0, 9) << " ";

    /**********************************
    ***         PQ block            ***
    **********************************/
    int c[] = {300, 20, 10, 60, 5, -20, 999};
    vector<int> nums(c, c + sizeof(c) / sizeof(int));

    // PQ<int> pq(20);
    // for (int i : nums)
    // {
    //     pq.insert(i);
    // }

    // pq.delMin();
    // pq.delMin();
    // pq.insert(3);

    // while (!pq.isEmpty())
    // {
    //     cout << pq.delMin() << " ";
    // }

    /**********************************
    ***      IndexPQ block          ***
    **********************************/
    // IndexPQ<int> ipq(nums.size());
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     ipq.insert(i, nums[i]);
    // }
    // while (!ipq.isEmpty())
    // {
    //     cout << nums[ipq.delMin()] << " ";
    // }

    /**********************************
    ***         MST block           ***
    **********************************/
    // int v;
    // cin >> v;
    // WeightGraph g(v);
    // cin >> g;

    // LazyPrim mst(g);
    // Prim mst(g);
    // Kruskal mst(g);

    // queue<Edge> edges=mst.edges();
    // while(!edges.empty())
    // {
    //     edges.front().toString();
    //     edges.pop();
    // }
    // cout << mst.getWeight();



    /**********************************
    ***          SP block           ***
    **********************************/
    int v;
    cin >> v;
    DirectedWeightGraph g(v);
    cin >> g;

    Dijkstra sp(g, 0);
    stack<DirectedEdge> res = sp.pathTo(2);
    while (!res.empty())
    {
        DirectedEdge e = res.top();
        e.toString();
        res.pop();
    }
    cout<<sp.getDistTo(2);

    return 0;
}