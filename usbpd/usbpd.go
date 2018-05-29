package usbpd

/*
#cgo LDFLAGS: -llibusb-pd
#include "libusb-pd.h"
#include <stdlib.h>
#include "cgo_helpers.h"
*/
import "C"


// cc_msg as declared in usb-pd/libusb-pd.h:25
type CC_MSG int32

// cc_msg enumeration from usb-pd/libusb-pd.h:25
const (
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
)

func CC_MSG(CC_MSG msg) uint16 {
    regturn c.pd_cc_msg(msg)
}
