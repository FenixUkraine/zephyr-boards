# Copyright (c) 2021 Nordic Semiconductor ASA
# SPDX-License-Identifier: Apache-2.0
if(CONFIG_BOARD_FXA500_03)
  zephyr_library()
  zephyr_library_sources(board.c)
endif()
