////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: second_two_digits_synthesis.v
// /___/   /\     Timestamp: Tue Dec 10 17:32:12 2019
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim second_two_digits.ngc second_two_digits_synthesis.v 
// Device	: xc3s1000-4-fg676
// Input file	: second_two_digits.ngc
// Output file	: D:\second_display1120191210_2\netgen\synthesis\second_two_digits_synthesis.v
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
  wire N45;
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
  wire \U_freq_div_1000/Mcount_cnt_cy<1>_rt_126 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<2>_rt_128 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<3>_rt_130 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<4>_rt_132 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<5>_rt_134 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<6>_rt_136 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<7>_rt_138 ;
  wire \U_freq_div_1000/Mcount_cnt_cy<8>_rt_140 ;
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
  wire \U_freq_div_1000/Mcount_cnt_xor<9>_rt_152 ;
  wire \U_freq_div_1000/clk_div_N_153 ;
  wire \U_freq_div_1000/clk_div_N_not0001 ;
  wire \U_freq_div_1000/cnt_cmp_eq0000 ;
  wire \U_freq_div_1000/cnt_cmp_eq000012_166 ;
  wire \U_freq_div_1000/cnt_cmp_eq000016_167 ;
  wire \U_freq_div_1000/cnt_cmp_eq00007_168 ;
  wire \U_h_1/U_bcd_cnt/Mcount_cnt ;
  wire \U_h_1/U_bcd_cnt/Mcount_cnt1 ;
  wire \U_h_1/U_bcd_cnt/Mcount_cnt2 ;
  wire \U_h_1/U_bcd_cnt/Mcount_cnt3 ;
  wire \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data ;
  wire \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data1 ;
  wire \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data2 ;
  wire \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data3 ;
  wire \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data4 ;
  wire \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data5 ;
  wire \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data6 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_186 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_188 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_190 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_192 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_194 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_196 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_198 ;
  wire \U_h_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_200 ;
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
  wire \U_h_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_212 ;
  wire \U_h_1/U_freq_div_10/clk_div_N_213 ;
  wire \U_h_1/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_h_1/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_h_1/U_freq_div_10/cnt_cmp_eq000011_226 ;
  wire \U_h_1/U_freq_div_10/cnt_cmp_eq000015_227 ;
  wire \U_h_1/U_freq_div_10/cnt_cmp_eq000036_228 ;
  wire \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data ;
  wire \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data1 ;
  wire \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data2 ;
  wire \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data3 ;
  wire \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data4 ;
  wire \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data5 ;
  wire \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data6 ;
  wire \U_h_10/U_cnt_digit_10/Mcount_cnt ;
  wire \U_h_10/U_cnt_digit_10/Mcount_cnt1 ;
  wire \U_h_10/U_cnt_digit_10/Mcount_cnt2 ;
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
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_259 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_261 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_263 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_265 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_267 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_269 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_271 ;
  wire \U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_273 ;
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
  wire \U_min_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_285 ;
  wire \U_min_1/U_freq_div_10/clk_div_N_286 ;
  wire \U_min_1/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_min_1/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_min_1/U_freq_div_10/cnt_cmp_eq000011_299 ;
  wire \U_min_1/U_freq_div_10/cnt_cmp_eq000015_300 ;
  wire \U_min_1/U_freq_div_10/cnt_cmp_eq000036_301 ;
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
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_317 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_319 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_321 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_323 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_325 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_327 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_329 ;
  wire \U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_331 ;
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
  wire \U_min_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_343 ;
  wire \U_min_10/U_freq_div_10/clk_div_N_344 ;
  wire \U_min_10/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_min_10/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_min_10/U_freq_div_10/cnt_cmp_eq000011_357 ;
  wire \U_min_10/U_freq_div_10/cnt_cmp_eq000015_358 ;
  wire \U_min_10/U_freq_div_10/cnt_cmp_eq000036_359 ;
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
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_377 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_379 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_381 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_383 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_385 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_387 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_389 ;
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_391 ;
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
  wire \U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_403 ;
  wire \U_sec_1/U_freq_div_10/clk_div_N_404 ;
  wire \U_sec_1/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_sec_1/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_sec_1/U_freq_div_10/cnt_cmp_eq000011_417 ;
  wire \U_sec_1/U_freq_div_10/cnt_cmp_eq000015_418 ;
  wire \U_sec_1/U_freq_div_10/cnt_cmp_eq000036_419 ;
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
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_435 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_437 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_439 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_441 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_443 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_445 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_447 ;
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_449 ;
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
  wire \U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_461 ;
  wire \U_sec_10/U_freq_div_10/clk_div_N_462 ;
  wire \U_sec_10/U_freq_div_10/clk_div_N_not0001 ;
  wire \U_sec_10/U_freq_div_10/cnt_cmp_eq0000 ;
  wire \U_sec_10/U_freq_div_10/cnt_cmp_eq000011_475 ;
  wire \U_sec_10/U_freq_div_10/cnt_cmp_eq000015_476 ;
  wire \U_sec_10/U_freq_div_10/cnt_cmp_eq000036_477 ;
  wire clk_BUFGP_479;
  wire rst_IBUF_482;
  wire seg_com_2_491;
  wire seg_com_3_492;
  wire seg_com_4_493;
  wire seg_com_5_494;
  wire seg_com_6_495;
  wire seg_com_7_496;
  wire seg_data_0_511;
  wire seg_data_1_512;
  wire seg_data_2_513;
  wire seg_data_3_514;
  wire seg_data_4_515;
  wire seg_data_5_516;
  wire seg_data_6_517;
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
  GND   XST_GND (
    .G(N0)
  );
  VCC   XST_VCC (
    .P(N1)
  );
  FD   seg_com_2 (
    .C(clk_BUFGP_479),
    .D(seg_com_mux0000[5]),
    .Q(seg_com_2_491)
  );
  FD   seg_com_3 (
    .C(clk_BUFGP_479),
    .D(seg_com_mux0000[4]),
    .Q(seg_com_3_492)
  );
  FD   seg_com_4 (
    .C(clk_BUFGP_479),
    .D(seg_com_mux0000[3]),
    .Q(seg_com_4_493)
  );
  FD   seg_com_5 (
    .C(clk_BUFGP_479),
    .D(seg_com_mux0000[2]),
    .Q(seg_com_5_494)
  );
  FD   seg_com_6 (
    .C(clk_BUFGP_479),
    .D(seg_com_mux0000[1]),
    .Q(seg_com_6_495)
  );
  FD   seg_com_7 (
    .C(clk_BUFGP_479),
    .D(seg_com_mux0000[0]),
    .Q(seg_com_7_496)
  );
  FD   seg_data_0 (
    .C(clk_BUFGP_479),
    .D(seg_data_mux0000[0]),
    .Q(seg_data_0_511)
  );
  FD   seg_data_1 (
    .C(clk_BUFGP_479),
    .D(seg_data_mux0000[1]),
    .Q(seg_data_1_512)
  );
  FD   seg_data_2 (
    .C(clk_BUFGP_479),
    .D(seg_data_mux0000[2]),
    .Q(seg_data_2_513)
  );
  FD   seg_data_3 (
    .C(clk_BUFGP_479),
    .D(seg_data_mux0000[3]),
    .Q(seg_data_3_514)
  );
  FD   seg_data_4 (
    .C(clk_BUFGP_479),
    .D(seg_data_mux0000[4]),
    .Q(seg_data_4_515)
  );
  FD   seg_data_5 (
    .C(clk_BUFGP_479),
    .D(seg_data_mux0000[5]),
    .Q(seg_data_5_516)
  );
  FD   seg_data_6 (
    .C(clk_BUFGP_479),
    .D(seg_data_mux0000[6]),
    .Q(seg_data_6_517)
  );
  FDPE   \U_freq_div_1000/clk_div_N  (
    .C(clk_BUFGP_479),
    .CE(\U_freq_div_1000/cnt_cmp_eq0000 ),
    .D(\U_freq_div_1000/clk_div_N_not0001 ),
    .PRE(rst_IBUF_482),
    .Q(\U_freq_div_1000/clk_div_N_153 )
  );
  FDPE   \U_h_1/U_freq_div_10/clk_div_N  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CE(\U_h_1/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_h_1/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_482),
    .Q(\U_h_1/U_freq_div_10/clk_div_N_213 )
  );
  FDPE   \U_min_1/U_freq_div_10/clk_div_N  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CE(\U_min_1/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_min_1/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_482),
    .Q(\U_min_1/U_freq_div_10/clk_div_N_286 )
  );
  FDPE   \U_sec_1/U_freq_div_10/clk_div_N  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CE(\U_sec_1/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_sec_1/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_482),
    .Q(\U_sec_1/U_freq_div_10/clk_div_N_404 )
  );
  FDPE   \U_min_10/U_freq_div_10/clk_div_N  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CE(\U_min_10/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_min_10/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_482),
    .Q(\U_min_10/U_freq_div_10/clk_div_N_344 )
  );
  FDPE   \U_sec_10/U_freq_div_10/clk_div_N  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CE(\U_sec_10/U_freq_div_10/cnt_cmp_eq0000 ),
    .D(\U_sec_10/U_freq_div_10/clk_div_N_not0001 ),
    .PRE(rst_IBUF_482),
    .Q(\U_sec_10/U_freq_div_10/clk_div_N_462 )
  );
  FDC   \U_freq_div_1000/cnt_0  (
    .C(clk_BUFGP_479),
    .CLR(rst_IBUF_482),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_0 ),
    .Q(\U_freq_div_1000/cnt [0])
  );
  FDC   \U_freq_div_1000/cnt_1  (
    .C(clk_BUFGP_479),
    .CLR(rst_IBUF_482),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_1 ),
    .Q(\U_freq_div_1000/cnt [1])
  );
  FDC   \U_freq_div_1000/cnt_2  (
    .C(clk_BUFGP_479),
    .CLR(rst_IBUF_482),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_2 ),
    .Q(\U_freq_div_1000/cnt [2])
  );
  FDC   \U_freq_div_1000/cnt_3  (
    .C(clk_BUFGP_479),
    .CLR(rst_IBUF_482),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_3 ),
    .Q(\U_freq_div_1000/cnt [3])
  );
  FDC   \U_freq_div_1000/cnt_4  (
    .C(clk_BUFGP_479),
    .CLR(rst_IBUF_482),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_4 ),
    .Q(\U_freq_div_1000/cnt [4])
  );
  FDC   \U_freq_div_1000/cnt_5  (
    .C(clk_BUFGP_479),
    .CLR(rst_IBUF_482),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_5 ),
    .Q(\U_freq_div_1000/cnt [5])
  );
  FDC   \U_freq_div_1000/cnt_6  (
    .C(clk_BUFGP_479),
    .CLR(rst_IBUF_482),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_6 ),
    .Q(\U_freq_div_1000/cnt [6])
  );
  FDC   \U_freq_div_1000/cnt_7  (
    .C(clk_BUFGP_479),
    .CLR(rst_IBUF_482),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_7 ),
    .Q(\U_freq_div_1000/cnt [7])
  );
  FDC   \U_freq_div_1000/cnt_8  (
    .C(clk_BUFGP_479),
    .CLR(rst_IBUF_482),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_8 ),
    .Q(\U_freq_div_1000/cnt [8])
  );
  FDC   \U_freq_div_1000/cnt_9  (
    .C(clk_BUFGP_479),
    .CLR(rst_IBUF_482),
    .D(\U_freq_div_1000/Mcount_cnt_eqn_9 ),
    .Q(\U_freq_div_1000/cnt [9])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_0  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_h_1/U_freq_div_10/cnt [0])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_1  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_h_1/U_freq_div_10/cnt [1])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_2  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_h_1/U_freq_div_10/cnt [2])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_3  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_h_1/U_freq_div_10/cnt [3])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_4  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_h_1/U_freq_div_10/cnt [4])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_5  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_h_1/U_freq_div_10/cnt [5])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_6  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_h_1/U_freq_div_10/cnt [6])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_7  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_h_1/U_freq_div_10/cnt [7])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_8  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_h_1/U_freq_div_10/cnt [8])
  );
  FDC   \U_h_1/U_freq_div_10/cnt_9  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_h_1/U_freq_div_10/cnt [9])
  );
  FDC   \U_h_1/U_bcd_cnt/cnt_0  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_bcd_cnt/Mcount_cnt ),
    .Q(\U_h_1/U_bcd_cnt/cnt [0])
  );
  FDC   \U_h_1/U_bcd_cnt/cnt_1  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_bcd_cnt/Mcount_cnt1 ),
    .Q(\U_h_1/U_bcd_cnt/cnt [1])
  );
  FDC   \U_h_1/U_bcd_cnt/cnt_2  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_bcd_cnt/Mcount_cnt2 ),
    .Q(\U_h_1/U_bcd_cnt/cnt [2])
  );
  FDC   \U_h_1/U_bcd_cnt/cnt_3  (
    .C(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_1/U_bcd_cnt/Mcount_cnt3 ),
    .Q(\U_h_1/U_bcd_cnt/cnt [3])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_0  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_min_1/U_freq_div_10/cnt [0])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_1  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_min_1/U_freq_div_10/cnt [1])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_2  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_min_1/U_freq_div_10/cnt [2])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_3  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_min_1/U_freq_div_10/cnt [3])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_4  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_min_1/U_freq_div_10/cnt [4])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_5  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_min_1/U_freq_div_10/cnt [5])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_6  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_min_1/U_freq_div_10/cnt [6])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_7  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_min_1/U_freq_div_10/cnt [7])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_8  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_min_1/U_freq_div_10/cnt [8])
  );
  FDC   \U_min_1/U_freq_div_10/cnt_9  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_min_1/U_freq_div_10/cnt [9])
  );
  FDC   \U_min_1/U_bcd_cnt/cnt_0  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_bcd_cnt/Mcount_cnt ),
    .Q(\U_min_1/U_bcd_cnt/cnt [0])
  );
  FDC   \U_min_1/U_bcd_cnt/cnt_1  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_bcd_cnt/Mcount_cnt1 ),
    .Q(\U_min_1/U_bcd_cnt/cnt [1])
  );
  FDC   \U_min_1/U_bcd_cnt/cnt_2  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_bcd_cnt/Mcount_cnt2 ),
    .Q(\U_min_1/U_bcd_cnt/cnt [2])
  );
  FDC   \U_min_1/U_bcd_cnt/cnt_3  (
    .C(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_1/U_bcd_cnt/Mcount_cnt3 ),
    .Q(\U_min_1/U_bcd_cnt/cnt [3])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_0  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [0])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_1  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [1])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_2  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [2])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_3  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [3])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_4  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [4])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_5  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [5])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_6  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [6])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_7  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [7])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_8  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [8])
  );
  FDC   \U_sec_1/U_freq_div_10/cnt_9  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_sec_1/U_freq_div_10/cnt [9])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_0  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_min_10/U_freq_div_10/cnt [0])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_1  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_min_10/U_freq_div_10/cnt [1])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_2  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_min_10/U_freq_div_10/cnt [2])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_3  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_min_10/U_freq_div_10/cnt [3])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_4  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_min_10/U_freq_div_10/cnt [4])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_5  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_min_10/U_freq_div_10/cnt [5])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_6  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_min_10/U_freq_div_10/cnt [6])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_7  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_min_10/U_freq_div_10/cnt [7])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_8  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_min_10/U_freq_div_10/cnt [8])
  );
  FDC   \U_min_10/U_freq_div_10/cnt_9  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_min_10/U_freq_div_10/cnt [9])
  );
  FDC   \U_sec_1/U_bcd_cnt/cnt_0  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_bcd_cnt/Mcount_cnt ),
    .Q(\U_sec_1/U_bcd_cnt/cnt [0])
  );
  FDC   \U_sec_1/U_bcd_cnt/cnt_1  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_bcd_cnt/Mcount_cnt1 ),
    .Q(\U_sec_1/U_bcd_cnt/cnt [1])
  );
  FDC   \U_sec_1/U_bcd_cnt/cnt_2  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_bcd_cnt/Mcount_cnt2 ),
    .Q(\U_sec_1/U_bcd_cnt/cnt [2])
  );
  FDC   \U_sec_1/U_bcd_cnt/cnt_3  (
    .C(\U_freq_div_1000/clk_div_N_153 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_1/U_bcd_cnt/Mcount_cnt3 ),
    .Q(\U_sec_1/U_bcd_cnt/cnt [3])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_0  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_0 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [0])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_1  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_1 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [1])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_2  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_2 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [2])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_3  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_3 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [3])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_4  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_4 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [4])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_5  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_5 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [5])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_6  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_6 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [6])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_7  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_7 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [7])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_8  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_8 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [8])
  );
  FDC   \U_sec_10/U_freq_div_10/cnt_9  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_9 ),
    .Q(\U_sec_10/U_freq_div_10/cnt [9])
  );
  FDC   \U_min_10/U_cnt_digit_10/cnt_0  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_10/U_cnt_digit_10/Mcount_cnt ),
    .Q(\U_min_10/U_cnt_digit_10/cnt [0])
  );
  FDC   \U_min_10/U_cnt_digit_10/cnt_1  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_10/U_cnt_digit_10/Mcount_cnt1 ),
    .Q(\U_min_10/U_cnt_digit_10/cnt [1])
  );
  FDC   \U_min_10/U_cnt_digit_10/cnt_2  (
    .C(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .CLR(rst_IBUF_482),
    .D(\U_min_10/U_cnt_digit_10/Mcount_cnt2 ),
    .Q(\U_min_10/U_cnt_digit_10/cnt [2])
  );
  FDC   \U_sec_10/U_cnt_digit_10/cnt_0  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_10/U_cnt_digit_10/Mcount_cnt ),
    .Q(\U_sec_10/U_cnt_digit_10/cnt [0])
  );
  FDC   \U_sec_10/U_cnt_digit_10/cnt_1  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_10/U_cnt_digit_10/Mcount_cnt1 ),
    .Q(\U_sec_10/U_cnt_digit_10/cnt [1])
  );
  FDC   \U_sec_10/U_cnt_digit_10/cnt_2  (
    .C(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .CLR(rst_IBUF_482),
    .D(\U_sec_10/U_cnt_digit_10/Mcount_cnt2 ),
    .Q(\U_sec_10/U_cnt_digit_10/cnt [2])
  );
  FDC   \U_h_10/U_cnt_digit_10/cnt_0  (
    .C(\U_h_1/U_freq_div_10/clk_div_N_213 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_10/U_cnt_digit_10/Mcount_cnt ),
    .Q(\U_h_10/U_cnt_digit_10/cnt [0])
  );
  FDC   \U_h_10/U_cnt_digit_10/cnt_1  (
    .C(\U_h_1/U_freq_div_10/clk_div_N_213 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_10/U_cnt_digit_10/Mcount_cnt1 ),
    .Q(\U_h_10/U_cnt_digit_10/cnt [1])
  );
  FDC   \U_h_10/U_cnt_digit_10/cnt_2  (
    .C(\U_h_1/U_freq_div_10/clk_div_N_213 ),
    .CLR(rst_IBUF_482),
    .D(\U_h_10/U_cnt_digit_10/Mcount_cnt2 ),
    .Q(\U_h_10/U_cnt_digit_10/cnt [2])
  );
  FD   ten_or_one_1 (
    .C(clk_BUFGP_479),
    .D(\Result<1>1 ),
    .Q(ten_or_one[1])
  );
  FD   ten_or_one_2 (
    .C(clk_BUFGP_479),
    .D(\Result<2>1 ),
    .Q(ten_or_one[2])
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
    .I1(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data6 ),
    .I2(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data6 ),
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
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_510 (
    .I0(ten_or_one[0]),
    .I1(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data5 ),
    .I2(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data5 ),
    .O(Mmux_seg_data_mux0000_510_23)
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
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_58 (
    .I0(ten_or_one[0]),
    .I1(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data4 ),
    .I2(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data4 ),
    .O(Mmux_seg_data_mux0000_58_33)
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
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_56 (
    .I0(ten_or_one[0]),
    .I1(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data3 ),
    .I2(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data3 ),
    .O(Mmux_seg_data_mux0000_56_31)
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
    .I1(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data2 ),
    .I2(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data2 ),
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
    .I1(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data1 ),
    .I2(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data1 ),
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
  LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_seg_data_mux0000_5 (
    .I0(ten_or_one[0]),
    .I1(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data ),
    .I2(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data ),
    .O(Mmux_seg_data_mux0000_5_21)
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
    .S(\U_freq_div_1000/Mcount_cnt_cy<1>_rt_126 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [1])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<1>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [0]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<1>_rt_126 ),
    .O(Result[1])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<2>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<2>_rt_128 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [2])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<2>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [1]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<2>_rt_128 ),
    .O(Result[2])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<3>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<3>_rt_130 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [3])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<3>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [2]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<3>_rt_130 ),
    .O(Result[3])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<4>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<4>_rt_132 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [4])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<4>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [3]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<4>_rt_132 ),
    .O(Result[4])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<5>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<5>_rt_134 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [5])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<5>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [4]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<5>_rt_134 ),
    .O(Result[5])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<6>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<6>_rt_136 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [6])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<6>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [5]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<6>_rt_136 ),
    .O(Result[6])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<7>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<7>_rt_138 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [7])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<7>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [6]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<7>_rt_138 ),
    .O(Result[7])
  );
  MUXCY   \U_freq_div_1000/Mcount_cnt_cy<8>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_freq_div_1000/Mcount_cnt_cy<8>_rt_140 ),
    .O(\U_freq_div_1000/Mcount_cnt_cy [8])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<8>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [7]),
    .LI(\U_freq_div_1000/Mcount_cnt_cy<8>_rt_140 ),
    .O(Result[8])
  );
  XORCY   \U_freq_div_1000/Mcount_cnt_xor<9>  (
    .CI(\U_freq_div_1000/Mcount_cnt_cy [8]),
    .LI(\U_freq_div_1000/Mcount_cnt_xor<9>_rt_152 ),
    .O(Result[9])
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
    .O(\Result<0>2 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<1>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_186 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_186 ),
    .O(\Result<1>2 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_188 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_188 ),
    .O(\Result<2>2 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_190 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_190 ),
    .O(\Result<3>1 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_192 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_192 ),
    .O(\Result<4>1 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_194 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_194 ),
    .O(\Result<5>1 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_196 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_196 ),
    .O(\Result<6>1 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_198 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_198 ),
    .O(\Result<7>1 )
  );
  MUXCY   \U_h_1/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_h_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_200 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_200 ),
    .O(\Result<8>1 )
  );
  XORCY   \U_h_1/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_h_1/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_h_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_212 ),
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
    .O(\Result<0>3 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<1>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_259 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_259 ),
    .O(\Result<1>3 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_261 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_261 ),
    .O(\Result<2>3 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_263 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_263 ),
    .O(\Result<3>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_265 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_265 ),
    .O(\Result<4>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_267 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_267 ),
    .O(\Result<5>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_269 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_269 ),
    .O(\Result<6>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_271 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_271 ),
    .O(\Result<7>2 )
  );
  MUXCY   \U_min_1/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_273 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_273 ),
    .O(\Result<8>2 )
  );
  XORCY   \U_min_1/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_min_1/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_min_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_285 ),
    .O(\Result<9>2 )
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
    .O(\Result<0>4 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_377 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_377 ),
    .O(\Result<1>4 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_379 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_379 ),
    .O(\Result<2>4 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_381 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_381 ),
    .O(\Result<3>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_383 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_383 ),
    .O(\Result<4>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_385 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_385 ),
    .O(\Result<5>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_387 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_387 ),
    .O(\Result<6>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_389 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_389 ),
    .O(\Result<7>3 )
  );
  MUXCY   \U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_391 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_391 ),
    .O(\Result<8>3 )
  );
  XORCY   \U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_sec_1/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_403 ),
    .O(\Result<9>3 )
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
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_317 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_317 ),
    .O(\Result<1>5 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_319 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_319 ),
    .O(\Result<2>5 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_321 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_321 ),
    .O(\Result<3>4 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_323 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_323 ),
    .O(\Result<4>4 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_325 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_325 ),
    .O(\Result<5>4 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_327 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_327 ),
    .O(\Result<6>4 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_329 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_329 ),
    .O(\Result<7>4 )
  );
  MUXCY   \U_min_10/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_331 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_331 ),
    .O(\Result<8>4 )
  );
  XORCY   \U_min_10/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_min_10/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_min_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_343 ),
    .O(\Result<9>4 )
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
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_435 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [1])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<1>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [0]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_435 ),
    .O(\Result<1>6 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [1]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_437 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [2])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<2>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [1]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_437 ),
    .O(\Result<2>6 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [2]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_439 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [3])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<3>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [2]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_439 ),
    .O(\Result<3>5 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [3]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_441 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [4])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<4>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [3]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_441 ),
    .O(\Result<4>5 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [4]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_443 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [5])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<5>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [4]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_443 ),
    .O(\Result<5>5 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [5]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_445 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [6])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<6>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [5]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_445 ),
    .O(\Result<6>5 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [6]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_447 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [7])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<7>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [6]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_447 ),
    .O(\Result<7>5 )
  );
  MUXCY   \U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [7]),
    .DI(N0),
    .S(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_449 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [8])
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<8>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [7]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_449 ),
    .O(\Result<8>5 )
  );
  XORCY   \U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>  (
    .CI(\U_sec_10/U_freq_div_10/Mcount_cnt_cy [8]),
    .LI(\U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_461 ),
    .O(\Result<9>5 )
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
    .INIT ( 8'h51 ))
  \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data41  (
    .I0(\U_h_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_h_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_h_10/U_cnt_digit_10/cnt [1]),
    .O(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data4 )
  );
  LUT3 #(
    .INIT ( 8'hFD ))
  \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data21  (
    .I0(\U_h_10/U_cnt_digit_10/cnt [1]),
    .I1(\U_h_10/U_cnt_digit_10/cnt [0]),
    .I2(\U_h_10/U_cnt_digit_10/cnt [2]),
    .O(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data2 )
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
    .I1(\U_min_10/U_cnt_digit_10/cnt [1]),
    .I2(\U_min_10/U_cnt_digit_10/cnt [0]),
    .O(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data5 )
  );
  LUT3 #(
    .INIT ( 8'h9F ))
  \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data111  (
    .I0(\U_min_10/U_cnt_digit_10/cnt [1]),
    .I1(\U_min_10/U_cnt_digit_10/cnt [0]),
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
    .INIT ( 8'h7A ))
  \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data61  (
    .I0(\U_h_10/U_cnt_digit_10/cnt [2]),
    .I1(\U_h_10/U_cnt_digit_10/cnt [0]),
    .I2(\U_h_10/U_cnt_digit_10/cnt [1]),
    .O(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data6 )
  );
  LUT3 #(
    .INIT ( 8'h2B ))
  \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data51  (
    .I0(\U_h_10/U_cnt_digit_10/cnt [2]),
    .I1(\U_h_10/U_cnt_digit_10/cnt [1]),
    .I2(\U_h_10/U_cnt_digit_10/cnt [0]),
    .O(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data5 )
  );
  LUT3 #(
    .INIT ( 8'h9F ))
  \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data111  (
    .I0(\U_h_10/U_cnt_digit_10/cnt [1]),
    .I1(\U_h_10/U_cnt_digit_10/cnt [0]),
    .I2(\U_h_10/U_cnt_digit_10/cnt [2]),
    .O(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data1 )
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
  LUT3 #(
    .INIT ( 8'h79 ))
  \U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data31  (
    .I0(\U_min_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_min_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_min_10/U_cnt_digit_10/cnt [1]),
    .O(\U_min_10/U_bcd_to_seg_mod_10/Mrom_seg_data3 )
  );
  LUT3 #(
    .INIT ( 8'h79 ))
  \U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data31  (
    .I0(\U_h_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_h_10/U_cnt_digit_10/cnt [2]),
    .I2(\U_h_10/U_cnt_digit_10/cnt [1]),
    .O(\U_h_10/U_bcd_to_seg_mod_10/Mrom_seg_data3 )
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
    .INIT ( 16'h0145 ))
  \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data41  (
    .I0(\U_h_1/U_bcd_cnt/cnt [0]),
    .I1(\U_h_1/U_bcd_cnt/cnt [1]),
    .I2(\U_h_1/U_bcd_cnt/cnt [2]),
    .I3(\U_h_1/U_bcd_cnt/cnt [3]),
    .O(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data4 )
  );
  LUT4 #(
    .INIT ( 16'h545F ))
  \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data21  (
    .I0(\U_h_1/U_bcd_cnt/cnt [3]),
    .I1(\U_h_1/U_bcd_cnt/cnt [0]),
    .I2(\U_h_1/U_bcd_cnt/cnt [2]),
    .I3(\U_h_1/U_bcd_cnt/cnt [1]),
    .O(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data2 )
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
  \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data111  (
    .I0(\U_h_1/U_bcd_cnt/cnt [1]),
    .I1(\U_h_1/U_bcd_cnt/cnt [3]),
    .I2(\U_h_1/U_bcd_cnt/cnt [0]),
    .I3(\U_h_1/U_bcd_cnt/cnt [2]),
    .O(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data1 )
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
  \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data61  (
    .I0(\U_h_1/U_bcd_cnt/cnt [3]),
    .I1(\U_h_1/U_bcd_cnt/cnt [2]),
    .I2(\U_h_1/U_bcd_cnt/cnt [1]),
    .I3(\U_h_1/U_bcd_cnt/cnt [0]),
    .O(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data6 )
  );
  LUT4 #(
    .INIT ( 16'h150B ))
  \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data51  (
    .I0(\U_h_1/U_bcd_cnt/cnt [3]),
    .I1(\U_h_1/U_bcd_cnt/cnt [0]),
    .I2(\U_h_1/U_bcd_cnt/cnt [1]),
    .I3(\U_h_1/U_bcd_cnt/cnt [2]),
    .O(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data5 )
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
  \U_h_1/U_bcd_to_seg_mod/Mrom_seg_data31  (
    .I0(\U_h_1/U_bcd_cnt/cnt [3]),
    .I1(\U_h_1/U_bcd_cnt/cnt [1]),
    .I2(\U_h_1/U_bcd_cnt/cnt [0]),
    .I3(\U_h_1/U_bcd_cnt/cnt [2]),
    .O(\U_h_1/U_bcd_to_seg_mod/Mrom_seg_data3 )
  );
  LUT2 #(
    .INIT ( 4'h6 ))
  \Mcount_ten_or_one_xor<1>11  (
    .I0(ten_or_one[1]),
    .I1(ten_or_one[0]),
    .O(\Result<1>1 )
  );
  LUT3 #(
    .INIT ( 8'h51 ))
  \U_h_10/U_cnt_digit_10/Mcount_cnt_xor<0>11  (
    .I0(\U_h_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_h_10/U_cnt_digit_10/cnt [1]),
    .I2(\U_h_10/U_cnt_digit_10/cnt [2]),
    .O(\U_h_10/U_cnt_digit_10/Mcount_cnt )
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
    .INIT ( 8'h62 ))
  \U_h_10/U_cnt_digit_10/Mcount_cnt_xor<1>11  (
    .I0(\U_h_10/U_cnt_digit_10/cnt [0]),
    .I1(\U_h_10/U_cnt_digit_10/cnt [1]),
    .I2(\U_h_10/U_cnt_digit_10/cnt [2]),
    .O(\U_h_10/U_cnt_digit_10/Mcount_cnt1 )
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
  \U_h_10/U_cnt_digit_10/Mcount_cnt_xor<2>11  (
    .I0(\U_h_10/U_cnt_digit_10/cnt [2]),
    .I1(\U_h_10/U_cnt_digit_10/cnt [1]),
    .I2(\U_h_10/U_cnt_digit_10/cnt [0]),
    .O(\U_h_10/U_cnt_digit_10/Mcount_cnt2 )
  );
  LUT3 #(
    .INIT ( 8'h6A ))
  \U_h_1/U_bcd_cnt/Mcount_cnt_xor<2>11  (
    .I0(\U_h_1/U_bcd_cnt/cnt [2]),
    .I1(\U_h_1/U_bcd_cnt/cnt [1]),
    .I2(\U_h_1/U_bcd_cnt/cnt [0]),
    .O(\U_h_1/U_bcd_cnt/Mcount_cnt2 )
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
    .I3(seg_com_2_491),
    .O(seg_com_mux0000[5])
  );
  LUT4 #(
    .INIT ( 16'hD8FF ))
  \seg_com_mux0000<4>1  (
    .I0(ten_or_one[1]),
    .I1(seg_com_3_492),
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
    .I3(seg_com_4_493),
    .O(seg_com_mux0000[3])
  );
  LUT4 #(
    .INIT ( 16'hD8FF ))
  \seg_com_mux0000<2>1  (
    .I0(ten_or_one[2]),
    .I1(seg_com_5_494),
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
    .I3(seg_com_6_495),
    .O(seg_com_mux0000[1])
  );
  LUT4 #(
    .INIT ( 16'hFE76 ))
  \seg_com_mux0000<0>1  (
    .I0(ten_or_one[2]),
    .I1(ten_or_one[1]),
    .I2(ten_or_one[0]),
    .I3(seg_com_7_496),
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
  \U_h_1/U_bcd_cnt/Mcount_cnt_xor<3>11  (
    .I0(\U_h_1/U_bcd_cnt/cnt [0]),
    .I1(\U_h_1/U_bcd_cnt/cnt [3]),
    .I2(\U_h_1/U_bcd_cnt/cnt [1]),
    .I3(\U_h_1/U_bcd_cnt/cnt [2]),
    .O(\U_h_1/U_bcd_cnt/Mcount_cnt3 )
  );
  IBUF   rst_IBUF (
    .I(rst),
    .O(rst_IBUF_482)
  );
  OBUF   clk_min_1_OBUF (
    .I(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .O(clk_min_1)
  );
  OBUF   seg_data_7_OBUF (
    .I(N0),
    .O(seg_data[7])
  );
  OBUF   seg_data_6_OBUF (
    .I(seg_data_6_517),
    .O(seg_data[6])
  );
  OBUF   seg_data_5_OBUF (
    .I(seg_data_5_516),
    .O(seg_data[5])
  );
  OBUF   seg_data_4_OBUF (
    .I(seg_data_4_515),
    .O(seg_data[4])
  );
  OBUF   seg_data_3_OBUF (
    .I(seg_data_3_514),
    .O(seg_data[3])
  );
  OBUF   seg_data_2_OBUF (
    .I(seg_data_2_513),
    .O(seg_data[2])
  );
  OBUF   seg_data_1_OBUF (
    .I(seg_data_1_512),
    .O(seg_data[1])
  );
  OBUF   seg_data_0_OBUF (
    .I(seg_data_0_511),
    .O(seg_data[0])
  );
  OBUF   seg_com_7_OBUF (
    .I(seg_com_7_496),
    .O(seg_com[7])
  );
  OBUF   seg_com_6_OBUF (
    .I(seg_com_6_495),
    .O(seg_com[6])
  );
  OBUF   seg_com_5_OBUF (
    .I(seg_com_5_494),
    .O(seg_com[5])
  );
  OBUF   seg_com_4_OBUF (
    .I(seg_com_4_493),
    .O(seg_com[4])
  );
  OBUF   seg_com_3_OBUF (
    .I(seg_com_3_492),
    .O(seg_com[3])
  );
  OBUF   seg_com_2_OBUF (
    .I(seg_com_2_491),
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
    .C(clk_BUFGP_479),
    .D(N1),
    .R(ten_or_one[0]),
    .Q(ten_or_one[0])
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<1>_rt  (
    .I0(\U_freq_div_1000/cnt [1]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<1>_rt_126 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<2>_rt  (
    .I0(\U_freq_div_1000/cnt [2]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<2>_rt_128 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<3>_rt  (
    .I0(\U_freq_div_1000/cnt [3]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<3>_rt_130 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<4>_rt  (
    .I0(\U_freq_div_1000/cnt [4]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<4>_rt_132 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<5>_rt  (
    .I0(\U_freq_div_1000/cnt [5]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<5>_rt_134 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<6>_rt  (
    .I0(\U_freq_div_1000/cnt [6]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<6>_rt_136 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<7>_rt  (
    .I0(\U_freq_div_1000/cnt [7]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<7>_rt_138 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_cy<8>_rt  (
    .I0(\U_freq_div_1000/cnt [8]),
    .O(\U_freq_div_1000/Mcount_cnt_cy<8>_rt_140 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [1]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_186 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [2]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_188 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [3]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_190 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [4]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_192 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [5]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_194 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [6]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_196 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [7]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_198 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [8]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_200 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [1]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_259 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [2]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_261 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [3]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_263 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [4]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_265 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [5]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_267 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [6]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_269 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [7]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_271 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [8]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_273 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [1]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<1>_rt_377 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [2]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<2>_rt_379 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [3]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<3>_rt_381 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [4]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<4>_rt_383 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [5]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<5>_rt_385 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [6]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<6>_rt_387 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [7]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<7>_rt_389 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [8]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_cy<8>_rt_391 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [1]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_317 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [2]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_319 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [3]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_321 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [4]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_323 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [5]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_325 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [6]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_327 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [7]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_329 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [8]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_331 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [1]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<1>_rt_435 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [2]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<2>_rt_437 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [3]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<3>_rt_439 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [4]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<4>_rt_441 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [5]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<5>_rt_443 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [6]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<6>_rt_445 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [7]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<7>_rt_447 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [8]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_cy<8>_rt_449 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_freq_div_1000/Mcount_cnt_xor<9>_rt  (
    .I0(\U_freq_div_1000/cnt [9]),
    .O(\U_freq_div_1000/Mcount_cnt_xor<9>_rt_152 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_h_1/U_freq_div_10/cnt [9]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_212 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_min_1/U_freq_div_10/cnt [9]),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_285 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_sec_1/U_freq_div_10/cnt [9]),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_xor<9>_rt_403 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_min_10/U_freq_div_10/cnt [9]),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_343 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>_rt  (
    .I0(\U_sec_10/U_freq_div_10/cnt [9]),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_xor<9>_rt_461 )
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_5_rt (
    .I0(seg_data_6_517),
    .O(Mmux_seg_data_mux0000_3_f5_5_rt_12)
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_4_rt (
    .I0(seg_data_5_516),
    .O(Mmux_seg_data_mux0000_3_f5_4_rt_11)
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_3_rt (
    .I0(seg_data_4_515),
    .O(Mmux_seg_data_mux0000_3_f5_3_rt_10)
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_2_rt (
    .I0(seg_data_3_514),
    .O(Mmux_seg_data_mux0000_3_f5_2_rt_9)
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_1_rt (
    .I0(seg_data_2_513),
    .O(Mmux_seg_data_mux0000_3_f5_1_rt_8)
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_0_rt (
    .I0(seg_data_1_512),
    .O(Mmux_seg_data_mux0000_3_f5_0_rt_7)
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  Mmux_seg_data_mux0000_3_f5_rt (
    .I0(seg_data_0_511),
    .O(Mmux_seg_data_mux0000_3_f5_rt_13)
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N46),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_475 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_476 ),
    .I3(\Result<9>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N49),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_417 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_418 ),
    .I3(\Result<9>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N52),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_357 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_358 ),
    .I3(\Result<9>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N55),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_299 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_300 ),
    .I3(\Result<9>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_91  (
    .I0(N58),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_226 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_227 ),
    .I3(\Result<9>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_91  (
    .I0(N60),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_168 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_167 ),
    .I3(Result[9]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_9 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_477 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_475 ),
    .I2(N45),
    .I3(\Result<8>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_419 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_417 ),
    .I2(N48),
    .I3(\Result<8>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_359 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_357 ),
    .I2(N51),
    .I3(\Result<8>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_301 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_299 ),
    .I2(N54),
    .I3(\Result<8>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_81  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_228 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_226 ),
    .I2(N57),
    .I3(\Result<8>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_81  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_166 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_168 ),
    .I2(N61),
    .I3(Result[8]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_8 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_477 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_475 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_476 ),
    .I3(\Result<7>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_419 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_417 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_418 ),
    .I3(\Result<7>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_359 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_357 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_358 ),
    .I3(\Result<7>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_301 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_299 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_300 ),
    .I3(\Result<7>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_71  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_228 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_226 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_227 ),
    .I3(\Result<7>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_71  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_166 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_168 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_167 ),
    .I3(Result[7]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_7 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_477 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_475 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_476 ),
    .I3(\Result<6>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_419 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_417 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_418 ),
    .I3(\Result<6>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_359 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_357 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_358 ),
    .I3(\Result<6>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_301 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_299 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_300 ),
    .I3(\Result<6>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_61  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_228 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_226 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_227 ),
    .I3(\Result<6>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_61  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_166 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_168 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_167 ),
    .I3(Result[6]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_6 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_477 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_475 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_476 ),
    .I3(\Result<5>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_419 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_417 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_418 ),
    .I3(\Result<5>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_359 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_357 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_358 ),
    .I3(\Result<5>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_301 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_299 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_300 ),
    .I3(\Result<5>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_51  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_228 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_226 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_227 ),
    .I3(\Result<5>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_51  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_166 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_168 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_167 ),
    .I3(Result[5]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_5 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_477 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_475 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_476 ),
    .I3(\Result<4>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_419 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_417 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_418 ),
    .I3(\Result<4>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_359 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_357 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_358 ),
    .I3(\Result<4>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_301 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_299 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_300 ),
    .I3(\Result<4>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_41  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_228 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_226 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_227 ),
    .I3(\Result<4>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_41  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_166 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_168 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_167 ),
    .I3(Result[4]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_4 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_477 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_475 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_476 ),
    .I3(\Result<3>5 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_419 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_417 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_418 ),
    .I3(\Result<3>3 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_359 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_357 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_358 ),
    .I3(\Result<3>4 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_301 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_299 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_300 ),
    .I3(\Result<3>2 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_31  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_228 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_226 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_227 ),
    .I3(\Result<3>1 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_31  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_166 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_168 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_167 ),
    .I3(Result[3]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_3 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_477 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_475 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_476 ),
    .I3(\Result<2>6 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_419 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_417 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_418 ),
    .I3(\Result<2>4 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_359 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_357 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_358 ),
    .I3(\Result<2>5 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_301 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_299 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_300 ),
    .I3(\Result<2>3 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_21  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_228 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_226 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_227 ),
    .I3(\Result<2>2 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_21  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_166 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_168 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_167 ),
    .I3(Result[2]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_2 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_477 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_475 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_476 ),
    .I3(\Result<1>6 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_419 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_417 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_418 ),
    .I3(\Result<1>4 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_359 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_357 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_358 ),
    .I3(\Result<1>5 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_301 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_299 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_300 ),
    .I3(\Result<1>3 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_11  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_228 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_226 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_227 ),
    .I3(\Result<1>2 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_11  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_166 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_168 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_167 ),
    .I3(Result[1]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_1 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_10/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_477 ),
    .I1(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_475 ),
    .I2(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_476 ),
    .I3(\Result<0>6 ),
    .O(\U_sec_10/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_sec_1/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_419 ),
    .I1(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_417 ),
    .I2(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_418 ),
    .I3(\Result<0>4 ),
    .O(\U_sec_1/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_10/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_359 ),
    .I1(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_357 ),
    .I2(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_358 ),
    .I3(\Result<0>5 ),
    .O(\U_min_10/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_min_1/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_301 ),
    .I1(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_299 ),
    .I2(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_300 ),
    .I3(\Result<0>3 ),
    .O(\U_min_1/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_h_1/U_freq_div_10/Mcount_cnt_eqn_01  (
    .I0(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_228 ),
    .I1(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_226 ),
    .I2(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_227 ),
    .I3(\Result<0>2 ),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h7F00 ))
  \U_freq_div_1000/Mcount_cnt_eqn_01  (
    .I0(\U_freq_div_1000/cnt_cmp_eq000012_166 ),
    .I1(\U_freq_div_1000/cnt_cmp_eq00007_168 ),
    .I2(\U_freq_div_1000/cnt_cmp_eq000016_167 ),
    .I3(Result[0]),
    .O(\U_freq_div_1000/Mcount_cnt_eqn_0 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_sec_10/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_sec_10/U_freq_div_10/cnt [4]),
    .I1(\U_sec_10/U_freq_div_10/cnt [5]),
    .I2(N44),
    .I3(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_477 ),
    .O(\U_sec_10/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_sec_1/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_sec_1/U_freq_div_10/cnt [4]),
    .I1(\U_sec_1/U_freq_div_10/cnt [5]),
    .I2(N47),
    .I3(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_419 ),
    .O(\U_sec_1/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_min_10/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_min_10/U_freq_div_10/cnt [4]),
    .I1(\U_min_10/U_freq_div_10/cnt [5]),
    .I2(N50),
    .I3(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_359 ),
    .O(\U_min_10/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_min_1/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_min_1/U_freq_div_10/cnt [4]),
    .I1(\U_min_1/U_freq_div_10/cnt [5]),
    .I2(N53),
    .I3(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_301 ),
    .O(\U_min_1/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_h_1/U_freq_div_10/cnt_cmp_eq000038  (
    .I0(\U_h_1/U_freq_div_10/cnt [4]),
    .I1(\U_h_1/U_freq_div_10/cnt [5]),
    .I2(N56),
    .I3(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_228 ),
    .O(\U_h_1/U_freq_div_10/cnt_cmp_eq0000 )
  );
  LUT4 #(
    .INIT ( 16'h1000 ))
  \U_freq_div_1000/cnt_cmp_eq000024  (
    .I0(\U_freq_div_1000/cnt [2]),
    .I1(\U_freq_div_1000/cnt [3]),
    .I2(N59),
    .I3(\U_freq_div_1000/cnt_cmp_eq000012_166 ),
    .O(\U_freq_div_1000/cnt_cmp_eq0000 )
  );
  BUFGP   clk_BUFGP (
    .I(clk),
    .O(clk_BUFGP_479)
  );
  INV   \U_freq_div_1000/Mcount_cnt_lut<0>_INV_0  (
    .I(\U_freq_div_1000/cnt [0]),
    .O(\U_freq_div_1000/Mcount_cnt_lut [0])
  );
  INV   \U_h_1/U_freq_div_10/Mcount_cnt_lut<0>_INV_0  (
    .I(\U_h_1/U_freq_div_10/cnt [0]),
    .O(\U_h_1/U_freq_div_10/Mcount_cnt_lut [0])
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
  INV   \U_sec_10/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_sec_10/U_freq_div_10/clk_div_N_462 ),
    .O(\U_sec_10/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_sec_10/U_cnt_digit_10/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_sec_10/U_cnt_digit_10/cnt [0]),
    .O(\U_sec_10/U_cnt_digit_10/Mcount_cnt )
  );
  INV   \U_sec_1/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_sec_1/U_freq_div_10/clk_div_N_404 ),
    .O(\U_sec_1/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_sec_1/U_bcd_cnt/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_sec_1/U_bcd_cnt/cnt [0]),
    .O(\U_sec_1/U_bcd_cnt/Mcount_cnt )
  );
  INV   \U_min_10/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_min_10/U_freq_div_10/clk_div_N_344 ),
    .O(\U_min_10/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_min_10/U_cnt_digit_10/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_min_10/U_cnt_digit_10/cnt [0]),
    .O(\U_min_10/U_cnt_digit_10/Mcount_cnt )
  );
  INV   \U_min_1/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_min_1/U_freq_div_10/clk_div_N_286 ),
    .O(\U_min_1/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_min_1/U_bcd_cnt/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_min_1/U_bcd_cnt/cnt [0]),
    .O(\U_min_1/U_bcd_cnt/Mcount_cnt )
  );
  INV   \U_h_1/U_freq_div_10/clk_div_N_not00011_INV_0  (
    .I(\U_h_1/U_freq_div_10/clk_div_N_213 ),
    .O(\U_h_1/U_freq_div_10/clk_div_N_not0001 )
  );
  INV   \U_h_1/U_bcd_cnt/Mcount_cnt_xor<0>11_INV_0  (
    .I(\U_h_1/U_bcd_cnt/cnt [0]),
    .O(\U_h_1/U_bcd_cnt/Mcount_cnt )
  );
  INV   \U_freq_div_1000/clk_div_N_not00011_INV_0  (
    .I(\U_freq_div_1000/clk_div_N_153 ),
    .O(\U_freq_div_1000/clk_div_N_not0001 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_sec_10/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_sec_10/U_freq_div_10/cnt [1]),
    .I1(\U_sec_10/U_freq_div_10/cnt [0]),
    .I2(\U_sec_10/U_freq_div_10/cnt [2]),
    .I3(\U_sec_10/U_freq_div_10/cnt [3]),
    .LO(N44),
    .O(\U_sec_10/U_freq_div_10/cnt_cmp_eq000011_475 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_sec_10/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_sec_10/U_freq_div_10/cnt [4]),
    .I1(\U_sec_10/U_freq_div_10/cnt [5]),
    .LO(N45),
    .O(\U_sec_10/U_freq_div_10/cnt_cmp_eq000015_476 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_sec_10/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_sec_10/U_freq_div_10/cnt [6]),
    .I1(\U_sec_10/U_freq_div_10/cnt [7]),
    .I2(\U_sec_10/U_freq_div_10/cnt [8]),
    .I3(\U_sec_10/U_freq_div_10/cnt [9]),
    .LO(N46),
    .O(\U_sec_10/U_freq_div_10/cnt_cmp_eq000036_477 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_sec_1/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_sec_1/U_freq_div_10/cnt [2]),
    .I1(\U_sec_1/U_freq_div_10/cnt [3]),
    .I2(\U_sec_1/U_freq_div_10/cnt [0]),
    .I3(\U_sec_1/U_freq_div_10/cnt [1]),
    .LO(N47),
    .O(\U_sec_1/U_freq_div_10/cnt_cmp_eq000011_417 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_sec_1/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_sec_1/U_freq_div_10/cnt [4]),
    .I1(\U_sec_1/U_freq_div_10/cnt [5]),
    .LO(N48),
    .O(\U_sec_1/U_freq_div_10/cnt_cmp_eq000015_418 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_sec_1/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_sec_1/U_freq_div_10/cnt [6]),
    .I1(\U_sec_1/U_freq_div_10/cnt [7]),
    .I2(\U_sec_1/U_freq_div_10/cnt [8]),
    .I3(\U_sec_1/U_freq_div_10/cnt [9]),
    .LO(N49),
    .O(\U_sec_1/U_freq_div_10/cnt_cmp_eq000036_419 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_min_10/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_min_10/U_freq_div_10/cnt [1]),
    .I1(\U_min_10/U_freq_div_10/cnt [0]),
    .I2(\U_min_10/U_freq_div_10/cnt [2]),
    .I3(\U_min_10/U_freq_div_10/cnt [3]),
    .LO(N50),
    .O(\U_min_10/U_freq_div_10/cnt_cmp_eq000011_357 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_min_10/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_min_10/U_freq_div_10/cnt [4]),
    .I1(\U_min_10/U_freq_div_10/cnt [5]),
    .LO(N51),
    .O(\U_min_10/U_freq_div_10/cnt_cmp_eq000015_358 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_min_10/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_min_10/U_freq_div_10/cnt [6]),
    .I1(\U_min_10/U_freq_div_10/cnt [7]),
    .I2(\U_min_10/U_freq_div_10/cnt [8]),
    .I3(\U_min_10/U_freq_div_10/cnt [9]),
    .LO(N52),
    .O(\U_min_10/U_freq_div_10/cnt_cmp_eq000036_359 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_min_1/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_min_1/U_freq_div_10/cnt [2]),
    .I1(\U_min_1/U_freq_div_10/cnt [3]),
    .I2(\U_min_1/U_freq_div_10/cnt [0]),
    .I3(\U_min_1/U_freq_div_10/cnt [1]),
    .LO(N53),
    .O(\U_min_1/U_freq_div_10/cnt_cmp_eq000011_299 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_min_1/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_min_1/U_freq_div_10/cnt [4]),
    .I1(\U_min_1/U_freq_div_10/cnt [5]),
    .LO(N54),
    .O(\U_min_1/U_freq_div_10/cnt_cmp_eq000015_300 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_min_1/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_min_1/U_freq_div_10/cnt [6]),
    .I1(\U_min_1/U_freq_div_10/cnt [7]),
    .I2(\U_min_1/U_freq_div_10/cnt [8]),
    .I3(\U_min_1/U_freq_div_10/cnt [9]),
    .LO(N55),
    .O(\U_min_1/U_freq_div_10/cnt_cmp_eq000036_301 )
  );
  LUT4_D #(
    .INIT ( 16'h0002 ))
  \U_h_1/U_freq_div_10/cnt_cmp_eq000011  (
    .I0(\U_h_1/U_freq_div_10/cnt [2]),
    .I1(\U_h_1/U_freq_div_10/cnt [3]),
    .I2(\U_h_1/U_freq_div_10/cnt [0]),
    .I3(\U_h_1/U_freq_div_10/cnt [1]),
    .LO(N56),
    .O(\U_h_1/U_freq_div_10/cnt_cmp_eq000011_226 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_h_1/U_freq_div_10/cnt_cmp_eq000015  (
    .I0(\U_h_1/U_freq_div_10/cnt [4]),
    .I1(\U_h_1/U_freq_div_10/cnt [5]),
    .LO(N57),
    .O(\U_h_1/U_freq_div_10/cnt_cmp_eq000015_227 )
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \U_h_1/U_freq_div_10/cnt_cmp_eq000036  (
    .I0(\U_h_1/U_freq_div_10/cnt [6]),
    .I1(\U_h_1/U_freq_div_10/cnt [7]),
    .I2(\U_h_1/U_freq_div_10/cnt [8]),
    .I3(\U_h_1/U_freq_div_10/cnt [9]),
    .LO(N58),
    .O(\U_h_1/U_freq_div_10/cnt_cmp_eq000036_228 )
  );
  LUT4_D #(
    .INIT ( 16'h2000 ))
  \U_freq_div_1000/cnt_cmp_eq00007  (
    .I0(\U_freq_div_1000/cnt [1]),
    .I1(\U_freq_div_1000/cnt [9]),
    .I2(\U_freq_div_1000/cnt [8]),
    .I3(\U_freq_div_1000/cnt [0]),
    .LO(N59),
    .O(\U_freq_div_1000/cnt_cmp_eq00007_168 )
  );
  LUT4_D #(
    .INIT ( 16'h8000 ))
  \U_freq_div_1000/cnt_cmp_eq000012  (
    .I0(\U_freq_div_1000/cnt [4]),
    .I1(\U_freq_div_1000/cnt [5]),
    .I2(\U_freq_div_1000/cnt [6]),
    .I3(\U_freq_div_1000/cnt [7]),
    .LO(N60),
    .O(\U_freq_div_1000/cnt_cmp_eq000012_166 )
  );
  LUT2_D #(
    .INIT ( 4'h1 ))
  \U_freq_div_1000/cnt_cmp_eq000016  (
    .I0(\U_freq_div_1000/cnt [2]),
    .I1(\U_freq_div_1000/cnt [3]),
    .LO(N61),
    .O(\U_freq_div_1000/cnt_cmp_eq000016_167 )
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

