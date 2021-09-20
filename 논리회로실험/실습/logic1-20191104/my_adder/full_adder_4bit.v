`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:25:17 11/04/2019 
// Design Name: 
// Module Name:    full_adder_4bit 
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
module full_adder_4bit(a,b,sum);
   input [3:0] a,b;
	
	output [3:0] sum;
	
	wire c0,c1,c2,c3,c4;
	assign c0=0;
	
	full_adder_1b U1(a[0],b[0],1'b0,c1,sum[0]);
	full_adder_1b U2(a[1],b[1],c1,c2,sum[1]);
	full_adder_1b U3(a[2],b[2],c2,c3,sum[2]);
	full_adder_1b U4(a[3],b[3],c3,c4,sum[3]);

endmodule
