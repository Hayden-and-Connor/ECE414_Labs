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
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Lab_03.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Lab_03.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c ../Utilities/Adafruit_2_4_LCD_Serial_Library/glcdfont.c ../Utilities/Adafruit_2_4_LCD_Serial_Library/tft_gfx.c ../Utilities/Adafruit_2_4_LCD_Serial_Library/tft_master.c ../Utilities/gpio.c ../Utilities/Screen/screen.c ../Utilities/vector.c ../Utilities/Screen/adc_intf.c ../Utilities/Screen/TouchScreen.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/1137048943/glcdfont.o ${OBJECTDIR}/_ext/1137048943/tft_gfx.o ${OBJECTDIR}/_ext/1137048943/tft_master.o ${OBJECTDIR}/_ext/1174900389/gpio.o ${OBJECTDIR}/_ext/980479936/screen.o ${OBJECTDIR}/_ext/1174900389/vector.o ${OBJECTDIR}/_ext/980479936/adc_intf.o ${OBJECTDIR}/_ext/980479936/TouchScreen.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/_ext/1137048943/glcdfont.o.d ${OBJECTDIR}/_ext/1137048943/tft_gfx.o.d ${OBJECTDIR}/_ext/1137048943/tft_master.o.d ${OBJECTDIR}/_ext/1174900389/gpio.o.d ${OBJECTDIR}/_ext/980479936/screen.o.d ${OBJECTDIR}/_ext/1174900389/vector.o.d ${OBJECTDIR}/_ext/980479936/adc_intf.o.d ${OBJECTDIR}/_ext/980479936/TouchScreen.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/1137048943/glcdfont.o ${OBJECTDIR}/_ext/1137048943/tft_gfx.o ${OBJECTDIR}/_ext/1137048943/tft_master.o ${OBJECTDIR}/_ext/1174900389/gpio.o ${OBJECTDIR}/_ext/980479936/screen.o ${OBJECTDIR}/_ext/1174900389/vector.o ${OBJECTDIR}/_ext/980479936/adc_intf.o ${OBJECTDIR}/_ext/980479936/TouchScreen.o

# Source Files
SOURCEFILES=main.c ../Utilities/Adafruit_2_4_LCD_Serial_Library/glcdfont.c ../Utilities/Adafruit_2_4_LCD_Serial_Library/tft_gfx.c ../Utilities/Adafruit_2_4_LCD_Serial_Library/tft_master.c ../Utilities/gpio.c ../Utilities/Screen/screen.c ../Utilities/vector.c ../Utilities/Screen/adc_intf.c ../Utilities/Screen/TouchScreen.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Lab_03.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX250F128B
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPKOBSKDEPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1137048943/glcdfont.o: ../Utilities/Adafruit_2_4_LCD_Serial_Library/glcdfont.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1137048943" 
	@${RM} ${OBJECTDIR}/_ext/1137048943/glcdfont.o.d 
	@${RM} ${OBJECTDIR}/_ext/1137048943/glcdfont.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1137048943/glcdfont.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPKOBSKDEPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/1137048943/glcdfont.o.d" -o ${OBJECTDIR}/_ext/1137048943/glcdfont.o ../Utilities/Adafruit_2_4_LCD_Serial_Library/glcdfont.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1137048943/tft_gfx.o: ../Utilities/Adafruit_2_4_LCD_Serial_Library/tft_gfx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1137048943" 
	@${RM} ${OBJECTDIR}/_ext/1137048943/tft_gfx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1137048943/tft_gfx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1137048943/tft_gfx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPKOBSKDEPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/1137048943/tft_gfx.o.d" -o ${OBJECTDIR}/_ext/1137048943/tft_gfx.o ../Utilities/Adafruit_2_4_LCD_Serial_Library/tft_gfx.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1137048943/tft_master.o: ../Utilities/Adafruit_2_4_LCD_Serial_Library/tft_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1137048943" 
	@${RM} ${OBJECTDIR}/_ext/1137048943/tft_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1137048943/tft_master.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1137048943/tft_master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPKOBSKDEPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/1137048943/tft_master.o.d" -o ${OBJECTDIR}/_ext/1137048943/tft_master.o ../Utilities/Adafruit_2_4_LCD_Serial_Library/tft_master.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1174900389/gpio.o: ../Utilities/gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1174900389" 
	@${RM} ${OBJECTDIR}/_ext/1174900389/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1174900389/gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1174900389/gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPKOBSKDEPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/1174900389/gpio.o.d" -o ${OBJECTDIR}/_ext/1174900389/gpio.o ../Utilities/gpio.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/980479936/screen.o: ../Utilities/Screen/screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/980479936" 
	@${RM} ${OBJECTDIR}/_ext/980479936/screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/980479936/screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/980479936/screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPKOBSKDEPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/980479936/screen.o.d" -o ${OBJECTDIR}/_ext/980479936/screen.o ../Utilities/Screen/screen.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1174900389/vector.o: ../Utilities/vector.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1174900389" 
	@${RM} ${OBJECTDIR}/_ext/1174900389/vector.o.d 
	@${RM} ${OBJECTDIR}/_ext/1174900389/vector.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1174900389/vector.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPKOBSKDEPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/1174900389/vector.o.d" -o ${OBJECTDIR}/_ext/1174900389/vector.o ../Utilities/vector.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/980479936/adc_intf.o: ../Utilities/Screen/adc_intf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/980479936" 
	@${RM} ${OBJECTDIR}/_ext/980479936/adc_intf.o.d 
	@${RM} ${OBJECTDIR}/_ext/980479936/adc_intf.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/980479936/adc_intf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPKOBSKDEPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/980479936/adc_intf.o.d" -o ${OBJECTDIR}/_ext/980479936/adc_intf.o ../Utilities/Screen/adc_intf.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/980479936/TouchScreen.o: ../Utilities/Screen/TouchScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/980479936" 
	@${RM} ${OBJECTDIR}/_ext/980479936/TouchScreen.o.d 
	@${RM} ${OBJECTDIR}/_ext/980479936/TouchScreen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/980479936/TouchScreen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPKOBSKDEPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/980479936/TouchScreen.o.d" -o ${OBJECTDIR}/_ext/980479936/TouchScreen.o ../Utilities/Screen/TouchScreen.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1137048943/glcdfont.o: ../Utilities/Adafruit_2_4_LCD_Serial_Library/glcdfont.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1137048943" 
	@${RM} ${OBJECTDIR}/_ext/1137048943/glcdfont.o.d 
	@${RM} ${OBJECTDIR}/_ext/1137048943/glcdfont.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1137048943/glcdfont.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/1137048943/glcdfont.o.d" -o ${OBJECTDIR}/_ext/1137048943/glcdfont.o ../Utilities/Adafruit_2_4_LCD_Serial_Library/glcdfont.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1137048943/tft_gfx.o: ../Utilities/Adafruit_2_4_LCD_Serial_Library/tft_gfx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1137048943" 
	@${RM} ${OBJECTDIR}/_ext/1137048943/tft_gfx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1137048943/tft_gfx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1137048943/tft_gfx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/1137048943/tft_gfx.o.d" -o ${OBJECTDIR}/_ext/1137048943/tft_gfx.o ../Utilities/Adafruit_2_4_LCD_Serial_Library/tft_gfx.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1137048943/tft_master.o: ../Utilities/Adafruit_2_4_LCD_Serial_Library/tft_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1137048943" 
	@${RM} ${OBJECTDIR}/_ext/1137048943/tft_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1137048943/tft_master.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1137048943/tft_master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/1137048943/tft_master.o.d" -o ${OBJECTDIR}/_ext/1137048943/tft_master.o ../Utilities/Adafruit_2_4_LCD_Serial_Library/tft_master.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1174900389/gpio.o: ../Utilities/gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1174900389" 
	@${RM} ${OBJECTDIR}/_ext/1174900389/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1174900389/gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1174900389/gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/1174900389/gpio.o.d" -o ${OBJECTDIR}/_ext/1174900389/gpio.o ../Utilities/gpio.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/980479936/screen.o: ../Utilities/Screen/screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/980479936" 
	@${RM} ${OBJECTDIR}/_ext/980479936/screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/980479936/screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/980479936/screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/980479936/screen.o.d" -o ${OBJECTDIR}/_ext/980479936/screen.o ../Utilities/Screen/screen.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1174900389/vector.o: ../Utilities/vector.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1174900389" 
	@${RM} ${OBJECTDIR}/_ext/1174900389/vector.o.d 
	@${RM} ${OBJECTDIR}/_ext/1174900389/vector.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1174900389/vector.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/1174900389/vector.o.d" -o ${OBJECTDIR}/_ext/1174900389/vector.o ../Utilities/vector.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/980479936/adc_intf.o: ../Utilities/Screen/adc_intf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/980479936" 
	@${RM} ${OBJECTDIR}/_ext/980479936/adc_intf.o.d 
	@${RM} ${OBJECTDIR}/_ext/980479936/adc_intf.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/980479936/adc_intf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/980479936/adc_intf.o.d" -o ${OBJECTDIR}/_ext/980479936/adc_intf.o ../Utilities/Screen/adc_intf.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/980479936/TouchScreen.o: ../Utilities/Screen/TouchScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/980479936" 
	@${RM} ${OBJECTDIR}/_ext/980479936/TouchScreen.o.d 
	@${RM} ${OBJECTDIR}/_ext/980479936/TouchScreen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/980479936/TouchScreen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../" -MMD -MF "${OBJECTDIR}/_ext/980479936/TouchScreen.o.d" -o ${OBJECTDIR}/_ext/980479936/TouchScreen.o ../Utilities/Screen/TouchScreen.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Lab_03.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -DPKOBSKDEPlatformTool=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Lab_03.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=PKOBSKDEPlatformTool=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Lab_03.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Lab_03.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Lab_03.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
