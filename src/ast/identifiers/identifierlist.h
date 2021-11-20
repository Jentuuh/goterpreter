#include <memory>
#include "../identifiers/identifier.h"

struct IdentifierList{
    virtual int length() = 0;
};

struct LastIdentifierList:IdentifierList{
    std::shared_ptr<Identifier> last;

    LastIdentifierList(Identifier* l): last{last}{};

};

struct PairIdentifierList:IdentifierList{
    std::shared_ptr<Identifier> head;
    std::shared_ptr<IdentifierList> tail;

    PairIdentifierList(Identifier* h, IdentifierList* t): head{h}, tail{t}{};
    
};