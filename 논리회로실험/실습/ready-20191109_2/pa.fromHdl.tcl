
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name ready-20191109_2 -dir "C:/LOGIC/ready-20191109_2/planAhead_run_1" -part xc3s1000fg676-5
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "full_adder_4b.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {half_adder.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {full_adder.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {full_adder_4b.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top full_adder_4b $srcset
add_files [list {full_adder_4b.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s1000fg676-5
