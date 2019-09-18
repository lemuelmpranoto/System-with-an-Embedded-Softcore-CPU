#define PIXEL_LENGTH 1967
#define ADDR_AVALON (volatile unsigned long *)0xa200

extern inline void vga_plot(unsigned, unsigned, unsigned);

inline void vga_plot(unsigned x, unsigned y, unsigned colour) {

  *ADDR_AVALON = (((unsigned long) colour << 16) | ((unsigned long) x << 8)) + y;
  
}