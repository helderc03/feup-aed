//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_FILEREADER_H
#define UNTITLED_FILEREADER_H

#include <unordered_set>
#include <limits>
#include <vector>
#include <sstream>
#include <iostream>

#include "Airline.h"
#include "Graph.h"
#include "Flight.h"
#include "Airport.h"

class FileReader {

    public:
        /**
         * Default constructor for the FileReader class.
         * Complexity: O(1)
         */
        FileReader();

        /**
         * Reader for the airports info file.
         * Complexity: O(n²)
         * @param airportFile Airports info file
         * @return Map containing all airports
         */
        airportMap readAirportsFile(std::istream &airportFile);

        /**
         * Reader for the airlines info file.
         * Complexity: O(n²)
         * @param airlinesFile Airlines info file
         * @return Map containing all airlines
         */
        airlineMap readAirlinesFile(std::istream &airlinesFile);

        /**
         * Reader for the flights info file.
         * Complexity: O(n²)
         * @param flightFile Flights info file
         * @param graph Graph in which the flights are saved
         */
        void readFlightFile(std::istream &flightFile, Graph &graph);

};


#endif //UNTITLED_FILEREADER_H
