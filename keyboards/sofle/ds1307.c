#include "ds1307.h"
// #include "i2c_master.h"
// #include "print.h"


// void ds1307_set_time(uint8_t h, uint8_t m, uint8_t s) {
//     uint8_t data[] = {
//         ((s % 10) | ((s / 10) << 4)) & 0x7F,
//         ((m % 10) | ((m / 10) << 4)) & 0x7F,
//         ((h % 10) | ((h / 10) << 4)) & 0x3F,
//         0, 0, 0, 0, 0
//     }; // 24-hour mode
//     i2c_writeReg(DS1307_ADDR, 0, data, 8, 100);
// }

#define DS_1307_ADDRESS (0x68 << 1)

i2c_status_t ds1307_get_time(uint8_t *h, uint8_t *m, uint8_t *s) {
    

    uint8_t data[3];
    i2c_status_t status = i2c_readReg(DS_1307_ADDRESS, 0, data, 3, 100);
//     #ifdef CONSOLE_ENABLE
//       xprintf("h: %d, m: %d, s: %d\n", data[0], data[1], data[2]);
//   #endif


    i2c_stop();
    *s = (data[0] & 0b1111) + ((data[0] & 0b1110000) >> 4) * 10;
    *m = (data[1] & 0b1111) + ((data[1] & 0b1110000) >> 4) * 10;
    *h = (data[2] & 0b1111) + ((data[2] & 0b0110000) >> 4) * 10;

    return status;
}

// TODO: get full date & time for initialization purposes & after midnight update
// i2c_status_t ds1307_get_date(uint8_t *year, uint8_t *month, uint8_t *day, uint8_t *day_of_week) {
//     uint8_t data[4];
//     i2c_status_t status = i2c_readReg(DS_1307_ADDRESS, 3, data, 4, 100);
//     i2c_stop();

//     *day_of_week = (data[0] & 0b111); // 1-7
//     *day = (data[1] & 0b1111) + ((data[1] & 0b110000) >> 4) * 10; // 1-31
//     *month = (data[2] & 0b1111) + ((data[2] & 0b10000) >> 4) * 10; // 1-12
//     *year = (data[3] & 0b1111) + ((data[3] & 0b11110000) >> 4) * 10; // 0-99

//     return status;
// }
