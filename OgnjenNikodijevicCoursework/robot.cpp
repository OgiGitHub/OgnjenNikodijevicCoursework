#include "robot.h"

robot::robot() {
    position_north = 0;
    position_east = 0;
    distance_travelled = 0;
}

// Getter for robot's north position
int robot::north() const {
    return position_north;
}

// Getter for robot's east position
int robot::east() const {
    return position_east;
}

// Move the robot north on the grid
void robot::move_north() {
    position_north++;
    distance_travelled++;
}

// Move the robot east on the grid
void robot::move_east() {
    position_east++;
    distance_travelled++;
}

// Move the robot south on the grid
void robot::move_south() {
    position_north--;
    distance_travelled++;
}

// Move the robot west on the grid
void robot::move_west() {
    position_east--;
    distance_travelled++;
}

// Getter for the distance travelled by the robot
int robot::travelled() const {
    return distance_travelled;
}
