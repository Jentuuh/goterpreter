#include "result.h"
#include <memory>

struct Signature{
    std::shared_ptr<ParameterList> parameters;
    std::shared_ptr<Result> result;

    Signature(ParameterList* params, Result* res):parameters{params}, result{res}{};
}