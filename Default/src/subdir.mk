################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BITOps.cpp \
../src/BedgraphWrite.cpp \
../src/LengthParse.cpp \
../src/ReadParse.cpp \
../src/ReweightIterator.cpp \
../src/SmartMap.cpp 

OBJS += \
./src/BITOps.o \
./src/BedgraphWrite.o \
./src/LengthParse.o \
./src/ReadParse.o \
./src/ReweightIterator.o \
./src/SmartMap.o 

CPP_DEPS += \
./src/BITOps.d \
./src/BedgraphWrite.d \
./src/LengthParse.d \
./src/ReadParse.d \
./src/ReweightIterator.d \
./src/SmartMap.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I../gzstream -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


