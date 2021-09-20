
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name my_buf_1 -dir "D:/logic/my_buf_1/planAhead_run_2" -part xc3s1000fg676-5
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "buf_gate.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {buf_gate.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top buf_gate $srcset
add_files [list {buf_gate.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s1000fg676-5
