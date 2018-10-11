#include <ws/opti/instruction/Instruction.hpp>

namespace ws::opti {

std::optional<Instruction> Instruction::make(Operation const& operation, std::vector<Argument> const& arguments) {
    if (operation.accessibilities.size() != arguments.size())
        return std::nullopt;

    auto arg_it = arguments.begin();
    for(auto a : operation.accessibilities) {
        auto const& argument = *(arg_it++); 
        if (!has_accessibility(argument, a))
            return std::nullopt;    
    }

    return Instruction { operation, arguments };
}

Instruction::Instruction(Operation const& operation, std::vector<Argument> const& arguments) 
    : operation(operation), arguments(arguments) {}


}