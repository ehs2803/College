`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:05:04 11/04/2019 
// Design Name: 
// Module Name:    full_adder 
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
module full_adder_1b(a,b,cin,cout,sum);
   input a,b,cin;
	output sum,cout;
	wire w1,w2,w3;
	
	myhalf_adder U1 (a,b,w2,w1);
	myhalf_adder U2 (w1,cin,w3,sum);
	or U3 (cout,w2,w3);
	
endmodule
