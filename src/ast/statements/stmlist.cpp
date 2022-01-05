#include "stmlist.h"
#include <iostream>

// ============= LastStmList =============
LastStmList::LastStmList(Stm* last):last{last}{};


void LastStmList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    last->interp(env, funcEnv);
}

void LastStmList::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    last->typecheck(env, funcEnv, typeErrors);
}

int LastStmList::amountPaths() 
{
    if(std::dynamic_pointer_cast<BlockStm>(last) != nullptr)
        return std::dynamic_pointer_cast<BlockStm>(last)->block->amountPaths();

    if(std::dynamic_pointer_cast<IfStm>(last) != nullptr)
        return std::dynamic_pointer_cast<IfStm>(last)->amountPaths();

    if(std::dynamic_pointer_cast<ForClauseStm>(last) != nullptr)
        return std::dynamic_pointer_cast<ForClauseStm>(last)->amountPaths();

    if(std::dynamic_pointer_cast<ForCondStm>(last) != nullptr)
        return std::dynamic_pointer_cast<ForCondStm>(last)->amountPaths();

    if(std::dynamic_pointer_cast<ForStm>(last) != nullptr)
        return std::dynamic_pointer_cast<ForStm>(last)->amountPaths();
    return 0;
}

int LastStmList::countReturnStatements()
{
    if(std::dynamic_pointer_cast<ReturnStm>(last) != nullptr)
            return 1;

    if(std::dynamic_pointer_cast<BlockStm>(last) != nullptr)
        return std::dynamic_pointer_cast<BlockStm>(last)->block->countReturnStatements();

    if(std::dynamic_pointer_cast<IfStm>(last) != nullptr)
        return std::dynamic_pointer_cast<IfStm>(last)->countReturnStatements();

    if(std::dynamic_pointer_cast<ForClauseStm>(last) != nullptr)
        return std::dynamic_pointer_cast<ForClauseStm>(last)->countReturnStatements();

    if(std::dynamic_pointer_cast<ForCondStm>(last) != nullptr)
        return std::dynamic_pointer_cast<ForCondStm>(last)->countReturnStatements();
    
    if(std::dynamic_pointer_cast<ForStm>(last) != nullptr)
        return std::dynamic_pointer_cast<ForStm>(last)->countReturnStatements();

    return 0;
}

bool LastStmList::hasBaseReturnStatement()
{
    if(std::dynamic_pointer_cast<ReturnStm>(last) != nullptr)
        return true;
    return false;
}

bool LastStmList::checkReturnPaths(bool isOkay) 
{
    if (std::dynamic_pointer_cast<IfStm>(last) != nullptr)
    {
       return isOkay || std::dynamic_pointer_cast<IfStm>(last)->checkReturnPaths(isOkay);
    } else if (std::dynamic_pointer_cast<ForStm>(last) != nullptr)
    {
        return isOkay || std::dynamic_pointer_cast<ForStm>(last)->checkReturnPaths(isOkay);
    } else if (std::dynamic_pointer_cast<ForClauseStm>(last) != nullptr)
    {
        return isOkay || std::dynamic_pointer_cast<ForClauseStm>(last)->checkReturnPaths(isOkay);
    } else if (std::dynamic_pointer_cast<ForCondStm>(last) != nullptr)
    {
        return isOkay || std::dynamic_pointer_cast<ForCondStm>(last)->checkReturnPaths(isOkay);
    }
    return isOkay || hasBaseReturnStatement();
}



// ============= PairStmList =============
PairStmList::PairStmList(Stm* head, StmList* tail): head{head}, tail{tail}{};


void PairStmList::interp(ScopedEnv& env, FunctionEnv& funcEnv)
{
    head->interp(env, funcEnv);
    tail->interp(env, funcEnv);
}

void PairStmList::typecheck(ScopedEnv& env, FunctionEnv& funcEnv, std::vector<std::string>& typeErrors)
{
    head->typecheck(env, funcEnv, typeErrors);
    tail->typecheck(env, funcEnv, typeErrors);
}

int PairStmList::amountPaths() 
{
    if(std::dynamic_pointer_cast<BlockStm>(head) != nullptr)
        return tail->amountPaths() + std::dynamic_pointer_cast<BlockStm>(head)->block->amountPaths();

    if(std::dynamic_pointer_cast<IfStm>(head) != nullptr)
        return tail->amountPaths() + std::dynamic_pointer_cast<IfStm>(head)->amountPaths();

    if(std::dynamic_pointer_cast<ForClauseStm>(head) != nullptr)
        return tail->amountPaths() + std::dynamic_pointer_cast<ForClauseStm>(head)->amountPaths();

    if(std::dynamic_pointer_cast<ForCondStm>(head) != nullptr)
        return tail->amountPaths() + std::dynamic_pointer_cast<ForCondStm>(head)->amountPaths();
    
    if(std::dynamic_pointer_cast<ForStm>(head) != nullptr)
        return tail->amountPaths() + std::dynamic_pointer_cast<ForStm>(head)->amountPaths();
    return 0 + tail->amountPaths();
}

int PairStmList::countReturnStatements()
{
    if(std::dynamic_pointer_cast<ReturnStm>(head) != nullptr)
            // Make sure we don't double count return statements in the same scope level
            if(!tail->hasBaseReturnStatement())
                return 1 + tail->countReturnStatements();

      if(std::dynamic_pointer_cast<BlockStm>(head) != nullptr)
        return tail->countReturnStatements() + std::dynamic_pointer_cast<BlockStm>(head)->block->countReturnStatements();

    if(std::dynamic_pointer_cast<IfStm>(head) != nullptr)
        return tail->countReturnStatements() + std::dynamic_pointer_cast<IfStm>(head)->countReturnStatements();

    if(std::dynamic_pointer_cast<ForClauseStm>(head) != nullptr)
        return tail->countReturnStatements() + std::dynamic_pointer_cast<ForClauseStm>(head)->countReturnStatements();

    if(std::dynamic_pointer_cast<ForCondStm>(head) != nullptr)
        return tail->countReturnStatements() + std::dynamic_pointer_cast<ForCondStm>(head)->countReturnStatements();
    
    if(std::dynamic_pointer_cast<ForStm>(head) != nullptr)
        return tail->countReturnStatements() + std::dynamic_pointer_cast<ForStm>(head)->countReturnStatements();

    return 0 + tail->countReturnStatements();
}

bool PairStmList::hasBaseReturnStatement()
{
    return std::dynamic_pointer_cast<ReturnStm>(head) != nullptr || tail->hasBaseReturnStatement();
}

bool PairStmList::checkReturnPaths(bool isOkay) 
{
    if(!isOkay)
    {
        isOkay = hasBaseReturnStatement();
    }

    if (std::dynamic_pointer_cast<IfStm>(head) != nullptr)
    {
        return std::dynamic_pointer_cast<IfStm>(head)->checkReturnPaths(isOkay) && tail->checkReturnPaths(isOkay);
    } else if (std::dynamic_pointer_cast<ForStm>(head) != nullptr)
    {
        return std::dynamic_pointer_cast<ForStm>(head)->checkReturnPaths(isOkay) && tail->checkReturnPaths(isOkay) ;
    } else if (std::dynamic_pointer_cast<ForClauseStm>(head) != nullptr)
    {
        return std::dynamic_pointer_cast<ForClauseStm>(head)->checkReturnPaths(isOkay) && tail->checkReturnPaths(isOkay);
    } else if (std::dynamic_pointer_cast<ForCondStm>(head) != nullptr)
    {
        return std::dynamic_pointer_cast<ForCondStm>(head)->checkReturnPaths(isOkay) && tail->checkReturnPaths(isOkay);
    }

    return tail->checkReturnPaths(isOkay);
}

