# No operating system
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
cmake_minimum_required(VERSION 3.21)

# specify cross compilers and tools
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
# skip compiler checks
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

project(Motor35 C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set(COMMON_FLAGS "-specs=nosys.specs -specs=nano.specs -u _printf_float -u _scanf_float")

add_compile_options(-mcpu=cortex-m3 -mthumb -mthumb-interwork)
add_compile_options(-ffunction-sections -fdata-sections -fno-common -fmessage-length=0)

# uncomment to mitigate c++17 absolute addresses warnings
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-register")

# Enable assembler files preprocessing
add_compile_options($<$<COMPILE_LANGUAGE:ASM>:-x$<SEMICOLON>assembler-with-cpp>)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    add_compile_options(-Og -g)
endif ()

include_directories(
    ./
    ${CMAKE_SOURCE_DIR}/drivers/CMSIS/Include
    ${CMAKE_SOURCE_DIR}/drivers/CMSIS/Device/ST/STM32F1xx/Include
    ${CMAKE_SOURCE_DIR}/drivers/STM32F1xx_HAL_Driver/Inc
    ${CMAKE_SOURCE_DIR}/drivers/STM32F1xx_HAL_Driver/Inc/Legacy
    ${CMAKE_SOURCE_DIR}/device/driver
    ${CMAKE_SOURCE_DIR}/device/encoder
    ${CMAKE_SOURCE_DIR}/device/motor
    ${CMAKE_SOURCE_DIR}/device/signal
    ${CMAKE_SOURCE_DIR}/device/signal/LedMX
    ${CMAKE_SOURCE_DIR}/device/signal/MultiButton
    ${CMAKE_SOURCE_DIR}/hal/inc
    ${CMAKE_SOURCE_DIR}/main
    ${CMAKE_SOURCE_DIR}/main/protocols
    ${CMAKE_SOURCE_DIR}/main/setup
    ${CMAKE_SOURCE_DIR}/utils/
    ${CMAKE_SOURCE_DIR}/utils/mem
    ${CMAKE_SOURCE_DIR}/utils/modbus
    ${CMAKE_SOURCE_DIR}/utils/MultiTimer
)
add_definitions(-DUSE_HAL_DRIVER -D__MICROLIB -DSTM32F1 -DSTM32F1xx -DSTM32F103xB)

aux_source_directory(${CMAKE_SOURCE_DIR}/drivers/STM32F1xx_HAL_Driver/Src HAL_DRIVER)
aux_source_directory(${CMAKE_SOURCE_DIR}/drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates SYSTEM)
aux_source_directory(${CMAKE_SOURCE_DIR}/device/driver DRIVER)
aux_source_directory(${CMAKE_SOURCE_DIR}/device/encoder ENCODER)
aux_source_directory(${CMAKE_SOURCE_DIR}/device/motor MOTOR)
aux_source_directory(${CMAKE_SOURCE_DIR}/device/signal SIGNAL)
aux_source_directory(${CMAKE_SOURCE_DIR}/device/signal/LedMX LEDMX)
aux_source_directory(${CMAKE_SOURCE_DIR}/device/signal/MultiButton BUTTON)
aux_source_directory(${CMAKE_SOURCE_DIR}/hal/src DEVHAL)
aux_source_directory(${CMAKE_SOURCE_DIR}/main MAIN)
aux_source_directory(${CMAKE_SOURCE_DIR}/main/protocols PROTOCOLS)
aux_source_directory(${CMAKE_SOURCE_DIR}/main/setup SETUP)
aux_source_directory(${CMAKE_SOURCE_DIR}/utils UTILS)
aux_source_directory(${CMAKE_SOURCE_DIR}/utils/mem MEM)
aux_source_directory(${CMAKE_SOURCE_DIR}/utils/modbus MODBUS)
aux_source_directory(${CMAKE_SOURCE_DIR}/utils/MultiTimer MULTITIMER)

set(STARTUP       ${CMAKE_SOURCE_DIR}/drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xb.s)
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/linker/STM32F103XB_FLASH.ld)

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-mcpu=cortex-m3 -mthumb -mthumb-interwork)
add_link_options(-T ${LINKER_SCRIPT})

add_executable(${PROJECT_NAME}.elf 
    ${HAL_DRIVER} ${SYSTEM} ${DRIVER} 
    ${ENCODER} ${MOTOR} 
    ${SIGNAL} ${LEDMX} ${BUTTON} 
    ${DEVHAL} 
    ${MAIN} ${PROTOCOLS} ${SETUP} 
    ${UTILS} ${MEM} ${MODBUS} ${MULTITIMER} 
    ${STARTUP} ${LINKER_SCRIPT}
)

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE}
Building ${BIN_FILE}")
