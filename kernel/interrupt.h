#pragma once

typedef struct 
{
  natural16_t offset_lower_bits;
  natural16_t selector;
  byte_t zero;
  byte_t selector_attribute;
  natural16_t offset_higher_bits;
} interrupt_descriptor_table_entry_t;

typedef void (*interrupt_handler_t)(void);
extern const interrupt_handler_t null_interrupt_handler;
interrupt_handler_t keyboard_interrupt_handler = null_interrupt_handler;
interrupt_handler_t timer_interrupt_handler = null_interrupt_handler;

extern const natural_t InterruptDescriptorTableSize;
