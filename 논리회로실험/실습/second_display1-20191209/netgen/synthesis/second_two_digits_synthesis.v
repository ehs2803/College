////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: second_two_digits_synthesis.v
// /___/   /\     Timestamp: Mon Dec 09 16:38:17 2019
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim second_two_digits.ngc second_two_digits_synthesis.v 
// Device	: xc3s1000-4-fg676
// Input file	: second_two_digits.ngc
// Output file	: D:\second_display1\netgen\synthesis\second_two_digits_synthesis.v
// # of Modules	: 1
// Design Name	: second_two_digits
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

module second_two_digits (
  clk, rst, clk_min_1, seg_data, seg_com
);
  input clk;
  input rst;
  output clk_min_1;
  output [7 : 0] seg_data;
  output [7 : 0] seg_com;
  wire Mmux_seg_data_mux0000_3_0;
  wire Mmux_seg_data_mux0000_31_1;
  wire Mmux_seg_data_mux0000_32_2;
  wire Mmux_seg_data_mux0000_33_3;
  wire Mmux_seg_data_mux0000_34_4;
  wire Mmux_seg_data_mux0000_35_5;
  wire Mmux_seg_data_mux0000_3_f5_6;
  wire Mmux_seg_data_mux0000_3_f5_rt_7;
  wire Mmux_seg_data_mux0000_4_8;
  wire Mmux_seg_data_mux0000_41_9;
  wire Mmux_seg_data_mux0000_42_10;
  wire Mmux_seg_data_mux0000_43_11;
  wire Mmux_seg_data_mux0000_44_12;
  wire Mmux_seg_data_mux0000_45_13;
  wire Mmux_seg_data_mux0000_4_f5_14;
  wire Mmux_seg_data_mux0000_5_15;
  wire Mmux_seg_data_mux0000_51_16;
  wire Mmux_seg_data_mux0000_6_17;
  wire N0;
  wire N1;
  wire N29;
  wire N30;
  wire N31;
  wire N32;
  wire N33;
  wire N34;
  wire N35;
  wire N36;
  wire N37;
  wire N38;
  wire N39;
  wire N40;
  wire N41;
  wire N42;
  wire N43;
  wire N44;
  wire N45;
  wire N46;
  wire \Result<0>1 ;
  wire \Result<0>2 ;
  wire \Result<0>3 ;
  wire \Result<0>4 ;
  wire \Result<0>5 ;
  wire \Result<0>6 ;
  wire \Result<0>7 ;
  wire \Result<0>8 ;
  wire \Result<1>1 ;
  wire \Result<1>2 ;
  wire \Result<1>3 ;
  wire \Result<1>4 ;
  wire \Result<1>5 ;
  wire \Result<1>6 ;
  wire \Result<1>7 ;
  wire \Result<1>8 ;
  wire \Result<2>1 ;
  wire \Result<2>2 ;
  wire \Result<2>3 ;
  wire \Result<2>4 ;
  wire \Result<2>5 ;
  wire \Result<2>6 ;
  wire \Result<2>7 ;
  wire \Result<2>8 ;
  wire \Result<3>1 ;
  wire \Result<3>2 ;
  wire \Result<3>3 ;
  wire \Result<3>4 ;
  wire \Result<3>5 ;
  wire \Result<4>1 ;
  wire \Result<4>2 ;
  wire \Result<4>3 ;
  wire \Result<4>4 ;
  wire \Result<4>5 ;
  wire \Result<5>1 ;
  wire \Result<5>2 ;
  wire \Result<5>3 ;
  wire \Result<5>4 ;
  wire \Result<5>5 ;
  wire \Result<6>1 ;
  wire \Result<6>2 ;
  wire \Result<6>3 ;
  wire \Result<6>4 ;
  wire \Result<6>5 ;
  wire \Result<7>1 ;
  wire \Result<7>2 ;
  wire \Result<7>3 ;
  wire \Result<7>4 ;
  wire \Result<7>5 ;
  wire \Result<8>1 ;
  wire \Result<8>2 ;
  wire \Result<8>3 ;
  wire \Result<8>4 ;
  wire \Result<8>5 ;
  wire \Result<9>1 ;
  wire \Result<9>2 ;
  wire \Result<9>3 ;
  wire \Result<9>4 ;
  wire \Result<9>5 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<1>_rt_109 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<2>_rt_111 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<3>_rt_113 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<4>_rt_115 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<5>_rt_117 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<6>_rt_119 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<7>_rt_121 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<8>_rt_123 ;
  wire \U_freq_div_1000/Mcount_cnt_eqn_0 ;
  wire \U_freq_div_1000/Mcount_cnt_eqn_1 ;
  wire \U_freq_div_1000/Mcount_cnt_eqn_2 ;
  wire \U_freq_div_1000/Mcount_cnt_eqn_3 ;
  wire \U_freq_div_1000/Mcount_cnt_eqn_4 ;
  wire \U_freq_div_1000/Mcount_cnt_eqn_5 ;
  wire \U_freq_div_1000/Mcount_cnt_eqn_6 ;
  wire \U_freq_div_1000/Mcount_cnt_eqn_7 ;
  wire \U_freq_div_1000/Mcount_cnt_eqn_8 ;
  wire \U_freq_div_1000/Mcount_cnt_eqn_9 ;
  wire \U_freq_div_1000/Mcount_cnt_xor<9>_rt_135 ;
  wire \U_freq_div_1000/clk_div_N_136 ;
  wire \U_freq_div_1000/clk_div_N_not0001 ;
  wire \U_freq_div_1000/cnt_cmp_eq0000 ;
  wire \U_freq_div_1000/cnt_cmp_eq000012_149 ;
  wire \U_freq_div_1000/cnt_cmp_eq000016_150 ;
  wire \U_freq_div_1000/cnt_cmp_eq00007_151 ;
  wire \U_h_1/U_bcd_cnt/Mcount_cnt ;
  wire \U_h_1/U_bcd_cnt/Mcount_cnt1 ;
  wire \U_h_1/U_bcd_cnt/Mcount_cnt2 ;
  wire \U_h_1/U_bcd_cnt/Mcount_cnt3 ;
  wire \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_163 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_165 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_167 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_169 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_171 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_173 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_175 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_177 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_eqn_0 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_eqn_1 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_eqn_2 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_eqn_3 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_eqn_4 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_eqn_5 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_eqn_6 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_eqn_7 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_eqn_8 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_eqn_9 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_189 ;
  wire \U_h_1/U_freq_div_10/clk_div_N_190 ;
  wire \U_h_1/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_h_1/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_h_1/U_freq_div_10/cnt_cmp_eq000011_203 ;
  wire \U_h_1/U_freq_div_10/cnt_cmp_eq000015_204 ;
  wire \U_h_1/U_freq_div_10/cnt_cmp_eq000036_205 ;
  wire \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data ;
  wire \U_h_10/U_cnt_digit_10/cnt_or0000 ;
  wire \U_min_1/U_bcd_cnt/Mcount_cnt ;
  wire \U_min_1/U_bcd_cnt/Mcount_cnt1 ;
  wire \U_min_1/U_bcd_cnt/Mcount_cnt2 ;
  wire \U_min_1/U_bcd_cnt/Mcount_cnt3 ;
  wire \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_222 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_224 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_226 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_228 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_230 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_232 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_234 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_236 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_eqn_0 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_eqn_1 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_eqn_2 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_eqn_3 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_eqn_4 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_eqn_5 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_eqn_6 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_eqn_7 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_eqn_8 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_eqn_9 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_248 ;
  wire \U_min_1/U_freq_div_10/clk_div_N_249 ;
  wire \U_min_1/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_min_1/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_min_1/U_freq_div_10/cnt_cmp_eq000011_262 ;
  wire \U_min_1/U_freq_div_10/cnt_cmp_eq000015_263 ;
  wire \U_min_1/U_freq_div_10/cnt_cmp_eq000036_264 ;
  wire \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data ;
  wire \U_min_10/U_cnt_digit_10/cnt_or0000 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_272 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_274 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_276 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_278 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_280 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_282 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_284 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_286 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_eqn_0 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_eqn_1 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_eqn_2 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_eqn_3 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_eqn_4 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_eqn_5 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_eqn_6 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_eqn_7 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_eqn_8 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_eqn_9 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_298 ;
  wire \U_min_10/U_freq_div_10/clk_div_N_299 ;
  wire \U_min_10/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_min_10/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_min_10/U_freq_div_10/cnt_cmp_eq000011_312 ;
  wire \U_min_10/U_freq_div_10/cnt_cmp_eq000015_313 ;
  wire \U_min_10/U_freq_div_10/cnt_cmp_eq000036_314 ;
  wire \U_sec_1/U_bcd_cnt/Mcount_cnt ;
  wire \U_sec_1/U_bcd_cnt/Mcount_cnt1 ;
  wire \U_sec_1/U_bcd_cnt/Mcount_cnt2 ;
  wire \U_sec_1/U_bcd_cnt/Mcount_cnt3 ;
  wire \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data ;
  wire \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data1 ;
  wire \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data2 ;
  wire \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data3 ;
  wire \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data4 ;
  wire \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data5 ;
  wire \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data6 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_332 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_334 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_336 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_338 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_340 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_342 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_344 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_346 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_0 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_1 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_2 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_3 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_4 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_5 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_6 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_7 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_8 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_9 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_358 ;
  wire \U_sec_1/U_freq_div_10/clk_div_N_359 ;
  wire \U_sec_1/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_sec_1/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_sec_1/U_freq_div_10/cnt_cmp_eq000011_372 ;
  wire \U_sec_1/U_freq_div_10/cnt_cmp_eq000015_373 ;
  wire \U_sec_1/U_freq_div_10/cnt_cmp_eq000036_374 ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data1 ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data2 ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data3 ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data4 ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data5 ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data6 ;
  wire \U_sec_10/U_cnt_digit_10/cnt_or0000 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_388 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_390 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_392 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_394 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_396 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_398 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_400 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_402 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_0 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_1 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_2 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_3 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_4 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_5 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_6 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_7 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_8 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_9 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_414 ;
  wire \U_sec_10/U_freq_div_10/clk_div_N_415 ;
  wire \U_sec_10/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_sec_10/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_sec_10/U_freq_div_10/cnt_cmp_eq000011_428 ;
  wire \U_sec_10/U_freq_div_10/cnt_cmp_eq000015_429 ;
  wire \U_sec_10/U_freq_div_10/cnt_cmp_eq000036_430 ;
  wire clk_BUFGP_432;
  wire rst_IBUF_435;
  wire seg_com_2_444;
  wire seg_com_3_445;
  wire seg_com_4_446;
  wire seg_com_5_447;
  wire seg_com_6_448;
  wire seg_com_7_449;
  wire seg_data_0_464;
  wire seg_data_1_465;
  wire seg_data_2_466;
  wire seg_data_3_467;
  wire seg_data_4_468;
  wire seg_data_5_469;
  wire seg_data_6_470;
  wire [9 : 0] Result;
  wire [8 : 0] \U_freq_div_1000/Mcount_cnt_cy ;
  wire [0 : 0] \U_freq_div_1000/Mcount_cnt_lut ;
  wire [9 : 0] \U_freq_div_1000/cnt ;
  wire [3 : 0] \U_h_1/U_bcd_cnt/cnt ;
  wire [8 : 0] \U_h_1/U_freq_div_10/Mcount_cnt_cy ;
  wire [0 : 0] \U_h_1/U_freq_div_10/Mcount_cnt_lut ;
  wire [9 : 0] \U_h_1/U_freq_div_10/cnt ;
  wire [2 : 0] \U_h_10/U_cnt_digit_10/cnt ;
  wire [3 : 0] \U_min_1/U_bcd_cnt/cnt ;
  wire [8 : 0] \U_min_1/U_freq_div_10/Mcount_cnt_cy ;
  wire [0 : 0] \U_min_1/U_freq_div_10/Mcount_cnt_lut ;
  wire [9 : 0] \U_min_1/U_freq_div_10/cnt ;
  wire [2 : 0] \U_min_10/U_cnt_digit_10/cnt ;
  wire [8 : 0] \U_min_10/U_freq_div_10/Mcount_cnt_cy ;
  wire [0 : 0] \U_min_10/U_freq_div_10/Mcount_cnt_lut ;
  wire [9 : 0] \U_min_10/U_freq_div_10/cnt ;
  wire [3 : 0] \U_sec_1/U_bcd_cnt/cnt ;
  wire [8 : 0] \U_sec_1/U_freq_div_10/Mcount_cnt_cy ;
  wire [0 : 0] \U_sec_1/U_freq_div_10/Mcount_cnt_lut ;
  wire [9 : 0] \U_sec_1/U_freq_div_10/cnt ;
  wire [2 : 0] \U_sec_10/U_cnt_digit_10/cnt ;
  wire [8 : 0] \U_sec_10/U_freq_div_10/Mcount_cnt_cy ;
  wire [0 : 0] \U_sec_10/U_freq_div_10/Mcount_cnt_lut ;
  wire [9 : 0] \U_sec_10/U_freq_div_10/cnt ;
  wire [5 : 0] seg_com_mux0000;
  wire [6 : 0] seg_data_mux0000;
  wire [2 : 0] ten_or_one;
  wire [2 : 0] ten_or_one_add0000;
  GND   XST_GND (
    .G(N0)
  );
  VCC   XST_VCC (
    .P(N1)
  );
  FD   seg_com_2 (
    .C(clk_BUFGP_432),
    .D(seg_com_mux0000[5]),
    .Q(seg_com_2_444)
  );
  FD   seg_com_3 (
    .C(clk_BUFGP_432),
    .D(seg_com_mux0000[4]),
    .Q(seg_com_3_445)
  );
  FD   seg_com_4 (
    .C(clk_BUFGP_432),
    .D(seg_com_mux0000[3]),
    .Q(seg_com_4_446)
  );
  FD   seg_com_5 (
    .C(clk_BUFGP_432),
    .D(seg_com_mux0000[2]),
    .Q(seg_com_5_447)
  );
  FD   seg_com_6 (
    .C(clk_BUFGP_432),
    .D(seg_com_mux0000[1]),
    .Q(seg_com_6_448)
  );
  FD   seg_com_7 (
    .C(clk_BUFGP_432),
    .D(seg_com_mux0000[0]),
    .Q(seg_com_7_449)
  );
  FD   ten_or_one_0 (
    .C(clk_BUFGP_432),
    .D(ten_or_one_add0000[0]),
    .Q(ten_or_one[0])
  );
  FD   ten_or_one_1 (
    .C(clk_BUFGP_432),
    .D(ten_or_one_add0000[1]),
    .Q(ten_or_one[1])
  );
  FD   ten_or_one_2 (
    .C(clk_BUFGP_432),
    .D(ten_or_one_add0000[2]),
    .Q(ten_or_one[2])
  );
  FD   seg_data_0 (
    .C(clk_BUFGP_432),
    .D(seg_data_mux0000[0]),
    .Q(seg_data_0_464)
  );
  FD   seg_data_1 (
    .C(clk_BUFGP_432),
    .D(seg_data_mux0000[1]),
    .Q(seg_data_1_465)
  );
  FD   seg_data_2 (
    .C(clk_BUFGP_432),
    .D(seg_data_mux0000[2]),
    .Q(seg_data_2_466)
  );
  FD   seg_data_3 (
    .C(clk_BUFGP_432),
    .D(seg_data_mux0000[3]),
    .Q(seg_data_3_467)
  );
  FD   seg_data_4 (
    .C(clk_BUFGP_432),
    .D(seg_data_mux0000[4]),
    .Q(seg_data_4_468)
  );
  FD   seg_data_5 (
    .C(clk_BUFGP_432),
    .D(seg_data_mux0000[5]),
    .Q(seg_data_5_469)
  );
  FD   seg_data_6 (
    .C(clk_BUFGP_432),
    .D(seg_data_mux0000[6]),
    .Q(seg_data_6_470)
  );
  FDPE   \U_freq_div_1000/clk_div_N  (
    .C(clk_BUFGP_432),
    .CE(\U_freq_div_1000/cnt_cmp_eq0000 ),
    .D(\U_freq_div_1000/clk_div_N_not0001 ),
    .PRE(rst_IBUF_435),
    .Q(\U_freq_div_1000/clk_div_N_136 )
  );
  FDPE   \U_h_1/U_freq_div_10/clk_div_N  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CE(\U_h_1/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_h_1/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_435),
    .Q(\U_h_1/U_freq_div_10/clk_div_N_190 )
  );
  FDPE   \U_min_1/U_freq_div_10/clk_div_N  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CE(\U_min_1/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_min_1/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_435),
    .Q(\U_min_1/U_freq_div_10/clk_div_N_249 )
  );
  FDPE   \U_sec_1/U_freq_div_10/clk_div_N  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CE(\U_sec_1/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_sec_1/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_435),
    .Q(\U_sec_1/U_freq_div_10/clk_div_N_359 )
  );
  FDPE   \U_min_10/U_freq_div_10/clk_div_N  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .CE(\U_min_10/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_min_10/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_435),
    .Q(\U_min_10/U_freq_div_10/clk_div_N_299 )
  );
  FDPE   \U_sec_10/U_freq_div_10/clk_div_N  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .CE(\U_sec_10/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_sec_10/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_435),
    .Q(\U_sec_10/U_freq_div_10/clk_div_N_415 )
  );
  FDC   \U_h_1/U_freq_div_10/cnt_0  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_h_1/U_freq_div_10/cnt [0])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_1  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_h_1/U_freq_div_10/cnt [1])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_2  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_h_1/U_freq_div_10/cnt [2])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_3  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_h_1/U_freq_div_10/cnt [3])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_4  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_h_1/U_freq_div_10/cnt [4])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_5  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_h_1/U_freq_div_10/cnt [5])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_6  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_h_1/U_freq_div_10/cnt [6])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_7  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_h_1/U_freq_div_10/cnt [7])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_8  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_h_1/U_freq_div_10/cnt [8])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_9  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_h_1/U_freq_div_10/cnt [9])
  );
  FDC   \U_freq_div_1000/cnt_0  (
    .C(clk_BUFGP_432),
    .CLR(rst_IBUF_435),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_0 ),
    .Q(\U_freq_div_1000/cnt [0])
  );
  FDC   \U_freq_div_1000/cnt_1  (
    .C(clk_BUFGP_432),
    .CLR(rst_IBUF_435),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_1 ),
    .Q(\U_freq_div_1000/cnt [1])
  );
  FDC   \U_freq_div_1000/cnt_2  (
    .C(clk_BUFGP_432),
    .CLR(rst_IBUF_435),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_2 ),
    .Q(\U_freq_div_1000/cnt [2])
  );
  FDC   \U_freq_div_1000/cnt_3  (
    .C(clk_BUFGP_432),
    .CLR(rst_IBUF_435),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_3 ),
    .Q(\U_freq_div_1000/cnt [3])
  );
  FDC   \U_freq_div_1000/cnt_4  (
    .C(clk_BUFGP_432),
    .CLR(rst_IBUF_435),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_4 ),
    .Q(\U_freq_div_1000/cnt [4])
  );
  FDC   \U_freq_div_1000/cnt_5  (
    .C(clk_BUFGP_432),
    .CLR(rst_IBUF_435),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_5 ),
    .Q(\U_freq_div_1000/cnt [5])
  );
  FDC   \U_freq_div_1000/cnt_6  (
    .C(clk_BUFGP_432),
    .CLR(rst_IBUF_435),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_6 ),
    .Q(\U_freq_div_1000/cnt [6])
  );
  FDC   \U_freq_div_1000/cnt_7  (
    .C(clk_BUFGP_432),
    .CLR(rst_IBUF_435),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_7 ),
    .Q(\U_freq_div_1000/cnt [7])
  );
  FDC   \U_freq_div_1000/cnt_8  (
    .C(clk_BUFGP_432),
    .CLR(rst_IBUF_435),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_8 ),
    .Q(\U_freq_div_1000/cnt [8])
  );
  FDC   \U_freq_div_1000/cnt_9  (
    .C(clk_BUFGP_432),
    .CLR(rst_IBUF_435),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_9 ),
    .Q(\U_freq_div_1000/cnt [9])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_0  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_min_1/U_freq_div_10/cnt [0])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_1  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_min_1/U_freq_div_10/cnt [1])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_2  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_min_1/U_freq_div_10/cnt [2])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_3  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_min_1/U_freq_div_10/cnt [3])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_4  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_min_1/U_freq_div_10/cnt [4])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_5  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_min_1/U_freq_div_10/cnt [5])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_6  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_min_1/U_freq_div_10/cnt [6])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_7  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_min_1/U_freq_div_10/cnt [7])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_8  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_min_1/U_freq_div_10/cnt [8])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_9  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_min_1/U_freq_div_10/cnt [9])
  );
  FDC   \U_h_1/U_bcd_cnt/cnt_0  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_bcd_cnt/Mcount_cnt ),
    .Q(\U_h_1/U_bcd_cnt/cnt [0])
  );
  FDC   \U_h_1/U_bcd_cnt/cnt_1  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_bcd_cnt/Mcount_cnt1 ),
    .Q(\U_h_1/U_bcd_cnt/cnt [1])
  );
  FDC   \U_h_1/U_bcd_cnt/cnt_2  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_bcd_cnt/Mcount_cnt2 ),
    .Q(\U_h_1/U_bcd_cnt/cnt [2])
  );
  FDC   \U_h_1/U_bcd_cnt/cnt_3  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .CLR(rst_IBUF_435),
    .D(\U_h_1/U_bcd_cnt/Mcount_cnt3 ),
    .Q(\U_h_1/U_bcd_cnt/cnt [3])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_0  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [0])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_1  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [1])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_2  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [2])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_3  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [3])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_4  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [4])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_5  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [5])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_6  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [6])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_7  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [7])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_8  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [8])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_9  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [9])
  );
  FDC   \U_min_1/U_bcd_cnt/cnt_0  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_bcd_cnt/Mcount_cnt ),
    .Q(\U_min_1/U_bcd_cnt/cnt [0])
  );
  FDC   \U_min_1/U_bcd_cnt/cnt_1  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_bcd_cnt/Mcount_cnt1 ),
    .Q(\U_min_1/U_bcd_cnt/cnt [1])
  );
  FDC   \U_min_1/U_bcd_cnt/cnt_2  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_bcd_cnt/Mcount_cnt2 ),
    .Q(\U_min_1/U_bcd_cnt/cnt [2])
  );
  FDC   \U_min_1/U_bcd_cnt/cnt_3  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_1/U_bcd_cnt/Mcount_cnt3 ),
    .Q(\U_min_1/U_bcd_cnt/cnt [3])
  );
  FDC   \U_sec_1/U_bcd_cnt/cnt_0  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_bcd_cnt/Mcount_cnt ),
    .Q(\U_sec_1/U_bcd_cnt/cnt [0])
  );
  FDC   \U_sec_1/U_bcd_cnt/cnt_1  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_bcd_cnt/Mcount_cnt1 ),
    .Q(\U_sec_1/U_bcd_cnt/cnt [1])
  );
  FDC   \U_sec_1/U_bcd_cnt/cnt_2  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_bcd_cnt/Mcount_cnt2 ),
    .Q(\U_sec_1/U_bcd_cnt/cnt [2])
  );
  FDC   \U_sec_1/U_bcd_cnt/cnt_3  (
    .C(\U_freq_div_1000/clk_div_N_136 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_1/U_bcd_cnt/Mcount_cnt3 ),
    .Q(\U_sec_1/U_bcd_cnt/cnt [3])
  );
  FDR   \U_h_10/U_cnt_digit_10/cnt_0  (
    .C(\U_h_1/U_freq_div_10/clk_div_N_190 ),
    .D(\Result<0>4 ),
    .R(\U_h_10/U_cnt_digit_10/cnt_or0000 ),
    .Q(\U_h_10/U_cnt_digit_10/cnt [0])
  );
  FDR   \U_h_10/U_cnt_digit_10/cnt_1  (
    .C(\U_h_1/U_freq_div_10/clk_div_N_190 ),
    .D(\Result<1>4 ),
    .R(\U_h_10/U_cnt_digit_10/cnt_or0000 ),
    .Q(\U_h_10/U_cnt_digit_10/cnt [1])
  );
  FDR   \U_h_10/U_cnt_digit_10/cnt_2  (
    .C(\U_h_1/U_freq_div_10/clk_div_N_190 ),
    .D(\Result<2>4 ),
    .R(\U_h_10/U_cnt_digit_10/cnt_or0000 ),
    .Q(\U_h_10/U_cnt_digit_10/cnt [2])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_0  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_min_10/U_freq_div_10/cnt [0])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_1  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_min_10/U_freq_div_10/cnt [1])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_2  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_min_10/U_freq_div_10/cnt [2])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_3  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_min_10/U_freq_div_10/cnt [3])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_4  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_min_10/U_freq_div_10/cnt [4])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_5  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_min_10/U_freq_div_10/cnt [5])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_6  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_min_10/U_freq_div_10/cnt [6])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_7  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_min_10/U_freq_div_10/cnt [7])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_8  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_min_10/U_freq_div_10/cnt [8])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_9  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .CLR(rst_IBUF_435),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_min_10/U_freq_div_10/cnt [9])
  );
  FDR   \U_min_10/U_cnt_digit_10/cnt_0  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .D(\Result<0>7 ),
    .R(\U_min_10/U_cnt_digit_10/cnt_or0000 ),
    .Q(\U_min_10/U_cnt_digit_10/cnt [0])
  );
  FDR   \U_min_10/U_cnt_digit_10/cnt_1  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .D(\Result<1>7 ),
    .R(\U_min_10/U_cnt_digit_10/cnt_or0000 ),
    .Q(\U_min_10/U_cnt_digit_10/cnt [1])
  );
  FDR   \U_min_10/U_cnt_digit_10/cnt_2  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .D(\Result<2>7 ),
    .R(\U_min_10/U_cnt_digit_10/cnt_or0000 ),
    .Q(\U_min_10/U_cnt_digit_10/cnt [2])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_0  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [0])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_1  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [1])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_2  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [2])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_3  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [3])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_4  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [4])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_5  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [5])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_6  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [6])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_7  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [7])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_8  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [8])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_9  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .CLR(rst_IBUF_435),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [9])
  );
  FDR   \U_sec_10/U_cnt_digit_10/cnt_0  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .D(\Result<0>8 ),
    .R(\U_sec_10/U_cnt_digit_10/cnt_or0000 ),
    .Q(\U_sec_10/U_cnt_digit_10/cnt [0])
  );
  FDR   \U_sec_10/U_cnt_digit_10/cnt_1  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .D(\Result<1>8 ),
    .R(\U_sec_10/U_cnt_digit_10/cnt_or0000 ),
    .Q(\U_sec_10/U_cnt_digit_10/cnt [1])
  );
  FDR   \U_sec_10/U_cnt_digit_10/cnt_2  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .D(\Result<2>8 ),
    .R(\U_sec_10/U_cnt_digit_10/cnt_or0000 ),
    .Q(\U_sec_10/U_cnt_digit_10/cnt [2])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<0>  (
    .CI(N0),
    .DI(N1),
    .S(\U_freq_div_1000/Mcount_cnt_lut [0]),
    .O(\U_freq_div_1000/Mcount_cnt_cy [0])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<0>  (
    .CI(N0),
    .LI(\U_freq_div_1000/Mcount_cnt_lut [0]),
    .O(Result[0])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<1>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [0]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<1>_rt_109 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [1])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<1>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [0]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<1>_rt_109 ),
    .O(Result[1])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<2>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<2>_rt_111 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [2])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<2>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [1]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<2>_rt_111 ),
    .O(Result[2])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<3>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<3>_rt_113 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [3])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<3>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [2]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<3>_rt_113 ),
    .O(Result[3])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<4>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<4>_rt_115 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [4])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<4>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [3]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<4>_rt_115 ),
    .O(Result[4])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<5>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<5>_rt_117 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [5])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<5>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [4]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<5>_rt_117 ),
    .O(Result[5])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<6>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<6>_rt_119 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [6])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<6>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [5]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<6>_rt_119 ),
    .O(Result[6])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<7>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<7>_rt_121 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [7])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<7>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [6]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<7>_rt_121 ),
    .O(Result[7])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<8>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<8>_rt_123 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [8])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<8>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [7]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<8>_rt_123 ),
    .O(Result[8])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<9>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [8]),
    .LI(\U_freq_div_1000/Mcount_cnt_xor<9>_rt_135 ),
    .O(Result[9])
  );
  MUXF5   Mmux_seg_data_mux0000_2_f5_4 (
    .I0(Mmux_seg_data_mux0000_45_13),
    .I1(Mmux_seg_data_mux0000_35_5),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[6])
  );
  LUT4 #(
    .INIT ( 16'h0E04 ))
  Mmux_seg_data_mux0000_45 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data6 ),
    .I2(ten_or_one[1]),
    .I3(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data6 ),
    .O(Mmux_seg_data_mux0000_45_13)
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  Mmux_seg_data_mux0000_35 (
    .I0(seg_data_6_470),
    .I1(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_35_5)
  );
  MUXF5   Mmux_seg_data_mux0000_2_f5_3 (
    .I0(Mmux_seg_data_mux0000_44_12),
    .I1(Mmux_seg_data_mux0000_34_4),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[5])
  );
  LUT4 #(
    .INIT ( 16'h0E04 ))
  Mmux_seg_data_mux0000_44 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data5 ),
    .I2(ten_or_one[1]),
    .I3(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data5 ),
    .O(Mmux_seg_data_mux0000_44_12)
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  Mmux_seg_data_mux0000_34 (
    .I0(seg_data_5_469),
    .I1(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_34_4)
  );
  MUXF5   Mmux_seg_data_mux0000_2_f5_2 (
    .I0(Mmux_seg_data_mux0000_43_11),
    .I1(Mmux_seg_data_mux0000_33_3),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[4])
  );
  LUT4 #(
    .INIT ( 16'h0E04 ))
  Mmux_seg_data_mux0000_43 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data4 ),
    .I2(ten_or_one[1]),
    .I3(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data4 ),
    .O(Mmux_seg_data_mux0000_43_11)
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  Mmux_seg_data_mux0000_33 (
    .I0(seg_data_4_468),
    .I1(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_33_3)
  );
  MUXF5   Mmux_seg_data_mux0000_2_f5_1 (
    .I0(Mmux_seg_data_mux0000_42_10),
    .I1(Mmux_seg_data_mux0000_32_2),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[3])
  );
  LUT4 #(
    .INIT ( 16'h0E04 ))
  Mmux_seg_data_mux0000_42 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data3 ),
    .I2(ten_or_one[1]),
    .I3(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data3 ),
    .O(Mmux_seg_data_mux0000_42_10)
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  Mmux_seg_data_mux0000_32 (
    .I0(seg_data_3_467),
    .I1(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_32_2)
  );
  MUXF5   Mmux_seg_data_mux0000_2_f5_0 (
    .I0(Mmux_seg_data_mux0000_41_9),
    .I1(Mmux_seg_data_mux0000_31_1),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[2])
  );
  LUT4 #(
    .INIT ( 16'h0E04 ))
  Mmux_seg_data_mux0000_41 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data2 ),
    .I2(ten_or_one[1]),
    .I3(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data2 ),
    .O(Mmux_seg_data_mux0000_41_9)
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  Mmux_seg_data_mux0000_31 (
    .I0(seg_data_2_466),
    .I1(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_31_1)
  );
  MUXF5   Mmux_seg_data_mux0000_2_f5 (
    .I0(Mmux_seg_data_mux0000_4_8),
    .I1(Mmux_seg_data_mux0000_3_0),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[1])
  );
  LUT4 #(
    .INIT ( 16'h0E04 ))
  Mmux_seg_data_mux0000_4 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data1 ),
    .I2(ten_or_one[1]),
    .I3(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data1 ),
    .O(Mmux_seg_data_mux0000_4_8)
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  Mmux_seg_data_mux0000_3 (
    .I0(seg_data_1_465),
    .I1(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_3_0)
  );
  MUXF6   Mmux_seg_data_mux0000_2_f6 (
    .I0(Mmux_seg_data_mux0000_4_f5_14),
    .I1(Mmux_seg_data_mux0000_3_f5_6),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[0])
  );
  MUXF5   Mmux_seg_data_mux0000_4_f5 (
    .I0(Mmux_seg_data_mux0000_6_17),
    .I1(Mmux_seg_data_mux0000_51_16),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_4_f5_14)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_6 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data ),
    .I2(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data ),
    .O(Mmux_seg_data_mux0000_6_17)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_51 (
    .I0(ten_or_one[0]),
    .I1(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data ),
    .I2(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data ),
    .O(Mmux_seg_data_mux0000_51_16)
  );
  MUXF5   Mmux_seg_data_mux0000_3_f5 (
    .I0(Mmux_seg_data_mux0000_5_15),
    .I1(Mmux_seg_data_mux0000_3_f5_rt_7),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_3_f5_6)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_5 (
    .I0(ten_or_one[0]),
    .I1(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data ),
    .I2(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data ),
    .O(Mmux_seg_data_mux0000_5_15)
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<0>  (
    .CI(N0),
    .DI(N1),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_lut [0]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [0])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<0>  (
    .CI(N0),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_lut [0]),
    .O(\Result<0>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_332 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_332 ),
    .O(\Result<1>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_334 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_334 ),
    .O(\Result<2>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_336 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_336 ),
    .O(\Result<3>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_338 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_338 ),
    .O(\Result<4>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_340 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_340 ),
    .O(\Result<5>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_342 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_342 ),
    .O(\Result<6>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_344 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_344 ),
    .O(\Result<7>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_346 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_346 ),
    .O(\Result<8>3 )
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_358 ),
    .O(\Result<9>3 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<0>  (
    .CI(N0),
    .DI(N1),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_lut [0]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [0])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<0>  (
    .CI(N0),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_lut [0]),
    .O(\Result<0>1 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<1>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_163 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_163 ),
    .O(\Result<1>1 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_165 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_165 ),
    .O(\Result<2>1 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_167 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_167 ),
    .O(\Result<3>1 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_169 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_169 ),
    .O(\Result<4>1 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_171 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_171 ),
    .O(\Result<5>1 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_173 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_173 ),
    .O(\Result<6>1 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_175 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_175 ),
    .O(\Result<7>1 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_177 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_177 ),
    .O(\Result<8>1 )
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_189 ),
    .O(\Result<9>1 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<0>  (
    .CI(N0),
    .DI(N1),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_lut [0]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [0])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<0>  (
    .CI(N0),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_lut [0]),
    .O(\Result<0>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<1>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_222 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_222 ),
    .O(\Result<1>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_224 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_224 ),
    .O(\Result<2>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_226 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_226 ),
    .O(\Result<3>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_228 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_228 ),
    .O(\Result<4>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_230 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_230 ),
    .O(\Result<5>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_232 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_232 ),
    .O(\Result<6>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_234 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_234 ),
    .O(\Result<7>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_236 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_236 ),
    .O(\Result<8>2 )
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_248 ),
    .O(\Result<9>2 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<0>  (
    .CI(N0),
    .DI(N1),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_lut [0]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [0])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<0>  (
    .CI(N0),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_lut [0]),
    .O(\Result<0>6 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [0]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_388 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_388 ),
    .O(\Result<1>6 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_390 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_390 ),
    .O(\Result<2>6 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_392 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_392 ),
    .O(\Result<3>5 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_394 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_394 ),
    .O(\Result<4>5 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_396 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_396 ),
    .O(\Result<5>5 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_398 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_398 ),
    .O(\Result<6>5 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_400 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_400 ),
    .O(\Result<7>5 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_402 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_402 ),
    .O(\Result<8>5 )
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_414 ),
    .O(\Result<9>5 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<0>  (
    .CI(N0),
    .DI(N1),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_lut [0]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [0])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<0>  (
    .CI(N0),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_lut [0]),
    .O(\Result<0>5 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<1>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [0]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_272 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_272 ),
    .O(\Result<1>5 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_274 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_274 ),
    .O(\Result<2>5 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_276 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_276 ),
    .O(\Result<3>4 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_278 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_278 ),
    .O(\Result<4>4 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_280 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_280 ),
    .O(\Result<5>4 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_282 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_282 ),
    .O(\Result<6>4 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_284 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_284 ),
    .O(\Result<7>4 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_286 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_286 ),
    .O(\Result<8>4 )
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_298 ),
    .O(\Result<9>4 )
  );
  LUT3 #(
    .INIT ( 8'h51 ))
  \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data41  (
    .I0(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .O(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data4 )
  );
  LUT3 #(
    .INIT ( 8'hFD ))
  \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data21  (
    .I0(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .I2(\U_sec_10/U_cnt_digit_10/cnt [2]),
    .O(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data2 )
  );
  LUT3 #(
    .INIT ( 8'h7A ))
  \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data61  (
    .I0(\U_sec_10/U_cnt_digit_10/cnt [2]),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .I2(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .O(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data6 )
  );
  LUT3 #(
    .INIT ( 8'h2B ))
  \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data51  (
    .I0(\U_sec_10/U_cnt_digit_10/cnt [2]),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .I2(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .O(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data5 )
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data111  (
    .I0(\U_sec_10/U_cnt_digit_10/cnt [2]),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .I2(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .O(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data1 )
  );
  LUT3 #(
    .INIT ( 8'hF9 ))
  \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data11  (
    .I0(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .O(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data )
  );
  LUT3 #(
    .INIT ( 8'hF9 ))
  \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data11  (
    .I0(\U_min_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_min_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_min_10/U_cnt_digit_10/cnt [1]),
    .O(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data )
  );
  LUT3 #(
    .INIT ( 8'hF9 ))
  \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data11  (
    .I0(\U_h_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_h_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_h_10/U_cnt_digit_10/cnt [1]),
    .O(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data )
  );
  LUT3 #(
    .INIT ( 8'h79 ))
  \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data31  (
    .I0(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .O(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data3 )
  );
  LUT4 #(
    .INIT ( 16'h0145 ))
  \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data41  (
    .I0(\U_sec_1/U_bcd_cnt/cnt [0]),
    .I1(\U_sec_1/U_bcd_cnt/cnt [1]),
    .I2(\U_sec_1/U_bcd_cnt/cnt [2]),
    .I3(\U_sec_1/U_bcd_cnt/cnt [3]),
    .O(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data4 )
  );
  LUT4 #(
    .INIT ( 16'h545F ))
  \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data21  (
    .I0(\U_sec_1/U_bcd_cnt/cnt [3]),
    .I1(\U_sec_1/U_bcd_cnt/cnt [0]),
    .I2(\U_sec_1/U_bcd_cnt/cnt [2]),
    .I3(\U_sec_1/U_bcd_cnt/cnt [1]),
    .O(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data2 )
  );
  LUT4 #(
    .INIT ( 16'h2177 ))
  \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data111  (
    .I0(\U_sec_1/U_bcd_cnt/cnt [1]),
    .I1(\U_sec_1/U_bcd_cnt/cnt [3]),
    .I2(\U_sec_1/U_bcd_cnt/cnt [0]),
    .I3(\U_sec_1/U_bcd_cnt/cnt [2]),
    .O(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data1 )
  );
  LUT4 #(
    .INIT ( 16'h1656 ))
  \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data61  (
    .I0(\U_sec_1/U_bcd_cnt/cnt [3]),
    .I1(\U_sec_1/U_bcd_cnt/cnt [2]),
    .I2(\U_sec_1/U_bcd_cnt/cnt [1]),
    .I3(\U_sec_1/U_bcd_cnt/cnt [0]),
    .O(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data6 )
  );
  LUT4 #(
    .INIT ( 16'h150B ))
  \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data51  (
    .I0(\U_sec_1/U_bcd_cnt/cnt [3]),
    .I1(\U_sec_1/U_bcd_cnt/cnt [0]),
    .I2(\U_sec_1/U_bcd_cnt/cnt [1]),
    .I3(\U_sec_1/U_bcd_cnt/cnt [2]),
    .O(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data5 )
  );
  LUT4 #(
    .INIT ( 16'h5563 ))
  \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data11  (
    .I0(\U_sec_1/U_bcd_cnt/cnt [3]),
    .I1(\U_sec_1/U_bcd_cnt/cnt [2]),
    .I2(\U_sec_1/U_bcd_cnt/cnt [0]),
    .I3(\U_sec_1/U_bcd_cnt/cnt [1]),
    .O(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data )
  );
  LUT4 #(
    .INIT ( 16'h5563 ))
  \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data11  (
    .I0(\U_min_1/U_bcd_cnt/cnt [3]),
    .I1(\U_min_1/U_bcd_cnt/cnt [2]),
    .I2(\U_min_1/U_bcd_cnt/cnt [0]),
    .I3(\U_min_1/U_bcd_cnt/cnt [1]),
    .O(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data )
  );
  LUT4 #(
    .INIT ( 16'h5563 ))
  \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data11  (
    .I0(\U_h_1/U_bcd_cnt/cnt [3]),
    .I1(\U_h_1/U_bcd_cnt/cnt [2]),
    .I2(\U_h_1/U_bcd_cnt/cnt [0]),
    .I3(\U_h_1/U_bcd_cnt/cnt [1]),
    .O(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data )
  );
  LUT4 #(
    .INIT ( 16'h1447 ))
  \U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data31  (
    .I0(\U_sec_1/U_bcd_cnt/cnt [3]),
    .I1(\U_sec_1/U_bcd_cnt/cnt [1]),
    .I2(\U_sec_1/U_bcd_cnt/cnt [0]),
    .I3(\U_sec_1/U_bcd_cnt/cnt [2]),
    .O(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data3 )
  );
  LUT2 #(
    .INIT ( 4'h6 ))
  \U_sec_10/U_cnt_digit_10/Mcount_cnt_xor<1>11  (
    .I0(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .O(\Result<1>8 )
  );
  LUT2 #(
    .INIT ( 4'h6 ))
  \U_min_10/U_cnt_digit_10/Mcount_cnt_xor<1>11  (
    .I0(\U_min_10/U_cnt_digit_10/cnt [1]),
    .I1(\U_min_10/U_cnt_digit_10/cnt [0]),
    .O(\Result<1>7 )
  );
  LUT2 #(
    .INIT ( 4'h6 ))
  \U_h_10/U_cnt_digit_10/Mcount_cnt_xor<1>11  (
    .I0(\U_h_10/U_cnt_digit_10/cnt [1]),
    .I1(\U_h_10/U_cnt_digit_10/cnt [0]),
    .O(\Result<1>4 )
  );
  LUT3 #(
    .INIT ( 8'h5D ))
  \Madd_ten_or_one_add0000_xor<0>11  (
    .I0(ten_or_one[0]),
    .I1(ten_or_one[2]),
    .I2(ten_or_one[1]),
    .O(ten_or_one_add0000[0])
  );
  LUT3 #(
    .INIT ( 8'h62 ))
  \Madd_ten_or_one_add0000_xor<2>11  (
    .I0(ten_or_one[2]),
    .I1(ten_or_one[0]),
    .I2(ten_or_one[1]),
    .O(ten_or_one_add0000[2])
  );
  LUT3 #(
    .INIT ( 8'h46 ))
  \Madd_ten_or_one_add0000_xor<1>11  (
    .I0(ten_or_one[0]),
    .I1(ten_or_one[1]),
    .I2(ten_or_one[2]),
    .O(ten_or_one_add0000[1])
  );
  LUT3 #(
    .INIT ( 8'h6A ))
  \U_sec_10/U_cnt_digit_10/Mcount_cnt_xor<2>11  (
    .I0(\U_sec_10/U_cnt_digit_10/cnt [2]),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .I2(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .O(\Result<2>8 )
  );
  LUT3 #(
    .INIT ( 8'h6A ))
  \U_sec_1/U_bcd_cnt/Mcount_cnt_xor<2>11  (
    .I0(\U_sec_1/U_bcd_cnt/cnt [2]),
    .I1(\U_sec_1/U_bcd_cnt/cnt [1]),
    .I2(\U_sec_1/U_bcd_cnt/cnt [0]),
    .O(\U_sec_1/U_bcd_cnt/Mcount_cnt2 )
  );
  LUT3 #(
    .INIT ( 8'h6A ))
  \U_min_10/U_cnt_digit_10/Mcount_cnt_xor<2>11  (
    .I0(\U_min_10/U_cnt_digit_10/cnt [2]),
    .I1(\U_min_10/U_cnt_digit_10/cnt [1]),
    .I2(\U_min_10/U_cnt_digit_10/cnt [0]),
    .O(\Result<2>7 )
  );
  LUT3 #(
    .INIT ( 8'h6A ))
  \U_min_1/U_bcd_cnt/Mcount_cnt_xor<2>11  (
    .I0(\U_min_1/U_bcd_cnt/cnt [2]),
    .I1(\U_min_1/U_bcd_cnt/cnt [1]),
    .I2(\U_min_1/U_bcd_cnt/cnt [0]),
    .O(\U_min_1/U_bcd_cnt/Mcount_cnt2 )
  );
  LUT3 #(
    .INIT ( 8'h6A ))
  \U_h_10/U_cnt_digit_10/Mcount_cnt_xor<2>11  (
    .I0(\U_h_10/U_cnt_digit_10/cnt [2]),
    .I1(\U_h_10/U_cnt_digit_10/cnt [1]),
    .I2(\U_h_10/U_cnt_digit_10/cnt [0]),
    .O(\Result<2>4 )
  );
  LUT3 #(
    .INIT ( 8'h6A ))
  \U_h_1/U_bcd_cnt/Mcount_cnt_xor<2>11  (
    .I0(\U_h_1/U_bcd_cnt/cnt [2]),
    .I1(\U_h_1/U_bcd_cnt/cnt [1]),
    .I2(\U_h_1/U_bcd_cnt/cnt [0]),
    .O(\U_h_1/U_bcd_cnt/Mcount_cnt2 )
  );
  LUT4 #(
    .INIT ( 16'hBF1F ))
  \seg_com_mux0000<5>1  (
    .I0(ten_or_one[1]),
    .I1(ten_or_one[0]),
    .I2(ten_or_one[2]),
    .I3(seg_com_2_444),
    .O(seg_com_mux0000[5])
  );
  LUT4 #(
    .INIT ( 16'hEF4F ))
  \seg_com_mux0000<4>1  (
    .I0(ten_or_one[1]),
    .I1(ten_or_one[0]),
    .I2(ten_or_one[2]),
    .I3(seg_com_3_445),
    .O(seg_com_mux0000[4])
  );
  LUT4 #(
    .INIT ( 16'hBF1F ))
  \seg_com_mux0000<3>1  (
    .I0(ten_or_one[2]),
    .I1(ten_or_one[0]),
    .I2(ten_or_one[1]),
    .I3(seg_com_4_446),
    .O(seg_com_mux0000[3])
  );
  LUT4 #(
    .INIT ( 16'hEF4F ))
  \seg_com_mux0000<2>1  (
    .I0(ten_or_one[2]),
    .I1(ten_or_one[0]),
    .I2(ten_or_one[1]),
    .I3(seg_com_5_447),
    .O(seg_com_mux0000[2])
  );
  LUT4 #(
    .INIT ( 16'hEF67 ))
  \seg_com_mux0000<1>1  (
    .I0(ten_or_one[1]),
    .I1(ten_or_one[2]),
    .I2(ten_or_one[0]),
    .I3(seg_com_6_448),
    .O(seg_com_mux0000[1])
  );
  LUT4 #(
    .INIT ( 16'hFE76 ))
  \seg_com_mux0000<0>1  (
    .I0(ten_or_one[1]),
    .I1(ten_or_one[2]),
    .I2(ten_or_one[0]),
    .I3(seg_com_7_449),
    .O(seg_com_mux0000[0])
  );
  LUT4 #(
    .INIT ( 16'h6466 ))
  \U_sec_1/U_bcd_cnt/Mcount_cnt_xor<1>11  (
    .I0(\U_sec_1/U_bcd_cnt/cnt [0]),
    .I1(\U_sec_1/U_bcd_cnt/cnt [1]),
    .I2(\U_sec_1/U_bcd_cnt/cnt [2]),
    .I3(\U_sec_1/U_bcd_cnt/cnt [3]),
    .O(\U_sec_1/U_bcd_cnt/Mcount_cnt1 )
  );
  LUT4 #(
    .INIT ( 16'h6466 ))
  \U_min_1/U_bcd_cnt/Mcount_cnt_xor<1>11  (
    .I0(\U_min_1/U_bcd_cnt/cnt [0]),
    .I1(\U_min_1/U_bcd_cnt/cnt [1]),
    .I2(\U_min_1/U_bcd_cnt/cnt [2]),
    .I3(\U_min_1/U_bcd_cnt/cnt [3]),
    .O(\U_min_1/U_bcd_cnt/Mcount_cnt1 )
  );
  LUT4 #(
    .INIT ( 16'h6466 ))
  \U_h_1/U_bcd_cnt/Mcount_cnt_xor<1>11  (
    .I0(\U_h_1/U_bcd_cnt/cnt [0]),
    .I1(\U_h_1/U_bcd_cnt/cnt [1]),
    .I2(\U_h_1/U_bcd_cnt/cnt [2]),
    .I3(\U_h_1/U_bcd_cnt/cnt [3]),
    .O(\U_h_1/U_bcd_cnt/Mcount_cnt1 )
  );
  LUT4 #(
    .INIT ( 16'h68CC ))
  \U_sec_1/U_bcd_cnt/Mcount_cnt_xor<3>11  (
    .I0(\U_sec_1/U_bcd_cnt/cnt [2]),
    .I1(\U_sec_1/U_bcd_cnt/cnt [3]),
    .I2(\U_sec_1/U_bcd_cnt/cnt [1]),
    .I3(\U_sec_1/U_bcd_cnt/cnt [0]),
    .O(\U_sec_1/U_bcd_cnt/Mcount_cnt3 )
  );
  LUT4 #(
    .INIT ( 16'h68CC ))
  \U_min_1/U_bcd_cnt/Mcount_cnt_xor<3>11  (
    .I0(\U_min_1/U_bcd_cnt/cnt [2]),
    .I1(\U_min_1/U_bcd_cnt/cnt [3]),
    .I2(\U_min_1/U_bcd_cnt/cnt [1]),
    .I3(\U_min_1/U_bcd_cnt/cnt [0]),
    .O(\U_min_1/U_bcd_cnt/Mcount_cnt3 )
  );
  LUT4 #(
    .INIT ( 16'h68CC ))
  \U_h_1/U_bcd_cnt/Mcount_cnt_xor<3>11  (
    .I0(\U_h_1/U_bcd_cnt/cnt [2]),
    .I1(\U_h_1/U_bcd_cnt/cnt [3]),
    .I2(\U_h_1/U_bcd_cnt/cnt [1]),
    .I3(\U_h_1/U_bcd_cnt/cnt [0]),
    .O(\U_h_1/U_bcd_cnt/Mcount_cnt3 )
  );
  LUT4 #(
    .INIT ( 16'hAABA ))
  \U_sec_10/U_cnt_digit_10/cnt_or00001  (
    .I0(rst_IBUF_435),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .I3(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .O(\U_sec_10/U_cnt_digit_10/cnt_or0000 )
  );
  LUT4 #(
    .INIT ( 16'hAABA ))
  \U_min_10/U_cnt_digit_10/cnt_or00001  (
    .I0(rst_IBUF_435),
    .I1(\U_min_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_min_10/U_cnt_digit_10/cnt [1]),
    .I3(\U_min_10/U_cnt_digit_10/cnt [0]),
    .O(\U_min_10/U_cnt_digit_10/cnt_or0000 )
  );
  LUT4 #(
    .INIT ( 16'hAABA ))
  \U_h_10/U_cnt_digit_10/cnt_or00001  (
    .I0(rst_IBUF_435),
    .I1(\U_h_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_h_10/U_cnt_digit_10/cnt [1]),
    .I3(\U_h_10/U_cnt_digit_10/cnt [0]),
    .O(\U_h_10/U_cnt_digit_10/cnt_or0000 )
  );
  IBUF   rst_IBUF (
    .I(rst),
    .O(rst_IBUF_435)
  );
  OBUF   clk_min_1_OBUF (
    .I(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .O(clk_min_1)
  );
  OBUF   seg_data_7_OBUF (
    .I(N0),
    .O(seg_data[7])
  );
  OBUF   seg_data_6_OBUF (
    .I(seg_data_6_470),
    .O(seg_data[6])
  );
  OBUF   seg_data_5_OBUF (
    .I(seg_data_5_469),
    .O(seg_data[5])
  );
  OBUF   seg_data_4_OBUF (
    .I(seg_data_4_468),
    .O(seg_data[4])
  );
  OBUF   seg_data_3_OBUF (
    .I(seg_data_3_467),
    .O(seg_data[3])
  );
  OBUF   seg_data_2_OBUF (
    .I(seg_data_2_466),
    .O(seg_data[2])
  );
  OBUF   seg_data_1_OBUF (
    .I(seg_data_1_465),
    .O(seg_data[1])
  );
  OBUF   seg_data_0_OBUF (
    .I(seg_data_0_464),
    .O(seg_data[0])
  );
  OBUF   seg_com_7_OBUF (
    .I(seg_com_7_449),
    .O(seg_com[7])
  );
  OBUF   seg_com_6_OBUF (
    .I(seg_com_6_448),
    .O(seg_com[6])
  );
  OBUF   seg_com_5_OBUF (
    .I(seg_com_5_447),
    .O(seg_com[5])
  );
  OBUF   seg_com_4_OBUF (
    .I(seg_com_4_446),
    .O(seg_com[4])
  );
  OBUF   seg_com_3_OBUF (
    .I(seg_com_3_445),
    .O(seg_com[3])
  );
  OBUF   seg_com_2_OBUF (
    .I(seg_com_2_444),
    .O(seg_com[2])
  );
  OBUF   seg_com_1_OBUF (
    .I(N1),
    .O(seg_com[1])
  );
  OBUF   seg_com_0_OBUF (
    .I(N1),
    .O(seg_com[0])
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<1>_rt  (
    .I0(\U_freq_div_1000/cnt [1]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<1>_rt_109 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<2>_rt  (
    .I0(\U_freq_div_1000/cnt [2]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<2>_rt_111 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<3>_rt  (
    .I0(\U_freq_div_1000/cnt [3]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<3>_rt_113 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<4>_rt  (
    .I0(\U_freq_div_1000/cnt [4]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<4>_rt_115 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<5>_rt  (
    .I0(\U_freq_div_1000/cnt [5]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<5>_rt_117 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<6>_rt  (
    .I0(\U_freq_div_1000/cnt [6]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<6>_rt_119 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<7>_rt  (
    .I0(\U_freq_div_1000/cnt [7]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<7>_rt_121 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<8>_rt  (
    .I0(\U_freq_div_1000/cnt [8]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<8>_rt_123 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [1]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_332 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [2]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_334 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [3]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_336 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [4]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_338 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [5]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_340 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [6]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_342 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [7]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_344 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [8]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_346 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [1]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_163 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [2]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_165 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [3]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_167 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [4]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_169 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [5]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_171 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [6]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_173 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [7]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_175 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [8]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_177 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [1]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_222 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [2]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_224 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [3]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_226 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [4]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_228 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [5]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_230 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [6]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_232 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [7]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_234 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [8]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_236 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [1]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_388 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [2]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_390 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [3]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_392 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [4]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_394 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [5]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_396 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [6]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_398 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [7]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_400 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [8]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_402 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [1]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_272 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [2]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_274 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [3]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_276 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [4]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_278 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [5]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_280 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [6]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_282 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [7]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_284 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [8]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_286 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_xor<9>_rt  (
    .I0(\U_freq_div_1000/cnt [9]),
    .O(\U_freq_div_1000/Mcount_cnt_xor<9>_rt_135 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [9]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_358 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [9]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_189 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [9]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_248 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [9]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_414 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [9]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_298 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_rt (
    .I0(seg_data_0_464),
    .O(Mmux_seg_data_mux0000_3_f5_rt_7)
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N31),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_428 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_429 ),
    .I3(\Result<9>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N34),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_372 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_373 ),
    .I3(\Result<9>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N37),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_312 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_313 ),
    .I3(\Result<9>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N40),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_262 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_263 ),
    .I3(\Result<9>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N43),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_203 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_204 ),
    .I3(\Result<9>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_91  (
    .I0(N45),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_151 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_150 ),
    .I3(Result[9]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_430 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_428 ),
    .I2(N30),
    .I3(\Result<8>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_374 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_372 ),
    .I2(N33),
    .I3(\Result<8>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_314 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_312 ),
    .I2(N36),
    .I3(\Result<8>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_264 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_262 ),
    .I2(N39),
    .I3(\Result<8>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_205 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_203 ),
    .I2(N42),
    .I3(\Result<8>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_81  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_149 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_151 ),
    .I2(N46),
    .I3(Result[8]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_430 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_428 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_429 ),
    .I3(\Result<7>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_374 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_372 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_373 ),
    .I3(\Result<7>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_314 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_312 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_313 ),
    .I3(\Result<7>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_264 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_262 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_263 ),
    .I3(\Result<7>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_205 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_203 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_204 ),
    .I3(\Result<7>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_71  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_149 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_151 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_150 ),
    .I3(Result[7]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_430 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_428 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_429 ),
    .I3(\Result<6>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_374 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_372 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_373 ),
    .I3(\Result<6>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_314 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_312 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_313 ),
    .I3(\Result<6>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_264 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_262 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_263 ),
    .I3(\Result<6>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_205 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_203 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_204 ),
    .I3(\Result<6>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_61  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_149 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_151 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_150 ),
    .I3(Result[6]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_430 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_428 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_429 ),
    .I3(\Result<5>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_374 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_372 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_373 ),
    .I3(\Result<5>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_314 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_312 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_313 ),
    .I3(\Result<5>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_264 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_262 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_263 ),
    .I3(\Result<5>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_205 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_203 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_204 ),
    .I3(\Result<5>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_51  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_149 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_151 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_150 ),
    .I3(Result[5]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_430 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_428 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_429 ),
    .I3(\Result<4>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_374 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_372 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_373 ),
    .I3(\Result<4>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_314 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_312 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_313 ),
    .I3(\Result<4>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_264 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_262 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_263 ),
    .I3(\Result<4>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_205 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_203 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_204 ),
    .I3(\Result<4>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_41  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_149 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_151 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_150 ),
    .I3(Result[4]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_430 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_428 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_429 ),
    .I3(\Result<3>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_374 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_372 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_373 ),
    .I3(\Result<3>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_314 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_312 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_313 ),
    .I3(\Result<3>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_264 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_262 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_263 ),
    .I3(\Result<3>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_205 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_203 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_204 ),
    .I3(\Result<3>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_31  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_149 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_151 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_150 ),
    .I3(Result[3]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_430 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_428 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_429 ),
    .I3(\Result<2>6 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_374 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_372 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_373 ),
    .I3(\Result<2>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_314 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_312 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_313 ),
    .I3(\Result<2>5 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_264 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_262 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_263 ),
    .I3(\Result<2>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_205 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_203 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_204 ),
    .I3(\Result<2>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_21  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_149 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_151 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_150 ),
    .I3(Result[2]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_430 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_428 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_429 ),
    .I3(\Result<1>6 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_374 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_372 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_373 ),
    .I3(\Result<1>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_314 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_312 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_313 ),
    .I3(\Result<1>5 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_264 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_262 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_263 ),
    .I3(\Result<1>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_205 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_203 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_204 ),
    .I3(\Result<1>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_11  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_149 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_151 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_150 ),
    .I3(Result[1]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_430 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_428 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_429 ),
    .I3(\Result<0>6 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_374 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_372 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_373 ),
    .I3(\Result<0>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_314 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_312 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_313 ),
    .I3(\Result<0>5 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_264 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_262 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_263 ),
    .I3(\Result<0>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_205 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_203 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_204 ),
    .I3(\Result<0>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_01  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_149 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_151 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_150 ),
    .I3(Result[0]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_sec_10/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_sec_10/U_freq_div_10/cnt [4]),
    .I1(\U_sec_10/U_freq_div_10/cnt [5]),
    .I2(N29),
    .I3(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_430 ),
    .O(\U_sec_10/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_sec_1/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_sec_1/U_freq_div_10/cnt [4]),
    .I1(\U_sec_1/U_freq_div_10/cnt [5]),
    .I2(N32),
    .I3(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_374 ),
    .O(\U_sec_1/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_min_10/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_min_10/U_freq_div_10/cnt [4]),
    .I1(\U_min_10/U_freq_div_10/cnt [5]),
    .I2(N35),
    .I3(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_314 ),
    .O(\U_min_10/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_min_1/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_min_1/U_freq_div_10/cnt [4]),
    .I1(\U_min_1/U_freq_div_10/cnt [5]),
    .I2(N38),
    .I3(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_264 ),
    .O(\U_min_1/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_h_1/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_h_1/U_freq_div_10/cnt [4]),
    .I1(\U_h_1/U_freq_div_10/cnt [5]),
    .I2(N41),
    .I3(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_205 ),
    .O(\U_h_1/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_freq_div_1000/cnt_cmp_eq000024  (
    .I0(\U_freq_div_1000/cnt [2]),
    .I1(\U_freq_div_1000/cnt [3]),
    .I2(N44),
    .I3(\U_freq_div_1000/cnt_cmp_eq000012_149 ),
    .O(\U_freq_div_1000/cnt_cmp_eq0000 )
  );
  BUFGP   clk_BUFGP (
    .I(clk),
    .O(clk_BUFGP_432)
  );
  INV   \U_freq_div_1000/Mcount_cnt_lut<0>_INV_0  (
    .I(\U_freq_div_1000/cnt [0]),
    .O(\U_freq_div_1000/Mcount_cnt_lut [0])
  );
  INV   \U_sec_1/U_freq_div_10/Mcount_cnt_lut<0>_INV_0  (
    .I(\U_sec_1/U_freq_div_10/cnt [0]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_lut [0])
  );
  INV   \U_h_1/U_freq_div_10/Mcount_cnt_lut<0>_INV_0  (
    .I(\U_h_1/U_freq_div_10/cnt [0]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_lut [0])
  );
  INV   \U_min_1/U_freq_div_10/Mcount_cnt_lut<0>_INV_0  (
    .I(\U_min_1/U_freq_div_10/cnt [0]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_lut [0])
  );
  INV   \U_sec_10/U_freq_div_10/Mcount_cnt_lut<0>_INV_0  (
    .I(\U_sec_10/U_freq_div_10/cnt [0]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_lut [0])
  );
  INV   \U_min_10/U_freq_div_10/Mcount_cnt_lut<0>_INV_0  (
    .I(\U_min_10/U_freq_div_10/cnt [0]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_lut [0])
  );
  INV   \U_sec_10/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_sec_10/U_freq_div_10/clk_div_N_415 ),
    .O(\U_sec_10/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_sec_10/U_cnt_digit_10/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .O(\Result<0>8 )
  );
  INV   \U_sec_1/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_sec_1/U_freq_div_10/clk_div_N_359 ),
    .O(\U_sec_1/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_sec_1/U_bcd_cnt/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_sec_1/U_bcd_cnt/cnt [0]),
    .O(\U_sec_1/U_bcd_cnt/Mcount_cnt )
  );
  INV   \U_min_10/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_min_10/U_freq_div_10/clk_div_N_299 ),
    .O(\U_min_10/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_min_10/U_cnt_digit_10/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_min_10/U_cnt_digit_10/cnt [0]),
    .O(\Result<0>7 )
  );
  INV   \U_min_1/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_min_1/U_freq_div_10/clk_div_N_249 ),
    .O(\U_min_1/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_min_1/U_bcd_cnt/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_min_1/U_bcd_cnt/cnt [0]),
    .O(\U_min_1/U_bcd_cnt/Mcount_cnt )
  );
  INV   \U_h_10/U_cnt_digit_10/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_h_10/U_cnt_digit_10/cnt [0]),
    .O(\Result<0>4 )
  );
  INV   \U_h_1/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_h_1/U_freq_div_10/clk_div_N_190 ),
    .O(\U_h_1/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_h_1/U_bcd_cnt/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_h_1/U_bcd_cnt/cnt [0]),
    .O(\U_h_1/U_bcd_cnt/Mcount_cnt )
  );
  INV   \U_freq_div_1000/clk_div_N_not00011_INV_0  (
    .I(\U_freq_div_1000/clk_div_N_136 ),
    .O(\U_freq_div_1000/clk_div_N_not0001 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_sec_10/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_sec_10/U_freq_div_10/cnt [1]),
    .I1(\U_sec_10/U_freq_div_10/cnt [0]),
    .I2(\U_sec_10/U_freq_div_10/cnt [2]),
    .I3(\U_sec_10/U_freq_div_10/cnt [3]),
    .LO(N29),
    .O(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_428 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_sec_10/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_sec_10/U_freq_div_10/cnt [4]),
    .I1(\U_sec_10/U_freq_div_10/cnt [5]),
    .LO(N30),
    .O(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_429 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_sec_10/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_sec_10/U_freq_div_10/cnt [6]),
    .I1(\U_sec_10/U_freq_div_10/cnt [7]),
    .I2(\U_sec_10/U_freq_div_10/cnt [8]),
    .I3(\U_sec_10/U_freq_div_10/cnt [9]),
    .LO(N31),
    .O(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_430 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_sec_1/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_sec_1/U_freq_div_10/cnt [2]),
    .I1(\U_sec_1/U_freq_div_10/cnt [3]),
    .I2(\U_sec_1/U_freq_div_10/cnt [0]),
    .I3(\U_sec_1/U_freq_div_10/cnt [1]),
    .LO(N32),
    .O(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_372 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_sec_1/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_sec_1/U_freq_div_10/cnt [4]),
    .I1(\U_sec_1/U_freq_div_10/cnt [5]),
    .LO(N33),
    .O(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_373 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_sec_1/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_sec_1/U_freq_div_10/cnt [6]),
    .I1(\U_sec_1/U_freq_div_10/cnt [7]),
    .I2(\U_sec_1/U_freq_div_10/cnt [8]),
    .I3(\U_sec_1/U_freq_div_10/cnt [9]),
    .LO(N34),
    .O(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_374 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_min_10/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_min_10/U_freq_div_10/cnt [1]),
    .I1(\U_min_10/U_freq_div_10/cnt [0]),
    .I2(\U_min_10/U_freq_div_10/cnt [2]),
    .I3(\U_min_10/U_freq_div_10/cnt [3]),
    .LO(N35),
    .O(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_312 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_min_10/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_min_10/U_freq_div_10/cnt [4]),
    .I1(\U_min_10/U_freq_div_10/cnt [5]),
    .LO(N36),
    .O(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_313 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_min_10/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_min_10/U_freq_div_10/cnt [6]),
    .I1(\U_min_10/U_freq_div_10/cnt [7]),
    .I2(\U_min_10/U_freq_div_10/cnt [8]),
    .I3(\U_min_10/U_freq_div_10/cnt [9]),
    .LO(N37),
    .O(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_314 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_min_1/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_min_1/U_freq_div_10/cnt [2]),
    .I1(\U_min_1/U_freq_div_10/cnt [3]),
    .I2(\U_min_1/U_freq_div_10/cnt [0]),
    .I3(\U_min_1/U_freq_div_10/cnt [1]),
    .LO(N38),
    .O(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_262 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_min_1/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_min_1/U_freq_div_10/cnt [4]),
    .I1(\U_min_1/U_freq_div_10/cnt [5]),
    .LO(N39),
    .O(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_263 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_min_1/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_min_1/U_freq_div_10/cnt [6]),
    .I1(\U_min_1/U_freq_div_10/cnt [7]),
    .I2(\U_min_1/U_freq_div_10/cnt [8]),
    .I3(\U_min_1/U_freq_div_10/cnt [9]),
    .LO(N40),
    .O(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_264 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_h_1/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_h_1/U_freq_div_10/cnt [2]),
    .I1(\U_h_1/U_freq_div_10/cnt [3]),
    .I2(\U_h_1/U_freq_div_10/cnt [0]),
    .I3(\U_h_1/U_freq_div_10/cnt [1]),
    .LO(N41),
    .O(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_203 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_h_1/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_h_1/U_freq_div_10/cnt [4]),
    .I1(\U_h_1/U_freq_div_10/cnt [5]),
    .LO(N42),
    .O(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_204 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_h_1/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_h_1/U_freq_div_10/cnt [6]),
    .I1(\U_h_1/U_freq_div_10/cnt [7]),
    .I2(\U_h_1/U_freq_div_10/cnt [8]),
    .I3(\U_h_1/U_freq_div_10/cnt [9]),
    .LO(N43),
    .O(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_205 )
  );
  LUT4_D #(
    .INIT ( 16'h2000 ))
  \U_freq_div_1000/cnt_cmp_eq00007  (
    .I0(\U_freq_div_1000/cnt [1]),
    .I1(\U_freq_div_1000/cnt [9]),
    .I2(\U_freq_div_1000/cnt [8]),
    .I3(\U_freq_div_1000/cnt [0]),
    .LO(N44),
    .O(\U_freq_div_1000/cnt_cmp_eq00007_151 )
  );
  LUT4_D #(
    .INIT ( 16'h8000 ))
  \U_freq_div_1000/cnt_cmp_eq000012  (
    .I0(\U_freq_div_1000/cnt [4]),
    .I1(\U_freq_div_1000/cnt [5]),
    .I2(\U_freq_div_1000/cnt [6]),
    .I3(\U_freq_div_1000/cnt [7]),
    .LO(N45),
    .O(\U_freq_div_1000/cnt_cmp_eq000012_149 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_freq_div_1000/cnt_cmp_eq000016  (
    .I0(\U_freq_div_1000/cnt [2]),
    .I1(\U_freq_div_1000/cnt [3]),
    .LO(N46),
    .O(\U_freq_div_1000/cnt_cmp_eq000016_150 )
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

