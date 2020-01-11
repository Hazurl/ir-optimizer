#pragma once

#include <ws/opti/instruction/Argument.hpp>
#include <ws/opti/instruction/Operation.hpp>

namespace ws::opti {

class Instruction {
public:

    Operation operation;
    std::vector<Argument> arguments;

    static std::optional<Instruction> make(Operation const& operation, std::vector<Argument> const& arguments);

private:

    Instruction(Operation const& operation, std::vector<Argument> const& arguments);

};

}