//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_LOCATION_H
#define UNTITLED_LOCATION_H

#include <iostream>
#include <string>

class Location{

private:
    std::string city;
    std::string country;
public:
    /**
     * Default constructor for the Location class.
     * Complexity: O(1)
     */
    Location(void);

    /**
     * Constructor for the Location class.
     * Complexity: O(1)
     * @param city Location's city
     * @param country Location's country
     */
    Location(std::string city, std::string country);

    /**
     * Constructor for the Location class.
     * Complexity: O(1)
     * @param country Location's country
     */
    Location(std::string country);

    /**
     * Setter for the location's city
     * Complexity: O(1)
     * @param city Location's city
     */
    void setCity(std::string city) ;

    /**
     * Setter for the location's country.
     * Complexity: O(1)
     * @param country Location's country
     */
    void setCountry(std::string country) ;

    /**
     * Getter for the location's city.
     * Complexity: O(1)
     * @return Location's city
     */
    std::string getCity() const;

    /**
     * Getter for the location's country.
     * Complexity: O(1)
     * @return Location's country
     */
    std::string getCountry() const;

    /**
     * Comparator between two cities.
     * @param city City used in comparator
     * @return True if the cities are the same or false otherwise
     */
    bool operator==(const Location &city) const;
};


#endif //UNTITLED_LOCATION_H


