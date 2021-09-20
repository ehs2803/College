`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:10:45 11/18/2019 
// Design Name: 
// Module Name:    bcd_seg_dec 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module bcd_seg_dec(bcd_in,seg_data,seg_com);
   input [3:0] bcd_in;
	output [7:0] seg_com;
	output [7:0] seg_data;
	
	function [7:0] bcd_to_seg;
	   input [3:0] bcd_in;
	begin
	   case(bcd_in)
		   4'h0 : bcd_to_seg = 8'b0011_1111;
			4'h1 : bcd_to_seg = 8'b0000_0110;
			4'h2 : bcd_to_seg = 8'b0101_1011;
			4'h3 : bcd_to_seg = 8'b0100_1111;
			4'h4 : bcd_to_seg = 8'b0110_0110;
			4'h5 : bcd_to_seg = 8'b0110_1101;
			4'h6 : bcd_to_seg = 8'b0111_1101;
			4'h7 : bcd_to_seg = 8'b0000_0111;
			4'h8 : bcd_to_seg = 8'b0111_1111;
			4'h9 : bcd_to_seg = 8'b0110_0111;
			default : bcd_to_seg = 8'b0000_0000;
		endcase
	end
	endfunction
	
	assign seg_data=bcd_to_seg(bcd_in);
	assign seg_com=8'b0111_1111;

endmodule
