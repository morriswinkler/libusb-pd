#ifndef USB_PD_H
#define USB_PD_H
#include <stdint.h>

#define PD_REV1 2
#define PD_REV2 1
#define PD_REV3 2

/*
  build 16 bit message header

  15    | Extended
  14-12 | Number of Data Objects
  11-9  | MessageID
  8     | Port Power Role
  7-6   | Specification Revision
  5     | Port Data Role
  4-0   | Message Type
*/
#define PD_HEADER(type, prole, drole, id, cnt, rev, ext) \
	((type) | ((rev) << 6) | \
	((drole) << 5) | ((prole) << 8) | \
	((id) << 9) | ((cnt) << 12) | ((ext) << 15))

enum cc_msg {
  GOOD_CRC = 0x1,
  GOTO_MIN = 0x2,
  ACCEPT = 0x3,
  REJECT = 0x4,
  PING = 0x5,
  PS_READY = 0x6,
  GET_SRC_CAP = 0x7,
  GET_SINK_CAP = 0x8,
  DR_SWAP = 0x9,
  PR_SWAP = 0x10,
  VCONN_SWAP = 0x11,
  WAIT = 0x12,
  SOFT_RESET = 0x13,
  NOT_SUPPORTED = 0x16,
  GET_SRC_CAP_EXT = 0x17,
  GET_STATUS = 0x18,
  FR_SWAP = 0x19,
  GET_PPS_STATUS = 0x20,
  GET_COUNTRY_CODES = 0x21,
};

uint16_t pd_cc_msg(enum cc_msg msg);
#endif /* USB_PD_H */