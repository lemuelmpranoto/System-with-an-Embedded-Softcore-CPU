module vga_avalon(input logic clk, input logic reset_n,
                  input logic [3:0] address,
                  input logic read, output logic [31:0] readdata,
                  input logic write, input logic [31:0] writedata,
                  output logic [7:0] VGA_R, output logic [7:0] VGA_G, output logic [7:0] VGA_B,
                  output logic VGA_HS, output logic VGA_VS, output logic VGA_CLK);

    // logics for the module
    logic [2:0] vga_colour;
    logic [7:0] vga_x;
    logic [6:0] vga_y;
    logic vga_plot;
    logic [9:0] vga_green, vga_blue, vga_red;

    // instantiating vga_adapter
    vga_adapter #(.RESOLUTION("160x120")) vga(.resetn(reset_n), .clock(clk), .colour(vga_colour),
                                                .x(vga_x), .y(vga_y), .plot(vga_plot), .VGA_R(vga_red),
                                                .VGA_G(vga_green), .VGA_B(vga_blue), .VGA_HS(VGA_HS), 
                                                .VGA_VS(VGA_VS), .VGA_CLK(VGA_CLK));

    // assign statements for lower bits of color
    assign VGA_B = vga_blue[7:0];
    assign VGA_G = vga_green[7:0];
    assign VGA_R = vga_red[7:0];

    // assign statements for addressing bits of writedata to corresponding ports
    assign vga_colour   = writedata[18:16];
    assign vga_x        = writedata[15:8];
    assign vga_y        = writedata[6:0];

    // always block to plot when time is appropriate
    always_comb begin : vga_pixel
        vga_plot = (vga_x < 8'd160 && vga_y < 7'd120 && address == 4'b0 && write)? 1'b1 : 1'b0;
    end

endmodule: vga_avalon