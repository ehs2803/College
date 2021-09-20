`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:48:08 12/02/2019 
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
module bunju(mclk,rst,mclk_out,clk_1hz);
   input rst, mclk;
	output clk_1hz, mclk_out;
	reg [2:0] cnt;
	reg clk_1hz;
	
	assign mclk_out=mclk;
	
	always @(posedge mclk or posedge rst)begin
	   if(rst)begin
		    cnt<=0;
			 clk_1hz<=0;
		end
		else begin
		   if(cnt==4)begin
			   cnt<=0;
				clk_1hz<=~clk_1hz;
			end
			else cnt<=cnt+1;	
		end	   	
	end
endmodule