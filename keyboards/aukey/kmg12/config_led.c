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
#ifdef RGB_MATRIX_ENABLE

#include "rgb_matrix.h"
#include "config_led.h"

led_config_t g_led_config = { {
  {   0,      1,   2,       3,       4,      5,   6,      7,       8,      9, 10,  11,     12, NO_LED,     13,     14,     15,  NO_LED, NO_LED, NO_LED, NO_LED  },
  {  16,     17,  18,      19,      20,     21,  22,     23,      24,     25, 26,  27,     28,     29,     30,     31,     32,      33,     34,     35,     36  },
  {  37,     38,  39,      40,      41,     42,  43,     44,      45,     46, 47,  48,     49, NO_LED,     50,     51,     52,      53,     54,     55,     56  },
  {  57,     58,  59,      60,      61,     62,  63,     64,      65,     66, 67,  68,     69,     70, NO_LED, NO_LED, NO_LED,      71,     72,     73,    152  }, //153 is led marked as DL23 on PCB
  {  74,     75,  76,      77,      78,     79,  80,     81,      82,     83, 84,  85, NO_LED,     86, NO_LED,     87, NO_LED,      88,     89,     90,     91  },
  {  92,     93,  94,     114,     115,    116,  95,    117,     118,   119,  96,  97,     98,     99,    100,    101,    102,  NO_LED,    103,    104,    153 }, //154 is led DL24,  114,115,116=41,41,40   14,115,116=41,41,40   117,118,119=39,38,37
  //underglow
  {105,106,107,108,109,110,111,112,113,120,121,122,123,124,125,126,127,128,129,130,154},//this row contains led marked as DL1,25-36,43-50 on PCB
  {131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151}, //this row contains led marked as DL2-22 on PCB

}, {
    { 1 *12, 0  }, { 2 *12, 0  }, { 3 *12, 0  }, { 4 *12, 0  }, { 5 *12,  0  }, { 6 *12,  0  }, { 7 *12,  0  }, { 8 *12, 0  }, { 9 *12,  0  }, { 10*12, 0  }, { 11*12, 0  }, { 12*12, 0  }, { 13*12, 0  },                { 15*12, 0  }, { 16*12, 0  }, { 17*12, 0  },
    { 1 *12, 11 }, { 2 *12, 11 }, { 3 *12, 11 }, { 4 *12, 11 }, { 5 *12,  11 }, { 6 *12,  11 }, { 7 *12,  11 }, { 8 *12, 11 }, { 9 *12,  11 }, { 10*12, 11 }, { 11*12, 11 }, { 12*12, 11 }, { 13*12, 11 }, { 14*12, 11 }, { 15*12, 11 }, { 16*12, 11 }, { 17*12, 11 }, { 18*12, 11 }, { 19*12, 11 }, { 20*12, 11 }, { 21*12, 11 },
    { 1 *12, 22 }, { 2 *12, 22 }, { 3 *12, 22 }, { 4 *12, 22 }, { 5 *12,  22 }, { 6 *12,  22 }, { 7 *12,  22 }, { 8 *12, 22 }, { 9 *12,  22 }, { 10*12, 22 }, { 11*12, 22 }, { 12*12, 22 }, { 13*12, 22 },                { 15*12, 22 }, { 16*12, 22 }, { 17*12, 22 }, { 18*12, 22 }, { 19*12, 22 }, { 20*12, 22 }, { 21*12, 22 },
    { 1 *12, 33 }, { 2 *12, 33 }, { 3 *12, 33 }, { 4 *12, 33 }, { 5 *12,  33 }, { 6 *12,  33 }, { 7 *12,  33 }, { 8 *12, 33 }, { 9 *12,  33 }, { 10*12, 33 }, { 11*12, 33 }, { 12*12, 33 }, { 13*12, 33 }, { 14*12, 33 },                                              { 18*12, 33 }, { 19*12, 33 }, { 20*12, 33 },
    { 1 *12, 44 }, { 2 *12, 44 }, { 3 *12, 44 }, { 4 *12, 44 }, { 5 *12,  44 }, { 6 *12,  44 }, { 7 *12,  44 }, { 8 *12, 44 }, { 9 *12,  44 }, { 10*12, 44 }, { 11*12, 44 }, { 12*12, 44 }, { 13*12, 44 },                               { 16*12, 44 },                { 18*12, 44 }, { 19*12, 44 }, { 20*12, 44 }, { 21*12, 44 },
    { 1 *12, 64 }, { 2 *12, 64 }, { 3 *12, 64 },                                                { 7 *12,  64 },                                               { 11*12, 64 }, { 12*12, 64 }, { 13*12, 64 }, { 14*12, 64 }, { 15*12, 64 }, { 16*12, 64 }, { 17*12, 64 },                { 19*12, 64 }, { 20*12, 64 },

    //underglow left 105-110
    { 1 , 0 }, { 1, 11 }, { 1, 22 }, { 1 *1, 33 }, { 1 ,  44 }, { 1,  64 },

    //underglow bottom 111-130 (same y as row 6)
    { 1 *12, 64 }, { 2 *12, 64 }, { 3 *12, 64 }, { 4 *12, 64 }, { 5 *12,  64 }, { 6 *12,  64 }, { 7 *12,  64 }, { 8 *12, 64 }, { 9 *12, 64 }, { 10*12, 64 }, { 11*12, 64 }, { 12*12, 64 }, { 13*12, 64 }, { 14*12, 64 }, { 15*12, 64 },  { 16*12, 64 }, { 17*12, 64 }, { 18*12, 64 }, { 19*12, 64 }, { 20*12, 64 },

    //131-149 top
    { 1 *12,  0 }, { 2 *12,  0 }, { 3 *12,  0 }, { 4 *12,  0 }, { 5 *12,   0 }, { 6 *12,   0 }, { 7 *12,   0 }, { 8 *12,  0 }, { 9 *12,  0 }, { 10*12,  0 }, { 11*12,  0 }, { 12*12,  0 }, { 13*12,  0 }, { 14*12,  0 }, { 15*12,  0 },  { 16*12,  0 }, { 17*12,  0 }, { 18*12,  0 }, { 19*12,  0 },

    //150 right
    { 20*12, 0 }, { 20*12, 11 }, { 20*12, 22 }, { 20*12, 33 }, { 20*12,  44 },

}, {
   5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,    5, 5, 5,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 4, 4, 4,
   5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    5, 5, 5, 4, 4, 4, 4,
   5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,          4, 4, 4,
   5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    5,    5,    4, 4, 4, 5,
   5, 5, 5,       5,             5, 5, 5, 5, 5, 5, 5,    4, 4,
   //underglow
   2, 2, 2, 2, 2, 2, 2, 2,
   2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
   2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
} };



#endif
