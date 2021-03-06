
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name abc -dir "D:/logic/abc/planAhead_run_5" -part xc3s1000fg676-5
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "aefde.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {aefde.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {add6bit.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top add6bit $srcset
add_files [list {aefde.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s1000fg676-5
