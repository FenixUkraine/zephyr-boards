# SPDX-License-Identifier: Apache-2.0

board_runner_args(pyocd "--target=stm32h563vgtx" "--frequency=4000000")
board_runner_args(jlink "--device=STM32H563VG" "--speed=4000" "--reset-after-load")
board_runner_args(dfu-util "--pid=0483:df11" "--alt=0" "--dfuse")
board_runner_args(stm32cubeprogrammer "--port=swd" "--reset-mode=hw")
board_runner_args(openocd "--tcl-port=6666")
board_runner_args(openocd --cmd-pre-init "gdb_report_data_abort enable")
board_runner_args(openocd "--no-halt")

# board_runner_args(nulink "-f")

include(${ZEPHYR_BASE}/boards/common/pyocd.board.cmake)
include(${ZEPHYR_BASE}/boards/common/nulink.board.cmake)
include(${ZEPHYR_BASE}/boards/common/openocd.board.cmake)
include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
include(${ZEPHYR_BASE}/boards/common/dfu-util.board.cmake)
include(${ZEPHYR_BASE}/boards/common/stm32cubeprogrammer.board.cmake)
# include(${ZEPHYR_BASE}/boards/common/canopen.board.cmake)

# board_set_flasher(jlink)
