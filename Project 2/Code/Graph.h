//
// Created by Jaime on 29/12/2022.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H
#include <iostream>
#include "Airport.h"
#include "MinHeap.h"
#include "unordered_map"
#include <vector>
#include <queue>
#include <list>
#include <cmath>
#include <set>
#define INF (INT16_MAX/2)

struct Edge{
    int dest;
    std::string destName;
    std::string airlineCode;
};

struct Node{
    Airport airport;
    std::list<Edge> adj;
    bool visited;
    int dist;
    int pred;
    int low;
    int num;
    std::string airlineUsed; //airline que conecta este node ao seu predecessor no algoritmo de dijkstra
};


class Graph {
    int n;
    bool hasDir;
    std::vector<Node> nodes;

public:
    /**
     * Default constructor for the Graph class.
     * Complexity: O(1)
     */
    Graph();

    /**
     * Constructor for the Graph class.
     * Complexity: O(1)
     * @param nodes How many nodes there are in the graph
     * @param dir Is the graph directed or not, default to false.
     */
    Graph(int nodes, bool dir = false);

    /**
     * Adds a edge to the graph.
     * Complexity: O(1)
     * @param src Edge's source
     * @param dest Edge's destination
     * @param airlineCode Airline associated (edges represent flights)
     */
    void addEdge(int src, int dest, std::string airlineCode = "");

    /**
     * Depth-first search starting at node v.
     * Complexity: O(n)
     * @param v Started node
     */
    void dfs(int v);

    /**
     * Breadth-first search with starting and ending node.
     * Complexity: O(1)
     * @param start Started node
     * @param end Ending node
     * @return Visited nodes (path)
     */
    std::vector<Node> bfs(int start, int end);

    /**
     * Breadth-first search with max distance limitator.
     * Complexity: O(n)
     * @param start Starter node
     * @param maxDistance Max distance allowed
     * @return Visited nodes (path)
     */
    std::vector<Node> bfsMD(int start, int maxDistance);

    /**
     * Depth-first search with counter.
     * Complexity: O(n)
     * @return Counter for the amount of nodes visited
     */
    int dfs_cc();

    /**
     * Adds a node to the graph.
     * Complexity: O(1).
     * @param airport Airport that corresponds to the new node
     */
    void addNode(Airport airport);

    /**
     * Calculates the distance between two different locations.
     * Complexity: O(1)
     * @param source Source location
     * @param dest Destination location
     * @return Distance between the locations.
     */
    double haversine(std::string source, std::string dest);

    /**
     *Algorithm that finds the shortest path between nodes.
     * Complexity: O(log n)
     * @param src Algorithm's source
     */
    void dijkstra(int src);
    /**
     * Using Dijkstra's algorithm to find the shortest path between to nodes.
     * Complexity: O(n²)
     * @param a Source node
     * @param b Destination node
     * @return Shortest path between the nodes
     */
    std::vector<Node> dijkstraPathNodes(int a, int b);

    std::unordered_map<std::string, int> codeToPos;
    std::unordered_map<int, std::string> posToCode;

    /**
     * Calculates either the airport with the most unique destinations or the airport with most flights.
     * Complexity: O(n²)
     * @param opt User's choice
     * @param country If the user wants to restrict the search to a specific country
     * @return Desired airport's code.
     */
    std::string getMaxConnections(int opt, std::string country = "");

    /**
     * Return the weight of a edge (represent a flight's distance).
     * Complexity: O(log n)
     * @param src Edge's source node
     * @param edge Edge (flight) in case
     * @return Edge's weight
     */
    int getWeight(int src, Edge edge);

    /**
     * Gets how many departures a certain airport has.
     * Complexity: O(n)
     * @param code Airport's code
     * @return Number of departures
     */
    int getDeparturesAirport(std::string code);

    /**
     * Gets how many destinations an airport has flights to.
     * Complexity: O(n)
     * @param code Airport's code
     * @return Number of destinations
     */
    int getNrDestinations(std::string &code);

    /**
     * Gets how many countries an airport has flights to.
     * Complexity: O(n)
     * @param code Airport's code
     * @return Number of countries
     */
    int getNrDestinationsCountries(std::string &code);

    /**
     * Gets the number of flights worldwide.
     * Complexity: O(n)
     * @return Number of flights
     */
    int getNrTotalFlights();

    /**
     * Gets how many flights an airline has.
     * Complexity: O(n)
     * @param airlineCode Airline's code
     * @return Number of flights
     */
    int getFlightsAirline(std::string airlineCode);

    /**
     * Gets how many airlines operate in a certain airport.
     * Complexity: O(n)
     * @param airportCode Airport's code
     * @return Number of airlines
     */
    int calculateAirlinesAirport(std::string airportCode);

    /**
     * Gets the number of arrivals in a certain airport.
     * Complexity: O(n)
     * @param code Airport's code
     * @return Number of arrivals
     */
    int getArrivalsAirport(std::string code);

    /**
     * Gets the airlines operating in a certain airport.
     * Complexity: O(n)
     * @param airportCode Airport's code
     * @return All the airlines operating in that airport
     */
    std::set<std::string> getAirlinesAirport(std::string airportCode);

    /**
     * Gets the number of articulation points.
     * Complexity: O(n)
     * @return Number of articulation points
     */
    std::vector<int> getArticulationPoints();

    /**
     * Depth-first search returning all the articulation points.
     * Complexity: O(n² log n)
     * @param i Starter node
     * @param order
     * @param vec Vector containing all the articulation points
     */
    void dfs_articulationPoints(int i,int order,std::vector<int> &vec);


    /**
     * Gets the graph diameter.
     * Complexity: O(n²)
     * @return Graph's diameter
     */
    int diameter();

};


#endif //UNTITLED_GRAPH_H
