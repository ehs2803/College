`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:44:28 11/25/2019 
// Design Name: 
// Module Name:    bitudcounter 
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
module bitudcounter(clk,rst,cnt,mode);
   input clk,rst,mode;
	output [7:0] cnt;
	reg [7:0] cnt;
	
	always @(posedge clk or posedge rst)begin
	    if(rst)
		   cnt<=0;
		 else begin
		    if(mode) 
			    cnt<=cnt-1;
			 else cnt<=cnt+1; 
		 end
	end

endmodule
