`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:57:00 11/25/2019 
// Design Name: 
// Module Name:    bcd_counter_seg 
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
module bcd_counter_seg(clk,rst,seg_com,seg_data);
   input clk,rst;
	output [7:0] seg_com, seg_data;
	wire [3:0] cnt;
	
	bcd_count U0(clk,rst,cnt);
	bcd_seg U1 (cnt,seg_data);
	
	assign seg_com=8'b0111_1111;


endmodule
