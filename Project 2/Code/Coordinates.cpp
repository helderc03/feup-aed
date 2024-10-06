//
// Created by Jaime on 30/12/2022.
//

#include "Coordinates.h"

Coordinates::Coordinates() {}

Coordinates::Coordinates(double latitude, double longitude) {this->latitude = latitude, this->longitude = longitude;}

double Coordinates::getLongitude() {return longitude;}

double Coordinates::getLatitude() {return latitude;}

void Coordinates::setLatitude(double latitude) {this->latitude = latitude;}

void Coordinates::setLongitude(double longitude) {this->longitude = longitude;}
