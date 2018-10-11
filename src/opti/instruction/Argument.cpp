#include <ws/opti/instruction/Argument.hpp>

#include <module/module.h>

#include <cctype>
#include <cassert>

namespace ws::opti {

std::optional<Argument> string_to_argument(std::string const& str) {
    if (str.empty())
        return std::nullopt;

    if (std::isdigit(str[0]))
        return Argument { Immediate { str } };
    if (std::isalpha(str[0]))
        return Argument { Identifier { str } };
    
    return std::nullopt;
}

std::string argument_to_string(Argument const& arg) {
    if (auto* imm = std::get_if<Immediate>(&arg))
        return imm->value;
    if (auto* ident = std::get_if<Identifier>(&arg))
        return ident->name;

    ws::module::errorln("Have you forget to implement 'argument_to_string' for all types ?");
    assert(false);
}


}