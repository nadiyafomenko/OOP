#pragma once
#include "PrintedProducts.h"

class StrategyInterface
{
public:
    virtual ~StrategyInterface() {}
    virtual double DoAlgorithm(const PrintedProducts& data) const = 0;
};

class Context
{

private:
    StrategyInterface* strategy_;
    PrintedProducts* obj;
public:
    Context(PrintedProducts* obj, StrategyInterface* strategy = nullptr) : strategy_(strategy)
    {
        this->obj = obj;
    }
    ~Context()
    {
        delete this->strategy_;
    }

    void set_strategy(StrategyInterface* strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }
    void DoSomeBusinessLogic() const
    {
        double result = this->strategy_->DoAlgorithm(*obj);
        std::cout << "Result:" << std::endl;
        std::cout << result << std::endl;
    }
};

class ConcreteStrategyA : public StrategyInterface
{
public:
    double DoAlgorithm(const PrintedProducts& data) const override
    {
        return data.GetPages();
    }
};
class ConcreteStrategyB : public StrategyInterface
{
public:
    double DoAlgorithm(const PrintedProducts& data) const override
    {
        return data.GetPages();
    }
};