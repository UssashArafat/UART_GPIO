# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct D:\Projects\SOC_Projects\UART_GPIO_Zedboard\VitisWorkspace\System_wrapper_1\platform.tcl
# 
# OR launch xsct and run below command.
# source D:\Projects\SOC_Projects\UART_GPIO_Zedboard\VitisWorkspace\System_wrapper_1\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {System_wrapper_1}\
-hw {D:\Projects\SOC_Projects\UART_GPIO_Zedboard\System_wrapper.xsa}\
-fsbl-target {psu_cortexa53_0} -out {D:/Projects/SOC_Projects/UART_GPIO_Zedboard/VitisWorkspace}

platform write
domain create -name {standalone_ps7_cortexa9_0} -display-name {standalone_ps7_cortexa9_0} -os {standalone} -proc {ps7_cortexa9_0} -runtime {cpp} -arch {32-bit} -support-app {empty_application}
platform generate -domains 
platform active {System_wrapper_1}
domain active {zynq_fsbl}
domain active {standalone_ps7_cortexa9_0}
platform generate -quick
catch {platform remove System_wrapper}
platform generate
platform clean
