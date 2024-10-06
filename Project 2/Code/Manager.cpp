//
// Created by Daniel Rebelo on 30/12/2022.
//

#include "Manager.h"
using namespace std;



Manager::Manager() {}

void Manager::init() {
    std::ifstream airportsFile , airlinesFile , flightsFile;

    airportsFile.open("Code/dataset/airports.csv");
    airlinesFile.open("Code/dataset/airlines.csv");
    flightsFile.open("Code/dataset/flights.csv");
    FileReader fileReader;

    airports = fileReader.readAirportsFile(airportsFile);
    airlines = fileReader.readAirlinesFile(airlinesFile);
    int numAirports = (int) airports.size();
    graph = Graph(numAirports, true);
    int index = 0;

    for(pair<std::string,Airport> p : airports){
        graph.addNode(p.second);
        graph.codeToPos[p.second.getCode()] = index;
        graph.posToCode[index] = p.second.getCode();
        index++;
    }
    fileReader.readFlightFile(flightsFile, graph);


}

airportMap Manager::getAirports(){
    return airports;
}
airlineMap Manager::getAirlines(){
    return airlines;
}
Graph Manager::getGraph(){
    return graph;
}

std::string Manager::get_airport_by_country(std::string country){
    if (!checkCountryExists(country)){cout << endl << "No airports in such country" << endl;
        return "";}
    airportMap airportsCountry = airports_filter_by_country(country);
    bool airportSelected = false;
    int i = 1;
    map <int,string> m;
    cout << endl << "Airports in " << airportsCountry.begin()->second.getLocation().getCountry() << endl;
    int input;
    while(!airportSelected) {
        int j = 1;
        cout << endl;
        for (auto itr = airportsCountry.begin(); itr != airportsCountry.end();) {
            cout << i << ". " << itr->second.getCode() << " - " << itr->second.getName() << " in "
                 << itr->second.getLocation().getCity() << endl;
            m.insert({i, itr->second.getCode()});
            itr = airportsCountry.erase(itr);
            i++;j++;
            if(j == 11)break;
        }
        while (true) {
            if (!airportsCountry.empty()) {
                cout << endl << "Return to main menu -> 0 || Next page -> -1 || Choose an airport -> 1-10  " << endl;
                cout << "Choose an airport or 0 to return to previous menu): ";
                try {
                    cin >> input;
                    if ((input >= 0 && input <= m.size()) || (input == -1)) break;
                }
                catch (exception e) { cout << "Invalid input" << endl; }
            }

            else if(airportsCountry.empty()){
                cout << "Choose an airport or 0 to return to previous menu): ";
                try {
                    cin >> input;
                    if (input >= 0 && input <= m.size()) break;
                }
                catch (exception e) { cout << "Invalid input" << endl; }
            }
        }

        switch (input) {
            case 0:
                return "";

            case -1:{
                break;
            }

            default:
                cout << endl << "Airport found!\n" << getAirports().at(m.at(input)).getCode() << " - "
                     << getAirports().at(m.at(input)).getName() << endl;
                airportSelected = true;
        }
    }
    return getAirports().at(m.at(input)).getCode();
}

airportMap Manager::airports_filter_by_country(std::string country){
    airportMap airportsCountry;
    auto it = airports.begin();
    bool noMoreFound = true;
    while (noMoreFound){
        it = find_if(it,airports.end(),[&country, this]
                (auto p) {return tolowerString(p.second.getLocation().getCountry()) == tolowerString(country);});
        if (it != airports.end()){
            airportsCountry.insert(*it);
            it++;
        }
        else{
            noMoreFound = false;
        }
    }
    return airportsCountry;
}


airportMap Manager::airports_filter_by_city(std::string city){
    airportMap airportsCity;
    auto it = airports.begin();
    bool noMoreFound = true;
    while (noMoreFound){
        it = find_if(it,airports.end(),[&city,this]
        (auto p) {return tolowerString(p.second.getLocation().getCity()) == tolowerString(city);});
        if (it != airports.end()){
            airportsCity.insert(*it);
            it++;
        }
        else{
            noMoreFound = false;
        }
    }
    return airportsCity;
}


airlineMap Manager::airlines_filter_by_airport(std::string airportCode){
    airlineMap am;
    if (checkAirportExists(airportCode)){
    set<string> s = graph.getAirlinesAirport(airportCode);
    for (string str : s){
        am.insert({str,airlines.at(str)});
    }
    }
    return am;
}


int Manager::getDepartures(std::string airportCode){
    return graph.getDeparturesAirport(airportCode);
}

int Manager::getArrivals(std::string airportCode){
    return graph.getArrivalsAirport(airportCode);
}

int Manager::getNumberFlights(std::string airportCode){
    return getDepartures(airportCode) + getArrivals(airportCode);
}

int Manager::getNumberAirlinesAirport(std::string airportCode){
    return graph.calculateAirlinesAirport(airportCode);
}

int Manager::getNumberDestinations(std::string airportCode){
    return graph.getNrDestinations(airportCode);
}

int Manager::getNumberDestinationsCountries(std::string airportCode){
    return graph.getNrDestinationsCountries(airportCode);
}

void Manager::calculateGlobalStatsNetwork(){
    int nrAirports = airports.size() , nrFlights = graph.getNrTotalFlights() , nrAirlines = airlines.size();
    cout << "This network consists of " << nrAirports << " airports , " << nrAirlines << " airlines and " << nrFlights  << " flights." << endl;
    int inp = -1;
    while (inp != 0){cout << endl << endl << "Press 0 to continue: "; cin >> inp; }
    return;
}



bool Manager::checkAirportExists(std::string airportCode) {
    auto it = std::find_if(airports.begin(), airports.end(),[&airportCode, this](pair<string,Airport> ap){return tolowerString(ap.second.getCode()) == tolowerString(airportCode);});
    if (it == airports.end()){ cout << "No such airport in database." << endl; return false;}
    return true;
}

bool Manager::checkAirlineExists(std::string airlineCode) {
    try {
        airlines.at(airlineCode);
    }
    catch (exception e) {
        cout << "No airline with such code.Please try again" << endl;
        return false;
    }
    return true;
}

bool Manager::checkCountryExists(std::string country) {
    auto it = std::find_if(airports.begin(), airports.end(),[&country, this](pair<string,Airport> ap){return tolowerString(ap.second.getLocation().getCountry()) == tolowerString(country);});
    if (it == airports.end()){ cout << "No such country in database." << endl; return false;}
    return true;
}

string Manager::tolowerString(string s){
    string newstr;
    for (auto c : s){
        newstr.push_back(tolower(c));
    }
    return newstr;
}

string Manager::toupperString(string s){
    string newstr;
    for (auto c : s){
        newstr.push_back(::toupper(c));
    }
    return newstr;
}

bool Manager::checkCityExists(std::string city) {
    tolowerString(city);
    auto it = std::find_if(airports.begin(), airports.end(),[&city, this](pair<string,Airport> ap){
        return tolowerString(ap.second.getLocation().getCity()) == tolowerString(city);
    });
    if (it == airports.end()){ cout << "No such city in database." << endl; return false;}
    return true;
}


void Manager::airportReport(std::string airportCode) {
    if (checkAirportExists(airportCode)){
        Airport airport = airports.at(airportCode);
        cout << endl << "The " << airport.getName() << " airport is an international airport in " << airport.getLocation().getCity() << "," << airport.getLocation().getCountry() << "." << endl;
        cout << "This airport has " << getNumberFlights(airportCode) << " flights , " << getDepartures(airportCode) <<" of these are departures and " <<
        getArrivals(airportCode) << " are arrivals, to " << getNumberDestinations(airportCode)
        << " cities in " << getNumberDestinationsCountries(airportCode) << " countries." << endl;
        cout << "On top of that, there exists " << getNumberAirlinesAirport(airportCode) << " airlines operating in it." << endl << endl;
        cout << "Do you wish to list all airlines operating on this airport?(Y/n): ";
        string input;
        cin >> input;
        while (tolowerString(input) != "n" && tolowerString(input) != "y") {
            cout << "Enter a valid response: Y for yes or N for no (not case sensitive):  " << endl;
            cin >> input;
        }
        if (tolowerString(input) == "n") return;
        cout << "These are: " << endl;
        airlineMap am = airlines_filter_by_airport(airportCode);
        int x = 0;
        cout << setw(30) << "Airline" << setw(30) << "Country" << endl;
        for (auto p : am){
            cout << ++x << ". " << setw(30) << p.second.getName() << setw(30) << p.second.getLocation().getCountry() << endl;
        }
        int inp = -1;
        while (inp != 0){cout << endl << endl << "Press 0 to continue: "; cin >> inp; }
        return;

    }
}



void Manager::countryReport(string &country){
    if (checkCountryExists(country)){
        airportMap am = airports_filter_by_country(country);
        cout << "The beautiful country of " << am.begin()->second.getLocation().getCountry() << " has " << am.size() << " airports." << endl;
        cout << "These are:" << endl;
        int departures = 0 , arrivals = 0 , airlines = 0;
        map<int,string> m;
        int x = 1;
        for (auto p : am){
            cout << x++ << ". " << p.second.getName() << " in " << p.second.getLocation().getCity() << endl;
            // m.insert({x,p.second.getCode()});
            departures += getDepartures(p.second.getCode());
            arrivals += getArrivals(p.second.getCode());
        }
        cout << "In all of these combined, there are " << departures + arrivals << " flights, " << departures << " of these are departures and " << arrivals << " are arrivals." << endl;
        cout << endl << "Enter 0 to leave: ";
        int input;
        cin >> input;
        while (input != 0) {
            cout << endl << "Enter 0 to leave: ";
            cin >> input;
        }
        return;
    }
}


void Manager::printPath(vector<Node> path) {
    if (path.empty()) cout << "Unable to find a route between your origin and the destination desired!" << endl;
    for(Node &node : path){
        cout << node.airport.getCode() << " " << node.airport.getName() << "\n";
        if(node.airlineUsed != "")
           cout << "Using airline: " << node.airlineUsed << "(" << airlines.at(node.airlineUsed).getName()
                << ")" << ", you go to" << "\n";
    }
}

int Manager::getConnectedComponents() {
    return graph.dfs_cc();
}

int Manager::getArticulationPoints() {
    return (int)graph.getArticulationPoints().size();
}

void Manager::printAirports(int k,int opt){
    vector<pair<string,int>> v;
    switch(opt){
        case 1:
        {
            for (pair<string,Airport> pa : airports){
                v.push_back(make_pair(pa.second.getCode(), getNumberFlights(pa.second.getCode())));
            }
            sort(v.begin(),v.end(),[] ( pair<string,int> &p1 , pair<string,int> &p2) {return p1.second > p2.second;});
            v.resize(k);
            int i = 1;
            cout << endl << "TOP "<< k << " AIRPORTS WITH MOST FLIGHTS\n" << endl;
            cout << left << setw(40) << "    Airport" << setw(23) << setfill(' ') << "Number of Flights" << setw(20) << "City" << setw(20) << "Country" << endl;
            for (auto elem : v){
                Airport a = airports.at(elem.first);
                cout << i++ << ". " << left << setw(40) << a.getName() << setw(20) << setfill(' ') << elem.second << setw(20) << a.getLocation().getCity() << setw(20) << a.getLocation().getCountry() << endl;
            }
            int inp = -1;
            while (inp != 0){cout << endl << "Press 0 to leave: "; cin >> inp; }
            break;
        }
        case 2:
        {
            for (pair<string,Airport> pa : airports){
                v.push_back(make_pair(pa.second.getCode(), getNumberAirlinesAirport(pa.second.getCode())));
            }
            sort(v.begin(),v.end(),[] ( pair<string,int> &p1 , pair<string,int> &p2) {return p1.second > p2.second;});
            v.resize(k);
            int i = 1;
            cout << endl << "TOP "<< k << " AIRPORTS WITH MOST AIRLINES\n" << endl;
            cout << left << setw(25) << "    Airport" << setw(23) << setfill(' ') << "Number of Airlines" << setw(20) << "City" << setw(20) << "Country" << endl;
            for (auto elem : v){
                Airport a = airports.at(elem.first);
                cout << i++ << ". " << left << setw(25) << a.getName() << setw(20) << setfill(' ') << elem.second << setw(20) << a.getLocation().getCity() << setw(20) << a.getLocation().getCountry() << endl;
            }
            int inp = -1;
            while (inp != 0){cout << endl << "Press 0 to leave: "; cin >> inp; }
            return;
        }
    }
}

void Manager::printArticulationPoints(){
    cout << endl << "Articulation points (also known as cut vertices) are an important concept in graph theory and can be used to analyze a variety of different types of networks, including flight networks.\n"
                    "\n"
                    "In a flight network, articulation points can help to identify the key airports that play a central role in connecting different parts of the network. For example, consider a flight network that consists of a series of airports connected by flights. Some airports may be connected to multiple other airports, while others may only be connected to a few. In this network there are " << getArticulationPoints() << " articulation points\n"
                    "\n"
                    "An airport that is an articulation point in the flight network is one that, if removed, would cause the network to become disconnected. In other words, it is an airport that plays a crucial role in connecting different groups of airports.\n"
                    "\n"
                    "Articulation points are important in a flight network because they can help to identify the airports that are most critical to the connectivity of the network. This information can be useful for a variety of purposes, such as identifying potential bottlenecks or points of failure in the network. For example, if an airport that is an articulation point in the network were to be closed for some reason, it could have a significant impact on the ability of the network to function properly. Understanding the role of articulation points in a flight network can help to inform decisions about how to maintain and improve the network's connectivity.";
    int inp = -1;
    while (inp != 0){cout << endl << endl << "Press 0 to leave: "; cin >> inp; }
    return;
}

void Manager::printConnectedComponents(){
    cout << "Connected components are an important concept in graph theory and can be used to analyze a variety of different types of networks, including flight networks.\n"
            "\n"
            "In a flight network, connected components can help to identify the different routes that are possible between airports. For example, consider a flight network that consists of a series of airports connected by flights. Some airports may be connected to multiple other airports, while others may only be connected to a few.\n"
            "\n"
            "The connected components of the flight network can help to identify the different routes that are possible between airports. For example, if there is a connected component consisting of airports A, B, C, and D, it means that there is a series of flights connecting these airports and it is possible to fly from any of these airports to any of the others. On the other hand, if there is a separate connected component consisting of airports E and F, it means that it is not possible to fly directly between airports A, B, C, and D and airports E and F.\n"
            "\n"
            "Connected components are important in a flight network because they can help to identify the different groups of airports that are connected to one another and the routes that are possible between them. In this case, there are " << getConnectedComponents() << " connected components. This information can be useful for a variety of purposes, such as planning flights or analyzing the efficiency of a flight network." << endl;
    int inp = -1;
    while (inp != 0){cout << endl << endl << "Press 0 to leave: "; cin >> inp; }
}

void Manager::printDiameter() {
    cout << endl << "This may take a while to calculate, please dont press any key" << endl;
    cout << "The diameter of a graph is the length of the shortest path between the most distanced nodes" << endl;
    cout << "The diameter of the network is: " << graph.diameter() << endl;
    int inp = -1;
    while (inp != 0){cout << endl << "Press 0 to leave: "; cin >> inp; }
}

int Manager::maxFlightsStats(string src, int maxFlights, int opt) {
    vector<Node> helper = graph.bfsMD(graph.codeToPos[src], maxFlights);
    vector<string> locations;
    if(opt == 1){
        for(const Node node : helper){
            auto itr = find_if(locations.begin(), locations.end(), [&node](const string &s){return node.airport.getLocation().getCountry() == s;});
            if(itr == locations.end())
                locations.push_back(node.airport.getLocation().getCountry());
        }
    }
    if(opt == 2){
        for(const Node node : helper){
            auto itr = find_if(locations.begin(), locations.end(), [&node](const string &s){return node.airport.getLocation().getCity() == s;});
            if(itr == locations.end())
                locations.push_back(node.airport.getLocation().getCity());
        }
    }

    if(opt == 3)
        return helper.size();

    return locations.size();
}

bool Manager::checkSameAirport(string origin, string dest){
    return airports.at(toupperString(origin)).getCode() == airports.at(toupperString(dest)).getCode();
}