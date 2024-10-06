//
// Created by Jaime on 30/12/2022.
//

#ifndef UNTITLED_COORDINATES_H
#define UNTITLED_COORDINATES_H


class Coordinates {
    private:
        double latitude;
        double longitude;
    public:
        /**
         * Default construcutor for the class Coordinates.
         * Complexity: O(1)
         */
        Coordinates();

        /**
         * Constructor for the call Coordinates.
         * Complexity: O(1)
         * @param latitude Latitude
         * @param longitude Longitude
         */
        Coordinates(double latitude, double longitude);

        /**
         * Getter for latitude.
         * Complexity: O(1)
         * @return Latitude
         */
        double getLatitude();

        /**
         * Getter for longitude.
         * Complexity: O(1)
         * @return Longitude
         */
        double getLongitude();

        /**
         * Setter for latitude.
         * Complexity: O(1)
         * @param latitude Latitude
         */
        void setLatitude(double latitude);

        /**
         * Setter for longitude.
         * Complexity: O(1)
         * @param longitude Longitude
         */
        void setLongitude(double longitude);


};


#endif //UNTITLED_COORDINATES_H
