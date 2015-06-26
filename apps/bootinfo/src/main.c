/*
 * Copyright 2015, Wink Saville
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 */

#include <stdbool.h>
#include <libsel4_io.h>
#include <sel4/bootinfo.h>

void println_SlotRegionEOL(seL4_SlotRegion *sr, bool eol) {
  libsel4_printf("{start:%d end:%d}", sr->start, sr->end);
  if (eol) libsel4_printf("\n");
}

void println_SlotRegion(seL4_SlotRegion *sr) {
  println_SlotRegionEOL(sr, true);
}

void println_DeviceRegion(seL4_DeviceRegion *dr) {
  libsel4_printf("{basePaddr:0x%x frameSizeBits:0x%x frames:",
     dr->basePaddr, dr->frameSizeBits);
  println_SlotRegionEOL(&dr->frames, false);
  libsel4_printf("}\n");
}

/**
 * No parameters are passed to main, the return
 * value is ignored and the program hangs.
 */
int main(void) {
  seL4_BootInfo *bi = seL4_GetBootInfo();
  libsel4_printf("bi=%p\n", bi);
  libsel4_printf("bi->nodeId=%d\n", bi->nodeID);
  libsel4_printf("bi->numNodes=%d\n", bi->numNodes);
  libsel4_printf("bi->numIOPTLevels=%d\n", bi->numIOPTLevels);
  libsel4_printf("bi->ipcBuffer=%p\n", bi->ipcBuffer);
  libsel4_printf("bi->empty=%p ", &bi->empty);
  println_SlotRegion(&bi->empty);
  libsel4_printf("bi->sharedFrames=%p ", &bi->sharedFrames);
  println_SlotRegion(&bi->sharedFrames);
  libsel4_printf("bi->userImageFrames=%p ", &bi->userImageFrames);
  println_SlotRegion(&bi->userImageFrames);
  libsel4_printf("bi->userImagePDs=%p ", &bi->userImagePDs);
  println_SlotRegion(&bi->userImagePDs);
  libsel4_printf("bi->userImagePTs=%p ", &bi->userImagePTs);
  println_SlotRegion(&bi->userImagePTs);
  libsel4_printf("bi->untyped=%p ", &bi->untyped);
  println_SlotRegion(&bi->untyped);
  libsel4_printf("bi->untypedPaddrList=%p\n", bi->untypedPaddrList);
  for(int i=0; i < CONFIG_MAX_NUM_BOOTINFO_UNTYPED_CAPS; i++) {
    libsel4_printf("bi->untypedPaddrList[%d] 0x%x\n", i, bi->untypedPaddrList[i]);
  }
  libsel4_printf("bi->untypedSizeBitsList=%p\n", bi->untypedSizeBitsList);
  for(int i=0; i < CONFIG_MAX_NUM_BOOTINFO_UNTYPED_CAPS; i++) {
    libsel4_printf("bi->untypedSizeBitsList[%d] 0x%x\n", i, bi->untypedSizeBitsList[i]);
  }
  libsel4_printf("bi->initThreadCNodeSizeBits=%d\n", bi->initThreadCNodeSizeBits);
  libsel4_printf("bi->numDeviceRegions=%d\n", bi->numDeviceRegions);
  for(int i=0; i < CONFIG_MAX_NUM_BOOTINFO_DEVICE_REGIONS; i++) {
    libsel4_printf("bi->deviceRegions[%d] ", i); println_DeviceRegion(&bi->deviceRegions[i]);
  }
  libsel4_printf("bi->initThreadDomain=%d\n", bi->initThreadDomain);

  return 0;
}
