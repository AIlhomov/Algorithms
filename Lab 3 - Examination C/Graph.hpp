#ifndef GRAPH_H
#define GRAPH_H
#include <utility>
#include <vector>
#include <climits>
#include <tuple>
#include <stdexcept>
#include <unordered_map>

#include "DisjointSets.hpp"
#include "MinPriorityQueue.hpp"
#include "Quicksort.hpp"

const int INFINIT_COST = INT_MAX;

using namespace std;

template <typename T>
class Graph
{
private:
	// for you to decide
	class Edge {
	public:
		T fromVertex;
		T toVertex;
		int weight;
		Edge() {}
		Edge(T f, T t, int w=0) : fromVertex(f), toVertex(t), weight(w) {}
		bool operator<(const Edge& other) const {
			return weight < other.weight;
		}
		bool operator>(const Edge& other) const {
			return weight > other.weight;
		}
		bool operator<=(const Edge& other) const {
			return weight <= other.weight;
		}
		bool operator>=(const Edge& other) const {
			return weight >= other.weight;
		}
		bool operator==(const Edge& other) const {
			return weight == other.weight && fromVertex == other.fromVertex && toVertex == other.toVertex;
		}
		bool operator!=(const Edge& other) const {
			return weight != other.weight || fromVertex != other.fromVertex || toVertex != other.toVertex;
		}
	};

	vector<vector<Edge>> adjList;
	unordered_map<T, int> vertexMap;
public:
	Graph();
	virtual ~Graph();
	Graph(const Graph& other) = delete;
	Graph& operator=(const Graph& other) = delete;
	void addVertex(T vertex);
	void addEdge(T from, T to, int weight = 0);
	std::vector<T> getAllNeighboursTo(T vertex);
	int getNrOfVertices() const;
	int getNrOfEdges() const;
	void MST(std::vector<std::tuple<T, T, int>>& mst, int &totalCost);
};


#endif

template<typename T>
inline Graph<T>::Graph()
{
}

template<typename T>
inline Graph<T>::~Graph()
{
}

template<typename T>
inline void Graph<T>::addVertex(T vertex)
{
	if (vertexMap.count(vertex) > 0) throw exception("Wrong");

	vertexMap[vertex] = (int)vertexMap.size();
	adjList.push_back(vector<Edge>());
}

template<typename T>
inline void Graph<T>::addEdge(T from, T to, int weight)
{
	if (vertexMap.count(from) == 0)
		addVertex(from);
	if (vertexMap.count(to) == 0)
		addVertex(to);

	adjList[vertexMap[from]].push_back(Edge(from, to, weight));
	//adjList[vertexMap[to]].push_back(Edge(from, to, weight)); makes it a undirected graph
}

template<typename T>
inline std::vector<T> Graph<T>::getAllNeighboursTo(T vertex)
{
	// Returns all neighbors to vertex in alphabetical order 

	if (vertexMap.count(vertex) == 0) throw exception("Wrong");

	vector<T> neighbours;
	for (int i = 0; i < adjList[vertexMap[vertex]].size(); i++)
		neighbours.push_back(adjList[vertexMap[vertex]][i].toVertex);
	sort(neighbours.begin(), neighbours.end());
	return neighbours;
}

template<typename T>
inline int Graph<T>::getNrOfVertices() const
{
	// Returns number of vertices
	return adjList.size();
}

template<typename T>
inline int Graph<T>::getNrOfEdges() const
{
	// Returns number of edges
	int count = 0;
	for (int i = 0; i < adjList.size(); i++)
		count += adjList[i].size();
	return count;
}


template<typename T>
inline void Graph<T>::MST(std::vector<std::tuple<T, T, int>>& mst, int& totalCost)
{
	// Creates the MST of the graph
	// Should populate the vector mst with all included edges in format tuple(from, to, weight)
	// and store the total cost of the MST in totalCost.
	totalCost = 0;
	DisjointSets<T> disSets;
	vector<Edge> allEdges;

	for (int i = 0; i < adjList.size(); i++) {
		vector<Edge> currVect = adjList[i];
		disSets.makeSet(currVect[0].fromVertex);

		for (int j = 0; j < adjList[i].size(); j++)
			allEdges.push_back(currVect[j]);
	}
	sort(allEdges.begin(), allEdges.end()); //must sort them
	int nrOfEdgesMST = 0;
	int index = 0;
	int nrOfVerticies = adjList.size();

	while (nrOfEdgesMST < nrOfVerticies - 1) {
		Edge currEdge = allEdges[index++];
		if (disSets.findSet(currEdge.fromVertex) != disSets.findSet(currEdge.toVertex)) {
			disSets.unionSet(currEdge.fromVertex, currEdge.toVertex);
			mst.push_back(make_tuple(currEdge.fromVertex, currEdge.toVertex, currEdge.weight));
			totalCost += currEdge.weight;
			nrOfEdgesMST++;
		}
	}
}