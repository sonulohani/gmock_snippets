#pragma once

#include "interface_1.h"

void call_intf(Interface1* intf)
{
    intf->test_method_1("Test_1");
    intf->test_method_1("Test_2");
    intf->test_method_1("Test_3");
}
