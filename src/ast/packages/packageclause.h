#include "../identifiers/identifier.h"
#include <memory>

struct PackageClause{
    std::shared_ptr<Identifier> packageName;

    PackageClause(Identifier* pack_name): packageName{pack_name}{};
};