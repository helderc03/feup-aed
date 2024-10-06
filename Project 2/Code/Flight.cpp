//
// Created by Jaime on 28/12/2022.
//

#include "Flight.h"


Flight::Flight() {}

Flight::Flight(std::string source, std::string dest, std::string airlineCode) {
    this->source = source;
    this->dest = dest;
    this->airlineCode = airlineCode;
}

std::string Flight::getSource() const{
    return source;
}

std::string Flight::getDest() const{
    return dest;
}

std::string Flight::getAirlineCode() const{
    return airlineCode;
}