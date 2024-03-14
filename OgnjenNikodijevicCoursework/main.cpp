#include "robot.h"


using namespace std;

int distance(const robot& robot) {
    return abs(robot.north()) + abs(robot.east());
}

class game {
private:
    /*
     * Private variable, accessible only through the getters;
     * A map with the name-robot pairs;
     */
    map<string, robot> robots_map;

public:
    // Construct Game object
    game() {}

    // Getter for the robot map
    map<string, robot> get_robots_map() {
        return robots_map;
    }

    /*
     * Compute robot's distance from the center of the grid by the
     * Manhattan metric
     */


     // Return the number of robots present in the map
    int num_robots() const {
        return robots_map.size();
    }

    /*
     * Move the robot in the said direction. If such robots doesn't exist,
     * create one
     *
     * parameter: name - name of the robots_map
     * parameter: direction - direction in which the robot will be moved
     */
    void move(const string& name, direction_type direction) {
        // Check if robot with such name exists. If not, create one;
        if (robots_map.find(name) == robots_map.end()) {
            robots_map[name] = robot();
        }

        // Move the robot according to the passed direction
        switch (direction) {
        case NORTH:
            robots_map[name].move_north();
            break;
        case EAST:
            robots_map[name].move_east();
            break;
        case SOUTH:
            robots_map[name].move_south();
            break;
        case WEST:
            robots_map[name].move_west();
            break;
        }
    }

    // Helper function: find if the robot is within the steps limit
    bool is_robot_within(const string& name, int steps) {
        // Handle the situation if there's no robot with this name
        if (robots_map.find(name) == robots_map.end()) {
            return false;
        }

        return steps <= distance(robots_map[name]);
    }

    // Count all the robots within the steps limit
    int num_within(int steps) {
        int number_of_robots_within = 0;
        for (auto robot_row : robots_map) {
            if (is_robot_within(robot_row.first, steps)) {
                number_of_robots_within++;
            }
        }

        return number_of_robots_within;
    }

    // Find the maximum distance travelled by the robots
    int max_travelled() {
        int max_distance = -1;
        for (auto robot_row : robots_map) {
            int current_cursor = robots_map[robot_row.first].travelled();
            if (current_cursor > max_distance) {
                max_distance = current_cursor;
            }
        }

        return max_distance;
    }

    /*
     * Sort the robots according to their distance from the origin
     *
     * returns: vector containing robot names, sorted ascendingly by their
     * distance from the origin
     */
    vector<string> robots_by_distance() const {
        // Initialize the temporary vector and dump all the names from the map
        vector<string> temporary_vector;
        for (auto robot_row : robots_map) {
            temporary_vector.push_back(robot_row.first);
        }

        // Sort using simple bubble sort method
        for (int i = 0; i < temporary_vector.size() - 1; i++) {
            for (int j = 0; j < temporary_vector.size() - i - 1; j++) {
                if (temporary_vector[j] < temporary_vector[j + 1]) {
                    swap(temporary_vector[j], temporary_vector[j + 1]);
                }
            }
        }

        return temporary_vector;
    }
};


int main() {
    robot r;
    r.move_north();
    r.move_east();
    r.move_south();
    r.move_east();
    r.move_south();
    cout << "Position: " << r.north() << " N, " << r.east() << " E\n";
    cout << "Distance: " << distance(r) << '\n';
    cout << "Travelled: " << r.travelled() << '\n';

    game g;
    cout << "Count before: " << g.num_robots() << '\n';
    g.move("Robbie", NORTH); // east
    g.move("Marvin", NORTH); // south
    g.move("Robbie", NORTH); // west
    cout << "Count after: " << g.num_robots() << '\n';
    cout << "Furtherest travelled: " << g.max_travelled() << '\n';
    cout << "Within 0 steps: " << g.num_within(0) << '\n';
    cout << "Within 1 step: " << g.num_within(1) << '\n';
    for (const auto& name : g.robots_by_distance())
        cout << name << '\n';

    return 0;
}
