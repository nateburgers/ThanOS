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
extern natural_t TerminalCursor;

typedef enum {
  TerminalBlack = 0,
  TerminalBlue,
  TerminalGreen,
  TerminalCyan,
  TerminalRed,
  TerminalMagenta,
  TerminalBrown,
  TerminalLightGrey,
  TerminalDarkGrey,
  TerminalLightBlue,
  TerminalLightGreen,
  TerminalLightCyan,
  TerminalLightRed,
  TerminalLightMagenta,
  TerminalLightBrown,
  TerminalWhite
} terminal_color_t;

terminal_character_style_t
terminal_character_style(terminal_color_t foreground_color,
			 terminal_color_t background_color);

void
terminal_write_character(character_t character,
			 terminal_character_style_t style,
			 natural_t position);

void
terminal_write_string(const character_t *string,
		      terminal_character_style_t style,
		      natural_t position);

void
terminal_put_character(character_t character,
		       terminal_character_style_t style);

void
terminal_put_string(const character_t *string,
		    terminal_character_style_t style);

void
terminal_clear_screen(void);
