################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Crystalfontz128x128_ST7735.obj: ../Crystalfontz128x128_ST7735.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="Crystalfontz128x128_ST7735.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.obj: ../HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MSP_EXP432P401R.obj: ../MSP_EXP432P401R.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="MSP_EXP432P401R.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

context.obj: ../context.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="context.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

display.obj: ../display.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="display.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

fontfixed6x8.obj: ../fontfixed6x8.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="fontfixed6x8.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

lcd_display.obj: ../lcd_display.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="lcd_display.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

line.obj: ../line.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="line.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

ped_adc.obj: ../ped_adc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="ped_adc.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

string.obj: ../string.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="string.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

uart_task.obj: ../uart_task.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="uart_task.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: ../uartecho.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/home/daniel/Programs/ti/xdctools_3_31_01_33_core/xs" --xdcpath="/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/packages;/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/bios_6_45_01_29/packages;/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/tidrivers_msp43x_2_16_00_08/packages;/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/uia_2_00_05_50/packages;/home/daniel/Programs/ti/ccsv6/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M4F -p ti.platforms.msp432:MSP432P401R -r release -c "/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6" --compileOptions "-mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path=\"/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include\" --include_path=\"/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS\" --include_path=\"/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R\" --include_path=\"/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS\" --include_path=\"/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc\" --include_path=\"/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx\" --include_path=\"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include\" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_warning=255 --diag_wrap=off --gen_func_subsections=on  " "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/compiler.opt: | configPkg/linker.cmd
configPkg/: | configPkg/linker.cmd


