#########################################################################
#									#
#									#
#  Makefile for Beaglebone Black version of the Xinu operating system	#
#									#
#  includes: .deps and .defs						#
#									#
#									#
#########################################################################

COMPILER_ROOT	=	arm-none-eabi-
PNAME		=	bbb
PLAT		=	Platform_$(PNAME)
TOPDIR		=	..

CC		=	${COMPILER_ROOT}gcc
LD		=	${COMPILER_ROOT}ld
OBJCOPY		=	${COMPILER_ROOT}objcopy
XINU		=	$(TOPDIR)/compile/xinu.elf
XINUBIN		=	$(TOPDIR)/compile/xinu.bin
XINUBOOT	=	$(TOPDIR)/compile/xinu
BUILDMAKE	=	$(TOPDIR)/compile/bin/build-make
MKVERS		=	$(TOPDIR)/compile/bin/mkvers

MAKEDEP		=	$(CC) -M -MG

DEPSFILE	=	.deps
DEFSFILE	=	.defs
VERSIONFILE	=	version
LDSCRIPT	=	ld.script
MKVERS		=	$(TOPDIR)/compile/bin/mkvers
REBUILDFLAGS	=	-s $(TOPDIR)/system  debug.c 	\
			-s $(TOPDIR)/lib			\
			-s $(TOPDIR)/device/tty			

INCLUDE		=	-I$(TOPDIR)/include
DEFS		= 	-DBSDURG -DVERSION=\""`cat $(VERSIONFILE)`"\"

# Compiler flags
CFLAGS  = -mcpu=cortex-a8 -mno-unaligned-access -marm -fno-builtin -fno-stack-protector -nostdlib -c -Wall -O ${DEFS} ${INCLUDE}
SFLAGS  = ${INCLUDE}

# Loader flags

LDFLAGS = -dn -m armelf -Map xinu.map -T ld.script

all:	xinu

#--------------------------------------------------------------------------------
# Handle generation of a new version string when initialize is recompiled
#--------------------------------------------------------------------------------

newversion:
	@echo creating new version
	@$(MKVERS) $(PNAME) > version

#--------------------------------------------------------------------------------
# Include generic make targets and rules from the file generated by build-make
#--------------------------------------------------------------------------------
-include $(DEFSFILE)

#--------------------------------------------------------------------------------
# Add files that require special rules and place start.o at the front
#--------------------------------------------------------------------------------
LD_LIST = binaries/start.o $(filter-out binaries/start.o,$(OBJ_FILES))

#------------------------------------------------------------
# Rules for files that need special handling
#------------------------------------------------------------

# Set up the required build directory structure

BLDDIRS	= binaries
export

#--------------------------------------------------------------------------------
# Specific additional rules and exceptions
#--------------------------------------------------------------------------------

xinu:	Makefile $(BLDDIRS) $(DEFSFILE) $(DEPSFILE) $(LD_LIST)
	@echo;echo 'Loading object files to produce xinu'
	@$(LD) $(LDFLAGS) $(LD_LIST) -o $(XINU) -L/usr/lib/gcc/arm-none-eabi/7.3.1/ -lgcc
	@$(OBJCOPY) -O binary $(XINU) $(XINUBIN)
	@./uboot-tool/mkimage -A arm -O linux -T kernel -C none -a 0x81000000 -e 0x81000000 -d $(XINUBIN) $(XINUBOOT)

$(BLDDIRS): 
	@mkdir -p $(BLDDIRS)

objects: $(LD_LIST)

clean:
	@echo removing .o files
	@rm -f ${LD_LIST}
	@echo removing xinu ...
	@rm -f $(XINU)
	@rm -f $(XINUBIN)
	@rm -f $(XINUBOOT)

#--------------------------------------------------------------------------------
# Locations of source directories and exceptions (.c and .[sS] files to exclude)
#--------------------------------------------------------------------------------
	
$(DEFSFILE):
	@rm -f $(DEFSFILE)
	@echo "" > $(DEFSFILE)
	@make rebuild

$(DEPSFILE):
	@rm -f $(DEPSFILE)
	@echo "" > $(DEPSFILE)
	@make depend

rebuild:
	@echo Rebuilding the $(DEFSFILE) file
	@$(BUILDMAKE) $(REBUILDFLAGS) > $(DEFSFILE)

defclean:
	rm -f $(DEFSFILE)
	echo "" > $(DEFSFILE)

depend: $(DEFSFILE)
	@echo;echo Making all dependencies in $(DEPSFILE)
	@$(MAKEDEP) ${INCLUDE} ${SRC_FULL} > $(DEPSFILE)
	@echo;echo Finished making dependencies

depclean:
	rm -f $(DEPSFILE)
	echo "" > $(DEPSFILE)

-include $(DEPSFILE)
