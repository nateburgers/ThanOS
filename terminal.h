#pragma once
#include "types.h"

typedef natural8_t terminal_character_style_t;
typedef struct {
  character_t character;
  terminal_character_style_t style;
} terminal_character_t;

extern terminal_character_t *const TerminalScreen;
extern const natural_t TerminalWidth;
extern const natural_t TerminalHeight;

typedef enum {
  Black = 0,
  Blue,
  Green,
  Cyan,
  Red,
  Magenta,
  Brown,
  LightGrey,
  DarkGrey,
  LightBlue,
  LightGreen,
  LightCyan,
  LightRed,
  LightMagenta,
  LightBrown,
  White
} terminal_color_t;

terminal_character_style_t
terminal_character_style(terminal_color_t foreground_color,
			 terminal_color_t background_color);

terminal_character_t
terminal_character(character_t character,
		   terminal_character_style_t style);

terminal_character_t
terminal_character_black_and_white(character_t character);

void
terminal_write_character(terminal_character_t character,
			 natural_t position);

void
terminal_clear_screen(void);
