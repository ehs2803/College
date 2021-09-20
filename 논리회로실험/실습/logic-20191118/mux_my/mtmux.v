`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:55:37 11/18/2019 
// Design Name: 
// Module Name:    mtmux 
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
module my_mux(a,b,c,d,sel,enable,out);
   input [3:0] a,b,c,d;
	input [1:0] sel;
	input enable;
	output [3:0] out;
	reg [3:0] out;
	
	always @(a,b,c,d,sel,enable)begin
	   
	   if(enable==1'b0)
		  case(sel)
		    2'b00 : out=a;
			 2'b01 : out=b;
			 2'b10 : out=c;
			 2'b11 : out=d;
		  endcase
		else
		  out=4'b0000;
		
	end
endmodule
