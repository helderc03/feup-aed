//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_FLIGHT_H
#define UNTITLED_FLIGHT_H
#include <string>



class Flight {

    private:
        std::string source;
        std::string dest;
        std::string airlineCode;
    public:
        /**
         * Default constructor for the Flight class.
         * Complexity: O(1)
         */
        Flight(void);

        /**
         * Constructor for the Flight class.
         * Complexity: O(1)
         * @param source Flight's source
         * @param dest Flight's destination
         * @param airlineCode Airline providing the flight
         */
        Flight(std::string source, std::string dest, std::string airlineCode);

        /**
         * Getter for the flight's source.
         * Complexity: O(1)
         * @return Flight's source
         */
        std::string getSource() const;

        /**
         * Getter for the flight's destination.
         * Complexity: O(1)
         * @return
         */
        std::string getDest() const;

        /**
         * Getter for the airline's code providing the flight.
         * Complexity: O(1)
         * @return Airline's code
         */
        std::string getAirlineCode() const;

};


#endif //UNTITLED_FLIGHT_H
