#pragma once
struct Position {
    int x, y;
    Position(int x = 0, int y = 0);
    bool operator==(const Position& other) const;
    bool operator!=(const Position& other) const;
};
