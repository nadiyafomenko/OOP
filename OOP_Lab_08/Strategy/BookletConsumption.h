#pragma once
#include "StrategyInetrface.h"

class BookletConsumption : public StrategyInterface
{
public:
    double DoAlgorithm(int width, int height, int amount, int period) const override
    {
        return width * height * amount * period;
    }
};

