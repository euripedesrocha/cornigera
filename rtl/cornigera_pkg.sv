package cornigera_pkg;
  parameter CORE_XLEN = `XLEN;
  //typedef enum logic [0:5]{zero, ra} RegisterName[> verilator public <];
  typedef logic [CORE_XLEN -1:0] DataType; 
endpackage
