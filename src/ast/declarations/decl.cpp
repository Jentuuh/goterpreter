#include <iostream>
#include "decl.h"
#include "../../environment/interp/env.h"

// ============= VarDecl =============
VarDecl::VarDecl(VarSpec* varspec): varspec{varspec}{};

void VarDecl::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
        // TODO: implement
        std::vector<std::string> identifiers;
        std::cout << "Getting identifier strings..." << std::endl;
        varspec->idList->getIdentifierStrings(identifiers);

        std::vector<std::shared_ptr<Literal>> values;
        std::cout << "Evaluating var expression list..." << std::endl;
        varspec->expList->interp(env, funcEnv, values);

        std::cout << "Done evaluating vardecl expressions!" << std::endl;

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