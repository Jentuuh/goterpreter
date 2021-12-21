#include "varspec.h"
#include <iostream>
#include <algorithm>

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

    std::vector<std::vector<std::string>> rightIdentifiers;
    if(expList != nullptr)
    {
        expList->getRefNames(rightIdentifiers);
    } else{
        return;
    }

    // Correct the order of the right identifiers
    std::reverse(rightIdentifiers.begin(), rightIdentifiers.end());

    int index = 0;
    for (auto i : leftIdentifiers)
    {
        for(auto j : rightIdentifiers[index])
        {
            if(j != "NO_OPERAND_EXPRESSION")
            {
                if(j == "FUNCTION_CALL")
                {
                    referenceGraph.push_back(std::make_pair(leftIdentifiers[index], "FUNC_CALL"));
                }
                else{
                    // Add an edge left_id --> right_id to the reference graph
                    referenceGraph.push_back(std::make_pair(leftIdentifiers[index], j));
                }
            }
            else{
                referenceGraph.push_back(std::make_pair(leftIdentifiers[index], "LITERAL_OP"));
            }

        }
      
        index++;
    }
}
