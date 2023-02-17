
/*
This is a Modified demonstration of the TMS9928A's
40 x 24 monochrome text mode that you can use to add 22 lines of text on a Coleco screen.
*/

#include <cv.h>
#include <cvu.h>

#include "common.h"
//#link "common.c"
//#link "fonts.s"

void setup_text_mode() {
  // set screen mode to text
  cv_set_screen_mode(CV_SCREENMODE_TEXT);
  // set image table address, which defines grid of characters
  cv_set_image_table(IMAGE);
  // set pattern table address, which defines character graphics
  cv_set_character_pattern_t(PATTERN);
  // clear VRAM to all zeroes
  cvu_vmemset(0, 0, 0x4000);
  // copy default character set from ROM to VRAM
  copy_default_character_set();
}

void show_text() {
  // set background and foreground colors
  cv_set_colors(CV_COLOR_LIGHT_GREEN, CV_COLOR_BLACK);
  // fill image table with '.' characters
  cvu_vmemset(IMAGE, '.', 40*24);
  // draw message at row 0, column 1
  cvu_memtovmemcpy(IMAGE + 41,"1st line of text display on the coleco", 38);
  cvu_memtovmemcpy(IMAGE + 81,"2nd line of text display on the coleco", 38);
  cvu_memtovmemcpy(IMAGE + 121,"3rd line of text display on the coleco", 38);
  cvu_memtovmemcpy(IMAGE + 161,"4th line of text display on the coleco", 38); 
  cvu_memtovmemcpy(IMAGE + 201,"5th line of text display on the coleco", 38);
  cvu_memtovmemcpy(IMAGE + 241,"6th line of text display on the coleco", 38);   
  cvu_memtovmemcpy(IMAGE + 281,"7th line of text display on the coleco", 38);  
  cvu_memtovmemcpy(IMAGE + 321,"8th line of text display on the coleco", 38);
  cvu_memtovmemcpy(IMAGE + 361,"9th line of text display on the coleco", 38); 
  cvu_memtovmemcpy(IMAGE + 401,"10th line of text display on my coleco", 38);
  cvu_memtovmemcpy(IMAGE + 441,"11th line of text display on my coleco", 38);
  cvu_memtovmemcpy(IMAGE + 481,"12th line of text display on my coleco", 38);
  cvu_memtovmemcpy(IMAGE + 521,"13th line of text display on my coleco", 38); 
  cvu_memtovmemcpy(IMAGE + 561,"14th line of text display on my coleco", 38); 
  cvu_memtovmemcpy(IMAGE + 601,"15th line of text display on my coleco", 38);
  cvu_memtovmemcpy(IMAGE + 641,"16th line of text display on my coleco", 38);
  cvu_memtovmemcpy(IMAGE + 681,"17th line of text display on my coleco", 38);
  cvu_memtovmemcpy(IMAGE + 721,"18th line of text display on my coleco", 38);
  cvu_memtovmemcpy(IMAGE + 761,"19th line of text display on my coleco", 38);
  cvu_memtovmemcpy(IMAGE + 801,"20th line of text display on my coleco", 38);
  cvu_memtovmemcpy(IMAGE + 841,"21th line of text display on my coleco", 38);  
  cvu_memtovmemcpy(IMAGE + 881,"22th line of text display on my coleco", 38);   
  // turn on display
  cv_set_screen_active(true);
}

void main() {
  setup_text_mode();
  show_text();
  while (1); // infinite loop
}
