# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(motor_acel C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

file (GLOB SRC "src/*.c"
        "src/mpu6050/*.c"
        "src/servo/*.c"
        "src/init/*.c"
        "src/pico-ssd1306/*.c")

# Add executable. Default name is the project name, version 0.1

add_executable(motor_acel ${SRC})

pico_set_program_name(motor_acel "motor_acel")
pico_set_program_version(motor_acel "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(motor_acel 0)
pico_enable_stdio_usb(motor_acel 1)

# Add the standard library to the build
target_link_libraries(motor_acel
        pico_stdlib
        hardware_i2c
        hardware_pwm
        hardware_adc)

# Add the standard include files to the build
target_include_directories(motor_acel PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/src
        ${CMAKE_CURRENT_LIST_DIR}/src/mpu6050
        ${CMAKE_CURRENT_LIST_DIR}/src/servo
        ${CMAKE_CURRENT_LIST_DIR}/src/init
        ${CMAKE_CURRENT_LIST_DIR}/src/pico-ssd1306
)

# Add any user requested libraries
target_link_libraries(motor_acel 
        
        )

pico_add_extra_outputs(motor_acel)

