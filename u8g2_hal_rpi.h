//
// Created by raffy on 6/27/18.
//

#ifndef U8G2DEMO_U8G2_HAL_RPI_H
#define U8G2DEMO_U8G2_HAL_RPI_H

#include <cstdint>
#include <u8g2.h>

//TODO: Add i2C support

struct u8g2_rpi_hal_t {
    int clk;  //lcd ENABLE pin
    int mosi; //lcd RW pin
    int cs; //lcd RS pin
    int reset; //optional (not yet supported)
};

struct u8g2_rpi_8080_hal_t {
    int cs; //lcd ENABLE pin
    int wr; //lcd RW pin
    int dc; //command/data
    int d0; //data
    int d1; //data
    int d2; //data
    int d3; //data
    int d4; //data
    int d5; //data
    int d6; //data
    int d7; //data
};

/**
 * Initialize the device pins to be used by the HAL
 */
void u8g2_rpi_hal_init(u8g2_rpi_hal_t param);
void u8g2_rpi_hal_init(u8g2_rpi_8080_hal_t param);

/**
 * Byte communications callback for I2C Hardware on the Raspberry Pi
 */
uint8_t cb_byte_i2c_hw(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

/**
 * Byte communications callback for SPI Hardware on the Raspberry Pi
 */
uint8_t cb_byte_spi_hw(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

/**
 * Byte communications callback for 8080 Hardware on the Raspberry Pi
 */
uint8_t cb_byte_8080_hw(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

/**
 * GPIO and Delay callback for Raspberry Pi
 */
uint8_t cb_gpio_delay_rpi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, U8X8_UNUSED void *arg_ptr);

#endif //U8G2DEMO_U8G2_HAL_RPI_H
