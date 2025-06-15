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

bool Grid::isInBounds(int x, int y)const {
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

Position Grid::getUnoccupiedPosition() const
{
    int x = 0, y = 0;
	int maxAttempts = GRID_SIZE * GRID_SIZE * 2; 
    for (int attempt = 0; attempt < maxAttempts; ++attempt) {
        x = rand() % GRID_SIZE;
        y = rand() % GRID_SIZE;
        if (cells[x][y] == nullptr) {
            return Position(x, y);
        }
    }
    // Fallback: search linearly if random failed
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (cells[i][j] == nullptr) {
                return Position(i, j);
            }
        }
    }

    // No unoccupied position found
    return Position(-1, -1);
}

Position Grid::getUnoccupiedPositionNear(int x, int y) const
{


    for (int d = 1; d < GRID_SIZE; ++d) {
        // Top and bottom rows of the ring
        for (int dx = -d; dx <= d; ++dx) {
            int nx_top = x + dx, ny_top = y - d;
            int nx_bot = x + dx, ny_bot = y + d;
            if (isInBounds(nx_top, ny_top) && cells[nx_top][ny_top] == nullptr)
                return Position(nx_top, ny_top);
            if (isInBounds(nx_bot, ny_bot) && cells[nx_bot][ny_bot] == nullptr)
                return Position(nx_bot, ny_bot);
        }
        // Left and right columns of the ring (excluding corners already checked)
        for (int dy = -d + 1; dy <= d - 1; ++dy) {
            int nx_left = x - d, ny_left = y + dy;
            int nx_right = x + d, ny_right = y + dy;
            if (isInBounds(nx_left, ny_left) && cells[nx_left][ny_left] == nullptr)
                return Position(nx_left, ny_left);
            if (isInBounds(nx_right, ny_right) && cells[nx_right][ny_right] == nullptr)
                return Position(nx_right, ny_right);
        }
    }
    return Position(-1, -1);
}




void Grid::updateAll() {
    //std::vector<Entity*> 
    //for (int i = 0; i < GRID_SIZE; ++i) {
    //    for (int j = 0; j < GRID_SIZE; ++j) {
    //        if (cells[i][j] && cells[i][j]->isDead()) {
    //            removeEntity(cells[i][j]);
    //        }
    //        if (cells[i][j]) cells[i][j]->upgrade();
    //    }
    //}

	std::vector<Entity*> entities = getEntities();
    for (Entity* e : entities) {
        if (e->isDead()) {
            removeEntity(e);
        } else {
            e->upgrade();
        }
	}

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