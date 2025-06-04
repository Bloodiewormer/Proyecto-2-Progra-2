#include "Group.h"

Group::Group()
{
}

void Group::add(Entity* entity)
{
	members.push_back(entity);
}

void Group::remove(Entity* entity)
{
    for (int i = 0; i < members.size(); ++i) {
        if (members[i] == entity) {
            members.erase(members.begin() + i);
            break;
        }
    }
}

void Group::update()
{
    for (int i = 0; i < members.size(); ++i) {
        members[i]->update();
    }
}

Group::~Group()
{
    for (int i = 0; i < members.size(); ++i) {
        delete members[i];
    }
}
