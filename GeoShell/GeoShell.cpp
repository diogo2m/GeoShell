#include "GeoShell.hpp"
#include <fstream>
#include <string>
#include <algorithm>
#include <exception>

//******************************************************************//
//**************************** FEATURES ****************************//
//******************************************************************//

std::array<double, 2> GeoShell::get_coordinates(std::string location)
{
    /*
        Description: Retrieves the coordinates of a location using GeoShell.

        Parameters:
        - location (std::string): The location for which to retrieve coordinates.

        Returns:
        - std::array<double, 2>: An array containing the latitude and longitude of the location.
    */

    // Getting file path created by GeoShell
    std::string file_name = location;
    std::replace(file_name.begin(), file_name.end(), ' ', '_');
    std::replace(file_name.begin(), file_name.end(), '/', '_');
    std::string path = "./GeoShell/.coordinates/" + file_name;

    // Trying to open previous requests
    std::ifstream file(path);

    // Checking if file doesn't exist
    if (!file.is_open())
    {
        // Preparing query
        std::string query = location;
        std::replace(query.begin(), query.end(), ' ', '+');

        // Setting and running command
        std::string command = "bash ./GeoShell/get_coordinates.sh \"" + query + "\"";
        std::system(command.c_str());

        // Opening output file
    }
    else
    {
        file.close();
    }

    // Opening output file
    file.open(path);

    // Declaring the coordinates array
    std::array<double, 2> coordinates;

    std::string tmp;

    // Getting coordinates
    for (int i=0; i<2; i++){
        file >> tmp;
        try{
            coordinates[i] = std::stod(tmp);
        }
        catch(...){
            return {0, 0};
        }
    }

    // Closing file
    file.close();

    // Returning coordinates
    return coordinates;
}
