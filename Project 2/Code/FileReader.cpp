//
// Created by Jaime on 28/12/2022.
//

#include "FileReader.h"
using namespace std;

FileReader::FileReader() {}



airportMap FileReader::readAirportsFile(istream &airportFile){
    airportFile.ignore(numeric_limits<streamsize>::max(), '\n');
    airportMap airports;
    while(airportFile.good()){

        string line, data;
        vector<string> lineVector;
        getline(airportFile, line);

        if(line.empty() || line == "\r") break;
        stringstream ss(line);

        while(getline(ss, data, ',')) lineVector.push_back(data);

        string code = lineVector[0],
                name = lineVector[1],
                city = lineVector[2],
                country = lineVector[3];

        double latitude = stod(lineVector[4]),
                longitude = stod(lineVector[5]);

        Location location = Location(city, country);
        Coordinates coordinates = Coordinates(latitude, longitude);

        Airport airport = Airport(code, name, location, coordinates);
        airports.insert({code,airport});
    }

    return airports;
}


airlineMap FileReader::readAirlinesFile(istream &airlinesFile){
    airlinesFile.ignore(numeric_limits<streamsize>::max(), '\n');
    airlineMap airlines;
    while(airlinesFile.good()){

        string line, data;
        vector<string> lineVector;
        getline(airlinesFile, line);

        if(line.empty() || line == "\r") break;
        stringstream ss(line);

        while(getline(ss, data, ',')) lineVector.push_back(data);

        string code = lineVector[0],
                name = lineVector[1],
                callSign = lineVector[2],
                country = lineVector[3];

        Airline airline = Airline(code, name, callSign, Location(country));
        airlines.insert({code, airline});

    }

    return airlines;
}


void FileReader::readFlightFile(std::istream &flightFile, Graph &graph) {
    flightFile.ignore(numeric_limits<streamsize>::max(), '\n');

    while(flightFile.good()){
        string line, data;
        vector<string> lineVector;
        getline(flightFile, line);

        if(line.empty() || line == "\r") break;
        stringstream ss(line);

        while(getline(ss, data, ',')) lineVector.push_back(data);

        string sourceCode = lineVector[0], targetCode = lineVector[1], airlineCode = lineVector[2];

        int posSource = graph.codeToPos[sourceCode];
        int posDest = graph.codeToPos[targetCode];

        graph.addEdge(posSource, posDest, airlineCode);
    }


}



