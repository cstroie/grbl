/*
  unipolar.h - code for driving unipolar motors
  Part of Grbl

  Copyright (c) 2014-2016 Sungeun K. Jeon for Gnea Research LLC
  Copyright (c) 2018 Costin Stroie <costinstroie@gmail.com>

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "grbl.h"

/* The order is DBCA */
uint8_t half_step[] = {0b0001, 0b0101, 0b0100, 0b0110, 0b0010, 0b1010, 0b1000, 0b1001};
uint8_t full_step[] = {0b0101, 0b0110, 0b1010, 0b1001};
uint8_t wave_step[] = {0b0001, 0b0100, 0b0010, 0b1000};

const uint8_t up_steps = 8;

uint8_t up_step_forward(uint8_t step) {
    return (step + 1) & (up_steps - 1);
}

uint8_t up_step_backward(uint8_t step) {
    return (step - 1) & (up_steps - 1);
}

uint8_t up_get_pins(uint8_t step) {
    return half_step[step];
}

