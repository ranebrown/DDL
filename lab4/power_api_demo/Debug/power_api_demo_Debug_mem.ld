/*
 * GENERATED FILE - DO NOT EDIT
 * (C) Code Red Technologies Ltd, 2008-2015
 * Linker script memory definitions
 * Created from LinkMemoryTemplate
 * By LPCXpresso v5.2.6 [Build 2137] [2013-07-08]  on Wed Feb 11 19:22:58 MST 2015)
*/

MEMORY
{
  /* Define each memory region */
  MFlash32 (rx) : ORIGIN = 0x0, LENGTH = 0x8000 /* 32k */
  RamLoc4 (rwx) : ORIGIN = 0x10000000, LENGTH = 0x1000 /* 4k */
  RamUsb2 (rwx) : ORIGIN = 0x20004000, LENGTH = 0x800 /* 2k */

}
  /* Define a symbol for the top of each memory region */
  __top_MFlash32 = 0x0 + 0x8000;
  __top_RamLoc4 = 0x10000000 + 0x1000;
  __top_RamUsb2 = 0x20004000 + 0x800;

