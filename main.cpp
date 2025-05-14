#include <iostream>

#include "my_project/test_class.h"
#include "quant_config/config.hpp"

int main() {
    quant_config::Config config(4, true, 6);
    Test_Class::Howdy();

    return 0;
}
