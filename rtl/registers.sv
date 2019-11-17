//import cornigera_pkg::*;

module registers (
  input logic clk,
  //input RegisterName write_to,
  //input RegisterName read_from,
  input logic write_data,
  output logic read_data
);

assign read_data = write_data;
endmodule
