module tb_counter();
  reg clk, reset_n, read;
  reg [3:0] address;
  wire [31:0] readdata;

  counter dut (clk, reset_n, address, read, readdata);

  initial begin
    clk = 1'b0; #5;
    forever begin
      clk = 1'b1; #5;   
      clk = 1'b0; #5;
    end
  end

  initial begin
    // test reset
    reset_n = 1'b0; #15;
    reset_n = 1'b1; #15;

    // start counter
    read = 1'b1;
    address = 4'b0000; #15;
    address = 4'b0100; #15;

    // test else statement
    address = 4'b0001;
    read = 1'b0; #15;

    $stop;
  end

endmodule: tb_counter