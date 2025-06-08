#pragma once
#include"IReproductionStrategy.h"


class AsexualReproduction : public IReproductionStrategy{

public:
    void reproduce(Entity* creature) override;
};

