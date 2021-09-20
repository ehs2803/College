
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name bcdcounter -dir "D:/logic-20191125/bcdcounter/planAhead_run_1" -part xc3s1000fg676-5
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "bcd_counter_seg.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {bcd_seg.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {bcd_count.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {bcd_counter_seg.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top bcd_counter_seg $srcset
add_files [list {bcd_counter_seg.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s1000fg676-5
