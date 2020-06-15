#pragma once
#include "StrategyInetrface.h"

class Context
{

private:
    StrategyInterface* strategy_;

public:
    Context(StrategyInterface* strategy = nullptr) : strategy_(strategy)
    {
    }
    ~Context()
    {
        delete this->strategy_;
    }
    void GetStrategy(StrategyInterface* strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }

    double CalculateConsumption(int width, int height, int amount, int period) const
    {
        double result = this->strategy_->DoAlgorithm(width, height, amount, period);
        return result;
    }
};

