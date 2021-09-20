`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:50:10 11/11/2019 
// Design Name: 
// Module Name:    add6bit 
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
module add6bit(a,b,sum,cin,cout);
  parameter N=6;
  input [N-1:0] a,b;
  input cin;
  output [N-1:0] sum;
  output cout;
  
  aefde #(N) U0(.a(a),.b(b),.cin(cin),.sum(sum),.cout(cout));


endmodule
