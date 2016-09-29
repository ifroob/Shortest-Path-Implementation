#ifndef GRAPH_H
#define GRAPH_H
#include <algorithm>
#include <vector>
#include "LocatorHeap.h"
using namespace std;

class Edge;

class Vertex
{
public:
	int data;
	bool marked;
	vector<Edge *> edges;
	float d;
	Vertex *parent;
	Heap<Vertex>::Locator locator;

	Vertex ( int newData ) : data ( newData ) { }

	bool operator < ( const Vertex &v ) const 
	{ 
		return d < v.d;  
	}
    void printData(){		
			cout << data << " ";
	}
};

class Edge
{
public:
	Vertex *v1, *v2;
	float weight;

	Edge ( Vertex *nv1, Vertex *nv2, float newWeight ) : v1 ( nv1 ), v2 ( nv2 ), weight ( newWeight ) { }

	
};

// you should implement the adjacency list data structure
class Graph
{
protected:
	vector<Vertex *> verts;
	vector<Edge *> edges;

public:
	Graph ( void ) { }

	~Graph ( void )									//destructor deallocates memory created in the vector
	{
		for (int i = 0; i < verts.size(); ++i){
			delete verts[i];
		}
		for (int i = 0; i < edges.size(); ++i){
			delete edges[i];
		}
		
	}
	void printEdges(){
		for (int i = 0; i < edges.size(); ++i){
		cout  << edges[i]->v1->data << "+"<< edges[i]->v2->data;
	}
	}

	Vertex *insertVertex ( int data )
	{
		// implement me
		for (int i = 0; i < verts.size(); ++i){		//prevent us from inserting the same vertex
			if (verts[i]->data==data){				
				return verts[i];
			}
		}
		Vertex *v = new Vertex(data);				//make a new vertex
		verts.push_back(v);							//push it into the Vertex vector
		return v;
	}

	void insertEdge ( Vertex *v, Vertex *w, float weight )
	{
		Edge *e = new Edge(v, w, weight);
		edges.push_back(e);
		v->edges.push_back(e);							//for each vertex v and w we have a list of edges in the vector
		w->edges.push_back(e);
	}
	void printEdgeweights(){
		//cout << endl;
		for (int i = 0; i < edges.size(); ++i){
			cout << edges[i]->weight << " ";		
		}
	}
	vector<Vertex *> shortestPath ( Vertex *start, Vertex *goal ) //Dijkstra's algorithm -- vector of vertices?
	{			
		Heap<Vertex> pq; 												//make a heap based priority queue
		vector<Vertex*> f;								//return the shortest path vector
		if (start == goal){
			f.push_back(start);			
			return f;
		}
		for (int i = 0; i < verts.size(); ++i){							//for all vertices in the graph
			if (verts[i]->data == start->data){		
				verts[i]->d = 0;										//set starting distance to 0
			}
			else {														//set all other distances to ~infinity
				verts[i]->d = 9999999;				
			}
			 Heap<Vertex>::Locator l = pq.insertElement(verts[i]);		//this is a locator, insert all vertices
			 verts[i]->locator = l;										//set locator for the vertex	
		}					
			
		while(!pq.isEmpty()){
			Vertex *v = pq.removeMin();								//pull a vertex INTO the cloud
																	//the cloud contains the shortest path?
				for (int i = 0; i < v->edges.size(); ++i){
					Vertex *z;										//in the incident edge, get the adjacent vertex, store this in z
					if (v->edges[i]->v1->data==v->data){
						z = v->edges[i]->v2;
					}
					else{
						z = v->edges[i]->v1;
					}
					float r = v->d+v->edges[i]->weight;  			//r is the total weight and distance
					if (r < z->d){						 			//if r less than the incident edge's weight
						z->d = r;						 			//
						z->parent = v;					    
						pq.update(z->locator);						//update the locator (check this, ask how)							
					}						
				}				
			
		} 
			Vertex *tmp = goal;										
			while(tmp!=NULL){
				f.push_back(tmp);
				tmp = tmp->parent;									//the parent stores the path we take				
			}
			reverse(f.begin(), f.end());							//reverse the vector
			return f;
	}

	void numVertices(){}
	void numEdges(){}
	void vertices(){}
	

};

#endif