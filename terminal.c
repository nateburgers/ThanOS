#include "terminal.h"

#pragma mark - Constants
terminal_character_t *const TerminalScreen = (terminal_character_t *)0x0B8000;
const natural_t TerminalWidth = 80;
const natural_t TerminalHeight = 25;

#pragma mark - Implementations

terminal_character_style_t
terminal_character_style(terminal_color_t foreground_color,
			 terminal_color_t background_color)
{
  return (background_color << 8) + foreground_color;
}

terminal_character_t
terminal_character(character_t character,
		   terminal_character_style_t style)
{
  terminal_character_t terminal_character = {
    .character = character,
    .style = style
  };
  return terminal_character;
}

terminal_character_t
terminal_character_black_and_white(character_t character)
{
  return terminal_character(character, terminal_character_style(Black, Black));
}

void
terminal_write_character(terminal_character_t character,
			 natural_t position)
{
  TerminalScreen[position] = character;
}

void
terminal_clear_screen(void)
{
  for (natural_t index = 0; index < TerminalWidth * TerminalHeight; index ++)
    {
      const terminal_character_t clear_character =
	terminal_character(' ', terminal_character_style(White,Brown));
      terminal_write_character(clear_character, index);
    }
}
