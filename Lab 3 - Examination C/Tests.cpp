#include <algorithm>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include "DisjointSets.hpp"
#include "Graph.hpp"

std::string getVector(std::vector<std::string> vec)
{
	std::string ret = "";
	if(vec.size() > 0)
	{
		ret += vec[0];
		for(int i = 1; i < vec.size(); ++i)
			ret += "," + vec[i];
	}

	return ret;
}

bool DisjointSetTests()
{
	std::cout << "Starting tests for DisjointSet" << std::endl << std::endl;
	DisjointSets<std::string> ds; 

	std::cout << "Using makeSet() to create sets [A, B, ..., I, J]" << std::endl;
	std::vector<std::string> names = {"A","B","C","D","E","F","G","H","I", "J"};
	for(int i = 0; i < names.size(); ++i)
		ds.makeSet(names[i]);

	std::cout << "Using findSet() to verify their existance ... "  << std::flush;
	std::vector<std::string> results;
	for(int i = 0; i < names.size(); ++i)
		results.push_back(ds.findSet(names[i]));
	if (names != results)
	{
		std::cout << "The created sets are incorrect." << std::endl;
		std::cout << "Should be: " << getVector(names) << std::endl;
		std::cout << "Yours are: " << getVector(results) << std::endl;
		return false;
	}
	std::cout << "OK!" << std::endl;

	std::cout << "Using unionSet('A', 'B') ... "  << std::flush;
	ds.unionSet("A","B");
	results = std::vector<std::string>();
	for(int i = 0; i < names.size(); ++i)
		results.push_back(ds.findSet(names[i]));

	std::vector<std::string> unions = {"A","A","C","D","E","F","G","H","I", "J"};
	if (results != unions)
	{
		std::cout << "The created sets are incorrect." << std::endl;
		std::cout << "Should be: " << getVector(unions) << std::endl;
		std::cout << "Yours are: " << getVector(results) << std::endl;
		return false;
	}
	std::cout << "OK!" << std::endl;

	std::cout << "Using unionSet('B', 'C') ... "  << std::flush;
	ds.unionSet("B","C");
	results = std::vector<std::string>();
	for(int i = 0; i < names.size(); ++i)
		results.push_back(ds.findSet(names[i]));
	unions = {"A","A","A","D","E","F","G","H","I", "J"};
	if (results != unions)
	{
		std::cout << "The created sets are incorrect." << std::endl;
		std::cout << "Should be: " << getVector(unions) << std::endl;
		std::cout << "Yours are: " << getVector(results) << std::endl;
		return false;
	}
	std::cout << "OK!" << std::endl;

	std::cout << "Using unionSet('D', 'C') ... " << std::flush;
	ds.unionSet("D","C");
	results = std::vector<std::string>();
	for(int i = 0; i < names.size(); ++i)
		results.push_back(ds.findSet(names[i]));
	unions = {"D","D","D","D","E","F","G","H","I", "J"};
	if (results != unions)
	{
		std::cout << "The created sets are incorrect." << std::endl;
		std::cout << "Should be: " << getVector(unions) << std::endl;
		std::cout << "Yours are: " << getVector(results) << std::endl;
		return false;
	}
	std::cout << "OK!" << std::endl;

	std::cout << "Using unionSet('E', 'F') ... "  << std::flush;
	ds.unionSet("E","F");
	results = std::vector<std::string>();
	for(int i = 0; i < names.size(); ++i)
		results.push_back(ds.findSet(names[i]));
	unions = {"D","D","D","D","E","E","G","H","I", "J"};
	if (results != unions)
	{
		std::cout << "The created sets are incorrect." << std::endl;
		std::cout << "Should be: " << getVector(unions) << std::endl;
		std::cout << "Yours are: " << getVector(results) << std::endl;
		return false;
	}
	std::cout << "OK!" << std::endl;

	std::cout << "Using unionSet('G', 'H') ... "  << std::flush;
	ds.unionSet("G","H");
	results = std::vector<std::string>();
	for(int i = 0; i < names.size(); ++i)
		results.push_back(ds.findSet(names[i]));
	unions = {"D","D","D","D","E","E","G","G","I", "J"};
	if (results != unions)
	{
		std::cout << "The created sets are incorrect." << std::endl;
		std::cout << "Should be: " << getVector(unions) << std::endl;
		std::cout << "Yours are: " << getVector(results) << std::endl;
		return false;
	}
	std::cout << "OK!" << std::endl;

	std::cout << "Using unionSet('I', 'E') ... "  << std::flush;
	ds.unionSet("I","E");
	results = std::vector<std::string>();
	for(int i = 0; i < names.size(); ++i)
		results.push_back(ds.findSet(names[i]));
	unions = {"D","D","D","D","I","I","G","G","I", "J"};
	if (results != unions)
	{
		std::cout << "The created sets are incorrect." << std::endl;
		std::cout << "Should be: " << getVector(unions) << std::endl;
		std::cout << "Yours are: " << getVector(results) << std::endl;
		return false;
	}
	std::cout << "OK!" << std::endl;

	std::cout << "Using unionSet('G', 'F') ... "  << std::flush;
	ds.unionSet("G","F");
	results = std::vector<std::string>();
	for(int i = 0; i < names.size(); ++i)
		results.push_back(ds.findSet(names[i]));
	unions = {"D","D","D","D","G","G","G","G","G", "J"};
	if (results != unions)
	{
		std::cout << "The created sets are incorrect." << std::endl;
		std::cout << "Should be: " << getVector(unions) << std::endl;
		std::cout << "Yours are: " << getVector(results) << std::endl;
		return false;
	}
	std::cout << "OK!" << std::endl;

	std::cout << "Using unionSet('D', 'G') ... "  << std::flush;
	ds.unionSet("D","G");
	results = std::vector<std::string>();
	for(int i = 0; i < names.size(); ++i)
		results.push_back(ds.findSet(names[i]));
	unions = {"D","D","D","D","D","D","D","D","D", "J"};
	if (results != unions)
	{
		std::cout << "The created sets are incorrect." << std::endl;
		std::cout << "Should be: " << getVector(unions) << std::endl;
		std::cout << "Yours are: " << getVector(results) << std::endl;
		return false;
	}
	std::cout << "OK!" << std::endl;

	std::cout << "All DisjointSet tests OK!" << std::endl << std::endl;
	return true;
}
bool ExceptionsDisjointSets()
{
	std::cout << "Starting Exception tests for DisjointSets" << std::endl << std::endl;

	DisjointSets<std::string> ds;
	ds.makeSet("A");

	std::cout << "Calling findSet() on non-existing element ..." << std::flush;
	try
	{
		ds.findSet("B");
		std::cout << " should result in exception being thrown." << std::endl;
		return false;
	} catch (const std::exception& e)
	{
		std::cout << " OK!" << std::endl;
	}

	std::cout << "Calling unionSet() with non-existing element(s) ..." << std::flush;
	try
	{
		ds.unionSet("A", "B");
		std::cout << " should result in exception being thrown." << std::endl;
		return false;
	} catch (const std::exception& e)
	{
		std::cout << "OK!" << std::endl;
	}
	try
	{
		ds.unionSet("B", "A");
		std::cout << " should result in exception being thrown." << std::endl;
		return false;
	} catch (const std::exception& e)
	{
		std::cout << " OK!" << std::endl;
	}

	std::cout << "Exception tests for DisjointSets OK!"  << std::endl << std::endl;
	return true;
}

void readFromFile(Graph<std::string> &g, std::string file)
{
	std::ifstream myfile(file);
	while(true)
	{
		std::string from = "";
		std::string to = "";
		int weight = 0;

		myfile >> from;
		myfile >> to; 
		myfile >> weight;
		g.addEdge(from, to, weight);
		g.addEdge(to, from, weight);
		if (myfile.eof())
			break;
	}
	myfile.close();
}

bool testGraphBasics()
{
	std::cout << "Starting basic Graph tests" << std::endl << std::endl;
	std::cout << "Creating a graph and using readFromFile() ... " << std::flush;
	Graph<std::string> g;
	readFromFile(g, "graph_basic.txt");
	std::cout << "OK!" << std::endl;

	std::cout << "Checking number of vertices with getNrOfVertices() ... " << std::flush;
	if (g.getNrOfVertices() != 6)
	{
		std::cout << "Incorrect." << std::endl;
		std::cout << "Should be 6, but returns " << g.getNrOfVertices() << "." << std::endl;
		return false;
	}
	std::cout << "OK!" << std::endl;

	std::cout << "Checking number of edges with getNrOfEdges() ... " << std::flush;
	if (g.getNrOfEdges() != 14)
	{
		std::cout << "Incorrect." << std::endl;
		std::cout << "Should be 14, but returns " << g.getNrOfEdges() << "." << std::endl;
		return false;
	}
	std::cout << "OK!" << std::endl;

	std::vector<std::string> vertices = {"A","B","C","D","E","F"};
	std::vector<std::vector<std::string>> edges;
	edges.push_back({"B","D"});
	edges.push_back({"A","C","F"});
	edges.push_back({"B","D"});
	edges.push_back({"A","C","E"});
	edges.push_back({"D","F"});
	edges.push_back({"B","E"});

	std::cout << "Checking that all vertices and edges exist using getAllNeighboursTo() ... " << std::flush;
	for(int i = 0; i < 6; ++i)
	{
		if (edges[i] != g.getAllNeighboursTo(vertices[i]))
		{
			std::cout << "Not all vertices and edges exist." << std::endl;
			std::cout << "On vertex "<< vertices[i] << " there should be these edges: " << getVector(edges[i]) << std::endl;
			std::cout << "But there are " << getVector(g.getAllNeighboursTo(vertices[i])) << std::endl;
			return false;
		}
	}
	std::cout << "OK!" << std::endl;
	
	std::cout << "Adding extra vertex Q using addVertex() and verifying its existence ... " << std::flush;
	g.addVertex("Q");
	std::vector<std::string> emptyVector;
	if (g.getNrOfVertices() != 7 || g.getAllNeighboursTo("Q") != emptyVector || g.getNrOfEdges() != 14)
	{
		std::cout << "Graph should contain 7 vertices, 14 edges, and Q should contain no neighbor." << std::endl;
		std::cout << "Your number of vertices are " << g.getNrOfVertices() << ", number of edges are " << g.getNrOfEdges() << " , and Qs neighbors are " << getVector(g.getAllNeighboursTo("Q"))<< std::endl;
		return false;
	}
	std::cout << "OK!" << std::endl;

	std::cout << "Adding edges between Q and A, and Q and C ... " << std::flush;
	g.addEdge("Q","A", 0);
	g.addEdge("A","Q", 0);
	g.addEdge("Q","C", 0);
	g.addEdge("C","Q", 0);
	std::vector<std::string> result = {"A","C"};
	if (g.getNrOfVertices() != 7 || g.getAllNeighboursTo("Q") != result || g.getNrOfEdges() != 18)
	{
		std::cout << "Graph should contain 7 vertices, 18 edges, and Q have A and C as neighbors." << std::endl;
		std::cout << "Your number of vertices are " << g.getNrOfVertices() << ", number of edges are " << g.getNrOfEdges()<< ", and Qs neighbors are " << getVector(g.getAllNeighboursTo("Q")) << std::endl;
		return false;
	}
	std::cout << "OK!" << std::endl;

	std::cout << "All basic Graph tests OK!" << std::endl << std::endl;
	return true;
}

bool ExceptionsGraph()
{
	std::cout << "Starting Exceptions tests for Graph" << std::endl << std::endl;

	Graph<std::string> g;
	g.addVertex("A");

	std::cout << "Calling addVertex() with already existing vertex ..." << std::flush;
	try
	{
		g.addVertex("A");
		std::cout << " should result in exception being thrown." << std::endl;
		return false;
	} catch (const std::exception& e)
	{
		std::cout << " OK!" << std::endl;
	}

	std::cout << "Calling getAllNeighboursTo() with non-existing vertex ..." << std::flush;
	try
	{
		g.getAllNeighboursTo("B");
		std::cout << " should result in exception being thrown." << std::endl;
		return false;
	} catch (const std::exception& e)
	{
		std::cout << "OK!" << std::endl;
	}
	std::cout << "Exception tests passed." << std::endl << std::endl;
	return true;
}

bool check_mst_edges(std::vector<std::tuple<std::string, std::string, int>> &mst, std::vector<std::tuple<std::string, std::string, int>> correct_mst)
{
	for(int i = 0; i < mst.size(); ++i)
	{
		if(std::find(correct_mst.begin(), correct_mst.end(), mst[i]) == correct_mst.end())
		{
			std::tuple<std::string, std::string, int> tup(std::get<1>(mst[i]), std::get<0>(mst[i]), std::get<2>(mst[i]));
			if(std::find(correct_mst.begin(), correct_mst.end(), tup) == correct_mst.end())
				return false;
			else
				correct_mst.erase(std::find(correct_mst.begin(), correct_mst.end(), tup));
		}
		else
			correct_mst.erase(std::find(correct_mst.begin(), correct_mst.end(), mst[i]));
	}
	return true;
}

std::string getEdges(std::vector<std::tuple<std::string, std::string, int>> edges)
{
	std::string ret = "";
	ret += "(" + std::get<0>(edges[0]) + "," + std::get<1>(edges[0]) + "," + std::to_string(std::get<2>(edges[0])) + ")";
	for(int i = 1; i < edges.size(); ++i)
		ret += ",(" + std::get<0>(edges[i]) + "," + std::get<1>(edges[i]) + "," + std::to_string(std::get<2>(edges[i])) + ")";
	return ret;
}

bool MSTTests()
{
	std::cout << "Starting MST Tests" << std::endl;
	Graph<std::string> g;

	std::cout << "Starting easier graph tests (graph_easy.txt) ... "  << std::flush;
	readFromFile(g, "graph_easy.txt");
	int cost = 0;
	std::vector<std::tuple<std::string, std::string, int>> mst;
	g.MST(mst, cost);
	std::vector<std::tuple<std::string, std::string, int>> correct_mst = {{"C", "D", 2}, {"A", "B", 3}, {"A", "D", 4}};
	if (cost != 9 || !check_mst_edges(mst, correct_mst))
	{
		std::cout << "The total cost of the MST is incorrect." << std::endl;
		std::cout << "It should be 9, but is " << cost << std::endl;
		std::cout << "The selected edges should be " << getEdges(correct_mst) << std::endl;
		std::cout << "The selected edges are " << getEdges(mst) << std::endl;
		std::cout << "The graph used is located in graph_easy.txt" << std::endl;
		return false;
	}
	std::cout << " OK!" << std::endl;

	Graph<std::string> g2;
	std::cout << "Starting medium graph tests (graph_medium.txt) ... " << std::flush;
	readFromFile(g2, "graph_medium.txt");
	cost = 0;
	mst = std::vector<std::tuple<std::string, std::string, int>>();
	g2.MST(mst, cost);
	correct_mst = {{"H", "G", 1}, {"C", "I", 2}, {"G", "F", 2}, {"A", "B", 4}, {"I", "G", 6}, {"C", "D", 7}, {"B","C",8}, {"D", "E", 9}};
	if (cost != 39 || !check_mst_edges(mst, correct_mst))
	{
		std::cout << "The total cost of the MST is incorrect." << std::endl;
		std::cout << "It should be 39, but is " << cost << std::endl;
		std::cout << "The selected edges should be " << getEdges(correct_mst) << std::endl;
		std::cout << "The selected edges are " << getEdges(mst) << std::endl;
		std::cout << "The graph used is located in graph_medium.txt" << std::endl;
		return false;
	}
	std::cout << " OK!" << std::endl;

	Graph<std::string> g3;
	std::cout << "Starting harder graph tests (graph_hard.txt) ... "  << std::flush;
	readFromFile(g3, "graph_hard.txt");
	cost = 0;
	mst = std::vector<std::tuple<std::string, std::string, int>>();
	g3.MST(mst, cost);
	correct_mst = {{"H","I",5},{"B","D",5},{"U","H",8},{"B","A",10},{"J","I",10},{"E","F",10},{"Y","Q",11},{"P","L",12},{"O","K",14},{"G","H",15},{"D","C",15},{"J","K",15},{"K","P",17},{"L","C",17},{"G","F",20},{"L","M",25},{"N","M",30},{"P","Q",45},{"Q","R",50},{"Z","W",55},{"S","R",55},{"T","S",60},{"U","V",70},{"V","W",75},{"W","X",80}};

	if (cost != 729 || !check_mst_edges(mst, correct_mst))
	{
		std::cout << "The total cost of the MST is incorrect." << std::endl;
		std::cout << "It should be 729, but is " << cost << std::endl;
		std::cout << "The selected edges should be " << getEdges(correct_mst) << std::endl;
		std::cout << "The selected edges are " << getEdges(mst) << std::endl;
		std::cout << "The graph used is located in graph_hard.txt" << std::endl;
		return false;
	}
	std::cout << " OK!" << std::endl;

	std::cout << "All MST tests OK!" << std::endl << std::endl;
	return true;
}

int main()
{
	if(!DisjointSetTests())
	{
		std::cout << "Disjoint Sets tests did not pass." << std::endl;
		return -1;
	}
	if(!ExceptionsDisjointSets())
	{
		std::cout << "Disjoint Sets Exceptions tests did not pass." << std::endl;
		return -2;
	}
	if (!testGraphBasics())
	{
		std::cout << "Basic testing not OK" << std::endl;
		return -3;
	}
	if(!ExceptionsGraph())
	{
		std::cout << "Exception tests not OK." << std::endl;
		return -4;
	}

	if (!MSTTests())
	{
		std::cout << "Testing MST algoritm on a small graph did not give the correct result ...." << std::endl;
		return -5;
	}
	std::cout<<std::endl;
	std::cout << "All tests passed. Hand in your code to the instructor." << std::endl;

	return 0;
}