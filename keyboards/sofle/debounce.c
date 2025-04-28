/*
Copyright 2017 Alex Ong<the.onga@gmail.com>
Copyright 2021 Simon Arlott
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
Basic global debounce algorithm. Used in 99% of keyboards at time of implementation
When no state changes have occured for DEBOUNCE milliseconds, we push the state.
*/
#include "debounce.h"
#include "timer.h"
#include <string.h>
#ifndef DEBOUNCE
#    define DEBOUNCE 5
#endif

// Maximum debounce: 255ms
#if DEBOUNCE > UINT8_MAX
#    undef DEBOUNCE
#    define DEBOUNCE UINT8_MAX
#endif

#if DEBOUNCE > 0


#define DEBOUNCE_ROW 4
#define DEBOUNCE_COL 4

static bool         key_debouncing = false;
static fast_timer_t key_debounce_timer;
static matrix_row_t last_raw;


void debounce_init(uint8_t num_rows) {}

bool debounce(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows, bool changed) {
    bool cooked_changed = false;

    // Copy cooked to raw directly for all keys
    memcpy(cooked, raw, num_rows * sizeof(matrix_row_t));

    // Get the specific key bit
    bool raw_key = raw[DEBOUNCE_ROW] & (1 << DEBOUNCE_COL);
    bool cooked_key = cooked[DEBOUNCE_ROW] & (1 << DEBOUNCE_COL);

    if (raw_key != cooked_key) {
        if (!key_debouncing) {
            key_debouncing = true;
            key_debounce_timer = timer_read_fast();
            last_raw = raw[DEBOUNCE_ROW];
        } else if (timer_elapsed_fast(key_debounce_timer) >= DEBOUNCE) {
            if ((last_raw & (1 << DEBOUNCE_COL)) != (raw[DEBOUNCE_ROW] & (1 << DEBOUNCE_COL))) {
                last_raw = raw[DEBOUNCE_ROW]; // Update last_raw for comparison
                cooked[DEBOUNCE_ROW] = (cooked[DEBOUNCE_ROW] & ~(1 << DEBOUNCE_COL)) | (raw[DEBOUNCE_ROW] & (1 << DEBOUNCE_COL));
                cooked_changed = true;
            }
            key_debouncing = false;
        }
    } else {
        key_debouncing = false;
    }

    return cooked_changed;
}

void debounce_free(void) {}
#else // no debouncing.
#    include "none.c"
#endif
