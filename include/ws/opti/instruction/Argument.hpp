#pragma once

#include <string>
#include <variant>
#include <optional>

namespace ws::opti {

struct Identifier {
    std::string name;
};

struct Immediate {
    std::string value;
};

using Argument = std::variant<Identifier, Immediate>;

std::optional<Argument> string_to_argument(std::string const& str);
std::string argument_to_string(Argument const& arg);

}