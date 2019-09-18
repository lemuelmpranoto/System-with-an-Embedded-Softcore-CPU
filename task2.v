module task2 (CLOCK_50, SW, KEY, LEDR);
    input CLOCK_50;
    input [7:0] SW;
    input [0:0] KEY;
    output [7:0] LEDR;

    pixel_xform_system NiosII (
        .clk_clk(CLOCK_50), .resetn_reset_n(KEY),
        .switches_export(SW), .leds_export(LEDR) );
endmodule
