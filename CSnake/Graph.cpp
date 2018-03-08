#include"Graph.h"
#include"utility_macros.h"
namespace structures {

	GraphList::GraphList(int numVert) {
		_numVertex = numVert;
		_numEdge = 0;
		_mark = new int[_numVertex];

		for (size_t i = 0; i < _numVertex; i++)
			_mark[i] = kUnvisited;
		// Create and initialize adjacency lists
		_vertex = (List<Edge>**) new List<Edge>*[_numVertex];
		for (size_t i = 0; i < _numVertex; i++)
			_vertex[i] = new LList<Edge>();

	}
	GraphList::~GraphList() {
		delete[] _mark;
		for (size_t i = 0; i < _numVertex; i++)
			delete[] _vertex[i];
		delete[] _vertex;
	}
	int GraphList::first(int v) {
		Edge it;
		_vertex[v]->setStart();
		if (_vertex[v]->getValue(it))
			return it.vertex;
		else
			return _numVertex;
	}
	int GraphList::next(int v1, int curr) {
		Edge it;
		_vertex[v1]->getValue(it);
		if (it.vertex == curr)
			_vertex[v1]->next();
		else {
			_vertex[v1]->setStart();
			while (_vertex[v1]->getValue(it) && (it.vertex <= curr))
				_vertex[v1]->next();
			if (_vertex[v1]->getValue(it))
				return it.vertex;
			else
				return _numVertex;
		}
	}
	void GraphList::setEdge(int v1, int v2, int weight) {
		Assert(weight > 0, "Illegal weight value");
		Edge it(v2, weight);
		Edge curr;
		_vertex[v1]->getValue(curr);
		if (curr.vertex != v2)
			for (_vertex[v1]->setStart(); _vertex[v1]->getValue(curr); _vertex[v1]->next())
				if (curr.vertex >= v2)
					break;
		if (curr.vertex == v2)
			_vertex[v1]->remove(curr);
		else
			_numEdge++;
		_vertex[v1]->insert(it);
	}
	void GraphList::deleteEdge(int v1, int v2) {
		Edge curr;
		_vertex[v1]->getValue(curr);
		if (curr.vertex != v2)
			for (_vertex[v1]->setStart(); _vertex[v1]->getValue(curr); _vertex[v1]->next())
				if (curr.vertex >= v2)
					break;
		if (curr.vertex == v2) {
			_vertex[v1]->remove(curr);
			_numEdge--;
		}
	}
	int GraphList::weight(int v1, int v2) const {
		Edge curr;
		_vertex[v1]->getValue(curr);
		if (curr.vertex != v2)
			for (_vertex[v1]->setStart(); _vertex[v1]->getValue(curr); _vertex[v1]->next())
				if (curr.vertex >= v2)
					break;
		if (curr.vertex == v2)
			return curr.weight;
		else
			return 0;	// No such edge
	}

	GraphMatrix::GraphMatrix(int numVertex) {
		_numVertex = numVertex;
		_numEdge = 0;
		_mark = new int[_numVertex];
		for (size_t i = 0; i < _numVertex; i++)
			_mark[i] = kUnvisited;
		_matrix = (int**) new int*[_numVertex];
		for (size_t i = 0; i < _numVertex; i++)
			_matrix[i] = new int[_numVertex];
		for (size_t i = 0; i < _numVertex; i++)
			for (size_t j = 0; j < _numVertex; j++)
				_matrix[i][j] = 0;
	}
	GraphMatrix::~GraphMatrix() {
		delete[] _mark;
		for (size_t i = 0; i < _numVertex; i++)
			delete[] _matrix[i];
		delete[] _matrix;
	}
	int GraphMatrix::first(int v) {
		int i;
		for (i = 0; i < _numVertex; i++)
			if (_matrix[v][i] != 0)
				return i;
		return i;	// Return n if none
	}
	int GraphMatrix::next(int v1, int curr) {
		int i;
		for (i = curr+1; i < _numVertex; i++)
			if (_matrix[v1][i] != 0) return i;
		return i;
	}
	void GraphMatrix::setEdge(int v1, int v2, int weight) {
		Assert(weight > 0, "Illegal weight value");
		if (_matrix[v1][v2] == 0)
			_numEdge++;
		_matrix[v1][v2] = weight;
	}
	void GraphMatrix::deleteEdge(int v1, int v2) {
		if (_matrix[v1][v2] != 0)
			_numEdge--;
		_matrix[v1][v2] = 0;
	}

}
//#define DEBUG_CSNAKE_GRAPH_H
#ifdef DEBUG_CSNAKE_GRAPH_H
#include <iostream>
int main(void) {
	std::cout << "1\n";
	using structures::GraphMatrix;
	GraphMatrix a(5);
	a.setEdge(0, 1, 1);
	a.setEdge(0, 4, 1);

	a.setEdge(1, 0, 1);
	a.setEdge(1, 2, 1);

	a.setEdge(2, 1, 1);
	a.setEdge(2, 3, 1);

	a.setEdge(3, 2, 1);
	a.setEdge(3, 4, 1);

	a.setEdge(4, 3, 1);
	a.setEdge(4, 0, 1);

	for (size_t i = 0; i < a.n(); i++)
	{
		for (size_t j = 0; j < a.n(); j++)
		{
			std::cout << a.weight(i, j) << " ";
		}
		std::cout << "\n";
	}

	for (int i = a.first(0); i < a.n(); i = a.next(0,i))
	{
		std::cout << a.weight(0, i) << " ";
	}
	std::cout << std::endl;
	
	system("pause");
}
#endif // DEBUG_CSNAKE_GRAPH_H
