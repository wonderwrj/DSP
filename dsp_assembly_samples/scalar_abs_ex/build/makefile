CC  = hexagon-clang

Q6VERSION = v66

INCLUDES = -I ../include \
		   -I ./../../qprintf/include \
           -I ../../../../../../../incs \
           -I ../../../../../../../incs/stddef

CFLAGS  += -O2 -g -m${Q6VERSION} -mhvx -mhvx-length=128B -DQDSP6SS_PUB_BASE=0xFE200000 $(INCLUDES)

LLIB = -lhexagon ./../../qprintf/build/libqprintf.a

all: clean scalar_abs_ex sim

C_SRCS = ../test/scalar_abs_ex.c \
		 ../src/scalar_abs_ex_i.c

C_OBJS = $(C_SRCS:%.c=%.o)

scalar_abs_ex: $(C_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) -o scalar_abs_ex $(LLIB)

clean:
	rm -f scalar_abs_ex $(C_OBJS) pmu_statsfile.txt stats.txt

sim:
	hexagon-sim --timing scalar_abs_ex

