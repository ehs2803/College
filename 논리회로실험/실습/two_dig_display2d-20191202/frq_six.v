`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:23:50 12/02/2019 
// Design Name: 
// Module Name:    frq_six 
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
module frq_six(clk3,rst,clk_6hz);
   input rst,clk3;
	output clk_6hz;
	reg [2:0] cnt;
	reg clk_6hz;
	
	always @(posedge clk3 or posedge rst)begin
	   if(rst)begin
		  cnt<=0;
		  clk_6hz<=0;
		end
		else begin
		  if(cnt==2)begin
		    cnt<=0;
			 clk_6hz<=~clk_6hz;
		  end
		  else cnt<=cnt+1;
		end
	
	end




endmodule
