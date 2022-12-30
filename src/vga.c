#include <vga.h>

uint8_t get_vga_color(enum vga_color foreground, enum vga_color background) {
        return foreground | background << 4;
}

uint16_t get_vga_entry(unsigned char c, uint8_t color) {
	return (uint16_t) c | (uint16_t) color << 8;
}

void vga_init() {
	vga_row = 0;
	vga_col = 0;
	vga_color = get_vga_color(VGA_LIGHT_GRAY, VGA_BLACK);
	vga_buffer = (uint16_t*) 0xB8000;

	for (size_t y = 0; y < VGA_HEIGHT; y++)
		for (size_t x = 0; x < VGA_WIDTH; x++)
			vga_buffer[y * VGA_WIDTH + x] = get_vga_entry(' ', vga_color);
}

void set_vga_color(uint8_t color) {
	vga_color = color;
}

void vga_putch(char c) {
	if (c == '\n') {
		vga_col = 0;
		vga_row++;
	} else {
		vga_buffer[vga_row * VGA_WIDTH + vga_col] = get_vga_entry(c, vga_color);
	}

	if (++vga_col == VGA_WIDTH) {
		vga_col = 0;
		if (++vga_row == VGA_HEIGHT)
			vga_row = 0;
	}
}

void vga_write(const char* s, size_t size) {
	for (size_t i = 0; i < size; i++)
		vga_putch(s[i]);
}

void vga_writeln(const char* s) {
	vga_write(s, _strlen(s));
}

size_t _strlen(const char* s) {
	size_t result = 0;
	while (s[result]) result++;
	return result;
}
