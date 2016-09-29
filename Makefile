all: graph

graph:
	g++ *.cpp -o graph 

clean: 
	rm graph
