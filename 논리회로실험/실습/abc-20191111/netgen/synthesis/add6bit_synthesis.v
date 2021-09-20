////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: add6bit_synthesis.v
// /___/   /\     Timestamp: Mon Nov 11 17:02:05 2019
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim add6bit.ngc add6bit_synthesis.v 
// Device	: xc3s1000-5-fg676
// Input file	: add6bit.ngc
// Output file	: D:\logic\abc\netgen\synthesis\add6bit_synthesis.v
// # of Modules	: 1
// Design Name	: add6bit
// Xilinx        : C:\Xilinx\14.7\ISE_DS\ISE\
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

module add6bit (
  cout, cin, sum, a, b
);
  output cout;
  input cin;
  output [5 : 0] sum;
  input [5 : 0] a;
  input [5 : 0] b;
  wire \U0/sum_1_mux0000 ;
  wire \U0/sum_2_mux0000 ;
  wire \U0/sum_3_mux0000 ;
  wire \U0/sum_4_mux0000 ;
  wire \U0/sum_5_mux0000 ;
  wire a_0_IBUF_11;
  wire a_1_IBUF_12;
  wire a_2_IBUF_13;
  wire a_3_IBUF_14;
  wire a_4_IBUF_15;
  wire a_5_IBUF_16;
  wire b_0_IBUF_23;
  wire b_1_IBUF_24;
  wire b_2_IBUF_25;
  wire b_3_IBUF_26;
  wire b_4_IBUF_27;
  wire b_5_IBUF_28;
  wire cin_IBUF_30;
  wire cout_OBUF_32;
  wire sum_0_OBUF_39;
  wire sum_1_OBUF_40;
  wire sum_2_OBUF_41;
  wire sum_3_OBUF_42;
  wire sum_4_OBUF_43;
  wire sum_5_OBUF_44;
  LUT3 #(
    .INIT ( 8'h96 ))
  \U0/Mxor_sum<0>_Result1  (
    .I0(a_0_IBUF_11),
    .I1(b_0_IBUF_23),
    .I2(cin_IBUF_30),
    .O(sum_0_OBUF_39)
  );
  LUT3 #(
    .INIT ( 8'h96 ))
  \U0/Mxor_sum<1>_Result1  (
    .I0(a_1_IBUF_12),
    .I1(b_1_IBUF_24),
    .I2(\U0/sum_1_mux0000 ),
    .O(sum_1_OBUF_40)
  );
  LUT3 #(
    .INIT ( 8'h96 ))
  \U0/Mxor_sum<2>_Result1  (
    .I0(a_2_IBUF_13),
    .I1(b_2_IBUF_25),
    .I2(\U0/sum_2_mux0000 ),
    .O(sum_2_OBUF_41)
  );
  LUT3 #(
    .INIT ( 8'h96 ))
  \U0/Mxor_sum<3>_Result1  (
    .I0(a_3_IBUF_14),
    .I1(b_3_IBUF_26),
    .I2(\U0/sum_3_mux0000 ),
    .O(sum_3_OBUF_42)
  );
  LUT3 #(
    .INIT ( 8'h96 ))
  \U0/Mxor_sum<4>_Result1  (
    .I0(a_4_IBUF_15),
    .I1(b_4_IBUF_27),
    .I2(\U0/sum_4_mux0000 ),
    .O(sum_4_OBUF_43)
  );
  LUT3 #(
    .INIT ( 8'hE8 ))
  \U0/sum_5_mux00001  (
    .I0(b_4_IBUF_27),
    .I1(\U0/sum_4_mux0000 ),
    .I2(a_4_IBUF_15),
    .O(\U0/sum_5_mux0000 )
  );
  LUT3 #(
    .INIT ( 8'hE8 ))
  \U0/sum_4_mux00001  (
    .I0(b_3_IBUF_26),
    .I1(\U0/sum_3_mux0000 ),
    .I2(a_3_IBUF_14),
    .O(\U0/sum_4_mux0000 )
  );
  LUT3 #(
    .INIT ( 8'hE8 ))
  \U0/sum_3_mux00001  (
    .I0(b_2_IBUF_25),
    .I1(\U0/sum_2_mux0000 ),
    .I2(a_2_IBUF_13),
    .O(\U0/sum_3_mux0000 )
  );
  LUT3 #(
    .INIT ( 8'hE8 ))
  \U0/sum_2_mux00001  (
    .I0(b_1_IBUF_24),
    .I1(\U0/sum_1_mux0000 ),
    .I2(a_1_IBUF_12),
    .O(\U0/sum_2_mux0000 )
  );
  LUT3 #(
    .INIT ( 8'hE8 ))
  \U0/sum_1_mux00001  (
    .I0(b_0_IBUF_23),
    .I1(cin_IBUF_30),
    .I2(a_0_IBUF_11),
    .O(\U0/sum_1_mux0000 )
  );
  LUT3 #(
    .INIT ( 8'hE8 ))
  \U0/carry_6_mux00001  (
    .I0(b_5_IBUF_28),
    .I1(\U0/sum_5_mux0000 ),
    .I2(a_5_IBUF_16),
    .O(cout_OBUF_32)
  );
  LUT3 #(
    .INIT ( 8'h96 ))
  \U0/Mxor_sum<5>_Result1  (
    .I0(a_5_IBUF_16),
    .I1(b_5_IBUF_28),
    .I2(\U0/sum_5_mux0000 ),
    .O(sum_5_OBUF_44)
  );
  IBUF   cin_IBUF (
    .I(cin),
    .O(cin_IBUF_30)
  );
  IBUF   a_5_IBUF (
    .I(a[5]),
    .O(a_5_IBUF_16)
  );
  IBUF   a_4_IBUF (
    .I(a[4]),
    .O(a_4_IBUF_15)
  );
  IBUF   a_3_IBUF (
    .I(a[3]),
    .O(a_3_IBUF_14)
  );
  IBUF   a_2_IBUF (
    .I(a[2]),
    .O(a_2_IBUF_13)
  );
  IBUF   a_1_IBUF (
    .I(a[1]),
    .O(a_1_IBUF_12)
  );
  IBUF   a_0_IBUF (
    .I(a[0]),
    .O(a_0_IBUF_11)
  );
  IBUF   b_5_IBUF (
    .I(b[5]),
    .O(b_5_IBUF_28)
  );
  IBUF   b_4_IBUF (
    .I(b[4]),
    .O(b_4_IBUF_27)
  );
  IBUF   b_3_IBUF (
    .I(b[3]),
    .O(b_3_IBUF_26)
  );
  IBUF   b_2_IBUF (
    .I(b[2]),
    .O(b_2_IBUF_25)
  );
  IBUF   b_1_IBUF (
    .I(b[1]),
    .O(b_1_IBUF_24)
  );
  IBUF   b_0_IBUF (
    .I(b[0]),
    .O(b_0_IBUF_23)
  );
  OBUF   cout_OBUF (
    .I(cout_OBUF_32),
    .O(cout)
  );
  OBUF   sum_5_OBUF (
    .I(sum_5_OBUF_44),
    .O(sum[5])
  );
  OBUF   sum_4_OBUF (
    .I(sum_4_OBUF_43),
    .O(sum[4])
  );
  OBUF   sum_3_OBUF (
    .I(sum_3_OBUF_42),
    .O(sum[3])
  );
  OBUF   sum_2_OBUF (
    .I(sum_2_OBUF_41),
    .O(sum[2])
  );
  OBUF   sum_1_OBUF (
    .I(sum_1_OBUF_40),
    .O(sum[1])
  );
  OBUF   sum_0_OBUF (
    .I(sum_0_OBUF_39),
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

