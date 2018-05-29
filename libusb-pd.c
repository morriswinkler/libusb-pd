#include "libusb-pd.h"

#include <stdint.h>
#include <printf.h>

enum message_type {
  src_cap = 0x1,          // Source_Capabilities Source or Dual-Role
  request = 0x2,          // Sink only
  bist = 0x3,             // Build in self test, Tester, Source or Sink
  sink_cap = 0x4,         // Sink or Dual-Role
  battery_status = 0x5,   // Source or Sink
  allert = 0x6,           // Source or Sink
  get_country_info = 0x7, // Source or Sink
  vendor_def = 0xf,       // Source, Sink or Cable Plug
};

enum power_role {
  sink = 0x0,
  source = 0x1,
};

enum data_role {
  ufp = 0x0, // upward facing port, USB data device
  dfp = 0x1, // downward facing port, USB data host
};

typedef struct {
  uint8_t sop0;
  uint8_t sop1;
  uint8_t sop2;
  uint8_t sop3;
} sop;

typedef struct {
  uint8_t message_type;
  uint8_t port_data_role;
  uint8_t spec_rev;
  uint8_t cable_plug;
  uint8_t port_power_role;
  uint8_t message_id;
  uint8_t num_data_objs;
  uint8_t extended;
} msg_header;

typedef struct {
  uint8_t data_size;
  uint8_t request_chunk;
  uint8_t cunk_number;
  uint8_t chunked;
} ext_msg_header;

typedef struct {
  sop sop;
  msg_header header;
  uint8_t *data_objects;
  uint32_t crc;
} pd_paket;

////assumes little endian
//void printBits(size_t const size, void const *const ptr) {
//  unsigned char *b = (unsigned char *) ptr;
//  unsigned char byte;
//  int i, j;
//
//  for (i = size - 1; i >= 0; i--) {
//    for (j = 7; j >= 0; j--) {
//      byte = (b[i] >> j) & 1;
//      printf("%u", byte);
//    }
//  }
//  puts("");
//}

/*
    pd_cc_msg creates a usb pd control message package
 */
uint16_t pd_cc_msg(enum cc_msg msg) {
  uint16_t header = PD_HEADER(msg, sink, ufp, 0, 0, PD_REV3, 0);
  return header;
}
