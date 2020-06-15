#pragma once
template <typename T> class IteratorInterface {
public:

    virtual bool hasNext() const = 0;
    virtual T getNext() = 0;
};
