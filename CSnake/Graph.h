#ifndef CSNAKE_GRAPH_H
#define CSNAKE_GRAPH_H

#include "List.h"
namespace structures {
	// Graph abstract class
	class Graph {
	public:
		virtual ~Graph()
		{
		}
	public:
		// Return the number of vertices
		virtual int n() const = 0;
		// Return the current number of edges
		virtual int e() const = 0;
		// Return the index of the first neigbor of given vertex
		virtual int first(int) = 0;
		// Return the index of the next neigbor of given vertex
		virtual int next(int, int) = 0;
		// Store an edge defined by two vertices and weight
		virtual void setEdge(int, int, int) = 0;
		// Delete edge defined by two vertices
		virtual void deleteEdge(int, int) = 0;
		// Return weight of edge connecting two vertices
		// Return 0 if no such edge exists
		virtual int weight(int, int) const = 0;
		// Get mark value for a vertex
		virtual int getMark(int) const = 0;
		// Set mark value for a vertex
		virtual void setMark(int, int) = 0;
	};

	class Edge {
	public:
		int vertex;
		int weight;
		Edge() {
			vertex = -1;
			weight = -1;
		}
		Edge(int v, int w) {
			vertex = v;
			weight = w;
		}
		friend std::ostream&
			operator<<(std::ostream& out, Edge e)
		{
			return out << "--" << e.weight << "-->" << e.vertex << "\n";
		}
		//    operator<< (){
		//
		//    }

	};


	class GraphList :public Graph {
	private:
		const static int kUnvisited = 0;
		int _numVertex, _numEdge;
		List<Edge>** _vertex;	// List headers
		int* _mark;
	public:
		GraphList(int numVert);
		~GraphList();
		int n() const override {
			return _numVertex;
		}
		int e() const override {
			return _numEdge;
		}
		int first(int v) override;
		int next(int v1, int curr) override;
		void setEdge(int v1, int v2, int weight) override;
		void deleteEdge(int v1, int v2) override;
		int weight(int v1, int v2) const override;
		int getMark(int v) const override {
			return _mark[v];
		}
		void setMark(int v, int val) override {
			_mark[v] = val;
		}		
	};

	class GraphMatrix :public Graph {
	private:
		const static int kUnvisited = 0;
		int _numVertex, _numEdge;	// Store number of vertices,edges
		int **_matrix;	// Pointer to adjacency matrix
		int *_mark;		// Pointer to mark array
	public:
		GraphMatrix(int numVertex);
		~GraphMatrix();
		// Number of vertices
		int n() const override{
			return _numVertex;
		}
		// Number of edges
		int e() const override{
			return _numEdge;
		}
		int first(int v) override;
		// Get v1's neighbor after curr
		int next(int v1, int curr) override;
		// Set edge (v1,v2) to weight
		void setEdge(int v1, int v2, int weight) override;
		void deleteEdge(int v1, int v2) override;
		int weight(int v1, int v2) const override {
			return _matrix[v1][v2];
		}
		int getMark(int v) const override {
			return _mark[v];
		}
		void setMark(int v, int val) override {
			_mark[v] = val;
		}
	};
}
#endif