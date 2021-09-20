`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:04:13 12/11/2019
// Design Name:   second_two_digits
// Module Name:   D:/second_display1120191211_1test/testse.v
// Project Name:  sec_display
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: second_two_digits
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testse;

	// Inputs
	reg clk;
	reg rst;

	// Outputs
	wire clk_min_1;
	wire [7:0] seg_com;
	wire [7:0] seg_data;

	// Instantiate the Unit Under Test (UUT)
	second_two_digits uut (
		.clk(clk), 
		.rst(rst), 
		.clk_min_1(clk_min_1), 
		.seg_com(seg_com), 
		.seg_data(seg_data)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

