#pragma once

#include <stdint.h>
#include "i2c_master.h"

// void ds1307_set_time(uint8_t h, uint8_t m, uint8_t s);
i2c_status_t ds1307_get_time(uint8_t *h, uint8_t *m, uint8_t *s);
