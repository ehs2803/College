`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:12:56 11/04/2019 
// Design Name: 
// Module Name:    mynand 
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
module mynand(a,b,y);
  input [7:0] a,b;
  output [7:0] y;
  
  nand U [7:0](y,a,b);

endmodule
