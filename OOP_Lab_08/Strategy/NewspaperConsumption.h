#pragma once
#include "StrategyInetrface.h"

class NewspaperConsumption : public StrategyInterface
{
public:
    double DoAlgorithm(int width, int height, int amount, int period) const override
    {
        return width * height * amount;
    }
};

