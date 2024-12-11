#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <random>

class Dice {
public:
    Dice() : engine(dev()), distribution(1, 6) {}

    int roll() {
        return distribution(engine);
    }

private:
    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> distribution;
};

class Grid {
public:
    Grid(int rows, int cols) : rows(rows), cols(cols) {
        grid.resize(rows, std::vector<int>(cols, 0));
    }

    bool place_value(int row, int col, int value) {
        if (row >= rows || col >= cols || grid[row][col] != 0) {
            return false;
        }
        grid[row][col] = value;
        return true;
    }

    void display() {
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int rows;
    int cols;
    std::vector<std::vector<int>> grid;
};

class Player {
public:
    Player(const std::string& name) : name(name), score(0) {}

    const std::string& get_name() const {
        return name;
    }

    int get_score() const {
        return score;
    }

    void add_score(int points) {
        score += points;
    }

private:
    std::string name;
    int score;
};

class Game {
public:
    Game() : dice(), grid(3, 3), current_player(nullptr) {}

    void initialize_players(const std::string& player1_name, const std::string& player2_name) {
        players[0] = Player(player1_name);
        players[1] = Player(player2_name);
        current_player = &players[0];
    }

    void start() {
        std::cout << "Game started!\n";
        bool game_over = false;

        while (!game_over) {
            take_turn();
            game_over = check_win();
            if (!game_over) {
                switch_turn();
            }
        }

        end_game();
    }

private:
    Dice dice;
    Grid grid;
    Player* current_player;
    Player players[2];

    void take_turn() {
        std::cout << current_player->get_name() << "'s turn.\n";
        int dice_roll = dice.roll();
        std::cout << "Rolled a " << dice_roll << ".\n";

        int row, col;
        do {
            std::cout << "Enter row and column to place the dice roll: ";
            std::cin >> row >> col;
        } while (!grid.place_value(row, col, dice_roll));

        grid.display();
    }

    bool check_win() {
        // Simple placeholder logic: if the grid is full, the game ends.
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (grid[row][col] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    void switch_turn() {
        current_player = (current_player == &players[0]) ? &players[1] : &players[0];
    }

    void end_game() {
        std::cout << "Game over!\n";
        // Add logic to determine and display winner.
    }
};

int main() {
    Game game;
    std::string player1, player2;

    std::cout << "Enter name for Player 1: ";
    std::cin >> player1;
    std::cout << "Enter name for Player 2: ";
    std::cin >> player2;

    game.initialize_players(player1, player2);
    game.start();

    return 0;
}
