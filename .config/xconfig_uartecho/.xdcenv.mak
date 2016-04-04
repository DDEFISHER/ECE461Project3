#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/packages;/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/bios_6_45_01_29/packages;/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/tidrivers_msp43x_2_16_00_08/packages;/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/uia_2_00_05_50/packages;/home/daniel/Programs/ti/ccsv6/ccs_base;/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R/.config
override XDCROOT = /home/daniel/Programs/ti/xdctools_3_31_01_33_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/packages;/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/bios_6_45_01_29/packages;/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/tidrivers_msp43x_2_16_00_08/packages;/home/daniel/Programs/ti/tirtos_msp43x_2_16_00_08/products/uia_2_00_05_50/packages;/home/daniel/Programs/ti/ccsv6/ccs_base;/home/daniel/Programs/ti/workspace2/uartecho_MSP_EXP432P401R_TI_MSP432P401R/.config;/home/daniel/Programs/ti/xdctools_3_31_01_33_core/packages;..
HOSTOS = Linux
endif
