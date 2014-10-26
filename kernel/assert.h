#pragma once
#include "types.h"
#include "terminal.h"

#if defined DEBUG || defined TESTING
# define Assert(expression) assert(expression, __FILE__, __LINE__, ##expression)
#else
# define Assert(expression)
#endif

void
assert(boolean_t succeeds,
       const character_t *restrict file_name,
       natural_t line_number,
       const character_t *restrict expression)
{
  if (!succeeds)
    {
      const terminal_character_style_t error_style = terminal_character_style(TerminalRed, TerminalBlack);
      
    }
}
