#ifndef UNTITLED1_ROBOT_H
#define UNTITLED1_ROBOT_H

#include <iostream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Enumerate all the possible directions on the 2D plane. For readability
enum direction_type {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};


class robot {
private:
    // Private variables, accessible only through the getters
    int position_north;
    int position_east;
    int distance_travelled;

public:
    // Construct robot; Set it's position to the center of the grid.
    robot();

    // Getter for robot's north position
    int north() const;

    // Getter for robot's east position
    int east() const;

    // Move the robot north on the grid
    void move_north();

    // Move the robot east on the grid
    void move_east();

    // Move the robot south on the grid
    void move_south();

    // Move the robot west on the grid
    void move_west();

    // Getter for the distance travelled by the robot
    int travelled() const;
};



#endif //UNTITLED1_ROBOT_H
