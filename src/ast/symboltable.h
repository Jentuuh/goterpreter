#include <map>
#include <string>

struct SymbolTable{
    std::map<std::string, int> entries;

    void update(std::string i, int v)
    {
        entries[i] = v;
    }

    void update(std::string i, bool v)
    {
        entries[i] = v;
    }
};   