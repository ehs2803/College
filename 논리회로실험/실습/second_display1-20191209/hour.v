`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:43:24 12/09/2019 
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
module hour(clk_inh1,rst,clko,seg_datah1,seg_datah2);
   input clk_inh1, rst;
	output clko;
	output [7:0] seg_datah1, seg_datah2;
   wire [3:0] cnt1, cnt2;
	reg [3:0] cnt1, cnt2;
	bcd_counter U_bcd_cnt (clk_inh1, rst, cnt1);
   bcd_to_seg_mod U_bcd_to_seg_mod (cnt1,seg_datah1);
   freq_div_N #(10) U_freq_div_10 (.clk_in(clk_inh1), 
											 .rst(rst), 
											 .clk_div_N(clk_out));	
											 
											 
  cnt_2 U_cnt_digit_10 (clk_out, rst, cnt2);
  bcd_to_seg_mod U_bcd_to_seg_mod_10 (cnt2,seg_datah2);
  freq_div_N #(6) U_freq_div_10h (.clk_in(clk_out), 
											 .rst(rst), 
											 .clk_div_N(clk_out1));
	always @(posedge clk_inh1) begin
	   if(cnt1==3&&cnt2==2) begin
		  cnt1<=0;
		  cnt2<=0;
		end
	end
endmodule
