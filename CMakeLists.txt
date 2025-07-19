# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/pico/pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(Pico-FreeRTOS) # <--- Project name: Pico-FreeRTOS. Is your target 'fusioncoreos'?

pico_sdk_init()

add_compile_definitions(PICO_RP2040_SET_INTERRUPT_VECTOR_TABLE_TO_RAM=1) # Empfohlen für FreeRTOS
add_compile_definitions(PICO_DEFAULT_UART_BAUD_RATE=115200) # Oder was du nutzen möchtest
add_compile_options(-I${CMAKE_CURRENT_SOURCE_DIR}/ProjectFiles)


add_subdirectory(freertos)
add_subdirectory(librarys)
add_subdirectory(ProjectFiles)