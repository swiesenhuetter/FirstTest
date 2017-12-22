#ifndef OPTVAL_H
#define OPTVAL_H

#include <memory>

template<typename T>
struct OptVal {
    std::unique_ptr<T> opt;

    OptVal(const T& val) :opt(std::make_unique<T>(val)){}

    OptVal(const OptVal& orig)
            :opt (static_cast<bool>(orig.opt) ? std::make_unique<T>(*orig.opt) : nullptr)
    {}

    OptVal()
            :opt(nullptr)
    {}

    OptVal& operator=(const OptVal& orig){
        opt = static_cast<bool>(orig.opt) ? std::make_unique<T>(*orig.opt) : nullptr;
        return *this;
    }

    OptVal(OptVal&&) = default;
    OptVal& operator=(OptVal&&) = default;

    bool operator==(const OptVal& other) const {
        const auto valid = static_cast<bool>(opt);
        const auto otherValid = static_cast<bool>(other.opt);
        if(valid && otherValid)
            return *opt == *other.opt;
        if (! valid && ! otherValid)
            return true;
        else
            return false;
    }
};

#endif //OPTVAL_H
