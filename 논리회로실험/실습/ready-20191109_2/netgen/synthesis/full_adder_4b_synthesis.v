////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: full_adder_4b_synthesis.v
// /___/   /\     Timestamp: Sat Nov 09 20:25:55 2019
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim full_adder_4b.ngc full_adder_4b_synthesis.v 
// Device	: xc3s1000-5-fg676
// Input file	: full_adder_4b.ngc
// Output file	: C:\LOGIC\ready-20191109_2\netgen\synthesis\full_adder_4b_synthesis.v
// # of Modules	: 1
// Design Name	: full_adder_4b
// Xilinx        : D:\xilinx\14.7\ISE_DS\ISE\
//             
// Purpose:    
//     This verilog netlist is a verification model and uses simulation 
//     primitives which may not represent the true implementation of the 
//     device, however the netlist is functionally correct and should not 
//     be modified. This file cannot be synthesized and should only be used 
//     with supported simulation tools.
//             
// Reference:  
//     Command Line Tools User Guide, Chapter 23 and Synthesis and Simulation Design Guide, Chapter 6
//             
////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns/1 ps

module full_adder_4b (
  c7, sum, a, b
);
  output c7;
  output [3 : 0] sum;
  input [3 : 0] a;
  input [3 : 0] b;
  wire a_0_IBUF_4;
  wire a_1_IBUF_5;
  wire a_2_IBUF_6;
  wire a_3_IBUF_7;
  wire b_0_IBUF_12;
  wire b_1_IBUF_13;
  wire b_2_IBUF_14;
  wire b_3_IBUF_15;
  wire c2;
  wire c3;
  wire c7_OBUF_19;
  wire sum_0_OBUF_24;
  wire sum_1_OBUF_25;
  wire sum_2_OBUF_26;
  wire sum_3_OBUF_27;
  LUT2 #(
    .INIT ( 4'h6 ))
  \fa1/U1/Mxor_sum_Result1  (
    .I0(b_0_IBUF_12),
    .I1(a_0_IBUF_4),
    .O(sum_0_OBUF_24)
  );
  LUT4 #(
    .INIT ( 16'h8778 ))
  \fa2/U2/Mxor_sum_Result1  (
    .I0(a_0_IBUF_4),
    .I1(b_0_IBUF_12),
    .I2(b_1_IBUF_13),
    .I3(a_1_IBUF_5),
    .O(sum_1_OBUF_25)
  );
  LUT3 #(
    .INIT ( 8'h96 ))
  \fa3/U2/Mxor_sum_Result1  (
    .I0(a_2_IBUF_6),
    .I1(b_2_IBUF_14),
    .I2(c2),
    .O(sum_2_OBUF_26)
  );
  LUT3 #(
    .INIT ( 8'hE8 ))
  \fa4/cout1  (
    .I0(b_3_IBUF_15),
    .I1(c3),
    .I2(a_3_IBUF_7),
    .O(c7_OBUF_19)
  );
  LUT3 #(
    .INIT ( 8'hE8 ))
  \fa3/cout1  (
    .I0(b_2_IBUF_14),
    .I1(c2),
    .I2(a_2_IBUF_6),
    .O(c3)
  );
  LUT3 #(
    .INIT ( 8'h96 ))
  \fa4/U2/Mxor_sum_Result1  (
    .I0(a_3_IBUF_7),
    .I1(b_3_IBUF_15),
    .I2(c3),
    .O(sum_3_OBUF_27)
  );
  LUT4 #(
    .INIT ( 16'hEA80 ))
  \fa2/cout1  (
    .I0(a_1_IBUF_5),
    .I1(a_0_IBUF_4),
    .I2(b_0_IBUF_12),
    .I3(b_1_IBUF_13),
    .O(c2)
  );
  IBUF   a_3_IBUF (
    .I(a[3]),
    .O(a_3_IBUF_7)
  );
  IBUF   a_2_IBUF (
    .I(a[2]),
    .O(a_2_IBUF_6)
  );
  IBUF   a_1_IBUF (
    .I(a[1]),
    .O(a_1_IBUF_5)
  );
  IBUF   a_0_IBUF (
    .I(a[0]),
    .O(a_0_IBUF_4)
  );
  IBUF   b_3_IBUF (
    .I(b[3]),
    .O(b_3_IBUF_15)
  );
  IBUF   b_2_IBUF (
    .I(b[2]),
    .O(b_2_IBUF_14)
  );
  IBUF   b_1_IBUF (
    .I(b[1]),
    .O(b_1_IBUF_13)
  );
  IBUF   b_0_IBUF (
    .I(b[0]),
    .O(b_0_IBUF_12)
  );
  OBUF   c7_OBUF (
    .I(c7_OBUF_19),
    .O(c7)
  );
  OBUF   sum_3_OBUF (
    .I(sum_3_OBUF_27),
    .O(sum[3])
  );
  OBUF   sum_2_OBUF (
    .I(sum_2_OBUF_26),
    .O(sum[2])
  );
  OBUF   sum_1_OBUF (
    .I(sum_1_OBUF_25),
    .O(sum[1])
  );
  OBUF   sum_0_OBUF (
    .I(sum_0_OBUF_24),
    .O(sum[0])
  );
endmodule


`ifndef GLBL
`define GLBL

`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;

    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule

`endif

