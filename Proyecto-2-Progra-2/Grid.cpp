#include "Grid.h"
#include <iostream>

Grid::Grid() {
    for (int i = 0; i < GRID_SIZE; ++i)
        for (int j = 0; j < GRID_SIZE; ++j)
            cells[i][j] = nullptr;
}

void Grid::placeEntity(Entity* e) {
    Position p = e->getPosition();
    if (isInBounds(p.x, p.y) && cells[p.x][p.y] == nullptr)
        cells[p.x][p.y] = e;
}

void Grid::moveEntity(Entity* e, int newX, int newY) {
    Position p = e->getPosition();
    if (!isInBounds(newX, newY) || cells[newX][newY] != nullptr) return;
    cells[p.x][p.y] = nullptr;
    e->setPosition(newX, newY);
    cells[newX][newY] = e;
}

bool Grid::isInBounds(int x, int y) {
    return x >= 0 && y >= 0 && x < GRID_SIZE && y < GRID_SIZE;
}

std::vector<Entity*> Grid::getEntities() const
{
    std::vector<Entity*> entities;
    for (int i = 0; i < GRID_SIZE; ++i)
        for (int j = 0; j < GRID_SIZE; ++j)
            if (cells[i][j])
                entities.push_back(cells[i][j]);
    return entities;
}

Entity* Grid::getEntityAt(int x, int y) const
{
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE)
        return nullptr;
    return cells[x][y];
}

void Grid::removeEntity(Entity* e)
{
    Position p = e->getPosition();
    if (isInBounds(p.x, p.y) && cells[p.x][p.y] == e) {
        cells[p.x][p.y] = nullptr;
	}
}



void Grid::updateAll() {
    for (int i = 0; i < GRID_SIZE; ++i)
        for (int j = 0; j < GRID_SIZE; ++j)
            if (cells[i][j]) cells[i][j]->update();
}

void Grid::draw() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (cells[i][j]) std::cout << cells[i][j]->getSymbol();
            else std::cout << '-';
        }
        std::cout << '\n';
    }
}