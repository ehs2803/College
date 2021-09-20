`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:24:19 11/04/2019 
// Design Name: 
// Module Name:    full_adder_1b 
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
module full_adder_1b(a,b,cin,sum1,cout1);
   input a,b,cin;
	output sum1,cout1;
	wire w1,w2,w3;
	
	myhalf_adder U1 (a,b,w1,w2);
	myhalf_adder U2 (w1,cin,sum1,w3);
	or U3 (cout1,w2,w3);
	
endmodule
