//
// Created by Daniel Rebelo on 30/12/2022.
//

#ifndef UNTITLED_MANAGER_H
#define UNTITLED_MANAGER_H

#include "FileReader.h"
#include <list>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>

class Manager {

    airportMap airports;
    airlineMap airlines;
    Graph graph;

public:
    /**
     * Default constructor for the manager class.
     * Complexity: O(1)
     */
    Manager();

    /**
     * Manager's initializer.
     * Complexity: O(n²)
     */
    void init();

    /**
     * Getter for all the airports.
     * Complexity: O(1)
     * @return All airports
     */
    airportMap getAirports();

    /**
     * Getter for all the airlines
     * Complexity: O(1)
     * @return All airlines
     */
    airlineMap getAirlines();

    /**
     * Getter for the graph.
     * Complexity: O(1)
     * @return The graph
     */
    Graph getGraph();

    /**
     * Get a user choice airport in a specific country.
     * Complexity: O(n)
     * @param country User's choice country
     * @return Airport's code chosen by the user
     */
    std::string get_airport_by_country(std::string country);

    /**
     * Gets all the airports in a country.
     * Complexity: O(n)
     * @param country Country (user chosen)
     * @return All the airports
     */
    airportMap airports_filter_by_country(std::string country);

    /**
     * Gets all the airports in a city.
     * Complexity: O(n)
     * @param city City (user chosen)
     * @return All the airports
     */
    airportMap airports_filter_by_city(std::string city);

    /**
     * Gets all the airlines operating in an airport
     * @param airportCode Airport code (user chosen)
     * @return All the airlines
     */
    airlineMap airlines_filter_by_airport(std::string airportCode);

    /**
     * Prints the airport with the most connections.
     * Complexity: O(n²)
     * @param opt User option
     * @param country Country restriction if needed
     */
    void airportWithMostConnections(int opt, std::string country);

    /**
     * Gets all the departures in an airport.
     * Complexity: O(n)
     * @param airportCode Airport's code
     * @return All the departures
     */
    int getDepartures(std::string airportCode);

    /**
     * Gets all the arrivals in an airport.
     * Complexity: O(n)
     * @param airportCode Airport's code
     * @return All the arrivals
     */
    int getArrivals(std::string airportCode);

    /**
     * Gets the number of flights in an airport (departures + arrivals).
     * Complexity: O(n)
     * @param airportCode Airport's code
     * @return Number of flights
     */
    int getNumberFlights(std::string airportCode);

    /**
     * Gets the number of airlines operating in an airport.
     * Complexity: O(n)
     * @param airportCode Airport's code
     * @return Number of airlines
     */
    int getNumberAirlinesAirport(std::string airportCode);

    /**
     * Gets the number of unique destinations from an airport.
     * Complexity: O(n)
     * @param airportCode Airport's code
     * @return Number of unique destinations
     */
    int getNumberDestinations(std::string airportCode);

    /**
     * Gets the number of countries an airport has flights to.
     * Complexity: O(n)
     * @param airportCode Airport's code
     * @return Number of countries
     */
    int getNumberDestinationsCountries(std::string airportCode);

    /**
     * Number of countries you can get to from an airport with X amount of flights.
     * Complexity: O(n)
     * @param airport Airport's code
     * @param maxFlights Amount of maximum flights.
     * @param opt User option
     * @return Number of countries
     */
    int maxFlightsStats(std::string airport, int maxFlights, int opt);

    /**
     * Prints the amount of airports, airlines and flights globally.
     * Complexity: O(n)
     */
    void calculateGlobalStatsNetwork();


    /**
     * Checks if the airport exists.
     * Complexity: O(1)
     * @param airportCode Airport's code
     * @return True or false
     */
    bool checkAirportExists(std::string airportCode);

    /**
     * Check if the airline exists.
     * Complexity: O(1)
     * @param airlineCode Airline's code
     * @return True or false
     */
    bool checkAirlineExists(std::string airlineCode);

    /**
     * Check if the country exists.
     * Complexity: O(1)
     * @param country Country's name
     * @return True or false
     */
    bool checkCountryExists(std::string country);

    /**
     * Check if city exists.
     * Complexity: O(1)
     * @param city City's name
     * @return True or false
     */
    bool checkCityExists(std::string city);

    /**
     * Prints the report of an airport with various details.
     * Complexity: O(n)
     * @param airportCode Airport's code
     */
    void airportReport(std::string airportCode);


    /**
     * Prints the path of a flight.
     * Complexity: O(n)
     */
    void printPath(std::vector<Node> airports );

    /**
     * Auxiliary that makes everything lower cased.
     * Complexity: O(n)
     * @param str String received
     * @return Lower cased string
     */
    std::string tolowerString(std::string str);

    /**
     * Gets the number of connected components.
     * Complexity: O(n)
     * @return Number of connected components
     */
    int getConnectedComponents();

    /**
     * Gets the number of articulation points.
     * Complexity: O(n)
     * @return Number of articulation points
     */
    int getArticulationPoints();

    /**
     * Prints airports with some details.
     * Complexity: O(n)
     * @param k Amount of airports
     * @param opt User option
     */
    void printAirports(int k,int opt);

    /**
     * Prints the articulation points.
     * Complexity: O(n)
     */
    void printArticulationPoints();

    /**
     * Prints the connected components.
     * Complexity: O(n)
     */
    void printConnectedComponents();

    /**
     * Prints the graph's diameter.
     * Complexity: O(n²)
     */
    void printDiameter();

    /**
     * Checks if two airports are the same.
     * Complexity: O(1)
     * @param origin Airport 1
     * @param dest Airport 2
     * @return True or false.
     */
    bool checkSameAirport(std::string origin, std::string dest);

    /**
     * Transform a string to all upper case.
     * Complexity: O(n)
     * @param s String to be transformed
     * @return Transformed string
     */
    std::string toupperString(std::string s);

    /**
     * Prints the report on a certain country
     * Complexity: O(n)
     * @param country Country on which to report
     */
    void countryReport(std::string &country);
};


#endif //UNTITLED_MANAGER_H
