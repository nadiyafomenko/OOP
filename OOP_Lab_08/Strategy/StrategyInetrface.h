#pragma once
class StrategyInterface
{
public:
    virtual ~StrategyInterface() {}
    virtual double DoAlgorithm(int width, int height, int amount, int period) const = 0;
};
