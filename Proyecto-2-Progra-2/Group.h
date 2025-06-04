#pragma once
#include<vector>
#include"Entity.h"
class Group{
private:
	std::vector<Entity*> members;

public:
    Group();
    void add(Entity* entity);
    void remove(Entity* entity);
    void update();

    ~Group();
};

