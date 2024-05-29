#ifndef DISJOINTSETS_HPP
#define DISJOINTSETS_HPP

#include <stdexcept>
#include <unordered_map>

using namespace std;

template <class T>
class DisjointSets {
private:
    // To be filled.
    unordered_map<T, T> sets;
public:
    DisjointSets();
    ~DisjointSets();
    DisjointSets(const DisjointSets &other) = delete;
    DisjointSets& operator=(const DisjointSets &other) = delete;
    int size();
    void makeSet(T u);
    T findSet(T u);
    void unionSet(T u, T v);
};
template <class T>
DisjointSets<T>::DisjointSets()
{

}
template <class T>
DisjointSets<T>::~DisjointSets()
{

}
template <class T>
int DisjointSets<T>::size()
{
    return sets.size();
}
template <class T>
void DisjointSets<T>::makeSet(T u)
{
    sets[u] = u;
}
template <class T>
T DisjointSets<T>::findSet(T u)
{
    if (sets.count(u) == 0)
        throw exception("Wrong");
    T parent = u;
    while (parent != sets[parent])
        parent = sets[parent];
    return parent;
}
template <class T>
void DisjointSets<T>::unionSet(T u, T v)
{
    T root_u = findSet(u);
    T root_v = findSet(v);
    if (root_u != root_v)
        sets[root_v] = root_u;
}
#endif