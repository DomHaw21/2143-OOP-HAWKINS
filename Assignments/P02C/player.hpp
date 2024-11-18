#pragma once
#include "logger.hpp"

#include <string>
#include "logger.hpp" // Assuming Logger is defined elsewhere in your code

class Player {
    std::string name;
    int score = 0; // Initialize score to zero

public:
    void setName(const std::string& n) { name = n; }
    void printName() { Logger::log("Name", name); }
    int getScore() const { return score; }
    void setScore(int s) { score = s; }
};

#endif // PLAYER_HPP
