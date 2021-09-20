`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:58:01 12/09/2019 
// Design Name: 
// Module Name:    cnt_2 
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
module cnt_2(clk,rst,cnt,ctr1);
 input     		clk, rst, ctr1;
  output	[2:0]	cnt;
  reg   	[2:0]	cnt;

	always @(posedge clk or posedge rst or ctr1) begin
		if (rst) cnt <= 0;
		else begin
			if (cnt == 2||ctr1==1) cnt <= 0;
			else	     cnt <= cnt + 1;
		end
	end



endmodule
