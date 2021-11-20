#include "../types/type.h"
#include <memory>


struct Result{
    
}

struct ParametersResult:Result{
    std::shared_ptr<ParameterList> parameters;

    ParametersResult(ParameterList* params): parameters{params}{};
};

struct TypeResult:Result{
    std::shared_ptr<Type> type;

    TypeResult(Type* type): type{type}{};

};