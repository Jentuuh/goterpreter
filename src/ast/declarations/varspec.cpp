#include "varspec.h"
#include <iostream>

// ============= VarSpec =============
VarSpec::VarSpec(IdentifierList* idList, Type* type, ExpList* expList): idList{idList}, type{type}, expList{expList}{}

void VarSpec::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    // TODO: implement
}


void VarSpec::getReferencePairs(std::vector<std::pair<std::string, std::string>>& referenceGraph)
{
    std::vector<std::string> leftIdentifiers;
    idList->getIdentifierStrings(leftIdentifiers);

    std::vector<std::string> rightIdentifiers;
    if(expList != nullptr)
    {
        expList->getOperandNames(rightIdentifiers);
    } else{
        return;
    }
    

    int index = 0;
    for (auto i : leftIdentifiers)
    {
        if(rightIdentifiers[index] != "NO_OPERAND_EXPRESSION")
        {
            if(rightIdentifiers[index] == "FUNCTION_CALL")
            {
                // TODO: implement
            }
            else{
                // Add an edge left_id --> right_id to the reference graph
                referenceGraph.push_back(std::make_pair(leftIdentifiers[index], rightIdentifiers[index]));
            }
        }
        index++;
    }
}
