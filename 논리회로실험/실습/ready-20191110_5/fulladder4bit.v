`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:04:25 11/10/2019 
// Design Name: 
// Module Name:    fulladder4bit 
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
module fulladder4bit(a,b,cin,sum,cout);
   input [3:0] a,b;
	input cin;
	output [3:0] sum;
	output cout;
	
	full_adder D1(a[0],b[0],cin,sum[0],c1);
	full_adder D2(a[1],b[1],c1,sum[1],c2);
	full_adder D3(a[2],b[2],c2,sum[2],c3);
	full_adder D4(a[3],b[3],c3,sum[3],cout);


endmodule
