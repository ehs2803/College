
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name two_dig_display2 -dir "D:/two_dig_display2/planAhead_run_1" -part xc3s1000fg676-4
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "two_digit_dis.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {mod_6_counter.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {frq_div10.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {bcd_to_seg_mod.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {bcd_counter.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {two_digit_dis.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top two_digit_dis $srcset
add_files [list {two_digit_dis.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s1000fg676-4
