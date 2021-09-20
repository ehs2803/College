
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name bujugi -dir "D:/logic-20191202/bujugi/planAhead_run_1" -part xc3s1000fg676-5
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "bunju.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {bunju.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top bunju $srcset
add_files [list {bunju.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s1000fg676-5
