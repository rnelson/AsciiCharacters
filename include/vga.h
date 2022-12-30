#pragma once
#ifndef _AC_VGA_H_
#define _AC_VGA_H_ 1

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static size_t vga_row;
static size_t vga_col;
static uint8_t vga_color;
static uint16_t* vga_buffer;

enum vga_color {
	VGA_BLACK = 0,
	VGA_BLUE = 1,
	VGA_GREEN = 2,
	VGA_CYAN = 3,
	VGA_RED = 4,
	VGA_MAGENTA = 5,
	VGA_BROWN = 6,
	VGA_LIGHT_GRAY = 7,
	VGA_GRAY = 8,
	VGA_LIGHT_BLUE = 9,
	VGA_LIGHT_GREEN = 10,
	VGA_LIGHT_CYAN = 11,
	VGA_LIGHT_RED = 12,
	VGA_LIGHT_MAGENTA = 13,
	VGA_LIGHT_BROWN = 14,
	VGA_WHITE = 15
};

uint8_t get_vga_color(enum vga_color foreground, enum vga_color background);
uint16_t get_vga_entry(unsigned char c, uint8_t color);
void vga_init();
void set_vga_color(uint8_t color);
void vga_putch(char c);
void vga_write(const char* s, size_t size);
void vga_writeln(const char* s);
size_t _strlen(const char* s);

#endif /* _AC_VGA_H_ */

