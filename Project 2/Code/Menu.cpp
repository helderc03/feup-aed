//
// Created by helde on 04/01/2023.
//

#include "Menu.h"
#include "Manager.h"


using namespace std;

int Menu::auxMenu(int maxOption, int minOption){
    int op;
    while (true) {
        std::cin >> op;
        if (std::cin.fail() || (op > maxOption || op < minOption)) {  // input is not an integer
            std::cout << "Please enter a valid integer: " ;
            std::cin.clear();  // clear the error flag
            std::cin.ignore(10000, '\n');  // ignore the invalid input
        } else {
            break;  // input is valid, break the loop
        }
    }
    return op;
}

int Menu::mainMenu() {
    cout << "\n";
    cout << "MAIN MENU\n\n";
    cout << "1.Route selection helper" << '\n' << "2.Airport information" << '\n' << "3.Network Stats" << '\n' << "4.Country Report" << '\n' << "5.About us" << '\n' << "0.Quit" << "\n\n";
    cout << "Choose an option: ";
    return auxMenu(5, 0);
}

int Menu::AboutUsMenu(){
    cout << "\nHelp platform for the use of air transports created in favor of the Algorithms and Data Structure course\n" << endl;
    cout << "Meet the team: \n";
    cout << left << setw(30) <<  "Student Name\t" << setw(18) << "Student number" << setw(9) << endl;
    cout << left << setw(30) <<  "Carlos Daniel Rebelo\t" << setw(18) << "202108885" << endl;
    cout << left << setw(30)  << "Hélder Costa\t"  << setw(18) << " 202108719" << endl;
    cout << left << setw(30)  << "Jaime Fonseca\t" << setw(18) << " 202108789" << endl;
    cout << endl << "0.Return to main menu: ";
    return auxMenu(0,0);
}

int Menu::flightMenu(){
    cout << endl << "ROUTE SELECTION HELP MENU\n" << endl;
    //correr função e adicionar print se necessário
    cout << "1.Route with less flights\n" << "2.Route with less distance\n" <<  "0.Return to main menu\n" << endl;
    cout << "Choose an option: ";
    return auxMenu(2,0);

}

int Menu::typeInfoChoiceMenu(){
    cout << endl << "INFORMATION MENU\n";
    cout << endl << "1.Get information about a specific airport\n";
    cout << "2.Top-k airports\n";
    cout << "0.Return to main menu\n";
    cout << endl << "Choose an option: ";
    return auxMenu(2,0);
}



int Menu::findChoiceMenu(){
    cout << endl << "How do you want to search for the airport:\n";
    cout << endl << "1.Search by airport code\n";
    cout << "2.Search by city\n";
    cout << "3.Search by country\n";
    cout << "4.Search the airport with the highest number of flights\n";
    cout << "5.Search the airport with the highest number of different destinations\n";
    cout << "0.Return to previous menu\n";
    cout <<endl << "Choose an option: ";
    return auxMenu(5,0);

}

int Menu::subMenu() {
    cout << endl << "1.Globally\n";
    cout << "2.City/Country\n";
    cout << endl << "Choose an option:";
    return auxMenu(2,1);
}

string Menu::findByCode(Manager& manager){
    string airport;
    cout << endl << "Insert airport code: ";
    cin >> airport;
    if(!manager.checkAirportExists(airport)){
        return "";
    }
    string s;
    for (char c : airport){
        s.push_back(::toupper(c));
    }
    cout << endl << "Airport found!\n" << manager.getAirports().at(s).getCode() << " - " << manager.getAirports().at(s).getName() << endl;

    return airport;
}

string Menu::findbyCity(Manager& manager){
    string city, r;
    int i = 1;
    cout << endl << "Insert the city: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, city);
    if (!manager.checkCityExists(city)) {return "";}
    airportMap airports = manager.airports_filter_by_city(city);
    map<int,string> m;
    cout << "Airports in " << airports.begin()->second.getLocation().getCity() << endl;
    for (auto a: airports){
        cout << i << ". " << a.second.getCode() << " - " << a.second.getName() << " - " << a.second.getLocation().getCountry() << endl;
        m.insert({i,a.second.getCode()});
        i++;
    }
    int input;
    while (true){
    cout << "Choose airport or 0 to return to previous menu: ";
    try{
        cin >> input;
        if (input >= 0 && input <= m.size()) break;
    }
    catch (exception e){ cout << "Invalid input" << endl;}
    }

    switch (input) {
        case 0:
            return "";
        default:
            return m.at(input);
    }

}

string Menu::findbyCountry(Manager& manager){
    string country, r;
    int i = 1;
    cout << endl << "Insert country:";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, country);
    if (!manager.checkCountryExists(country)) {return "";}
    string airport = manager.get_airport_by_country(country);
    if(airport == "") return "";
    return airport;

}

int Menu::infoChoiceMenu(){
    cout << "\nChoose the desired information:";
    cout << endl << "1.Airport Report\n";
    cout<< "2.How many countries can you get to with X flights\n";
    cout<< "3.How many cities can you get to with X flights\n";
    cout<< "4.How many airports can you get to with X flights\n";
    cout<< "5.Choose new airport\n";
    cout<< "0.Return to information menu\n";
    cout << "Choose an option: ";
    return auxMenu(5,0);

}

int Menu::nrFlights(){
    int x;
    cout << endl << "Choose the number of desired flights: ";
    cin >> x;
    return x;
}

int Menu::topAirportsMenu(){
    cout << endl << "1. Top-k airports with most flights" << endl;
    cout << "2. Top-k airports with most airlines" << endl;
    cout << "0. Return to information menu" << endl;
    cout << "Choose an option: ";
    return auxMenu(2,0);
}

int Menu::choiceK(){
    cout << endl << "Type a value for k: ";
    return auxMenu(3019,1);
}

int Menu::airportChoiceMenu1(){
    cout << endl << "Select airport of origin" << endl;
    cout << "1. Select airport by code" << endl;
    cout << "2. Select airport by city" << endl;
    cout << "3. Select airport by country" << endl;
    cout << "0. Return to main menu" << endl;
    cout << endl << "Choose an option: ";
    return auxMenu(3,0);
}

int Menu::airportChoiceMenu2(){
    cout << endl << "Select airport of destination" << endl;
    cout << "1. Select airport by code" << endl;
    cout << "2. Select airport by city" << endl;
    cout << "3. Select airport by country" << endl;
    cout << "0. Return to main menu" << endl;
    cout << endl << "Choose an option: ";
    return auxMenu(3,0);
}

int Menu::networkReportMenu(){
    cout << endl << "Select network stat\n" << endl;
    cout << "1. Network Report" << endl;
    cout << "2. Network articulation points" << endl;
    cout << "3. Network connected components/routes" << endl;
    cout << "4. Network diameter" << endl;
    cout << "0. Return to main menu" << endl;
    cout << endl << "Choose an option: ";
    return auxMenu(4,0);
}

string Menu::countryReportMenu(std::string &country){
    cout << endl << "Insert the country: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, country);
    return country;
}

void Menu::menuController(Manager& manager) {
    int op;
    cout << endl << "Welcome to the support platform for the use of air transports!\n";
    do {
        int temp;
        op = mainMenu();
        do {
            int temp2 , ex;

            switch (op) {
                case 1:{
                    string origin, dest;
                    int control = airportChoiceMenu1();
                    do{
                        switch (control) {
                            case 1:
                            {
                                origin = findByCode(manager);
                                control = 0;
                                ex = 1;
                                break;
                            }
                            case 2:
                            {
                                origin = findbyCity(manager);
                                control = 0;
                                break;
                            }
                            case 3:
                            {
                                origin = findbyCountry(manager);
                                control = 0;
                                break;
                            }
                            case 0 : {
                                ex = 0; temp = 0;
                            };
                        }
                    }while(control != 0);
                    if(!ex || origin == "") break;
                    cout << endl << "Airport of origin: " << origin << endl;
                    int var = airportChoiceMenu2();
                    int ex = 1;
                    do{
                        switch (var) {
                            case 1:
                            {
                                dest = findByCode(manager);
                                var = 0;
                                break;
                            }
                            case 2:
                            {
                                dest = findbyCity(manager);
                                var = 0;
                                break;
                            }
                            case 3:
                            {
                                dest = findbyCountry(manager);
                                var = 0;
                                break;
                            }
                            case 0 : {
                                ex = 0; temp = 0;
                            };
                        }
                    }while(var != 0);
                    if (!ex || dest == "") break;
                    if (manager.checkSameAirport(origin,dest)) { cout << endl << "Cant travel to same airport" << endl; break; }
                    cout << endl << "You want to travel from " << manager.toupperString(origin) << "-" << manager.toupperString(dest) << endl;
                    temp = flightMenu();
                    do{
                        switch(temp){
                            case 1:{
                                vector<Node> res = manager.getGraph().bfs(manager.getGraph().codeToPos[manager.toupperString(origin)], manager.getGraph().codeToPos[manager.toupperString(dest)]);
                                manager.printPath(res);
                                cout << endl << "Press 0 to continue.\n";
                                auxMenu(0,0);
                                // system("pause > nul");
                                temp = 0;
                                break;
                            }
                            case 2:{
                                vector<Node> res = manager.getGraph().dijkstraPathNodes(manager.getGraph().codeToPos[manager.toupperString(origin)], manager.getGraph().codeToPos[manager.toupperString(dest)]);
                                manager.printPath(res);
                                cout << endl << "Press 0 to continue.\n";
                                auxMenu(0,0);
                                temp = 0;
                                break;
                            }
                        }
                    }while(temp != 0);
                    break;
                }

                case 2:{
                    int control;
                    string str, airport;
                    do{
                        control = 1;
                        do{
                            int temp3;
                            temp2 = typeInfoChoiceMenu();
                            switch(temp2){
                                case 1:{
                                    do {
                                        control = 1;
                                        temp3 = findChoiceMenu();
                                        switch (temp3) {
                                            case 1: {
                                                airport = findByCode(manager);
                                                control = 1;
                                                break;
                                            }

                                            case 2: {
                                                airport = findbyCity(manager);
                                                if (airport == "") {
                                                    control = 0;
                                                    temp = 0;
                                                }
                                                else {
                                                control = 1;
                                                break;}
                                                break;
                                            }

                                            case 3: {
                                                airport = findbyCountry(manager);
                                                if (airport == "") {
                                                    control = 0;
                                                    temp = 0;
                                                    break;
                                                }
                                                else {
                                                control = 1;
                                                break;}
                                                // break;
                                            }

                                            case 4:{
                                                cout << endl << "Globally or in a specific country/city?\n"; //code smell em baixo quando criarmos a aux class podemos corrigir
                                                int x = subMenu();
                                                if(x == 1){
                                                    airport = manager.getGraph().getMaxConnections(2);
                                                    manager.airportReport(manager.toupperString(airport));
                                                }
                                                else{
                                                    string loc;
                                                    cout << endl << "What is the country/city ?";
                                                    cin.sync();
                                                    cin.clear();
                                                    getline(cin, loc);
                                                    airport = manager.getGraph().getMaxConnections(2,loc);
                                                    if(!manager.checkAirportExists(airport)){
                                                        temp3 = 0;
                                                        control = 0;
                                                    }
                                                    else
                                                        manager.airportReport(airport);

                                                }
                                                break;
                                            }

                                            case 5:{
                                                cout << endl << "Globally or in a specific country/city\n";
                                                int x = subMenu();
                                                if(x == 1){
                                                    airport = manager.getGraph().getMaxConnections(1);
                                                    manager.airportReport(airport);
                                                }
                                                else{
                                                    string loc;
                                                    cout << endl << "What is the country/city: ";
                                                    cin.sync();
                                                    cin.clear();
                                                    // cin.ignore();
                                                    getline(cin, loc);
                                                    airport = manager.getGraph().getMaxConnections(1,loc);
                                                    if(!manager.checkAirportExists(airport)){
                                                        temp3 = 0, control = 0;
                                                    }
                                                    else{
                                                         manager.airportReport(airport);
                                                    }
                                                }
                                                break;
                                            }

                                            case 0: {
                                                temp3 = 0;
                                                control = 0;
                                                break;
                                            }

                                        }
                                        while(control != 0) {
                                            temp = infoChoiceMenu();
                                            switch (temp) {
                                                int x;
                                                case 1: {
                                                    manager.airportReport(manager.toupperString(airport));
                                                    break;
                                                }

                                                case 2: {
                                                    x = nrFlights();
                                                    cout << "\nNumber of countries reachable with "<< x << " flights\n";
                                                    cout << manager.maxFlightsStats(airport, x,1);
                                                    cout << endl << "Press 0 to continue: ";
                                                    auxMenu(0,0);
                                                    // system("pause > nul");
                                                    break;
                                                }

                                                case 3: {
                                                    x = nrFlights();
                                                    cout << "\nNumber of cities reachable with "<< x << " flights\n";
                                                    cout << manager.maxFlightsStats(airport, x, 2);
                                                    cout << endl << "Press 0 to continue: ";
                                                    auxMenu(0,0);
                                                    // system("pause > nul");
                                                    break;
                                                }

                                                case 4: {
                                                    x = nrFlights();
                                                    cout << "\nNumber of airports reachable with "<< x << " flights\n";
                                                    cout << manager.maxFlightsStats(airport, x, 3);
                                                    cout << endl << "Press 0 to continue: ";
                                                    auxMenu(0,0);
                                                    // system("pause > nul");
                                                    break;
                                                }

                                                case 5: {
                                                    control = 0;
                                                    temp3 = 10;
                                                    break;
                                                }

                                                case 0:{
                                                    temp3 = 0;
                                                    control = 0;
                                                    break;
                                                }
                                            }
                                        }
                                    } while (temp3 != 0);
                                    break;
                                }

                                case 2:{
                                    int choice = topAirportsMenu();
                                    switch(choice){

                                        case 1:
                                        {
                                            int k = choiceK();
                                            cout << endl << "This might take a while, please wait" << endl;
                                            manager.printAirports(k,1);
                                            break;
                                        }

                                        case 2:
                                        {
                                            int k = choiceK();
                                            manager.printAirports(k,2);
                                            break;
                                        }

                                    }
                                    break;
                                }
                                case 3:
                                {
                                    manager.printArticulationPoints();
                                    break;
                                }
                                case 4:
                                {
                                    manager.printConnectedComponents();
                                    break;
                                }

                                case 5:
                                {
                                    manager.printDiameter();
                                    break;
                                }
                                
                                case 0:{
                                    control = 0;
                                    temp = 0;
                                    break;
                                }
                            }
                        } while (temp2 != 0);
                    } while(temp != 0);
                    break;
                }

                case 3:{
                    int temp2 = networkReportMenu();
                    int temp3 = 1;
                    do{
                        switch (temp2) {
                            case 1:
                                manager.calculateGlobalStatsNetwork();
                                temp3 = 0;
                                break;
                            case 2:
                                manager.printArticulationPoints();
                                temp3 = 0;
                                break;
                            case 3:
                                manager.printConnectedComponents();
                                temp3 = 0;
                                break;
                            case 4:
                                manager.printDiameter();
                                temp3 = 0;
                                break;
                            case 0:
                                temp = 0;
                                temp3 = 0;
                                break;
                        }
                        }while (temp3 != 0);
                    break;
                }

                case 4:{
                    string country;
                    countryReportMenu(country);
                    manager.countryReport(country);
                    temp = 0;
                    break;
                }


                case 5:{
                    temp = AboutUsMenu();
                    break;
                }

                case 0:{
                    temp = 0;
                    break;
                }

            }

        } while (temp != 0);

    } while (op != 0);
    cout << "\n";
    cout << "Thank you for using our platform! :) " << endl;
}

