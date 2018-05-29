//
// Created by Morris Winkler on 23.05.18.
//

#include <stdint.h>
#include <stdio.h>
#include "libusb-pd.h"
int crc;

void crcBits(int x, int len) {
  const int poly = 0x04C11DB6;  //spec 04C1 1DB7h
  int newbit,newword,rl_crc;
  for(int i=0;i<len;i++) {
    newbit = ((crc>>31) ^ ((x>>i)&1)) & 1;
    if(newbit) newword=poly; else newword=0;
    rl_crc = (crc<<1) | newbit;
    crc = rl_crc ^ newword;
    printf("%2d newbit=%d, x>>i=0x%x, crc=0x%x\n",i,newbit,(x>>i),crc);
  }
}

int crcWrap(int c){
  int ret = 0;
  int j, bit;
  c = ~c;
  printf("~crc=0x%x\n",c);
  for(int i=0;i<32;i++) {
    j = 31-i;
    bit = (c>>i) & 1;
    ret |= bit<<j;
  }
  return ret;
}

//assumes little endian
void printBits(size_t const size, void const *const ptr) {
  unsigned char *b = (unsigned char *) ptr;
  unsigned char byte;
  int i, j;

  for (i = size - 1; i >= 0; i--) {
    for (j = 7; j >= 0; j--) {
      byte = (b[i] >> j) & 1;
      printf("%u", byte);
    }
  }
  puts("");
}

int main(){
//  int txCrc=0,rxCrc=0,residue=0,data;
//  printf("using packet data 0x%x\n", data=0x0101);
//  crc = 0xffffffff;
//  crcBits(data,16);
//  txCrc = crcWrap(crc);
//  printf("crc=0x%x, txCrc=0x%x\n",crc,txCrc);
//  printf("received packet after decode= 0x%x, 0x%x\n",data,txCrc);
//  crc = 0xffffffff;
//  crcBits(data,16);
//  rxCrc = crcWrap(crc);
//  printf("Crc of the received packet data is (of course) =0x%x\n",rxCrc);
//  printf("continue by running the transmit crc through the crc\n");
//  crcBits(rxCrc,32);
//  printf("Now the crc residue is 0x%x\n",crc);
//  printf("should be 0xc704dd7b\n");


  uint16_t cc_msg = pd_cc_msg(GOOD_CRC);
  printBits(sizeof(cc_msg), &cc_msg);
}