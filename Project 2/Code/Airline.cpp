//
// Created by Jaime on 28/12/2022.
//

#include "Airline.h"

Airline::Airline(std::string code, std::string name, std::string callSign, Location location){
    this->code = code;
    this->name = name;
    this->callSign = callSign;
    this->location = location;
}

void Airline::setCode(std::string code){
    this->code = code;
}

void Airline::setName( std::string name){
    this->name = name;
}
void Airline::setCallSign(std::string callSign){
    this->callSign = callSign;
}

void Airline::setLocation(Location location) {
    this->location = location;
}


std::string Airline::getCode() const{
    return this->code;
}
std::string Airline::getName() const{
    return this->name;
}
std::string Airline::getCallSign() const{
    return this->callSign;
}

Location Airline::getLocation() const {
    return this->location;
}

