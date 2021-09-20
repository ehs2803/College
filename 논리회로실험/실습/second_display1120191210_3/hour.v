`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:24:32 12/10/2019 
// Design Name: 
// Module Name:    hour 
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
module hour(clk_in,rst,seg_data1,seg_data2);
   input clk_in, rst;
	output [7:0] seg_data1, seg_data2;
   wire [3:0] cnt1;
	wire [2:0] cnt2;
	wire [7:0] seg_data1, seg_data2;
	
	freq_div_N #(10) U_freq_div_10 (.clk_in(clk_in), 
											 .rst(rst), 
											 .clk_div_N(clk_out));
	counterc U11(clk_in,clk_out,rst,cnt1,cnt2);									 
	//couter10 U_cnt_digit_10 (clk_in, rst, cnt1,cnt2);
   bcd_to_seg_mod U_bcd_to_seg_mod_10 (cnt1,seg_data1);
	
	//cnt_2 U_cnt_digit (clk_out, rst, cnt2,cnt1);
   bcd_to_seg_mod U_bcd_to_seg_10 (cnt2,seg_data2); 
endmodule
