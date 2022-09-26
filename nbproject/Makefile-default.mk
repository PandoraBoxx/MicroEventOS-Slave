#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PwmSignal05Slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PwmSignal05Slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=machine/event_process.c machine/msim_machine.c machine/servo_process.c machine/timer_machine.c machine/adcv_machine.c peripheral/gpio_config.c peripheral/msim_config.c peripheral/pwm_config.c peripheral/qeim_config.c peripheral/timer_config.c peripheral/adcv_config.c system/system_init.c system/system_interrupt.c system/system_traps.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/machine/event_process.o ${OBJECTDIR}/machine/msim_machine.o ${OBJECTDIR}/machine/servo_process.o ${OBJECTDIR}/machine/timer_machine.o ${OBJECTDIR}/machine/adcv_machine.o ${OBJECTDIR}/peripheral/gpio_config.o ${OBJECTDIR}/peripheral/msim_config.o ${OBJECTDIR}/peripheral/pwm_config.o ${OBJECTDIR}/peripheral/qeim_config.o ${OBJECTDIR}/peripheral/timer_config.o ${OBJECTDIR}/peripheral/adcv_config.o ${OBJECTDIR}/system/system_init.o ${OBJECTDIR}/system/system_interrupt.o ${OBJECTDIR}/system/system_traps.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/machine/event_process.o.d ${OBJECTDIR}/machine/msim_machine.o.d ${OBJECTDIR}/machine/servo_process.o.d ${OBJECTDIR}/machine/timer_machine.o.d ${OBJECTDIR}/machine/adcv_machine.o.d ${OBJECTDIR}/peripheral/gpio_config.o.d ${OBJECTDIR}/peripheral/msim_config.o.d ${OBJECTDIR}/peripheral/pwm_config.o.d ${OBJECTDIR}/peripheral/qeim_config.o.d ${OBJECTDIR}/peripheral/timer_config.o.d ${OBJECTDIR}/peripheral/adcv_config.o.d ${OBJECTDIR}/system/system_init.o.d ${OBJECTDIR}/system/system_interrupt.o.d ${OBJECTDIR}/system/system_traps.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/machine/event_process.o ${OBJECTDIR}/machine/msim_machine.o ${OBJECTDIR}/machine/servo_process.o ${OBJECTDIR}/machine/timer_machine.o ${OBJECTDIR}/machine/adcv_machine.o ${OBJECTDIR}/peripheral/gpio_config.o ${OBJECTDIR}/peripheral/msim_config.o ${OBJECTDIR}/peripheral/pwm_config.o ${OBJECTDIR}/peripheral/qeim_config.o ${OBJECTDIR}/peripheral/timer_config.o ${OBJECTDIR}/peripheral/adcv_config.o ${OBJECTDIR}/system/system_init.o ${OBJECTDIR}/system/system_interrupt.o ${OBJECTDIR}/system/system_traps.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=machine/event_process.c machine/msim_machine.c machine/servo_process.c machine/timer_machine.c machine/adcv_machine.c peripheral/gpio_config.c peripheral/msim_config.c peripheral/pwm_config.c peripheral/qeim_config.c peripheral/timer_config.c peripheral/adcv_config.c system/system_init.c system/system_interrupt.c system/system_traps.c main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PwmSignal05Slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33CH64MP202S1
MP_LINKER_FILE_OPTION=,--script=p33CH64MP202S1.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/machine/event_process.o: machine/event_process.c  .generated_files/flags/default/ce978b5b592732e794fc1975ba2fb83278b4abfc .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/event_process.o.d 
	@${RM} ${OBJECTDIR}/machine/event_process.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/event_process.c  -o ${OBJECTDIR}/machine/event_process.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/event_process.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/msim_machine.o: machine/msim_machine.c  .generated_files/flags/default/334940eb9076bccc24c5676a2ab199e7855d8929 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/msim_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/msim_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/msim_machine.c  -o ${OBJECTDIR}/machine/msim_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/msim_machine.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/servo_process.o: machine/servo_process.c  .generated_files/flags/default/769b8d7d15cdb3203947f967777d9c680c01a6a0 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/servo_process.o.d 
	@${RM} ${OBJECTDIR}/machine/servo_process.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/servo_process.c  -o ${OBJECTDIR}/machine/servo_process.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/servo_process.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/timer_machine.o: machine/timer_machine.c  .generated_files/flags/default/974e43b3064125008eaa3e34aa3d20c7550ce0d5 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/timer_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/timer_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/timer_machine.c  -o ${OBJECTDIR}/machine/timer_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/timer_machine.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/adcv_machine.o: machine/adcv_machine.c  .generated_files/flags/default/487beac6f36fc8584a17d82d51c400e48716cb21 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/adcv_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/adcv_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/adcv_machine.c  -o ${OBJECTDIR}/machine/adcv_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/adcv_machine.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/gpio_config.o: peripheral/gpio_config.c  .generated_files/flags/default/35e10b28086fbd2aac230585c9b2da722cb0ebca .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/gpio_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/gpio_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/gpio_config.c  -o ${OBJECTDIR}/peripheral/gpio_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/gpio_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/msim_config.o: peripheral/msim_config.c  .generated_files/flags/default/2f4b6b552ddd1ccf64b50f1cc56064659b70b304 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/msim_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/msim_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/msim_config.c  -o ${OBJECTDIR}/peripheral/msim_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/msim_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/pwm_config.o: peripheral/pwm_config.c  .generated_files/flags/default/277f2c696e6e3bf654475e178837002ce4264ea .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/pwm_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/pwm_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/pwm_config.c  -o ${OBJECTDIR}/peripheral/pwm_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/pwm_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/qeim_config.o: peripheral/qeim_config.c  .generated_files/flags/default/8f15dd0b71195a35fc960ab2d78dadd860610fce .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/qeim_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/qeim_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/qeim_config.c  -o ${OBJECTDIR}/peripheral/qeim_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/qeim_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/timer_config.o: peripheral/timer_config.c  .generated_files/flags/default/41c054bb90e01d45b900c39bdaa4ba288dddd682 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/timer_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/timer_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/timer_config.c  -o ${OBJECTDIR}/peripheral/timer_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/timer_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/adcv_config.o: peripheral/adcv_config.c  .generated_files/flags/default/861e2f3ee2a7480cf20f0c03090744df000a6e32 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/adcv_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/adcv_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/adcv_config.c  -o ${OBJECTDIR}/peripheral/adcv_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/adcv_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_init.o: system/system_init.c  .generated_files/flags/default/553b2e8a6d8177a8dd3ce8cd9b1bf77e6b7282ad .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_init.o.d 
	@${RM} ${OBJECTDIR}/system/system_init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_init.c  -o ${OBJECTDIR}/system/system_init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_init.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_interrupt.o: system/system_interrupt.c  .generated_files/flags/default/77e3f52133cfd3deb4cf6baee4aeb004c5c6ce73 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/system/system_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_interrupt.c  -o ${OBJECTDIR}/system/system_interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_interrupt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_traps.o: system/system_traps.c  .generated_files/flags/default/5f131c0c7a7ee0ed2abf013a555e1be079dc9aab .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_traps.o.d 
	@${RM} ${OBJECTDIR}/system/system_traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_traps.c  -o ${OBJECTDIR}/system/system_traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/36d2462d4fbb24ed89ccc65c9de2a6d9e206c575 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
else
${OBJECTDIR}/machine/event_process.o: machine/event_process.c  .generated_files/flags/default/e05b8d85f8277a98d728e7c95118c52fd0fbf7b .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/event_process.o.d 
	@${RM} ${OBJECTDIR}/machine/event_process.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/event_process.c  -o ${OBJECTDIR}/machine/event_process.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/event_process.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/msim_machine.o: machine/msim_machine.c  .generated_files/flags/default/c66acdd82984351245e8ed054d8d824ef3089b29 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/msim_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/msim_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/msim_machine.c  -o ${OBJECTDIR}/machine/msim_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/msim_machine.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/servo_process.o: machine/servo_process.c  .generated_files/flags/default/c58665199f88c98226d191db56f6badf11b46078 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/servo_process.o.d 
	@${RM} ${OBJECTDIR}/machine/servo_process.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/servo_process.c  -o ${OBJECTDIR}/machine/servo_process.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/servo_process.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/timer_machine.o: machine/timer_machine.c  .generated_files/flags/default/6e720dc9b3b5551f8766e1774409c0e358a4dd5b .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/timer_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/timer_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/timer_machine.c  -o ${OBJECTDIR}/machine/timer_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/timer_machine.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/adcv_machine.o: machine/adcv_machine.c  .generated_files/flags/default/cbbeb8fcc335a22ca7e827ec402226e4ff7bd312 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/adcv_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/adcv_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/adcv_machine.c  -o ${OBJECTDIR}/machine/adcv_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/adcv_machine.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/gpio_config.o: peripheral/gpio_config.c  .generated_files/flags/default/fb580008d1d2c48e8e1b49423deebfdb9ae41c0b .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/gpio_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/gpio_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/gpio_config.c  -o ${OBJECTDIR}/peripheral/gpio_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/gpio_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/msim_config.o: peripheral/msim_config.c  .generated_files/flags/default/d9a31a762e1935ca55ddcbb848c911c78362661e .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/msim_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/msim_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/msim_config.c  -o ${OBJECTDIR}/peripheral/msim_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/msim_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/pwm_config.o: peripheral/pwm_config.c  .generated_files/flags/default/265f490508dfe15f1f45ded33f31ea2224d7f32 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/pwm_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/pwm_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/pwm_config.c  -o ${OBJECTDIR}/peripheral/pwm_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/pwm_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/qeim_config.o: peripheral/qeim_config.c  .generated_files/flags/default/e6fcae807b9e14ae1e39a47c8853ee59034c4286 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/qeim_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/qeim_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/qeim_config.c  -o ${OBJECTDIR}/peripheral/qeim_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/qeim_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/timer_config.o: peripheral/timer_config.c  .generated_files/flags/default/b3fff5719ccc56681dcd9865bf69c8fcfc5a700f .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/timer_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/timer_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/timer_config.c  -o ${OBJECTDIR}/peripheral/timer_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/timer_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/adcv_config.o: peripheral/adcv_config.c  .generated_files/flags/default/625acebb29160cd3b85f7605c07b4ad5ec4f763b .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/adcv_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/adcv_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/adcv_config.c  -o ${OBJECTDIR}/peripheral/adcv_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/adcv_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_init.o: system/system_init.c  .generated_files/flags/default/dd05e9cd886fba4146c1e2dfe24ed7f5cb8eed69 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_init.o.d 
	@${RM} ${OBJECTDIR}/system/system_init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_init.c  -o ${OBJECTDIR}/system/system_init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_init.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_interrupt.o: system/system_interrupt.c  .generated_files/flags/default/757c7c6b803ead1ba63a9d7f3c8cdfe4b4ad28a8 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/system/system_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_interrupt.c  -o ${OBJECTDIR}/system/system_interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_interrupt.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_traps.o: system/system_traps.c  .generated_files/flags/default/7f724d884b7bc71606e750f67663896cfda1c63 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_traps.o.d 
	@${RM} ${OBJECTDIR}/system/system_traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_traps.c  -o ${OBJECTDIR}/system/system_traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/87b6ebc6c63193e26337c717687e2b624045d9cd .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PwmSignal05Slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/PwmSignal05Slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	
else
${DISTDIR}/PwmSignal05Slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/PwmSignal05Slave.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	${MP_CC_DIR}/xc16-bin2hex ${DISTDIR}/PwmSignal05Slave.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:


# Target called by master project, if any (multi core devices)
.create-sub-image: dist/${CND_CONF}/${IMAGE_TYPE}/$(SUB_IMAGE_NAME).s
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/$(SUB_IMAGE_NAME).s: nbproject/Makefile-default.mk ${DISTDIR}/PwmSignal05Slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  nbproject/Makefile-${CND_CONF}.mk    
	${MP_CC_DIR}/xc16-bin2hex ${DISTDIR}/PwmSignal05Slave.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} --image ${DISTDIR}/$(SUB_IMAGE_NAME) $(SUB_IMAGE_ADDRESS_COMMAND) 
else
${DISTDIR}/$(SUB_IMAGE_NAME).s: nbproject/Makefile-default.mk ${DISTDIR}/PwmSignal05Slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  nbproject/Makefile-${CND_CONF}.mk   
	${MP_CC_DIR}/xc16-bin2hex ${DISTDIR}/PwmSignal05Slave.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} --image ${DISTDIR}/$(SUB_IMAGE_NAME) $(SUB_IMAGE_ADDRESS_COMMAND) 
endif


# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
