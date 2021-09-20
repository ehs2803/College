`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:42:34 11/09/2019 
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
module full_adder(a,b,cin,cout,sum);
   input a,b,cin;
	output cout,sum;
	wire w1,w2,w3;
	
	half_adder U1(a,b,w2,w1);
	half_adder U2(w1,cin,w3,sum);
	or (cout,w2,w3);

endmodule
