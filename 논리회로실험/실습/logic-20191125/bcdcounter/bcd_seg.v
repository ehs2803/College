`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:52:46 11/25/2019 
// Design Name: 
// Module Name:    bcd_seg 
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
module bcd_seg(bcd_in, seg_data);
   input [3:0] bcd_in;
	output [7:0] seg_data;
	
	reg [7:0] seg_data;
	
	always @(bcd_in)begin
	   case(bcd_in)
		  4'b0000 : seg_data=8'b0011_1111;
		  4'b0001 : seg_data=8'b0000_0110;
		  4'b0010 : seg_data=8'b0101_1011;
		  4'b0011 : seg_data=8'b0100_1111;
		  4'b0100 : seg_data=8'b0110_0110;
		  4'b0101 : seg_data=8'b0110_1101;
		  4'b0110 : seg_data=8'b0111_1101;
		  4'b0111 : seg_data=8'b0000_0111;
		  4'b1000 : seg_data=8'b0111_1111;
		  4'b1001 : seg_data=8'b0110_0111;
		  default : seg_data=8'b0000_0000;
		 endcase
	
	
	end


endmodule
