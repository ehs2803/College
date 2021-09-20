
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name mux_my -dir "C:/logic/mux_my/planAhead_run_1" -part xc3s1000fg676-5
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "my_mux.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {mtmux.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top my_mux $srcset
add_files [list {my_mux.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s1000fg676-5
