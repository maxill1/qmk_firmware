/* Copyright (C) 2024 Luca Mazzilli
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

/*#define MATRIX_UNSELECT_DRIVE_HIGH*/

/* key matrix size */
#define MATRIX_ROWS 8 //had to use 8 row to map the additional 2 underglow rows (LED_MATRIX_ROWS is ignored in initing the array g_led_config)
#define MATRIX_COLS 21

#include "config_led.h"


