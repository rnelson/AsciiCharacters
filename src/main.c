#include <vga.h>

void kernel_main() {
	vga_init();

	char min = 0x20;
	char max = 0x7E;
	int chars = 16;
	int cur = 0;

	for (char c = min; c <= max; c++) {
		vga_putch(c);
		if (++cur >= chars) vga_putch('\n');
	}

	while (1);
}
