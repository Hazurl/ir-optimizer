#pragma once

#include <unordered_map>
#include <vector>
#include <ws/opti/instruction/Argument.hpp>

namespace ws::opti {

struct Operation {
    enum class Accessibility {
        Write, Read
    };

    std::string name;
    std::vector<Accessibility> accessibilities;

};

bool has_accessibility(Argument const& arg, Operation::Accessibility access);

inline std::unordered_map<std::string, Operation> operations = {
#define ENTRY(name, ws...) { name, Operation { name, { ws } } },
    ENTRY("add", Operation::Accessibility::Write, Operation::Accessibility::Read, Operation::Accessibility::Read)
    ENTRY("sub", Operation::Accessibility::Write, Operation::Accessibility::Read, Operation::Accessibility::Read)
    ENTRY("mult", Operation::Accessibility::Write, Operation::Accessibility::Read, Operation::Accessibility::Read)
    ENTRY("div", Operation::Accessibility::Write, Operation::Accessibility::Read, Operation::Accessibility::Read)
    ENTRY("mov", Operation::Accessibility::Write, Operation::Accessibility::Read)
    ENTRY("neg", Operation::Accessibility::Write, Operation::Accessibility::Read)
    ENTRY("print", Operation::Accessibility::Read)
#undef ENTRY
};

}