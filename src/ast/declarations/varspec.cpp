#include "varspec.h"
#include <iostream>
#include <algorithm>

// ============= VarSpec =============
VarSpec::VarSpec(IdentifierList* idList, Type* type, ExpList* expList): idList{idList}, type{type}, expList{expList}{}


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

    if(rightIdentifiers.size() == leftIdentifiers.size())
    {
        int index = 0;
        for (auto i : leftIdentifiers)
        {
            for(auto j : rightIdentifiers[index])
            {
                if(j != "NO_OPERAND_EXPRESSION")
                {
                    if(j == "FUNCTION_CALL")
                    {
                        referenceGraph.push_back(std::make_pair(i, "FUNC_CALL"));
                    }
                    else{
                        // Add an edge left_id --> right_id to the reference graph
                        referenceGraph.push_back(std::make_pair(i, j));
                    }
                }
                else{
                    referenceGraph.push_back(std::make_pair(i, "LITERAL_OP"));
                }

            }
        
            index++;
        }
    }
    else if(rightIdentifiers[0][0] == "FUNCTION_CALL") {
        for (auto i : leftIdentifiers)
        {
            referenceGraph.push_back(std::make_pair(i, "FUNC_CALL"));
        }
    }
    else {
        std::cout << "Error in building reference graph: size of left identifiers must be equal to size of right identifiers, or the right hand expression must be a single function call.";
    }

}
