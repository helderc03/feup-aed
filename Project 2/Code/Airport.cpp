//
// Created by Jaime on 28/12/2022.
//

#include "Airport.h"
using namespace std;

Airport::Airport(string code, string name, Location location, Coordinates coordinates){
    this->code = code;
    this->name = name;
    this->location = location;
    this->coordinates = coordinates;
}

std::string Airport::getCode() const{
    return code;
}

std::string Airport::getName() const{
    return name;
}
Location Airport::getLocation() const {
    return location;
}

Coordinates Airport::getCoordinates() const {
    return coordinates;
}

void Airport::setCode(string code){
    this->code = code;
}

void Airport::setName(string name) {
    this->name = name;
}

void Airport::setLocation(Location location) {
    this->location = location;
}

void Airport::setCoordinates(Coordinates coordinates) {this->coordinates = coordinates;}



