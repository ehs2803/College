`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:03:38 12/02/2019 
// Design Name: 
// Module Name:    frq_div10 
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
module frq_div10(clk,rst,clk_1hz);
   input rst,clk;
	output clk_1hz;
	reg [2:0] cnt;
	reg clk_1hz;
	
	always @(posedge clk or posedge rst)begin
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
