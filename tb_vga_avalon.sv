module tb_vga_avalon();

    logic clk, reset_n, read, write, VGA_HS, VGA_VS, VGA_CLK;
    logic [3:0] address;
    logic [31:0] readdata, writedata;
    logic [7:0] VGA_G, VGA_R, VGA_B;

    vga_avalon dut (.clk(clk), .reset_n(reset_n), .read(read), .write(write),
                    .VGA_HS(VGA_HS), .VGA_VS(VGA_VS), .VGA_CLK(VGA_CLK),
                    .address(address), .readdata(readdata), .writedata(writedata),
                    .VGA_G(VGA_G), .VGA_R(VGA_R), .VGA_B(VGA_B) );

    // creating clock cycles
    initial begin
        clk = 1'b0; #10;
        forever begin
        clk = 1'b1; #10;
        clk = 1'b0; #10;    
        end
    end

    // start testbench
    initial begin
        // test reset
        reset_n = 0; #40;
        reset_n = 1; #40;

        // set plot to high
        address = 0;
        write = 1;

        //drawing pixels
        writedata = 32'b0000000000000_111_00000001_0_0000001;
        #20;
        writedata = 32'b0000000000000_101_00000010_0_0000010;
        #20;
        writedata = 32'b0000000000000_110_00000001_0_0000011;

        // repeat clock cycles
        repeat(20) begin
            #1;
        end
        
        $stop;
    end

endmodule: tb_vga_avalon
