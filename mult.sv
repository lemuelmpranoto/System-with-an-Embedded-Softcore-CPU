module mult(input logic [31:0] dataa, input logic [31:0] datab, output logic [31:0] result);

    // output is multiplication of the two inputs
    assign result = dataa * datab;

endmodule: mult
