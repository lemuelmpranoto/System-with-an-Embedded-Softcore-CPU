module tb_mult();
  logic dataa;
  logic datab;
  logic result;

  mult dut(dataa, datab, result);

  initial begin
    clk = 1'b0; #5;
    forever begin
      clk = 1'b1; #5;  
      clk = 1'b0; #5;
    end
  end

  initial begin
    #10;
    // set the two numbers
    dataa = 32'd8;
    datab = 32'd9;
    #10;
    $stop;
  end
endmodule: tb_mult
