module task4 (input CLOCK_50, input [7:0] SW, input [7:0] KEY, output [7:0] LEDR,
              output [7:0] VGA_B, output [7:0] VGA_G, output [7:0] VGA_R, 
              output VGA_HS, output VGA_CLK, output VGA_VS);
        
        pixel_xform_system u0 (
        .clk_clk         (CLOCK_50),         //      clk.clk
        .leds_export     (LEDR),     //     leds.export
        .resetn_reset_n  (KEY[3]),  //   resetn.reset_n
        .switches_export (SW), // switches.export
        .to_hex_vga_b    (VGA_B),    //   to_hex.vga_b
        .to_hex_vga_clk  (VGA_CLK),  //         .vga_clk
        .to_hex_vga_g    (VGA_G),    //         .vga_g
        .to_hex_vga_hs   (VGA_HS),   //         .vga_hs
        .to_hex_vga_r    (VGA_R),    //         .vga_r
        .to_hex_vga_vs   (VGA_VS)    //         .vga_vs
    );

endmodule
