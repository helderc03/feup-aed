//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_AIRLINE_H
#define UNTITLED_AIRLINE_H

#include <iostream>
#include "Location.h"
#include <unordered_set>
#include <unordered_map>


class Airline {
private:
    std::string code;
    std::string name;
    std::string callSign;
    Location location;
public:
    /**
     * Constructor for the Airline class.
     * Complexity: O(1)
     * @param code Airline code
     * @param name Airline name
     * @param callSign Airline call sign
     * @param location Airline location (city and country)
     */
    Airline(std::string code, std::string name, std::string callSign, Location location);

    /**
     * Setter for the airline's code.
     * Complexity: O(1)
     * @param code Airline code
     */
    void setCode(std::string code) ;

    /**
     * Setter for the airline's name.
     * Complexity: O(1)
     * @param name Airline name
     */
    void setName( std::string name) ;

    /**
     * Setter for the airline's call sign.
     * Complexity: O(1)
     * @param callSign Airline call sign
     */
    void setCallSign(std::string callSign) ;

    /**
     * Setter for the airline's location.
     * Complexity: O(1)
     * @param location Airline location
     */
    void setLocation(Location location);

    /**
     * Getter for the airline's location.
     * Complexity: O(1)
     * @return Airline's location
     */
    Location getLocation() const;

    /**
     * Getter for the airline's code.
     * Complexity: O(1)
     * @return Airline's code
     */
    std::string getCode() const;

    /**
     * Getter for the airline's name.
     * Complexity: O(1)
     * @return Airline's name
     */
    std::string getName() const;

    /**
     * Getter for the airline's call sign.
     * Complexity: O(1)
     * @return Airline's call sign.
     */
    std::string getCallSign() const;

};

struct HashF {
    int operator()(const std::string &code) const {
        int res = 0;
        for (int i = 0; i < code.size(); i++) {
            res = res * 23 + code[i];
        }
        return res;
    }

    bool operator()(const std::string &code1, const std::string &code2) const {
        return code1 == code2;
    }
};

typedef std::unordered_map<std::string,Airline,HashF> airlineMap;



#endif //UNTITLED_AIRLINE_H
