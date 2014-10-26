#pragma once
#include "types.h"

byte_t
port_read_byte(natural32_t port_number);

void
port_write_byte(natural32_t port_number,
		byte_t value);

