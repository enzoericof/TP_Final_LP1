################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/c-phalopod.c.c \
../src/computadora.c \
../src/preparacion.c \
../src/tablero.c \
../src/usuario.c 

C_DEPS += \
./src/c-phalopod.c.d \
./src/computadora.d \
./src/preparacion.d \
./src/tablero.d \
./src/usuario.d 

OBJS += \
./src/c-phalopod.c.o \
./src/computadora.o \
./src/preparacion.o \
./src/tablero.o \
./src/usuario.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/c-phalopod.c.d ./src/c-phalopod.c.o ./src/computadora.d ./src/computadora.o ./src/preparacion.d ./src/preparacion.o ./src/tablero.d ./src/tablero.o ./src/usuario.d ./src/usuario.o

.PHONY: clean-src

