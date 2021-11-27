#include <iostream>
#include "decl.h"
#include "../../environment/interp/env.h"

// ============= VarDecl =============
VarDecl::VarDecl(VarSpec* varspec): varspec{varspec}{};

void VarDecl::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
        // Get variable identifiers on the left
        std::vector<std::string> identifiers;
        varspec->idList->getIdentifierStrings(identifiers);

        // Get values from the expression list on the right
        std::vector<std::shared_ptr<Literal>> values;
        varspec->expList->interp(env, funcEnv, values);


        for (int i = 0; i < identifiers.size(); i++)
        {
                env.currentScope()->add(identifiers[i], varspec->type, values[i]);
        }
        // for (auto v : values)
        // {
        //       v->printValue();
        // }
        // for(auto s : identifiers)
        // {
        //         env.currentScope()->add(s, varspec->type, );
        //         std::cout << s << std::endl;
        // }
}

// ============= FunctionDecl =============
FunctionDecl::FunctionDecl(Identifier* funcName, Signature* sign, Block* body): funcName{funcName}, funcSign{sign}, funcBody{body}{}

void FunctionDecl::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
        // Add the function declaration to our function environment
        funcEnv.declaredFunctions.add(funcName->name, std::make_shared<FunctionDecl>(funcName.get(), funcSign.get(), funcBody.get()));
        return;
}