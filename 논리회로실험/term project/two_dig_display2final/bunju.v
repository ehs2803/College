`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:29:59 12/04/2019 
// Design Name: 
// Module Name:    bunju 
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
module bunju(clk,rst,clk_out);
   input clk,rst;
	output clk_out;
	reg [2:0] cnt;
	reg clk_out;
	
	always @(posedge clk or posedge rst)begin
	   if(rst) begin
		   cnt<=0;
			clk_out<=1;
		end
		else begin
		   if(cnt==4)begin
			   cnt<=0;
				clk_out<=~clk_out;
			end
			else cnt<=cnt+1;
		end
	end
endmodule
