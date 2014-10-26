#include "types.h"
#include "conditional.h"
#include "terminal.h"

void kernel_main(void) {
  terminal_clear_screen();
  character_t *boot_message = "Hello, World!";
  for (natural_t index = 0; boot_message[index] != '\0'; index ++) {
      terminal_character_t message_character =
  	terminal_character(boot_message[index], terminal_character_style(Brown,LightGrey));
    }
  return;
}
