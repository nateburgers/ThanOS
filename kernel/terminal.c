#include "terminal.h"

/* Constants */
terminal_character_t *const TerminalScreen = (terminal_character_t *)0x0B8000;
const natural_t TerminalWidth = 80;
const natural_t TerminalHeight = 25;
natural_t TerminalCursor = 0;

/* Implementations */
terminal_character_style_t
terminal_character_style(terminal_color_t foreground_color,
			 terminal_color_t background_color)
{
  return (background_color << 4) + foreground_color;
}

void
terminal_write_character(character_t character,
			 terminal_character_style_t style,
			 natural_t position)
{
  terminal_character_t terminal_character = 
    {
      .character = character,
      .style = style
    };
  TerminalScreen[position] = terminal_character;
}

void
terminal_write_string(const character_t *string,
		      terminal_character_style_t style,
		      natural_t position)
{
  while (string[position] != '\0')
    {
      terminal_write_character(string[position], style, position);
      position += 1;
    }
}

void
terminal_put_character(character_t character,
		       terminal_character_style_t style)
{
  terminal_write_character(character, style, TerminalCursor);
  TerminalCursor += 1;
}

void
terminal_put_string(const character_t *string,
		    terminal_character_style_t style)
{
  natural_t position = 0;
  while (string[position] != '\0')
    {
      terminal_put_character(string[position], style);
      position += 1;
    }
}

void
terminal_clear_screen(void)
{
  TerminalCursor = 0;
  for (natural_t index = 0; index < TerminalWidth * TerminalHeight; index ++)
    {
      terminal_write_character(' ', terminal_character_style(TerminalWhite,TerminalBlack), index);
    }
}
