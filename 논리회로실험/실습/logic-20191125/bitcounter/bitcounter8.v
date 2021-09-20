`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:32:04 11/25/2019 
// Design Name: 
// Module Name:    bitcounter8 
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
module bitcounter8(clk,rst,cnt);
   input clk,rst;
	output [7:0] cnt;
	reg [7:0] cnt;
	
	always @(posedge clk or posedge rst)begin
	   if(rst) cnt<=8'b0000_0000;
		else cnt<=cnt+1;
	
	end

endmodule
