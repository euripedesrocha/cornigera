#include <catch.hpp>
#include <cstdint>
#include <memory>
#include <string>
#include <tbpp.hpp>

#include "Vregisters.h"

namespace {
enum class reg : uint8_t { zero, ra };

using register_tb = tbpp::clocked_tb<Vregisters, true>;

void write(register_tb& dut, reg reg_name, std::uint32_t data) {
  dut->write_en = true;
  dut->write_to = static_cast<uint8_t>(reg_name);
  dut->write_data = data;
  tbpp::run(dut);
}
auto read(register_tb& dut, reg reg_name) {
  dut->read_from = static_cast<uint8_t>(reg_name);
  tbpp::run(dut);
  return dut->read_data;
}

}  // namespace

TEST_CASE("Functional Verification of Registers", "[Reg]") {
  register_tb tb;
  SECTION("Write to R0 must not change it's value") {
    write(tb, reg::zero, 5);
    auto data = read(tb, reg::ra);
    REQUIRE(data == 0);
  }
  SECTION("Write to any register") {
    tb.trace_to("registers.vcd");
    write(tb, reg::ra, 5);
    auto data = read(tb, reg::ra);
    REQUIRE(data == 5);
  }
}
