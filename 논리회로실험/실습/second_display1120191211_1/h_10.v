`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:05:28 12/09/2019 
// Design Name: 
// Module Name:    h_10 
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
module h_10(clk_in,rst,clk_out,seg_data);
  input clk_in,rst;
  output clk_out;
  output [7:0] seg_data;

  wire	 [2:0]	cnt_digit_10;

  cnt_2 U_cnt_digit_10 (clk_in, rst, cnt_digit_10);
  bcd_to_seg_mod U_bcd_to_seg_mod_10 (cnt_digit_10,seg_data);

  freq_div_N #(6) U_freq_div_10 (.clk_in(clk_in), 
											 .rst(rst), 
											 .clk_div_N(clk_out));

endmodule



  
											 

