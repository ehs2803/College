
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name nand_my -dir "D:/logic1/nand_my/planAhead_run_3" -part xc3s1000fg676-5
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "mynand.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {mynand.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top mynand $srcset
add_files [list {mynand.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s1000fg676-5
