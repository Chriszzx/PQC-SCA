# Hey Emacs, this is a -*- makefile -*-
#----------------------------------------------------------------------------
#
# Makefile for ChipWhisperer SimpleSerial-AES Program
#
#----------------------------------------------------------------------------
# On command line:
#
# make all = Make software.
#
# make clean = Clean out built project files.
#
# make coff = Convert ELF to AVR COFF.
#
# make extcoff = Convert ELF to AVR Extended COFF.
#
# make program = Download the hex file to the device, using avrdude.
#                Please customize the avrdude settings below first!
#
# make debug = Start either simulavr or avarice as specified for debugging,
#              with avr-gdb or avr-insight as the front end for debugging.
#
# make filename.s = Just compile filename.c into the assembler code only.
#
# make filename.i = Create a preprocessed source file for use in submitting
#                   bug reports to the GCC project.
#
# To rebuild project do "make clean" then "make all".
#----------------------------------------------------------------------------

# Target file name (without extension).
# This is the name of the compiled .hex file.
TARGET = simpleserial-kyber

ASFLAGS += -mfpu=fpv4-sp-d16

# List C source files here.
# Header files (.h) are automatically pulled in.
SRC += main.c kem.c indcpa.c polyvec.c poly.c ntt.c cbd.c verify.c fips202.c symmetric-fips202.c
OPT = 0	# 关闭优化
# -----------------------------------------------------------------------------
ifeq ($(CRYPTO_OPTIONS),)
CRYPTO_OPTIONS = NONE
endif

SS_VER = SS_VER_1_1
ASRC += fastaddsub.S fastbasemul.S fastinvntt.S fastntt.S matacc_asm.S poly_asm.S reduce.S keccakf1600.S
#Add simpleserial project to build
include ../../hardware/victims/firmware/simpleserial/Makefile.simpleserial

FIRMWAREPATH = ../../hardware/victims/firmware/.
include $(FIRMWAREPATH)/Makefile.inc

