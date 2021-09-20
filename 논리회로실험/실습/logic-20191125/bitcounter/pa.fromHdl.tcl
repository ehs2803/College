
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name bitcounter -dir "D:/logic-20191125/bitcounter/planAhead_run_1" -part xc3s1000fg676-5
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "bitcounter8.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {bitcounter8.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top bitcounter8 $srcset
add_files [list {bitcounter8.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s1000fg676-5
