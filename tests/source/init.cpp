#include <catch.hpp>
#include <stack0.0.1.hpp>

TEST_CASE("pop") 
{
    stack<int> stack_;
    stack_.push(32);
    stack_.push(128);
    stack_.push(256);
    stack_.pop();
    REQUIRE(stack_.count() == 2);
}

TEST_CASE("push", "") {
    stack<int> v1;
    v1.push(51);
    v1.push(513);
    v1.push(256);
    v1.push(123);
    v1.push(9853);
    REQUIRE(v1.count() == 5);
}

TEST_CASE("top", "") {
    stack<int> v2;
    v2.push(17);
    v2.push(413);
    v2.push(769);
    v2.push(1230);
    v2.push(4567);
    v2.top();
    REQUIRE(v2.count() == 5);
}
