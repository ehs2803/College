`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:22:38 11/04/2019 
// Design Name: 
// Module Name:    myhalf_adder 
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
module myhalf_adder(a,b,cout,sum);
   input a,b;
	output cout,sum;
	
	and U0 (cout,a,b);
	xor U1 (sum,a,b);
	
endmodule
