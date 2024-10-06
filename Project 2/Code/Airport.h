//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_AIRPORT_H
#define UNTITLED_AIRPORT_H
#include <iostream>
#include "Location.h"
#include "Coordinates.h"
#include <unordered_set>
#include <unordered_map>


class Airport {

    private:
        std::string code;
        std::string name;
        Location location;
        Coordinates coordinates;
    public:
        /**
         * Constructor for the class Airport.
         * Complexity: O(1)
         * @param code Airport's code
         * @param name Airport's name
         * @param location Airport's location (city and country)
         * @param coordinates Airport's coordinates
         */
        Airport(std::string code, std::string name, Location location, Coordinates coordinates);

        /**
         * Getter for the airport's code.
         * Complexity: O(1)
         * @return Airport's code
         */
        std::string getCode() const;

        /**
         * Getter for the airport's name.
         * Complexity: O(1)
         * @return Airport's name
         */
        std::string getName() const;

        /**
         * Getter for the airport's location.
         * Complexity: O(1)
         * @return Airport's location
         */
        Location getLocation() const;

        /**
         * Getter for the airport's coordinates.
         * Complexity: O(1)
         * @return Airport's coordinates
         */
        Coordinates getCoordinates() const;

        /**
         * Setter for the airport's code.
         * Complexity: O(1)
         * @param code Airport's code
         */
        void setCode(std::string code);

        /**
         * Setter for the airport's name.
         * Complexity: O(1)
         * @param name Airport's name
         */
        void setName(std::string name);

        /**
         * Setter for the airport's location.
         * Complexity: O(1)
         * @param location Airport's location
         */
        void setLocation(Location location);

        /**
         * Setter for the airport's coordinates.
         * Complexity: O(1)
         * @param coordinates Airport's coordinates
         */
        void setCoordinates(Coordinates coordinates);
};


struct HashFunction{

    int operator()(const std::string &code) const{
        int res = 0;
        for(int i = 0; i < code.size(); i++){
            res = res * 13 + code[i];
        }
        return res;
    }

    bool operator()(const std::string &code1 , const std::string &code2) const {
        return code1 == code2;
    }
};

typedef std::unordered_map<std::string,Airport,HashFunction> airportMap;

#endif //UNTITLED_AIRPORT_H
