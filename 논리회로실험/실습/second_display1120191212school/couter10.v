`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:10:37 12/10/2019 
// Design Name: 
// Module Name:    couter10 
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
module couter10(clk,rst,cnt,in);
  input     		clk, rst;
  input [2:0] in;
  output	[3:0]	cnt;
  reg   	[3:0]	cnt;
  

	always @(posedge clk or posedge rst) begin
		   if (rst) cnt <= 0;
		   else begin
			   if (cnt == 9) cnt <= 0;
			   else	     cnt <= cnt + 1;
				if (in==2) cnt<=0;
		   end		
	end
 
endmodule
