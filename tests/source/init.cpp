#include <catch.hpp>
#include <stack0.0.1.hpp>
TEST_CASE("push") 
{
    stack<int> stack_;
    stack_.push(32);
    stack_.push(64);
    REQUIRE(stack_.count() == 2);
}

TEST_CASE("pop") 
{
    stack<int> stack_;
    stack_.push(32);
    stack_.push(128);
    stack_.push(256);
    stack_.pop();
    REQUIRE(stack_.count() == 2);
}
