//Brian Ta
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


int main(){
	cout << "Look at me!!!" << endl;
	ifstream in("rand200.txt");		//get the txt file
	string input, input2, input3;
	int vert, edge, v1, v2  = 0;	
	float wt;
	getline(in, input, ' ');	
	getline(in, input2);	
	vert = atoi(input.c_str());		//number of vertices
	edge = atoi(input2.c_str());	//number of edges	
	Vertex *v_1;
	Vertex *v_2;
	Graph g;
	 
	 
	 cout << "Connected vertices: ";
	 for(int i = 0; i < edge; ++i){
		getline(in, input, ' ');
		getline(in, input2, ' ');
		getline(in, input3);
		wt = atof(input3.c_str());  //get the weight
		v1 = atoi(input.c_str());	//vertex one
		v2 = atoi(input2.c_str());	//vertex two
		
		v_1 = g.insertVertex(v1);	//insert vertex 1
		v_2 = g.insertVertex(v2);	//insert vertex 2
		
	    g.insertEdge(v_1, v_2, wt);	//insert the edge v_1 and v_2 make
	    v_1->printData();			//print vertices
		v_2->printData();
		
		//g.printEdges();
	} 
	cout << endl << "Edge weights: ";
	g.printEdgeweights();			//print all edge weights
	
	
	//code to grab the last two indices (start vertex to goal vertex) in the file
	
	int ind1=0;
	int ind2=0;
	getline(in, input, ' ');
	getline(in, input2);
	ind1 = atoi(input.c_str());			
	ind2 = atoi(input2.c_str());	
	Vertex *start = g.insertVertex(ind1);
	Vertex *end = g.insertVertex(ind2);
	vector<Vertex*> sp;
	sp = g.shortestPath(start, end);				//Grab the Shortest Path vector of vertices
	
	
	/* Print the Shortest Path Vector */
	
	cout << "\n\n\nShortest Path: " << endl;
	for (int i = 0; i < sp.size(); ++i){		
		if (sp[i]==end){
			cout << sp[i]->data;
		}
		else{
			cout << sp[i]->data << " -> ";			//print the shortest path vertices		
		}
	}
	cout << endl;
	
	
	
	

	
	
}
	
	
 