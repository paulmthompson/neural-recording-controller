
#include <catch2/catch_all.hpp>

#include <evalBoard.h>

#include <memory>

using namespace Catch::literals;


TEST_CASE("Test evalBoard object construction", "[evalBoard]") {

    std::unique_ptr<EvalBoard> board = std::make_unique<EvalBoard>();

    REQUIRE(board);
}

TEST_CASE("Test evalBoard object construction and usb3 status", "[evalBoard]") {

    std::unique_ptr<EvalBoard> board = std::make_unique<EvalBoard>();
    bool usb_status = board->isUSB3();
    REQUIRE(!usb_status);
}