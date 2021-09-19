#include "gmock/gmock.h"
#include "code_uses_interface_1.h"

class Interface1Mock : public Interface1
{
public:
    MOCK_METHOD(void, test_method_1, (const std::string&), (override));
};

TEST(TestExpectation, ExpectionSatisfied)
{
    Interface1Mock mock;
    EXPECT_CALL(mock, test_method_1(::testing::_)).Times(3);
    call_intf(&mock);
}
