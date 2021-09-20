`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:50:49 11/25/2019 
// Design Name: 
// Module Name:    bcd_count 
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
module bcd_count(clk,rst,cnt);
   input clk,rst;
	output [3:0] cnt;
	reg [3:0] cnt;
	
	always @(posedge clk or posedge rst)begin
	   if(rst) cnt<=0;
		else begin
		   if(cnt==9) cnt<=0;
			else cnt<=cnt+1;
		end
	
	end


endmodule
