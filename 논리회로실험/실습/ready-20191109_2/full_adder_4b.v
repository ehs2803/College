`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:44:45 11/09/2019 
// Design Name: 
// Module Name:    full_adder_4b 
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
module full_adder_4b(a,b,sum,c7);
   input [3:0] a,b;
	output c7;
	output [3:0] sum;
	wire c1,c2,c3;
	
	full_adder fa1(a[0],b[0],1'b0,c1,sum[0]);
	full_adder fa2(a[1],b[1],c1,c2,sum[1]);
	full_adder fa3(a[2],b[2],c2,c3,sum[2]);
	full_adder fa4(a[3],b[3],c3,c7,sum[3]);
	
endmodule