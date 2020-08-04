CC  = hexagon-clang

Q6VERSION = v66

INCLUDES = -I ../include \
           -I ../../../../../../../incs \
           -I ../../../../../../../incs/stddef

CFLAGS  += -O2 -g -m${Q6VERSION} -mhvx -mhvx-length=128B -DQDSP6SS_PUB_BASE=0xFE200000 $(INCLUDES)

all: clean qprintf

ASM_DIR = ../asm_src
ASM_SRCS = $(ASM_DIR)/qprintf.S

C_SRCS = ../src/qprintf.c

ASM_OBJS = $(ASM_SRCS:%.S=%.obj)
C_OBJS = $(C_SRCS:%.c=%.o)

$(ASM_OBJS): $(ASM_SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

qprintf: $(ASM_OBJS) $(C_OBJS)
	ar rcs libqprintf.a $(ASM_OBJS) $(C_OBJS)

clean:
	rm -f libqprintf.a $(ASM_OBJS) $(C_OBJS)
