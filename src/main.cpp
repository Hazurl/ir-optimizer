#include <iostream>

#include <ws/test_header.hpp>
#include <module/module.h>

int main() {

    ws::receive(32, [&] (const std::string& buffer, int, bool) {
        ws::pipe(buffer);
    });

    return 0;
}