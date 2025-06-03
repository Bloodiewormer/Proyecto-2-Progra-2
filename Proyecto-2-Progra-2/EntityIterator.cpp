#include "EntityIterator.h"

EntityIterator::EntityIterator(const std::vector<Entity*>& list) : collection(list), current(0) {}

bool EntityIterator::hasNext() const
{	// Check if the current index is less than the size of the collection
	// to determine if there are more elements to iterate over.
	return current < collection.size();;
}

Entity* EntityIterator::next()
{
	// Return the next entity in the collection if available.
	if (!hasNext()) return nullptr;
	return collection[current++];
}
