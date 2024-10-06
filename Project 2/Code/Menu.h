//
// Created by Daniel Rebelo on 30/12/2022.
//

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#include <iomanip>
#include <iostream>
#include "Manager.h"

class Menu {
public:
    /**
     * Auxiliary menu that limits user input.
     * Complexity: O(1)
     * @param maxOption Max input allowed
     * @param minOption Minimum input allowed
     * @return User input
     */
    int auxMenu(int maxOption, int minOption);

    /**
     * Prints the main menu and allows user choice.
     * Complexity: O(1)
     * @return User's choice
     */
    int mainMenu();

    /**
     * Prints the about us menu and allows user choice.
     * Complexity: O(1)
     * @return User's choice
     */
    int AboutUsMenu();

    /**
     * Allows the user to choose the type of route wanted.
     * Complexity: O(1)
     * @return User's choice
     */
    int flightMenu();

    /**
     * Allows the user to choose how he wants to search for an airport.
     * Complexity: O(1)
     * @return User's choice
     */
    int findChoiceMenu();

    /**
     * Allows the user to choose between globally or locally.
     * @return User's choice
     */
    int subMenu();

    /**
     * Finds an airport by user inputting its code.
     * Complexity: O(1)
     * @param manager Manager object with all the information
     * @return The requested airport's code
     */
    std::string findByCode(Manager& manager);

    /**
     * Finds all the airports in a city and allows user choice.
     * Complexity: O(n)
     * @param manager Manager object with all the information
     * @return The user's choice airport code
     */
    std::string findbyCity(Manager& manager);

    /**
     * Finds all the airport in a country and allows user choice.
     * Complexity: O(n)
     * @param manager Manager object with all the information
     * @return The user's choice airport code
     */
    std::string findbyCountry(Manager& manager);

    /**
     * Allows the user to choose the type of information he wants to see.
     * Complexity: O(1)
     * @return User's choice
     */
    int typeInfoChoiceMenu();

    /**
     * Allows the user to choose the specific type of information he wants to see.
     * Complexity: O(1)
     * @return User's choice
     */
    int infoChoiceMenu();

    /**
     * Allows the user to choose the number of flights to use in the search.
     * Complexity: O(1)
     * @return User's choice
     */
    int nrFlights();

    /**
     * Menu controller that calls all the other menus and function necessary.
     * Complexity: Since it can be run indefinitely and call an infinite amount of functions it's impossible to calculate the worst case scenario.
     * @param manager Manager with all the information
     */
    void menuController(Manager& manager);

    /**
     * Allows the user to choose the top-k in X he wants to see.
     * Complexity: O(1)
     * @return User's choice
     */
    int topAirportsMenu();

    /**
     * Allows the user to choose the k in the previous function.
     * Complexity: O(1)
     * @return User's choice
     */
    int choiceK();

    /**
     * Allows the user to choose the way to search for an airport (origin).
     * Complexity: O(1)
     * @return User's choice
     */
    int airportChoiceMenu1();

    /**
     * Allows the user to choose the way to seach for an airport (destination).
     * Complexity: O(1)
     * @return User's choice
     */
    int airportChoiceMenu2();

    /**
     * Allows the user to choose the type of information about the entire network.
     * Complexity: O(1)
     * @return User's choice
     */
    int networkReportMenu();

    /**
     * Allows the user to choose the country.
     * Complexity: O(1)
     * @param country Country
     * @return The desired country
     */
    std::string countryReportMenu(std::string &country);
};


#endif //UNTITLED_MENU_H
