import cornigera_pkg::*;

module registers (
  input logic clk,
  input RegisterName write_to,
  input RegisterName read_from,
  input DataType write_data
  output DataType read_data
);

endmodule
