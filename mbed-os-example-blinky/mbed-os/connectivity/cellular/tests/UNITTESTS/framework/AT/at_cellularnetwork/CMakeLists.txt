# Copyright (c) 2021 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

set(TEST_NAME at_cellularnetwork-unittest)

add_executable(${TEST_NAME})

target_compile_definitions(${TEST_NAME}
    PRIVATE
        DEVICE_SERIAL=1
        DEVICE_INTERRUPTIN=1
        MBED_CONF_PLATFORM_DEFAULT_SERIAL_BAUD_RATE=115200
        MBED_CONF_CELLULAR_AT_HANDLER_BUFFER_SIZE=32
)

target_sources(${TEST_NAME}
    PRIVATE
        ${mbed-os_SOURCE_DIR}/connectivity/cellular/source/framework/AT/AT_CellularNetwork.cpp
        ${mbed-os_SOURCE_DIR}/connectivity/cellular/source/framework/common/CellularUtil.cpp
        at_cellularnetworktest.cpp
)

target_link_libraries(${TEST_NAME}
    PRIVATE
        mbed-headers-platform
        mbed-headers-events
        mbed-headers-rtos
        mbed-headers-drivers
        mbed-headers-hal
        mbed-headers-netsocket
        mbed-headers-cellular
        mbed-stubs-netsocket
        mbed-stubs-cellular
        mbed-stubs-platform
        mbed-stubs-events
        gmock_main
)

add_test(NAME "${TEST_NAME}" COMMAND ${TEST_NAME})

set_tests_properties(${TEST_NAME} PROPERTIES LABELS "cellular")
