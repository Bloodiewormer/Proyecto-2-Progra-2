#pragma once
class Position {
private:
    int x;
    int y;

public:
    Position(int x = 0, int y = 0);

    int getX() const;
    int getY() const;

    bool operator==(const Position& other) const;
};

