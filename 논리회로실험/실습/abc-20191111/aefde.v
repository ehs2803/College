`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:17:50 11/11/2019 
// Design Name: 
// Module Name:    aefde 
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
module aefde(a,b,cin,sum,cout);
   parameter N=1;
	input [N-1:0] a,b;
	input cin;
	output [N-1:0] sum;
	output cout;
	reg [N-1:0] sum;
	reg [N-1:0] p;
	reg [N:0] carry;
	integer i;
	
	always @(a or b or cin)begin
	   carry[0]=cin;
		for(i=0; i<N; i=i+1)begin
		   p[i]=(a[i]^b[i]);
			sum[i]=(p[i]^carry[i]);
			case(p[i])
           0 : carry[i+1]=a[i];
			  default : carry[i+1]=carry[i]; 
         endcase	
      end			
	end
	assign cout = carry[N];


endmodule
