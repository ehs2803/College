`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:39:44 12/10/2019 
// Design Name: 
// Module Name:    counterc 
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
module counterc(clk1,clk2,rst,cnt1,cnt2);
   input clk1, clk2, rst;
	output [3:0] cnt1;
	output [2:0] cnt2;
	reg [3:0] cnt1;
	reg [2:0] cnt2;
	
	always @(posedge clk1 or posedge rst) begin
		   if (rst) cnt1 <= 0;
		   else begin
			   if (cnt1 == 9) cnt1 <= 0;
			   else cnt1 <= cnt1 + 1;
				if(cnt2==2)
				  if(cnt1==3) cnt1<=0;       			  
		   end		
	end
	
	always @(posedge clk2 or posedge rst) begin
		if (rst) cnt2 <= 0;
		else begin
			if (cnt2 == 0) 
			   if(cnt1==6) cnt2<=cnt2+1;
			else if(cnt2==1)
			   if(cnt1==6) cnt2<=cnt2+1;
			else if(cnt2==2)
			   cnt2<=0; 
		end
	end
endmodule
