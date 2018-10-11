#include <ws/opti/instruction/Operation.hpp>

namespace ws::opti {

bool has_accessibility(Argument const& arg, Operation::Accessibility access) {
    switch(access) {
        case Operation::Accessibility::Write:
            return std::holds_alternative<Identifier>(arg);
        case Operation::Accessibility::Read:
            return true;
        default:
            return false;
    }
}

}