
module registers 
  import cornigera_pkg::*;
(
  input logic clk,
  input logic write_en,
  input [4:0] write_to,
  input [4:0] read_from,
  input DataType write_data,
  output DataType read_data
);
  
  DataType RegisterBank [0:31];

  always_ff@(posedge clk)
  begin
    if (write_en) begin
      RegisterBank[write_to] <= write_data;
    end
    read_data <= RegisterBank[read_from];
    if(read_from == 0) begin
      read_data <= 0; 
    end
  end 

endmodule
