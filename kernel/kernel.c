#include "types.h"
#include "conditional.h"
#include "terminal.h"

void
kernel_main(void)
{
  character_t *boot_message = "Hello, World!";
  terminal_clear_screen();
  terminal_put_string(boot_message, terminal_character_style(TerminalBlue, TerminalDarkGrey));
  character_t *other_message = " this is neat isn't it?!?";
  terminal_put_string(other_message, terminal_character_style(TerminalRed, TerminalLightGrey));
}
