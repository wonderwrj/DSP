CC  = hexagon-clang

Q6VERSION = v66

INCLUDES = -I ../include \
		   -I ./../../qprintf/include \
           -I ../../../../../../../incs \
           -I ../../../../../../../incs/stddef

CFLAGS  += -O2 -g -m${Q6VERSION} -mhvx -mhvx-length=128B -DQDSP6SS_PUB_BASE=0xFE200000 $(INCLUDES)

LLIB = -lhexagon ./../../qprintf/build/libqprintf.a

all: clean hvx_samples sim

C_SRCS = ../test/hvx_samples.c \
		../src/hvx_samples_utility.c \
		 ../src/hvx_splat_i.c \
		 ../src/hvx_vzero_i.c \
		 ../src/hvx_q_vset_i.c \
		 ../src/hvx_vmux_i.c \
		../src/hvx_multiply_with_reduction_i.c \
		../src/hvx_multiply_vec_by_vec_with_reduction_i.c \
		../src/hvx_vmemu_i.c

C_OBJS = $(C_SRCS:%.c=%.o)

hvx_samples: $(C_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) -o hvx_samples $(LLIB)

clean:
	rm -f hvx_samples $(C_OBJS) pmu_statsfile.txt stats.txt

sim:
	hexagon-sim --timing hvx_samples

