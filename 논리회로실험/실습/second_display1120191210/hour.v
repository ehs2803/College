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
module hour(clk_in,rst,seg_data1,seg_data2,ctr1,ctr2);
   input clk, rst, ctr2, ctr1;
	output [7:0] seg_data1, seg_data2;
   
	wire [2:0] cnt1;
	wire [3:0] cnt2;
	
	cnt_2 U_cnt_digit_10 (clk_out, rst, cnt1);
  bcd_to_seg_mod U_bcd_to_seg_mod_10 (cnt1,seg_data2);
	
	freq_div_N #(6) U_freq_div_10 (.clk_in(clk_in), 
											 .rst(rst), 
											 .clk_div_N(clk_out));
	cnt_2 U_cnt_digit_10 (clk_in, rst, cnt2,ctr2);
  bcd_to_seg_mod U_bcd_to_seg_mod_10 (cnt2,seg_data1);
  
  always @(posedge clk_in) begin
     if(seg_data2==8'b)
	     if(seg_data1==8'b) begin
		    ctr2<=1;
		     ctr1<=1;
		  end     
  end
endmodule
