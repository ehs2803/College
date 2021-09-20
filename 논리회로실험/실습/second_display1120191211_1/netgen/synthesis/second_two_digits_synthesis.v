////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: second_two_digits_synthesis.v
// /___/   /\     Timestamp: Wed Dec 11 20:57:47 2019
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim second_two_digits.ngc second_two_digits_synthesis.v 
// Device	: xc3s1000-4-fg676
// Input file	: second_two_digits.ngc
// Output file	: D:\second_display1120191211_1\netgen\synthesis\second_two_digits_synthesis.v
// # of Modules	: 1
// Design Name	: second_two_digits
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

module second_two_digits (
  clk, rst, clk_min_1, seg_data, seg_com
);
  input clk;
  input rst;
  output clk_min_1;
  output [7 : 0] seg_data;
  output [7 : 0] seg_com;
  wire Mmux_seg_data_mux0000_3_f5_6;
  wire Mmux_seg_data_mux0000_3_f51;
  wire Mmux_seg_data_mux0000_3_f52;
  wire Mmux_seg_data_mux0000_3_f53;
  wire Mmux_seg_data_mux0000_3_f54;
  wire Mmux_seg_data_mux0000_3_f55;
  wire Mmux_seg_data_mux0000_3_f56;
  wire Mmux_seg_data_mux0000_3_f5_0_rt_7;
  wire Mmux_seg_data_mux0000_3_f5_1_rt_8;
  wire Mmux_seg_data_mux0000_3_f5_2_rt_9;
  wire Mmux_seg_data_mux0000_3_f5_3_rt_10;
  wire Mmux_seg_data_mux0000_3_f5_4_rt_11;
  wire Mmux_seg_data_mux0000_3_f5_5_rt_12;
  wire Mmux_seg_data_mux0000_3_f5_rt_13;
  wire Mmux_seg_data_mux0000_4_f5_14;
  wire Mmux_seg_data_mux0000_4_f51;
  wire Mmux_seg_data_mux0000_4_f52;
  wire Mmux_seg_data_mux0000_4_f53;
  wire Mmux_seg_data_mux0000_4_f54;
  wire Mmux_seg_data_mux0000_4_f55;
  wire Mmux_seg_data_mux0000_4_f56;
  wire Mmux_seg_data_mux0000_5_21;
  wire Mmux_seg_data_mux0000_51_22;
  wire Mmux_seg_data_mux0000_510_23;
  wire Mmux_seg_data_mux0000_511_24;
  wire Mmux_seg_data_mux0000_512_25;
  wire Mmux_seg_data_mux0000_513_26;
  wire Mmux_seg_data_mux0000_52_27;
  wire Mmux_seg_data_mux0000_53_28;
  wire Mmux_seg_data_mux0000_54_29;
  wire Mmux_seg_data_mux0000_55_30;
  wire Mmux_seg_data_mux0000_56_31;
  wire Mmux_seg_data_mux0000_57_32;
  wire Mmux_seg_data_mux0000_58_33;
  wire Mmux_seg_data_mux0000_59_34;
  wire Mmux_seg_data_mux0000_6_35;
  wire Mmux_seg_data_mux0000_61_36;
  wire Mmux_seg_data_mux0000_62_37;
  wire Mmux_seg_data_mux0000_63_38;
  wire Mmux_seg_data_mux0000_64_39;
  wire Mmux_seg_data_mux0000_65_40;
  wire Mmux_seg_data_mux0000_66_41;
  wire N0;
  wire N1;
  wire N44;
  wire N46;
  wire N47;
  wire N48;
  wire N49;
  wire N50;
  wire N51;
  wire N52;
  wire N53;
  wire N54;
  wire N55;
  wire N56;
  wire N57;
  wire N58;
  wire N59;
  wire N60;
  wire N61;
  wire N62;
  wire N63;
  wire \Result<0>2 ;
  wire \Result<0>3 ;
  wire \Result<0>4 ;
  wire \Result<0>5 ;
  wire \Result<0>6 ;
  wire \Result<1>1 ;
  wire \Result<1>2 ;
  wire \Result<1>3 ;
  wire \Result<1>4 ;
  wire \Result<1>5 ;
  wire \Result<1>6 ;
  wire \Result<2>1 ;
  wire \Result<2>2 ;
  wire \Result<2>3 ;
  wire \Result<2>4 ;
  wire \Result<2>5 ;
  wire \Result<2>6 ;
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
  wire \UD/U11/cnt2_133 ;
  wire \UD/U11/cnt2_not0001 ;
  wire \UD/U11/cnt2_not00011_135 ;
  wire \UD/U_bcd_to_seg_mod_10/Mrom_seg_data ;
  wire \UD/U_bcd_to_seg_mod_10/Mrom_seg_data1 ;
  wire \UD/U_bcd_to_seg_mod_10/Mrom_seg_data2 ;
  wire \UD/U_bcd_to_seg_mod_10/Mrom_seg_data3 ;
  wire \UD/U_bcd_to_seg_mod_10/Mrom_seg_data5 ;
  wire \UD/U_bcd_to_seg_mod_10/Mrom_seg_data6 ;
  wire \UD/U_freq_div_10/Mcount_cnt_cy<1>_rt_144 ;
  wire \UD/U_freq_div_10/Mcount_cnt_cy<2>_rt_146 ;
  wire \UD/U_freq_div_10/Mcount_cnt_cy<3>_rt_148 ;
  wire \UD/U_freq_div_10/Mcount_cnt_cy<4>_rt_150 ;
  wire \UD/U_freq_div_10/Mcount_cnt_cy<5>_rt_152 ;
  wire \UD/U_freq_div_10/Mcount_cnt_cy<6>_rt_154 ;
  wire \UD/U_freq_div_10/Mcount_cnt_cy<7>_rt_156 ;
  wire \UD/U_freq_div_10/Mcount_cnt_cy<8>_rt_158 ;
  wire \UD/U_freq_div_10/Mcount_cnt_eqn_0 ;
  wire \UD/U_freq_div_10/Mcount_cnt_eqn_1 ;
  wire \UD/U_freq_div_10/Mcount_cnt_eqn_2 ;
  wire \UD/U_freq_div_10/Mcount_cnt_eqn_3 ;
  wire \UD/U_freq_div_10/Mcount_cnt_eqn_4 ;
  wire \UD/U_freq_div_10/Mcount_cnt_eqn_5 ;
  wire \UD/U_freq_div_10/Mcount_cnt_eqn_6 ;
  wire \UD/U_freq_div_10/Mcount_cnt_eqn_7 ;
  wire \UD/U_freq_div_10/Mcount_cnt_eqn_8 ;
  wire \UD/U_freq_div_10/Mcount_cnt_eqn_9 ;
  wire \UD/U_freq_div_10/Mcount_cnt_xor<9>_rt_170 ;
  wire \UD/U_freq_div_10/clk_div_N_171 ;
  wire \UD/U_freq_div_10/clk_div_N_not0001 ;
  wire \UD/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \UD/U_freq_div_10/cnt_cmp_eq000011_184 ;
  wire \UD/U_freq_div_10/cnt_cmp_eq000015_185 ;
  wire \UD/U_freq_div_10/cnt_cmp_eq000036_186 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<1>_rt_189 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<2>_rt_191 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<3>_rt_193 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<4>_rt_195 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<5>_rt_197 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<6>_rt_199 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<7>_rt_201 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<8>_rt_203 ;
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
  wire \U_freq_div_1000/Mcount_cnt_xor<9>_rt_215 ;
  wire \U_freq_div_1000/clk_div_N_216 ;
  wire \U_freq_div_1000/clk_div_N_not0001 ;
  wire \U_freq_div_1000/cnt_cmp_eq0000 ;
  wire \U_freq_div_1000/cnt_cmp_eq000012_229 ;
  wire \U_freq_div_1000/cnt_cmp_eq000016_230 ;
  wire \U_freq_div_1000/cnt_cmp_eq00007_231 ;
  wire \U_min_1/U_bcd_cnt/Mcount_cnt ;
  wire \U_min_1/U_bcd_cnt/Mcount_cnt1 ;
  wire \U_min_1/U_bcd_cnt/Mcount_cnt2 ;
  wire \U_min_1/U_bcd_cnt/Mcount_cnt3 ;
  wire \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data ;
  wire \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data1 ;
  wire \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data2 ;
  wire \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data3 ;
  wire \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data4 ;
  wire \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data5 ;
  wire \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data6 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_249 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_251 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_253 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_255 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_257 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_259 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_261 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_263 ;
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
  wire \U_min_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_275 ;
  wire \U_min_1/U_freq_div_10/clk_div_N_276 ;
  wire \U_min_1/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_min_1/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_min_1/U_freq_div_10/cnt_cmp_eq000011_289 ;
  wire \U_min_1/U_freq_div_10/cnt_cmp_eq000015_290 ;
  wire \U_min_1/U_freq_div_10/cnt_cmp_eq000036_291 ;
  wire \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data ;
  wire \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data1 ;
  wire \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data2 ;
  wire \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data3 ;
  wire \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data4 ;
  wire \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data5 ;
  wire \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data6 ;
  wire \U_min_10/U_cnt_digit_10/Mcount_cnt ;
  wire \U_min_10/U_cnt_digit_10/Mcount_cnt1 ;
  wire \U_min_10/U_cnt_digit_10/Mcount_cnt2 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_307 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_309 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_311 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_313 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_315 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_317 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_319 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_321 ;
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
  wire \U_min_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_333 ;
  wire \U_min_10/U_freq_div_10/clk_div_N_334 ;
  wire \U_min_10/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_min_10/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_min_10/U_freq_div_10/cnt_cmp_eq000011_347 ;
  wire \U_min_10/U_freq_div_10/cnt_cmp_eq000015_348 ;
  wire \U_min_10/U_freq_div_10/cnt_cmp_eq000036_349 ;
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
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_367 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_369 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_371 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_373 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_375 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_377 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_379 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_381 ;
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
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_393 ;
  wire \U_sec_1/U_freq_div_10/clk_div_N_394 ;
  wire \U_sec_1/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_sec_1/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_sec_1/U_freq_div_10/cnt_cmp_eq000011_407 ;
  wire \U_sec_1/U_freq_div_10/cnt_cmp_eq000015_408 ;
  wire \U_sec_1/U_freq_div_10/cnt_cmp_eq000036_409 ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data1 ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data2 ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data3 ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data4 ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data5 ;
  wire \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data6 ;
  wire \U_sec_10/U_cnt_digit_10/Mcount_cnt ;
  wire \U_sec_10/U_cnt_digit_10/Mcount_cnt1 ;
  wire \U_sec_10/U_cnt_digit_10/Mcount_cnt2 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_425 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_427 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_429 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_431 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_433 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_435 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_437 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_439 ;
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
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_451 ;
  wire \U_sec_10/U_freq_div_10/clk_div_N_452 ;
  wire \U_sec_10/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_sec_10/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_sec_10/U_freq_div_10/cnt_cmp_eq000011_465 ;
  wire \U_sec_10/U_freq_div_10/cnt_cmp_eq000015_466 ;
  wire \U_sec_10/U_freq_div_10/cnt_cmp_eq000036_467 ;
  wire clk_BUFGP_469;
  wire rst_IBUF_472;
  wire seg_com_2_481;
  wire seg_com_3_482;
  wire seg_com_4_483;
  wire seg_com_5_484;
  wire seg_com_6_485;
  wire seg_com_7_486;
  wire seg_data_0_501;
  wire seg_data_1_502;
  wire seg_data_2_503;
  wire seg_data_3_504;
  wire seg_data_4_505;
  wire seg_data_5_506;
  wire seg_data_6_507;
  wire [9 : 0] Result;
  wire [3 : 0] \UD/U11/cnt1 ;
  wire [3 : 0] \UD/U11/cnt1_mux0000 ;
  wire [8 : 0] \UD/U_freq_div_10/Mcount_cnt_cy ;
  wire [0 : 0] \UD/U_freq_div_10/Mcount_cnt_lut ;
  wire [9 : 0] \UD/U_freq_div_10/cnt ;
  wire [8 : 0] \U_freq_div_1000/Mcount_cnt_cy ;
  wire [0 : 0] \U_freq_div_1000/Mcount_cnt_lut ;
  wire [9 : 0] \U_freq_div_1000/cnt ;
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
  GND   XST_GND (
    .G(N0)
  );
  VCC   XST_VCC (
    .P(N1)
  );
  FD   seg_com_2 (
    .C(clk_BUFGP_469),
    .D(seg_com_mux0000[5]),
    .Q(seg_com_2_481)
  );
  FD   seg_com_3 (
    .C(clk_BUFGP_469),
    .D(seg_com_mux0000[4]),
    .Q(seg_com_3_482)
  );
  FD   seg_com_4 (
    .C(clk_BUFGP_469),
    .D(seg_com_mux0000[3]),
    .Q(seg_com_4_483)
  );
  FD   seg_com_5 (
    .C(clk_BUFGP_469),
    .D(seg_com_mux0000[2]),
    .Q(seg_com_5_484)
  );
  FD   seg_com_6 (
    .C(clk_BUFGP_469),
    .D(seg_com_mux0000[1]),
    .Q(seg_com_6_485)
  );
  FD   seg_com_7 (
    .C(clk_BUFGP_469),
    .D(seg_com_mux0000[0]),
    .Q(seg_com_7_486)
  );
  FD   seg_data_0 (
    .C(clk_BUFGP_469),
    .D(seg_data_mux0000[0]),
    .Q(seg_data_0_501)
  );
  FD   seg_data_1 (
    .C(clk_BUFGP_469),
    .D(seg_data_mux0000[1]),
    .Q(seg_data_1_502)
  );
  FD   seg_data_2 (
    .C(clk_BUFGP_469),
    .D(seg_data_mux0000[2]),
    .Q(seg_data_2_503)
  );
  FD   seg_data_3 (
    .C(clk_BUFGP_469),
    .D(seg_data_mux0000[3]),
    .Q(seg_data_3_504)
  );
  FD   seg_data_4 (
    .C(clk_BUFGP_469),
    .D(seg_data_mux0000[4]),
    .Q(seg_data_4_505)
  );
  FD   seg_data_5 (
    .C(clk_BUFGP_469),
    .D(seg_data_mux0000[5]),
    .Q(seg_data_5_506)
  );
  FD   seg_data_6 (
    .C(clk_BUFGP_469),
    .D(seg_data_mux0000[6]),
    .Q(seg_data_6_507)
  );
  FDPE   \U_freq_div_1000/clk_div_N  (
    .C(clk_BUFGP_469),
    .CE(\U_freq_div_1000/cnt_cmp_eq0000 ),
    .D(\U_freq_div_1000/clk_div_N_not0001 ),
    .PRE(rst_IBUF_472),
    .Q(\U_freq_div_1000/clk_div_N_216 )
  );
  FDPE   \U_min_1/U_freq_div_10/clk_div_N  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CE(\U_min_1/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_min_1/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_472),
    .Q(\U_min_1/U_freq_div_10/clk_div_N_276 )
  );
  FDPE   \U_sec_1/U_freq_div_10/clk_div_N  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CE(\U_sec_1/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_sec_1/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_472),
    .Q(\U_sec_1/U_freq_div_10/clk_div_N_394 )
  );
  FDPE   \U_min_10/U_freq_div_10/clk_div_N  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CE(\U_min_10/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_min_10/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_472),
    .Q(\U_min_10/U_freq_div_10/clk_div_N_334 )
  );
  FDPE   \U_sec_10/U_freq_div_10/clk_div_N  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CE(\U_sec_10/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_sec_10/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_472),
    .Q(\U_sec_10/U_freq_div_10/clk_div_N_452 )
  );
  FDPE   \UD/U_freq_div_10/clk_div_N  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CE(\UD/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\UD/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_472),
    .Q(\UD/U_freq_div_10/clk_div_N_171 )
  );
  FDC   \U_freq_div_1000/cnt_0  (
    .C(clk_BUFGP_469),
    .CLR(rst_IBUF_472),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_0 ),
    .Q(\U_freq_div_1000/cnt [0])
  );
  FDC   \U_freq_div_1000/cnt_1  (
    .C(clk_BUFGP_469),
    .CLR(rst_IBUF_472),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_1 ),
    .Q(\U_freq_div_1000/cnt [1])
  );
  FDC   \U_freq_div_1000/cnt_2  (
    .C(clk_BUFGP_469),
    .CLR(rst_IBUF_472),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_2 ),
    .Q(\U_freq_div_1000/cnt [2])
  );
  FDC   \U_freq_div_1000/cnt_3  (
    .C(clk_BUFGP_469),
    .CLR(rst_IBUF_472),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_3 ),
    .Q(\U_freq_div_1000/cnt [3])
  );
  FDC   \U_freq_div_1000/cnt_4  (
    .C(clk_BUFGP_469),
    .CLR(rst_IBUF_472),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_4 ),
    .Q(\U_freq_div_1000/cnt [4])
  );
  FDC   \U_freq_div_1000/cnt_5  (
    .C(clk_BUFGP_469),
    .CLR(rst_IBUF_472),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_5 ),
    .Q(\U_freq_div_1000/cnt [5])
  );
  FDC   \U_freq_div_1000/cnt_6  (
    .C(clk_BUFGP_469),
    .CLR(rst_IBUF_472),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_6 ),
    .Q(\U_freq_div_1000/cnt [6])
  );
  FDC   \U_freq_div_1000/cnt_7  (
    .C(clk_BUFGP_469),
    .CLR(rst_IBUF_472),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_7 ),
    .Q(\U_freq_div_1000/cnt [7])
  );
  FDC   \U_freq_div_1000/cnt_8  (
    .C(clk_BUFGP_469),
    .CLR(rst_IBUF_472),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_8 ),
    .Q(\U_freq_div_1000/cnt [8])
  );
  FDC   \U_freq_div_1000/cnt_9  (
    .C(clk_BUFGP_469),
    .CLR(rst_IBUF_472),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_9 ),
    .Q(\U_freq_div_1000/cnt [9])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_0  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_min_1/U_freq_div_10/cnt [0])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_1  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_min_1/U_freq_div_10/cnt [1])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_2  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_min_1/U_freq_div_10/cnt [2])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_3  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_min_1/U_freq_div_10/cnt [3])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_4  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_min_1/U_freq_div_10/cnt [4])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_5  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_min_1/U_freq_div_10/cnt [5])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_6  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_min_1/U_freq_div_10/cnt [6])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_7  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_min_1/U_freq_div_10/cnt [7])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_8  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_min_1/U_freq_div_10/cnt [8])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_9  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_min_1/U_freq_div_10/cnt [9])
  );
  FDC   \U_min_1/U_bcd_cnt/cnt_0  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_bcd_cnt/Mcount_cnt ),
    .Q(\U_min_1/U_bcd_cnt/cnt [0])
  );
  FDC   \U_min_1/U_bcd_cnt/cnt_1  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_bcd_cnt/Mcount_cnt1 ),
    .Q(\U_min_1/U_bcd_cnt/cnt [1])
  );
  FDC   \U_min_1/U_bcd_cnt/cnt_2  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_bcd_cnt/Mcount_cnt2 ),
    .Q(\U_min_1/U_bcd_cnt/cnt [2])
  );
  FDC   \U_min_1/U_bcd_cnt/cnt_3  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_1/U_bcd_cnt/Mcount_cnt3 ),
    .Q(\U_min_1/U_bcd_cnt/cnt [3])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_0  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [0])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_1  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [1])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_2  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [2])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_3  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [3])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_4  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [4])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_5  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [5])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_6  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [6])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_7  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [7])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_8  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [8])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_9  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [9])
  );
  FDC   \U_sec_1/U_bcd_cnt/cnt_0  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_bcd_cnt/Mcount_cnt ),
    .Q(\U_sec_1/U_bcd_cnt/cnt [0])
  );
  FDC   \U_sec_1/U_bcd_cnt/cnt_1  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_bcd_cnt/Mcount_cnt1 ),
    .Q(\U_sec_1/U_bcd_cnt/cnt [1])
  );
  FDC   \U_sec_1/U_bcd_cnt/cnt_2  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_bcd_cnt/Mcount_cnt2 ),
    .Q(\U_sec_1/U_bcd_cnt/cnt [2])
  );
  FDC   \U_sec_1/U_bcd_cnt/cnt_3  (
    .C(\U_freq_div_1000/clk_div_N_216 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_1/U_bcd_cnt/Mcount_cnt3 ),
    .Q(\U_sec_1/U_bcd_cnt/cnt [3])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_0  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_min_10/U_freq_div_10/cnt [0])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_1  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_min_10/U_freq_div_10/cnt [1])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_2  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_min_10/U_freq_div_10/cnt [2])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_3  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_min_10/U_freq_div_10/cnt [3])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_4  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_min_10/U_freq_div_10/cnt [4])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_5  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_min_10/U_freq_div_10/cnt [5])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_6  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_min_10/U_freq_div_10/cnt [6])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_7  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_min_10/U_freq_div_10/cnt [7])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_8  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_min_10/U_freq_div_10/cnt [8])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_9  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_min_10/U_freq_div_10/cnt [9])
  );
  FDC   \U_sec_10/U_cnt_digit_10/cnt_0  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_10/U_cnt_digit_10/Mcount_cnt ),
    .Q(\U_sec_10/U_cnt_digit_10/cnt [0])
  );
  FDC   \U_sec_10/U_cnt_digit_10/cnt_1  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_10/U_cnt_digit_10/Mcount_cnt1 ),
    .Q(\U_sec_10/U_cnt_digit_10/cnt [1])
  );
  FDC   \U_sec_10/U_cnt_digit_10/cnt_2  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_10/U_cnt_digit_10/Mcount_cnt2 ),
    .Q(\U_sec_10/U_cnt_digit_10/cnt [2])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_0  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [0])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_1  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [1])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_2  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [2])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_3  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [3])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_4  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [4])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_5  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [5])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_6  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [6])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_7  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [7])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_8  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [8])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_9  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .CLR(rst_IBUF_472),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [9])
  );
  FDC   \U_min_10/U_cnt_digit_10/cnt_0  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_10/U_cnt_digit_10/Mcount_cnt ),
    .Q(\U_min_10/U_cnt_digit_10/cnt [0])
  );
  FDC   \U_min_10/U_cnt_digit_10/cnt_1  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_10/U_cnt_digit_10/Mcount_cnt1 ),
    .Q(\U_min_10/U_cnt_digit_10/cnt [1])
  );
  FDC   \U_min_10/U_cnt_digit_10/cnt_2  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .CLR(rst_IBUF_472),
    .D(\U_min_10/U_cnt_digit_10/Mcount_cnt2 ),
    .Q(\U_min_10/U_cnt_digit_10/cnt [2])
  );
  FDC   \UD/U_freq_div_10/cnt_0  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\UD/U_freq_div_10/cnt [0])
  );
  FDC   \UD/U_freq_div_10/cnt_1  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\UD/U_freq_div_10/cnt [1])
  );
  FDC   \UD/U_freq_div_10/cnt_2  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\UD/U_freq_div_10/cnt [2])
  );
  FDC   \UD/U_freq_div_10/cnt_3  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\UD/U_freq_div_10/cnt [3])
  );
  FDC   \UD/U_freq_div_10/cnt_4  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\UD/U_freq_div_10/cnt [4])
  );
  FDC   \UD/U_freq_div_10/cnt_5  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\UD/U_freq_div_10/cnt [5])
  );
  FDC   \UD/U_freq_div_10/cnt_6  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\UD/U_freq_div_10/cnt [6])
  );
  FDC   \UD/U_freq_div_10/cnt_7  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\UD/U_freq_div_10/cnt [7])
  );
  FDC   \UD/U_freq_div_10/cnt_8  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\UD/U_freq_div_10/cnt [8])
  );
  FDC   \UD/U_freq_div_10/cnt_9  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\UD/U_freq_div_10/cnt [9])
  );
  FD   ten_or_one_1 (
    .C(clk_BUFGP_469),
    .D(\Result<1>1 ),
    .Q(ten_or_one[1])
  );
  FD   ten_or_one_2 (
    .C(clk_BUFGP_469),
    .D(\Result<2>1 ),
    .Q(ten_or_one[2])
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
    .S(\U_freq_div_1000/Mcount_cnt_cy<1>_rt_189 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [1])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<1>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [0]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<1>_rt_189 ),
    .O(Result[1])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<2>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<2>_rt_191 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [2])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<2>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [1]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<2>_rt_191 ),
    .O(Result[2])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<3>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<3>_rt_193 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [3])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<3>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [2]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<3>_rt_193 ),
    .O(Result[3])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<4>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<4>_rt_195 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [4])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<4>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [3]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<4>_rt_195 ),
    .O(Result[4])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<5>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<5>_rt_197 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [5])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<5>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [4]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<5>_rt_197 ),
    .O(Result[5])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<6>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<6>_rt_199 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [6])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<6>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [5]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<6>_rt_199 ),
    .O(Result[6])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<7>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<7>_rt_201 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [7])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<7>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [6]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<7>_rt_201 ),
    .O(Result[7])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<8>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<8>_rt_203 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [8])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<8>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [7]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<8>_rt_203 ),
    .O(Result[8])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<9>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [8]),
    .LI(\U_freq_div_1000/Mcount_cnt_xor<9>_rt_215 ),
    .O(Result[9])
  );
  MUXF6   Mmux_seg_data_mux0000_2_f6_5 (
    .I0(Mmux_seg_data_mux0000_4_f56),
    .I1(Mmux_seg_data_mux0000_3_f56),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[6])
  );
  MUXF5   Mmux_seg_data_mux0000_4_f5_5 (
    .I0(Mmux_seg_data_mux0000_66_41),
    .I1(Mmux_seg_data_mux0000_513_26),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_4_f56)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_66 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data6 ),
    .I2(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data6 ),
    .O(Mmux_seg_data_mux0000_66_41)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_513 (
    .I0(ten_or_one[0]),
    .I1(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data6 ),
    .I2(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data6 ),
    .O(Mmux_seg_data_mux0000_513_26)
  );
  MUXF5   Mmux_seg_data_mux0000_3_f5_5 (
    .I0(Mmux_seg_data_mux0000_512_25),
    .I1(Mmux_seg_data_mux0000_3_f5_5_rt_12),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_3_f56)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_512 (
    .I0(ten_or_one[0]),
    .I1(\UD/U_bcd_to_seg_mod_10/Mrom_seg_data6 ),
    .I2(N0),
    .O(Mmux_seg_data_mux0000_512_25)
  );
  MUXF6   Mmux_seg_data_mux0000_2_f6_4 (
    .I0(Mmux_seg_data_mux0000_4_f55),
    .I1(Mmux_seg_data_mux0000_3_f55),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[5])
  );
  MUXF5   Mmux_seg_data_mux0000_4_f5_4 (
    .I0(Mmux_seg_data_mux0000_65_40),
    .I1(Mmux_seg_data_mux0000_511_24),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_4_f55)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_65 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data5 ),
    .I2(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data5 ),
    .O(Mmux_seg_data_mux0000_65_40)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_511 (
    .I0(ten_or_one[0]),
    .I1(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data5 ),
    .I2(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data5 ),
    .O(Mmux_seg_data_mux0000_511_24)
  );
  MUXF5   Mmux_seg_data_mux0000_3_f5_4 (
    .I0(Mmux_seg_data_mux0000_510_23),
    .I1(Mmux_seg_data_mux0000_3_f5_4_rt_11),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_3_f55)
  );
  MUXF6   Mmux_seg_data_mux0000_2_f6_3 (
    .I0(Mmux_seg_data_mux0000_4_f54),
    .I1(Mmux_seg_data_mux0000_3_f54),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[4])
  );
  MUXF5   Mmux_seg_data_mux0000_4_f5_3 (
    .I0(Mmux_seg_data_mux0000_64_39),
    .I1(Mmux_seg_data_mux0000_59_34),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_4_f54)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_64 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data4 ),
    .I2(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data4 ),
    .O(Mmux_seg_data_mux0000_64_39)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_59 (
    .I0(ten_or_one[0]),
    .I1(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data4 ),
    .I2(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data4 ),
    .O(Mmux_seg_data_mux0000_59_34)
  );
  MUXF5   Mmux_seg_data_mux0000_3_f5_3 (
    .I0(Mmux_seg_data_mux0000_58_33),
    .I1(Mmux_seg_data_mux0000_3_f5_3_rt_10),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_3_f54)
  );
  MUXF6   Mmux_seg_data_mux0000_2_f6_2 (
    .I0(Mmux_seg_data_mux0000_4_f53),
    .I1(Mmux_seg_data_mux0000_3_f53),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[3])
  );
  MUXF5   Mmux_seg_data_mux0000_4_f5_2 (
    .I0(Mmux_seg_data_mux0000_63_38),
    .I1(Mmux_seg_data_mux0000_57_32),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_4_f53)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_63 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data3 ),
    .I2(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data3 ),
    .O(Mmux_seg_data_mux0000_63_38)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_57 (
    .I0(ten_or_one[0]),
    .I1(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data3 ),
    .I2(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data3 ),
    .O(Mmux_seg_data_mux0000_57_32)
  );
  MUXF5   Mmux_seg_data_mux0000_3_f5_2 (
    .I0(Mmux_seg_data_mux0000_56_31),
    .I1(Mmux_seg_data_mux0000_3_f5_2_rt_9),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_3_f53)
  );
  MUXF6   Mmux_seg_data_mux0000_2_f6_1 (
    .I0(Mmux_seg_data_mux0000_4_f52),
    .I1(Mmux_seg_data_mux0000_3_f52),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[2])
  );
  MUXF5   Mmux_seg_data_mux0000_4_f5_1 (
    .I0(Mmux_seg_data_mux0000_62_37),
    .I1(Mmux_seg_data_mux0000_55_30),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_4_f52)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_62 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data2 ),
    .I2(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data2 ),
    .O(Mmux_seg_data_mux0000_62_37)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_55 (
    .I0(ten_or_one[0]),
    .I1(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data2 ),
    .I2(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data2 ),
    .O(Mmux_seg_data_mux0000_55_30)
  );
  MUXF5   Mmux_seg_data_mux0000_3_f5_1 (
    .I0(Mmux_seg_data_mux0000_54_29),
    .I1(Mmux_seg_data_mux0000_3_f5_1_rt_8),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_3_f52)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_54 (
    .I0(ten_or_one[0]),
    .I1(\UD/U_bcd_to_seg_mod_10/Mrom_seg_data2 ),
    .I2(N1),
    .O(Mmux_seg_data_mux0000_54_29)
  );
  MUXF6   Mmux_seg_data_mux0000_2_f6_0 (
    .I0(Mmux_seg_data_mux0000_4_f51),
    .I1(Mmux_seg_data_mux0000_3_f51),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[1])
  );
  MUXF5   Mmux_seg_data_mux0000_4_f5_0 (
    .I0(Mmux_seg_data_mux0000_61_36),
    .I1(Mmux_seg_data_mux0000_53_28),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_4_f51)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_61 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data1 ),
    .I2(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data1 ),
    .O(Mmux_seg_data_mux0000_61_36)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_53 (
    .I0(ten_or_one[0]),
    .I1(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data1 ),
    .I2(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data1 ),
    .O(Mmux_seg_data_mux0000_53_28)
  );
  MUXF5   Mmux_seg_data_mux0000_3_f5_0 (
    .I0(Mmux_seg_data_mux0000_52_27),
    .I1(Mmux_seg_data_mux0000_3_f5_0_rt_7),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_3_f51)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_52 (
    .I0(ten_or_one[0]),
    .I1(\UD/U_bcd_to_seg_mod_10/Mrom_seg_data1 ),
    .I2(N1),
    .O(Mmux_seg_data_mux0000_52_27)
  );
  MUXF6   Mmux_seg_data_mux0000_2_f6 (
    .I0(Mmux_seg_data_mux0000_4_f5_14),
    .I1(Mmux_seg_data_mux0000_3_f5_6),
    .S(ten_or_one[2]),
    .O(seg_data_mux0000[0])
  );
  MUXF5   Mmux_seg_data_mux0000_4_f5 (
    .I0(Mmux_seg_data_mux0000_6_35),
    .I1(Mmux_seg_data_mux0000_51_22),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_4_f5_14)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_6 (
    .I0(ten_or_one[0]),
    .I1(\U_sec_1/U_bcd_to_seg_mod/Mrom_seg_data ),
    .I2(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data ),
    .O(Mmux_seg_data_mux0000_6_35)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_51 (
    .I0(ten_or_one[0]),
    .I1(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data ),
    .I2(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data ),
    .O(Mmux_seg_data_mux0000_51_22)
  );
  MUXF5   Mmux_seg_data_mux0000_3_f5 (
    .I0(Mmux_seg_data_mux0000_5_21),
    .I1(Mmux_seg_data_mux0000_3_f5_rt_13),
    .S(ten_or_one[1]),
    .O(Mmux_seg_data_mux0000_3_f5_6)
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
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_249 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_249 ),
    .O(\Result<1>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_251 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_251 ),
    .O(\Result<2>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_253 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_253 ),
    .O(\Result<3>1 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_255 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_255 ),
    .O(\Result<4>1 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_257 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_257 ),
    .O(\Result<5>1 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_259 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_259 ),
    .O(\Result<6>1 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_261 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_261 ),
    .O(\Result<7>1 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_263 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_263 ),
    .O(\Result<8>1 )
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_275 ),
    .O(\Result<9>1 )
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
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_367 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_367 ),
    .O(\Result<1>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_369 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_369 ),
    .O(\Result<2>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_371 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_371 ),
    .O(\Result<3>2 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_373 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_373 ),
    .O(\Result<4>2 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_375 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_375 ),
    .O(\Result<5>2 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_377 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_377 ),
    .O(\Result<6>2 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_379 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_379 ),
    .O(\Result<7>2 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_381 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_381 ),
    .O(\Result<8>2 )
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_393 ),
    .O(\Result<9>2 )
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
    .O(\Result<0>4 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<1>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [0]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_307 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_307 ),
    .O(\Result<1>4 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_309 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_309 ),
    .O(\Result<2>4 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_311 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_311 ),
    .O(\Result<3>3 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_313 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_313 ),
    .O(\Result<4>3 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_315 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_315 ),
    .O(\Result<5>3 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_317 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_317 ),
    .O(\Result<6>3 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_319 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_319 ),
    .O(\Result<7>3 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_321 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_321 ),
    .O(\Result<8>3 )
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_333 ),
    .O(\Result<9>3 )
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
    .O(\Result<0>5 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [0]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_425 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_425 ),
    .O(\Result<1>5 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_427 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_427 ),
    .O(\Result<2>5 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_429 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_429 ),
    .O(\Result<3>4 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_431 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_431 ),
    .O(\Result<4>4 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_433 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_433 ),
    .O(\Result<5>4 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_435 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_435 ),
    .O(\Result<6>4 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_437 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_437 ),
    .O(\Result<7>4 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_439 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_439 ),
    .O(\Result<8>4 )
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_451 ),
    .O(\Result<9>4 )
  );
  MUXCY   \UD/U_freq_div_10/Mcount_cnt_cy<0>  (
    .CI(N0),
    .DI(N1),
    .S(\UD/U_freq_div_10/Mcount_cnt_lut [0]),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy [0])
  );
  XORCY   \UD/U_freq_div_10/Mcount_cnt_xor<0>  (
    .CI(N0),
    .LI(\UD/U_freq_div_10/Mcount_cnt_lut [0]),
    .O(\Result<0>6 )
  );
  MUXCY   \UD/U_freq_div_10/Mcount_cnt_cy<1>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [0]),
    .DI(N0),
    .S(\UD/U_freq_div_10/Mcount_cnt_cy<1>_rt_144 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \UD/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\UD/U_freq_div_10/Mcount_cnt_cy<1>_rt_144 ),
    .O(\Result<1>6 )
  );
  MUXCY   \UD/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\UD/U_freq_div_10/Mcount_cnt_cy<2>_rt_146 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \UD/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\UD/U_freq_div_10/Mcount_cnt_cy<2>_rt_146 ),
    .O(\Result<2>6 )
  );
  MUXCY   \UD/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\UD/U_freq_div_10/Mcount_cnt_cy<3>_rt_148 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \UD/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\UD/U_freq_div_10/Mcount_cnt_cy<3>_rt_148 ),
    .O(\Result<3>5 )
  );
  MUXCY   \UD/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\UD/U_freq_div_10/Mcount_cnt_cy<4>_rt_150 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \UD/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\UD/U_freq_div_10/Mcount_cnt_cy<4>_rt_150 ),
    .O(\Result<4>5 )
  );
  MUXCY   \UD/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\UD/U_freq_div_10/Mcount_cnt_cy<5>_rt_152 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \UD/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\UD/U_freq_div_10/Mcount_cnt_cy<5>_rt_152 ),
    .O(\Result<5>5 )
  );
  MUXCY   \UD/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\UD/U_freq_div_10/Mcount_cnt_cy<6>_rt_154 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \UD/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\UD/U_freq_div_10/Mcount_cnt_cy<6>_rt_154 ),
    .O(\Result<6>5 )
  );
  MUXCY   \UD/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\UD/U_freq_div_10/Mcount_cnt_cy<7>_rt_156 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \UD/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\UD/U_freq_div_10/Mcount_cnt_cy<7>_rt_156 ),
    .O(\Result<7>5 )
  );
  MUXCY   \UD/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\UD/U_freq_div_10/Mcount_cnt_cy<8>_rt_158 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \UD/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\UD/U_freq_div_10/Mcount_cnt_cy<8>_rt_158 ),
    .O(\Result<8>5 )
  );
  XORCY   \UD/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\UD/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\UD/U_freq_div_10/Mcount_cnt_xor<9>_rt_170 ),
    .O(\Result<9>5 )
  );
  FDC   \UD/U11/cnt1_3  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U11/cnt1_mux0000 [0]),
    .Q(\UD/U11/cnt1 [3])
  );
  FDC   \UD/U11/cnt1_2  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U11/cnt1_mux0000 [1]),
    .Q(\UD/U11/cnt1 [2])
  );
  FDC   \UD/U11/cnt1_1  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U11/cnt1_mux0000 [2]),
    .Q(\UD/U11/cnt1 [1])
  );
  FDC   \UD/U11/cnt1_0  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .CLR(rst_IBUF_472),
    .D(\UD/U11/cnt1_mux0000 [3]),
    .Q(\UD/U11/cnt1 [0])
  );
  FDCE   \UD/U11/cnt2  (
    .C(\UD/U_freq_div_10/clk_div_N_171 ),
    .CE(\UD/U11/cnt2_not0001 ),
    .CLR(rst_IBUF_472),
    .D(N1),
    .Q(\UD/U11/cnt2_133 )
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
    .INIT ( 8'h51 ))
  \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data41  (
    .I0(\U_min_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_min_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_min_10/U_cnt_digit_10/cnt [1]),
    .O(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data4 )
  );
  LUT3 #(
    .INIT ( 8'hFD ))
  \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data21  (
    .I0(\U_min_10/U_cnt_digit_10/cnt [1]),
    .I1(\U_min_10/U_cnt_digit_10/cnt [0]),
    .I2(\U_min_10/U_cnt_digit_10/cnt [2]),
    .O(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data2 )
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
    .INIT ( 8'h9F ))
  \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data111  (
    .I0(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .I2(\U_sec_10/U_cnt_digit_10/cnt [2]),
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
    .INIT ( 8'h7A ))
  \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data61  (
    .I0(\U_min_10/U_cnt_digit_10/cnt [2]),
    .I1(\U_min_10/U_cnt_digit_10/cnt [0]),
    .I2(\U_min_10/U_cnt_digit_10/cnt [1]),
    .O(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data6 )
  );
  LUT3 #(
    .INIT ( 8'h2B ))
  \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data51  (
    .I0(\U_min_10/U_cnt_digit_10/cnt [2]),
    .I1(\U_min_10/U_cnt_digit_10/cnt [0]),
    .I2(\U_min_10/U_cnt_digit_10/cnt [1]),
    .O(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data5 )
  );
  LUT3 #(
    .INIT ( 8'h9F ))
  \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data111  (
    .I0(\U_min_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_min_10/U_cnt_digit_10/cnt [1]),
    .I2(\U_min_10/U_cnt_digit_10/cnt [2]),
    .O(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data1 )
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
    .INIT ( 8'h79 ))
  \U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data31  (
    .I0(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .O(\U_sec_10/U_bcd_to_seg_mod_10/Mrom_seg_data3 )
  );
  LUT3 #(
    .INIT ( 8'h79 ))
  \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data31  (
    .I0(\U_min_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_min_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_min_10/U_cnt_digit_10/cnt [1]),
    .O(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data3 )
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
    .INIT ( 16'h0145 ))
  \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data41  (
    .I0(\U_min_1/U_bcd_cnt/cnt [0]),
    .I1(\U_min_1/U_bcd_cnt/cnt [1]),
    .I2(\U_min_1/U_bcd_cnt/cnt [2]),
    .I3(\U_min_1/U_bcd_cnt/cnt [3]),
    .O(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data4 )
  );
  LUT4 #(
    .INIT ( 16'h545F ))
  \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data21  (
    .I0(\U_min_1/U_bcd_cnt/cnt [3]),
    .I1(\U_min_1/U_bcd_cnt/cnt [0]),
    .I2(\U_min_1/U_bcd_cnt/cnt [2]),
    .I3(\U_min_1/U_bcd_cnt/cnt [1]),
    .O(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data2 )
  );
  LUT4 #(
    .INIT ( 16'h545F ))
  \UD/U_bcd_to_seg_mod_10/Mrom_seg_data21  (
    .I0(\UD/U11/cnt1 [3]),
    .I1(\UD/U11/cnt1 [0]),
    .I2(\UD/U11/cnt1 [2]),
    .I3(\UD/U11/cnt1 [1]),
    .O(\UD/U_bcd_to_seg_mod_10/Mrom_seg_data2 )
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
    .INIT ( 16'h2177 ))
  \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data111  (
    .I0(\U_min_1/U_bcd_cnt/cnt [1]),
    .I1(\U_min_1/U_bcd_cnt/cnt [3]),
    .I2(\U_min_1/U_bcd_cnt/cnt [0]),
    .I3(\U_min_1/U_bcd_cnt/cnt [2]),
    .O(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data1 )
  );
  LUT4 #(
    .INIT ( 16'h2177 ))
  \UD/U_bcd_to_seg_mod_10/Mrom_seg_data111  (
    .I0(\UD/U11/cnt1 [1]),
    .I1(\UD/U11/cnt1 [3]),
    .I2(\UD/U11/cnt1 [0]),
    .I3(\UD/U11/cnt1 [2]),
    .O(\UD/U_bcd_to_seg_mod_10/Mrom_seg_data1 )
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
    .INIT ( 16'h1656 ))
  \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data61  (
    .I0(\U_min_1/U_bcd_cnt/cnt [3]),
    .I1(\U_min_1/U_bcd_cnt/cnt [2]),
    .I2(\U_min_1/U_bcd_cnt/cnt [1]),
    .I3(\U_min_1/U_bcd_cnt/cnt [0]),
    .O(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data6 )
  );
  LUT4 #(
    .INIT ( 16'h150B ))
  \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data51  (
    .I0(\U_min_1/U_bcd_cnt/cnt [3]),
    .I1(\U_min_1/U_bcd_cnt/cnt [0]),
    .I2(\U_min_1/U_bcd_cnt/cnt [1]),
    .I3(\U_min_1/U_bcd_cnt/cnt [2]),
    .O(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data5 )
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
    .INIT ( 16'h1656 ))
  \UD/U_bcd_to_seg_mod_10/Mrom_seg_data61  (
    .I0(\UD/U11/cnt1 [3]),
    .I1(\UD/U11/cnt1 [2]),
    .I2(\UD/U11/cnt1 [1]),
    .I3(\UD/U11/cnt1 [0]),
    .O(\UD/U_bcd_to_seg_mod_10/Mrom_seg_data6 )
  );
  LUT4 #(
    .INIT ( 16'h150B ))
  \UD/U_bcd_to_seg_mod_10/Mrom_seg_data51  (
    .I0(\UD/U11/cnt1 [3]),
    .I1(\UD/U11/cnt1 [0]),
    .I2(\UD/U11/cnt1 [1]),
    .I3(\UD/U11/cnt1 [2]),
    .O(\UD/U_bcd_to_seg_mod_10/Mrom_seg_data5 )
  );
  LUT4 #(
    .INIT ( 16'h5563 ))
  \UD/U_bcd_to_seg_mod_10/Mrom_seg_data11  (
    .I0(\UD/U11/cnt1 [3]),
    .I1(\UD/U11/cnt1 [2]),
    .I2(\UD/U11/cnt1 [0]),
    .I3(\UD/U11/cnt1 [1]),
    .O(\UD/U_bcd_to_seg_mod_10/Mrom_seg_data )
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
  LUT4 #(
    .INIT ( 16'h1447 ))
  \U_min_1/U_bcd_to_seg_mod/Mrom_seg_data31  (
    .I0(\U_min_1/U_bcd_cnt/cnt [3]),
    .I1(\U_min_1/U_bcd_cnt/cnt [1]),
    .I2(\U_min_1/U_bcd_cnt/cnt [0]),
    .I3(\U_min_1/U_bcd_cnt/cnt [2]),
    .O(\U_min_1/U_bcd_to_seg_mod/Mrom_seg_data3 )
  );
  LUT4 #(
    .INIT ( 16'h1447 ))
  \UD/U_bcd_to_seg_mod_10/Mrom_seg_data31  (
    .I0(\UD/U11/cnt1 [3]),
    .I1(\UD/U11/cnt1 [1]),
    .I2(\UD/U11/cnt1 [0]),
    .I3(\UD/U11/cnt1 [2]),
    .O(\UD/U_bcd_to_seg_mod_10/Mrom_seg_data3 )
  );
  LUT2 #(
    .INIT ( 4'h6 ))
  \Mcount_ten_or_one_xor<1>11  (
    .I0(ten_or_one[1]),
    .I1(ten_or_one[0]),
    .O(\Result<1>1 )
  );
  LUT3 #(
    .INIT ( 8'h62 ))
  \U_sec_10/U_cnt_digit_10/Mcount_cnt_xor<2>11  (
    .I0(\U_sec_10/U_cnt_digit_10/cnt [2]),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .I2(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .O(\U_sec_10/U_cnt_digit_10/Mcount_cnt2 )
  );
  LUT3 #(
    .INIT ( 8'h26 ))
  \U_sec_10/U_cnt_digit_10/Mcount_cnt_xor<1>11  (
    .I0(\U_sec_10/U_cnt_digit_10/cnt [1]),
    .I1(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .I2(\U_sec_10/U_cnt_digit_10/cnt [2]),
    .O(\U_sec_10/U_cnt_digit_10/Mcount_cnt1 )
  );
  LUT3 #(
    .INIT ( 8'h62 ))
  \U_min_10/U_cnt_digit_10/Mcount_cnt_xor<2>11  (
    .I0(\U_min_10/U_cnt_digit_10/cnt [2]),
    .I1(\U_min_10/U_cnt_digit_10/cnt [0]),
    .I2(\U_min_10/U_cnt_digit_10/cnt [1]),
    .O(\U_min_10/U_cnt_digit_10/Mcount_cnt2 )
  );
  LUT3 #(
    .INIT ( 8'h26 ))
  \U_min_10/U_cnt_digit_10/Mcount_cnt_xor<1>11  (
    .I0(\U_min_10/U_cnt_digit_10/cnt [1]),
    .I1(\U_min_10/U_cnt_digit_10/cnt [0]),
    .I2(\U_min_10/U_cnt_digit_10/cnt [2]),
    .O(\U_min_10/U_cnt_digit_10/Mcount_cnt1 )
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
  \U_min_1/U_bcd_cnt/Mcount_cnt_xor<2>11  (
    .I0(\U_min_1/U_bcd_cnt/cnt [2]),
    .I1(\U_min_1/U_bcd_cnt/cnt [1]),
    .I2(\U_min_1/U_bcd_cnt/cnt [0]),
    .O(\U_min_1/U_bcd_cnt/Mcount_cnt2 )
  );
  LUT3 #(
    .INIT ( 8'h6A ))
  \UD/U11/cnt1_mux0000<1>1  (
    .I0(\UD/U11/cnt1 [2]),
    .I1(\UD/U11/cnt1 [1]),
    .I2(\UD/U11/cnt1 [0]),
    .O(\UD/U11/cnt1_mux0000 [1])
  );
  LUT3 #(
    .INIT ( 8'h6A ))
  \Mcount_ten_or_one_xor<2>11  (
    .I0(ten_or_one[2]),
    .I1(ten_or_one[1]),
    .I2(ten_or_one[0]),
    .O(\Result<2>1 )
  );
  LUT4 #(
    .INIT ( 16'hBF1F ))
  \seg_com_mux0000<5>1  (
    .I0(ten_or_one[1]),
    .I1(ten_or_one[0]),
    .I2(ten_or_one[2]),
    .I3(seg_com_2_481),
    .O(seg_com_mux0000[5])
  );
  LUT4 #(
    .INIT ( 16'hD8FF ))
  \seg_com_mux0000<4>1  (
    .I0(ten_or_one[1]),
    .I1(seg_com_3_482),
    .I2(ten_or_one[0]),
    .I3(ten_or_one[2]),
    .O(seg_com_mux0000[4])
  );
  LUT4 #(
    .INIT ( 16'hBF1F ))
  \seg_com_mux0000<3>1  (
    .I0(ten_or_one[2]),
    .I1(ten_or_one[0]),
    .I2(ten_or_one[1]),
    .I3(seg_com_4_483),
    .O(seg_com_mux0000[3])
  );
  LUT4 #(
    .INIT ( 16'hD8FF ))
  \seg_com_mux0000<2>1  (
    .I0(ten_or_one[2]),
    .I1(seg_com_5_484),
    .I2(ten_or_one[0]),
    .I3(ten_or_one[1]),
    .O(seg_com_mux0000[2])
  );
  LUT4 #(
    .INIT ( 16'hEF67 ))
  \seg_com_mux0000<1>1  (
    .I0(ten_or_one[2]),
    .I1(ten_or_one[1]),
    .I2(ten_or_one[0]),
    .I3(seg_com_6_485),
    .O(seg_com_mux0000[1])
  );
  LUT4 #(
    .INIT ( 16'hFE76 ))
  \seg_com_mux0000<0>1  (
    .I0(ten_or_one[2]),
    .I1(ten_or_one[1]),
    .I2(ten_or_one[0]),
    .I3(seg_com_7_486),
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
  \UD/U11/cnt1_mux0000<2>1  (
    .I0(\UD/U11/cnt1 [0]),
    .I1(\UD/U11/cnt1 [1]),
    .I2(\UD/U11/cnt1 [2]),
    .I3(\UD/U11/cnt1 [3]),
    .O(\UD/U11/cnt1_mux0000 [2])
  );
  LUT4 #(
    .INIT ( 16'h6CC4 ))
  \U_sec_1/U_bcd_cnt/Mcount_cnt_xor<3>11  (
    .I0(\U_sec_1/U_bcd_cnt/cnt [0]),
    .I1(\U_sec_1/U_bcd_cnt/cnt [3]),
    .I2(\U_sec_1/U_bcd_cnt/cnt [1]),
    .I3(\U_sec_1/U_bcd_cnt/cnt [2]),
    .O(\U_sec_1/U_bcd_cnt/Mcount_cnt3 )
  );
  LUT4 #(
    .INIT ( 16'h6CC4 ))
  \U_min_1/U_bcd_cnt/Mcount_cnt_xor<3>11  (
    .I0(\U_min_1/U_bcd_cnt/cnt [0]),
    .I1(\U_min_1/U_bcd_cnt/cnt [3]),
    .I2(\U_min_1/U_bcd_cnt/cnt [1]),
    .I3(\U_min_1/U_bcd_cnt/cnt [2]),
    .O(\U_min_1/U_bcd_cnt/Mcount_cnt3 )
  );
  LUT4 #(
    .INIT ( 16'h6CC4 ))
  \UD/U11/cnt1_mux0000<0>1  (
    .I0(\UD/U11/cnt1 [0]),
    .I1(\UD/U11/cnt1 [3]),
    .I2(\UD/U11/cnt1 [1]),
    .I3(\UD/U11/cnt1 [2]),
    .O(\UD/U11/cnt1_mux0000 [0])
  );
  IBUF   rst_IBUF (
    .I(rst),
    .O(rst_IBUF_472)
  );
  OBUF   clk_min_1_OBUF (
    .I(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .O(clk_min_1)
  );
  OBUF   seg_data_7_OBUF (
    .I(N0),
    .O(seg_data[7])
  );
  OBUF   seg_data_6_OBUF (
    .I(seg_data_6_507),
    .O(seg_data[6])
  );
  OBUF   seg_data_5_OBUF (
    .I(seg_data_5_506),
    .O(seg_data[5])
  );
  OBUF   seg_data_4_OBUF (
    .I(seg_data_4_505),
    .O(seg_data[4])
  );
  OBUF   seg_data_3_OBUF (
    .I(seg_data_3_504),
    .O(seg_data[3])
  );
  OBUF   seg_data_2_OBUF (
    .I(seg_data_2_503),
    .O(seg_data[2])
  );
  OBUF   seg_data_1_OBUF (
    .I(seg_data_1_502),
    .O(seg_data[1])
  );
  OBUF   seg_data_0_OBUF (
    .I(seg_data_0_501),
    .O(seg_data[0])
  );
  OBUF   seg_com_7_OBUF (
    .I(seg_com_7_486),
    .O(seg_com[7])
  );
  OBUF   seg_com_6_OBUF (
    .I(seg_com_6_485),
    .O(seg_com[6])
  );
  OBUF   seg_com_5_OBUF (
    .I(seg_com_5_484),
    .O(seg_com[5])
  );
  OBUF   seg_com_4_OBUF (
    .I(seg_com_4_483),
    .O(seg_com[4])
  );
  OBUF   seg_com_3_OBUF (
    .I(seg_com_3_482),
    .O(seg_com[3])
  );
  OBUF   seg_com_2_OBUF (
    .I(seg_com_2_481),
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
  FDR   ten_or_one_0 (
    .C(clk_BUFGP_469),
    .D(N1),
    .R(ten_or_one[0]),
    .Q(ten_or_one[0])
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<1>_rt  (
    .I0(\U_freq_div_1000/cnt [1]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<1>_rt_189 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<2>_rt  (
    .I0(\U_freq_div_1000/cnt [2]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<2>_rt_191 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<3>_rt  (
    .I0(\U_freq_div_1000/cnt [3]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<3>_rt_193 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<4>_rt  (
    .I0(\U_freq_div_1000/cnt [4]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<4>_rt_195 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<5>_rt  (
    .I0(\U_freq_div_1000/cnt [5]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<5>_rt_197 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<6>_rt  (
    .I0(\U_freq_div_1000/cnt [6]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<6>_rt_199 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<7>_rt  (
    .I0(\U_freq_div_1000/cnt [7]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<7>_rt_201 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<8>_rt  (
    .I0(\U_freq_div_1000/cnt [8]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<8>_rt_203 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [1]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_249 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [2]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_251 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [3]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_253 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [4]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_255 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [5]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_257 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [6]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_259 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [7]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_261 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [8]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_263 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [1]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_367 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [2]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_369 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [3]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_371 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [4]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_373 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [5]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_375 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [6]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_377 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [7]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_379 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [8]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_381 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [1]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_307 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [2]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_309 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [3]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_311 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [4]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_313 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [5]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_315 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [6]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_317 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [7]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_319 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [8]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_321 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [1]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_425 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [2]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_427 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [3]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_429 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [4]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_431 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [5]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_433 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [6]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_435 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [7]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_437 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [8]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_439 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \UD/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\UD/U_freq_div_10/cnt [1]),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy<1>_rt_144 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \UD/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\UD/U_freq_div_10/cnt [2]),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy<2>_rt_146 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \UD/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\UD/U_freq_div_10/cnt [3]),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy<3>_rt_148 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \UD/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\UD/U_freq_div_10/cnt [4]),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy<4>_rt_150 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \UD/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\UD/U_freq_div_10/cnt [5]),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy<5>_rt_152 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \UD/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\UD/U_freq_div_10/cnt [6]),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy<6>_rt_154 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \UD/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\UD/U_freq_div_10/cnt [7]),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy<7>_rt_156 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \UD/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\UD/U_freq_div_10/cnt [8]),
    .O(\UD/U_freq_div_10/Mcount_cnt_cy<8>_rt_158 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_xor<9>_rt  (
    .I0(\U_freq_div_1000/cnt [9]),
    .O(\U_freq_div_1000/Mcount_cnt_xor<9>_rt_215 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [9]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_275 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [9]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_393 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [9]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_333 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [9]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_451 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \UD/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\UD/U_freq_div_10/cnt [9]),
    .O(\UD/U_freq_div_10/Mcount_cnt_xor<9>_rt_170 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_5_rt (
    .I0(seg_data_6_507),
    .O(Mmux_seg_data_mux0000_3_f5_5_rt_12)
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_4_rt (
    .I0(seg_data_5_506),
    .O(Mmux_seg_data_mux0000_3_f5_4_rt_11)
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_3_rt (
    .I0(seg_data_4_505),
    .O(Mmux_seg_data_mux0000_3_f5_3_rt_10)
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_2_rt (
    .I0(seg_data_3_504),
    .O(Mmux_seg_data_mux0000_3_f5_2_rt_9)
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_1_rt (
    .I0(seg_data_2_503),
    .O(Mmux_seg_data_mux0000_3_f5_1_rt_8)
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_0_rt (
    .I0(seg_data_1_502),
    .O(Mmux_seg_data_mux0000_3_f5_0_rt_7)
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_rt (
    .I0(seg_data_0_501),
    .O(Mmux_seg_data_mux0000_3_f5_rt_13)
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N48),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_465 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_466 ),
    .I3(\Result<9>4 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N51),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_407 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_408 ),
    .I3(\Result<9>2 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N54),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_347 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_348 ),
    .I3(\Result<9>3 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N57),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_289 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_290 ),
    .I3(\Result<9>1 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_91  (
    .I0(N59),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_231 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_230 ),
    .I3(Result[9]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \UD/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N63),
    .I1(\UD/U_freq_div_10/cnt_cmp_eq000011_184 ),
    .I2(\UD/U_freq_div_10/cnt_cmp_eq000015_185 ),
    .I3(\Result<9>5 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_467 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_465 ),
    .I2(N47),
    .I3(\Result<8>4 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_409 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_407 ),
    .I2(N50),
    .I3(\Result<8>2 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_349 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_347 ),
    .I2(N53),
    .I3(\Result<8>3 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_291 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_289 ),
    .I2(N56),
    .I3(\Result<8>1 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_81  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_229 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_231 ),
    .I2(N60),
    .I3(Result[8]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \UD/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\UD/U_freq_div_10/cnt_cmp_eq000036_186 ),
    .I1(\UD/U_freq_div_10/cnt_cmp_eq000011_184 ),
    .I2(N62),
    .I3(\Result<8>5 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_467 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_465 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_466 ),
    .I3(\Result<7>4 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_409 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_407 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_408 ),
    .I3(\Result<7>2 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_349 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_347 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_348 ),
    .I3(\Result<7>3 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_291 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_289 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_290 ),
    .I3(\Result<7>1 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_71  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_229 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_231 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_230 ),
    .I3(Result[7]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \UD/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\UD/U_freq_div_10/cnt_cmp_eq000036_186 ),
    .I1(\UD/U_freq_div_10/cnt_cmp_eq000011_184 ),
    .I2(\UD/U_freq_div_10/cnt_cmp_eq000015_185 ),
    .I3(\Result<7>5 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_467 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_465 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_466 ),
    .I3(\Result<6>4 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_409 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_407 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_408 ),
    .I3(\Result<6>2 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_349 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_347 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_348 ),
    .I3(\Result<6>3 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_291 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_289 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_290 ),
    .I3(\Result<6>1 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_61  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_229 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_231 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_230 ),
    .I3(Result[6]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \UD/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\UD/U_freq_div_10/cnt_cmp_eq000036_186 ),
    .I1(\UD/U_freq_div_10/cnt_cmp_eq000011_184 ),
    .I2(\UD/U_freq_div_10/cnt_cmp_eq000015_185 ),
    .I3(\Result<6>5 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_467 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_465 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_466 ),
    .I3(\Result<5>4 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_409 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_407 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_408 ),
    .I3(\Result<5>2 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_349 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_347 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_348 ),
    .I3(\Result<5>3 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_291 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_289 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_290 ),
    .I3(\Result<5>1 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_51  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_229 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_231 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_230 ),
    .I3(Result[5]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \UD/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\UD/U_freq_div_10/cnt_cmp_eq000036_186 ),
    .I1(\UD/U_freq_div_10/cnt_cmp_eq000011_184 ),
    .I2(\UD/U_freq_div_10/cnt_cmp_eq000015_185 ),
    .I3(\Result<5>5 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_467 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_465 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_466 ),
    .I3(\Result<4>4 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_409 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_407 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_408 ),
    .I3(\Result<4>2 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_349 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_347 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_348 ),
    .I3(\Result<4>3 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_291 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_289 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_290 ),
    .I3(\Result<4>1 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_41  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_229 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_231 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_230 ),
    .I3(Result[4]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \UD/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\UD/U_freq_div_10/cnt_cmp_eq000036_186 ),
    .I1(\UD/U_freq_div_10/cnt_cmp_eq000011_184 ),
    .I2(\UD/U_freq_div_10/cnt_cmp_eq000015_185 ),
    .I3(\Result<4>5 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_467 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_465 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_466 ),
    .I3(\Result<3>4 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_409 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_407 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_408 ),
    .I3(\Result<3>2 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_349 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_347 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_348 ),
    .I3(\Result<3>3 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_291 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_289 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_290 ),
    .I3(\Result<3>1 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_31  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_229 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_231 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_230 ),
    .I3(Result[3]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \UD/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\UD/U_freq_div_10/cnt_cmp_eq000036_186 ),
    .I1(\UD/U_freq_div_10/cnt_cmp_eq000011_184 ),
    .I2(\UD/U_freq_div_10/cnt_cmp_eq000015_185 ),
    .I3(\Result<3>5 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_467 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_465 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_466 ),
    .I3(\Result<2>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_409 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_407 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_408 ),
    .I3(\Result<2>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_349 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_347 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_348 ),
    .I3(\Result<2>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_291 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_289 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_290 ),
    .I3(\Result<2>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_21  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_229 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_231 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_230 ),
    .I3(Result[2]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \UD/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\UD/U_freq_div_10/cnt_cmp_eq000036_186 ),
    .I1(\UD/U_freq_div_10/cnt_cmp_eq000011_184 ),
    .I2(\UD/U_freq_div_10/cnt_cmp_eq000015_185 ),
    .I3(\Result<2>6 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_467 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_465 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_466 ),
    .I3(\Result<1>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_409 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_407 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_408 ),
    .I3(\Result<1>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_349 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_347 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_348 ),
    .I3(\Result<1>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_291 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_289 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_290 ),
    .I3(\Result<1>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_11  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_229 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_231 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_230 ),
    .I3(Result[1]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \UD/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\UD/U_freq_div_10/cnt_cmp_eq000036_186 ),
    .I1(\UD/U_freq_div_10/cnt_cmp_eq000011_184 ),
    .I2(\UD/U_freq_div_10/cnt_cmp_eq000015_185 ),
    .I3(\Result<1>6 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_467 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_465 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_466 ),
    .I3(\Result<0>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_409 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_407 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_408 ),
    .I3(\Result<0>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_349 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_347 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_348 ),
    .I3(\Result<0>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_291 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_289 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_290 ),
    .I3(\Result<0>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_01  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_229 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_231 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_230 ),
    .I3(Result[0]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \UD/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\UD/U_freq_div_10/cnt_cmp_eq000036_186 ),
    .I1(\UD/U_freq_div_10/cnt_cmp_eq000011_184 ),
    .I2(\UD/U_freq_div_10/cnt_cmp_eq000015_185 ),
    .I3(\Result<0>6 ),
    .O(\UD/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT3 #(
    .INIT ( 8'h72 ))
  Mmux_seg_data_mux0000_510 (
    .I0(ten_or_one[0]),
    .I1(\UD/U11/cnt2_133 ),
    .I2(\UD/U_bcd_to_seg_mod_10/Mrom_seg_data5 ),
    .O(Mmux_seg_data_mux0000_510_23)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_58_SW0 (
    .I0(\UD/U11/cnt1 [1]),
    .I1(\UD/U11/cnt1 [2]),
    .I2(\UD/U11/cnt1 [3]),
    .O(N44)
  );
  LUT4 #(
    .INIT ( 16'h2227 ))
  Mmux_seg_data_mux0000_58 (
    .I0(ten_or_one[0]),
    .I1(\UD/U11/cnt2_133 ),
    .I2(\UD/U11/cnt1 [0]),
    .I3(N44),
    .O(Mmux_seg_data_mux0000_58_33)
  );
  LUT3 #(
    .INIT ( 8'h72 ))
  Mmux_seg_data_mux0000_56 (
    .I0(ten_or_one[0]),
    .I1(\UD/U11/cnt2_133 ),
    .I2(\UD/U_bcd_to_seg_mod_10/Mrom_seg_data3 ),
    .O(Mmux_seg_data_mux0000_56_31)
  );
  LUT3 #(
    .INIT ( 8'h72 ))
  Mmux_seg_data_mux0000_5 (
    .I0(ten_or_one[0]),
    .I1(\UD/U11/cnt2_133 ),
    .I2(\UD/U_bcd_to_seg_mod_10/Mrom_seg_data ),
    .O(Mmux_seg_data_mux0000_5_21)
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_sec_10/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_sec_10/U_freq_div_10/cnt [5]),
    .I1(\U_sec_10/U_freq_div_10/cnt [4]),
    .I2(N46),
    .I3(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_467 ),
    .O(\U_sec_10/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_sec_1/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_sec_1/U_freq_div_10/cnt [5]),
    .I1(\U_sec_1/U_freq_div_10/cnt [4]),
    .I2(N49),
    .I3(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_409 ),
    .O(\U_sec_1/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_min_10/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_min_10/U_freq_div_10/cnt [5]),
    .I1(\U_min_10/U_freq_div_10/cnt [4]),
    .I2(N52),
    .I3(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_349 ),
    .O(\U_min_10/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_min_1/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_min_1/U_freq_div_10/cnt [5]),
    .I1(\U_min_1/U_freq_div_10/cnt [4]),
    .I2(N55),
    .I3(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_291 ),
    .O(\U_min_1/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_freq_div_1000/cnt_cmp_eq000024  (
    .I0(\U_freq_div_1000/cnt [3]),
    .I1(\U_freq_div_1000/cnt [2]),
    .I2(N58),
    .I3(\U_freq_div_1000/cnt_cmp_eq000012_229 ),
    .O(\U_freq_div_1000/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \UD/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\UD/U_freq_div_10/cnt [5]),
    .I1(\UD/U_freq_div_10/cnt [4]),
    .I2(N61),
    .I3(\UD/U_freq_div_10/cnt_cmp_eq000036_186 ),
    .O(\UD/U_freq_div_10/cnt_cmp_eq0000 )
  );
  BUFGP   clk_BUFGP (
    .I(clk),
    .O(clk_BUFGP_469)
  );
  INV   \U_freq_div_1000/Mcount_cnt_lut<0>_INV_0  (
    .I(\U_freq_div_1000/cnt [0]),
    .O(\U_freq_div_1000/Mcount_cnt_lut [0])
  );
  INV   \U_min_1/U_freq_div_10/Mcount_cnt_lut<0>_INV_0  (
    .I(\U_min_1/U_freq_div_10/cnt [0]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_lut [0])
  );
  INV   \U_sec_1/U_freq_div_10/Mcount_cnt_lut<0>_INV_0  (
    .I(\U_sec_1/U_freq_div_10/cnt [0]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_lut [0])
  );
  INV   \U_min_10/U_freq_div_10/Mcount_cnt_lut<0>_INV_0  (
    .I(\U_min_10/U_freq_div_10/cnt [0]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_lut [0])
  );
  INV   \U_sec_10/U_freq_div_10/Mcount_cnt_lut<0>_INV_0  (
    .I(\U_sec_10/U_freq_div_10/cnt [0]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_lut [0])
  );
  INV   \UD/U_freq_div_10/Mcount_cnt_lut<0>_INV_0  (
    .I(\UD/U_freq_div_10/cnt [0]),
    .O(\UD/U_freq_div_10/Mcount_cnt_lut [0])
  );
  INV   \U_sec_10/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_sec_10/U_freq_div_10/clk_div_N_452 ),
    .O(\U_sec_10/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_sec_10/U_cnt_digit_10/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .O(\U_sec_10/U_cnt_digit_10/Mcount_cnt )
  );
  INV   \U_sec_1/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_sec_1/U_freq_div_10/clk_div_N_394 ),
    .O(\U_sec_1/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_sec_1/U_bcd_cnt/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_sec_1/U_bcd_cnt/cnt [0]),
    .O(\U_sec_1/U_bcd_cnt/Mcount_cnt )
  );
  INV   \U_min_10/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_min_10/U_freq_div_10/clk_div_N_334 ),
    .O(\U_min_10/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_min_10/U_cnt_digit_10/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_min_10/U_cnt_digit_10/cnt [0]),
    .O(\U_min_10/U_cnt_digit_10/Mcount_cnt )
  );
  INV   \U_min_1/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_min_1/U_freq_div_10/clk_div_N_276 ),
    .O(\U_min_1/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_min_1/U_bcd_cnt/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_min_1/U_bcd_cnt/cnt [0]),
    .O(\U_min_1/U_bcd_cnt/Mcount_cnt )
  );
  INV   \U_freq_div_1000/clk_div_N_not00011_INV_0  (
    .I(\U_freq_div_1000/clk_div_N_216 ),
    .O(\U_freq_div_1000/clk_div_N_not0001 )
  );
  INV   \UD/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\UD/U_freq_div_10/clk_div_N_171 ),
    .O(\UD/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \UD/U11/cnt1_mux0000<3>1_INV_0  (
    .I(\UD/U11/cnt1 [0]),
    .O(\UD/U11/cnt1_mux0000 [3])
  );
  LUT4 #(
    .INIT ( 16'h0040 ))
  \UD/U11/cnt2_not00011  (
    .I0(\UD/U11/cnt1 [3]),
    .I1(\UD/U11/cnt1 [2]),
    .I2(\UD/U11/cnt1 [1]),
    .I3(\UD/U11/cnt1 [0]),
    .O(\UD/U11/cnt2_not00011_135 )
  );
  MUXF5   \UD/U11/cnt2_not0001_f5  (
    .I0(\UD/U11/cnt2_not00011_135 ),
    .I1(N0),
    .S(\UD/U11/cnt2_133 ),
    .O(\UD/U11/cnt2_not0001 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_sec_10/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_sec_10/U_freq_div_10/cnt [1]),
    .I1(\U_sec_10/U_freq_div_10/cnt [0]),
    .I2(\U_sec_10/U_freq_div_10/cnt [2]),
    .I3(\U_sec_10/U_freq_div_10/cnt [3]),
    .LO(N46),
    .O(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_465 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_sec_10/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_sec_10/U_freq_div_10/cnt [4]),
    .I1(\U_sec_10/U_freq_div_10/cnt [5]),
    .LO(N47),
    .O(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_466 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_sec_10/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_sec_10/U_freq_div_10/cnt [6]),
    .I1(\U_sec_10/U_freq_div_10/cnt [7]),
    .I2(\U_sec_10/U_freq_div_10/cnt [8]),
    .I3(\U_sec_10/U_freq_div_10/cnt [9]),
    .LO(N48),
    .O(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_467 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_sec_1/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_sec_1/U_freq_div_10/cnt [2]),
    .I1(\U_sec_1/U_freq_div_10/cnt [3]),
    .I2(\U_sec_1/U_freq_div_10/cnt [0]),
    .I3(\U_sec_1/U_freq_div_10/cnt [1]),
    .LO(N49),
    .O(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_407 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_sec_1/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_sec_1/U_freq_div_10/cnt [4]),
    .I1(\U_sec_1/U_freq_div_10/cnt [5]),
    .LO(N50),
    .O(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_408 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_sec_1/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_sec_1/U_freq_div_10/cnt [6]),
    .I1(\U_sec_1/U_freq_div_10/cnt [7]),
    .I2(\U_sec_1/U_freq_div_10/cnt [8]),
    .I3(\U_sec_1/U_freq_div_10/cnt [9]),
    .LO(N51),
    .O(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_409 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_min_10/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_min_10/U_freq_div_10/cnt [1]),
    .I1(\U_min_10/U_freq_div_10/cnt [0]),
    .I2(\U_min_10/U_freq_div_10/cnt [2]),
    .I3(\U_min_10/U_freq_div_10/cnt [3]),
    .LO(N52),
    .O(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_347 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_min_10/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_min_10/U_freq_div_10/cnt [4]),
    .I1(\U_min_10/U_freq_div_10/cnt [5]),
    .LO(N53),
    .O(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_348 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_min_10/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_min_10/U_freq_div_10/cnt [6]),
    .I1(\U_min_10/U_freq_div_10/cnt [7]),
    .I2(\U_min_10/U_freq_div_10/cnt [8]),
    .I3(\U_min_10/U_freq_div_10/cnt [9]),
    .LO(N54),
    .O(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_349 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_min_1/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_min_1/U_freq_div_10/cnt [2]),
    .I1(\U_min_1/U_freq_div_10/cnt [3]),
    .I2(\U_min_1/U_freq_div_10/cnt [0]),
    .I3(\U_min_1/U_freq_div_10/cnt [1]),
    .LO(N55),
    .O(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_289 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_min_1/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_min_1/U_freq_div_10/cnt [4]),
    .I1(\U_min_1/U_freq_div_10/cnt [5]),
    .LO(N56),
    .O(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_290 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_min_1/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_min_1/U_freq_div_10/cnt [6]),
    .I1(\U_min_1/U_freq_div_10/cnt [7]),
    .I2(\U_min_1/U_freq_div_10/cnt [8]),
    .I3(\U_min_1/U_freq_div_10/cnt [9]),
    .LO(N57),
    .O(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_291 )
  );
  LUT4_D #(
    .INIT ( 16'h2000 ))
  \U_freq_div_1000/cnt_cmp_eq00007  (
    .I0(\U_freq_div_1000/cnt [1]),
    .I1(\U_freq_div_1000/cnt [9]),
    .I2(\U_freq_div_1000/cnt [8]),
    .I3(\U_freq_div_1000/cnt [0]),
    .LO(N58),
    .O(\U_freq_div_1000/cnt_cmp_eq00007_231 )
  );
  LUT4_D #(
    .INIT ( 16'h8000 ))
  \U_freq_div_1000/cnt_cmp_eq000012  (
    .I0(\U_freq_div_1000/cnt [4]),
    .I1(\U_freq_div_1000/cnt [5]),
    .I2(\U_freq_div_1000/cnt [6]),
    .I3(\U_freq_div_1000/cnt [7]),
    .LO(N59),
    .O(\U_freq_div_1000/cnt_cmp_eq000012_229 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_freq_div_1000/cnt_cmp_eq000016  (
    .I0(\U_freq_div_1000/cnt [2]),
    .I1(\U_freq_div_1000/cnt [3]),
    .LO(N60),
    .O(\U_freq_div_1000/cnt_cmp_eq000016_230 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \UD/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\UD/U_freq_div_10/cnt [0]),
    .I1(\UD/U_freq_div_10/cnt [1]),
    .I2(\UD/U_freq_div_10/cnt [2]),
    .I3(\UD/U_freq_div_10/cnt [3]),
    .LO(N61),
    .O(\UD/U_freq_div_10/cnt_cmp_eq000011_184 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \UD/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\UD/U_freq_div_10/cnt [4]),
    .I1(\UD/U_freq_div_10/cnt [5]),
    .LO(N62),
    .O(\UD/U_freq_div_10/cnt_cmp_eq000015_185 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \UD/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\UD/U_freq_div_10/cnt [6]),
    .I1(\UD/U_freq_div_10/cnt [7]),
    .I2(\UD/U_freq_div_10/cnt [8]),
    .I3(\UD/U_freq_div_10/cnt [9]),
    .LO(N63),
    .O(\UD/U_freq_div_10/cnt_cmp_eq000036_186 )
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

