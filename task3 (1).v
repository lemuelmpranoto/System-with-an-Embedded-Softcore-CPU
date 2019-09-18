module task3 ( input CLOCK_50, input [7:0] SW, input[3:0] KEY, output [7:0] LEDR);
    pixel_xform_system NiosII (.clk_clk(CLOCK_50), .resetn_reset_n(KEY[3]), .switches_export(SW), .leds_export(LEDR) );
endmodule
