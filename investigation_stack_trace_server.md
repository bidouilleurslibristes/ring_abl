millis sur le serveur quand ça merde (diode bleu client)

103694
408344





===============================================




Exception (29):
epc1=0x4000e1c3 epc2=0x00000000 epc3=0x00000000 excvaddr=0x00000018 depc=0x00000000

ctx: sys
sp: 3ffffc80 end: 3fffffb0 offset: 01a0

>>>stack>>>
3ffffe20:  40208932 3fffbdf4 3fff0f2c 3ffe992e
3ffffe30:  40210c59 40210b96 3fff0f2c 3fffbdf4
3ffffe40:  00000018 3ffed4ac 3ffed428 00000000
3ffffe50:  40210cf4 3ff20a00 3fff0f2c 3ffea5b6
3ffffe60:  3ffea594 40210e20 3fffbdf4 3ffea594
3ffffe70:  3ffea5b6 0000002c 00000004 401004f4
3ffffe80:  3ffea59e 3fff13a4 4020da3f 3ff20a00
3ffffe90:  3fff0f2c 3fff3054 00000015 4020d911
3ffffea0:  3ffed110 7fffffff 00000000 3ffec690
3ffffeb0:  3ffecac0 00000006 00000000 00000000
3ffffec0:  3ffea588 3fffdcc0 3ffe90f8 00000030
3ffffed0:  00000000 00000000 00000001 3ffef240
3ffffee0:  00000000 3fffdad0 3ffef230 00000030
3ffffef0:  00000000 3fffdad0 3ffef230 0000001a
3fffff00:  3ffea5ac 00000000 00000052 401004d8
3fffff10:  40214eb9 fffffff2 00000000 00000000
3fffff20:  4020d1a9 3ffea594 3ffeca48 3fff0f2c
3fffff30:  00000000 3ffea59e 3ffea5c0 3ffe8e64
3fffff40:  40104fb6 00000000 3ffea59e 00000001
3fffff50:  00000036 3ffe8e64 3fff13a4 3ffea588
3fffff60:  00000000 00000052 40208226 3ffeca48
3fffff70:  3ffea588 3fffdcc0 3ffe9178 3fff11d4
3fffff80:  3ffea5a4 00000040 00000000 3ffef240
3fffff90:  40207b73 3fffdab0 00000000 40205f2b
3fffffa0:  3ffe9178 40000f49 3fffdab0 40000f49
<<<stack<<<



Exception 29: StoreProhibited: A store referenced a page mapped with an attribute that does not permit stores
Decoding 18 results
0x40208932: pp_attach at ?? line ?
0x40210c59: ieee80211_alloc_proberesp at ?? line ?
0x40210b96: ieee80211_alloc_proberesp at ?? line ?
0x40210cf4: ieee80211_send_proberesp at ?? line ?
0x40210e20: ieee80211_send_proberesp at ?? line ?
0x401004f4: calloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1684
0x4020da3f: hostap_input at ?? line ?
0x4020d911: hostap_input at ?? line ?
0x401004d8: malloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1664
0x40214eb9: cnx_node_search at ?? line ?
0x4020d1a9: hostap_input at ?? line ?
0x40104fb6: wdt_feed at ?? line ?
0x40208226: pp_tx_idle_timeout at ?? line ?
0x40207b73: ppPeocessRxPktHdr at ?? line ?
0x40205f2b: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56




================================================

Exception (29):
epc1=0x4000e1b2 epc2=0x00000000 epc3=0x00000000 excvaddr=0x00000000 depc=0x00000000

ctx: sys
sp: 3ffffc40 end: 3fffffb0 offset: 01a0

>>>stack>>>
3ffffde0:  3ffed65c 00000020 40232d90 401004f4
3ffffdf0:  00000005 3fffbfa4 40232d90 40107078
3ffffe00:  40215a23 401048ef 402088df 4020a008
3ffffe10:  000000b8 4020c6bf 00000018 3ffed3ec
3ffffe20:  40208932 3fffbe7c 3fff0f2c 3ffeb882
3ffffe30:  3ffffe40 40210b96 3fff0f2c 3fffbe7c
3ffffe40:  00000000 3ffed4ac 3ffed428 00000000
3ffffe50:  40210cf4 3ff20a00 3fff0f2c 3ffeb23e
3ffffe60:  3ffeb21c 40210e20 3fffbe7c 3ffeb21c
3ffffe70:  3ffeb23e 0000002c 00000004 401004f4
3ffffe80:  3ffeb226 3fff13a4 4020da3f 3ff20a00
3ffffe90:  3fff0f2c 3fff33dc 00000015 4020d911
3ffffea0:  40205f45 00000030 0000001c ffffffff
3ffffeb0:  40000f49 00000000 00000000 00000000
3ffffec0:  feefeffe 00000000 3fffd9d0 3ffef230
3ffffed0:  00000000 00000000 00000001 3fffdab0
3ffffee0:  00000000 3fffdad0 3ffef230 00000030
3ffffef0:  00000000 00000001 3fff0a54 00000002
3fffff00:  3ffeb234 00000000 00000053 401004d8
3fffff10:  40214eb9 fffffff3 00000000 00000000
3fffff20:  4020d1a9 3ffeb21c 3ffeca20 3fff0f2c
3fffff30:  00000000 3ffeb226 3ffeb248 3ffe8e64
3fffff40:  40104fb6 00000000 3ffeb226 00000001
3fffff50:  00000036 3ffe8e64 3fff13a4 3ffeb210
3fffff60:  00000000 00000053 40208226 3ffeca20
3fffff70:  3ffeb210 3fffdcc0 3ffe9078 3fff11d4
3fffff80:  3ffeb22c 00000040 00000000 3ffef240
3fffff90:  40207b73 3fffdab0 00000000 40205f2b
3fffffa0:  3ffe9078 40000f49 3fffdab0 40000f49
<<<stack<<<




Exception 29: StoreProhibited: A store referenced a page mapped with an attribute that does not permit stores
Decoding 28 results
0x40232d90: sleep_reset_analog_rtcreg_8266 at ?? line ?
0x401004f4: calloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1684
0x40232d90: sleep_reset_analog_rtcreg_8266 at ?? line ?
0x40107078: pvPortZalloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/heap.c line 33
0x40215a23: ieee80211_add_ie_vendor_esp_head at ?? line ?
0x401048ef: lmacRxDone at ?? line ?
0x402088df: pp_attach at ?? line ?
0x4020a008: esf_buf_alloc at ?? line ?
0x4020c6bf: ieee80211_getmgtframe at ?? line ?
0x40208932: pp_attach at ?? line ?
0x40210b96: ieee80211_alloc_proberesp at ?? line ?
0x40210cf4: ieee80211_send_proberesp at ?? line ?
0x40210e20: ieee80211_send_proberesp at ?? line ?
0x401004f4: calloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1684
0x4020da3f: hostap_input at ?? line ?
0x4020d911: hostap_input at ?? line ?
0x40205f45: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56
0x401004d8: malloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1664
0x40214eb9: cnx_node_search at ?? line ?
0x4020d1a9: hostap_input at ?? line ?
0x40104fb6: wdt_feed at ?? line ?
0x40208226: pp_tx_idle_timeout at ?? line ?
0x40207b73: ppPeocessRxPktHdr at ?? line ?
0x40205f2b: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56





=============================================

Exception (29):
epc1=0x4000e1c3 epc2=0x00000000 epc3=0x00000000 excvaddr=0x00000018 depc=0x00000000

ctx: sys
sp: 3ffffc80 end: 3fffffb0 offset: 01a0

>>>stack>>>
3ffffe20:  40208932 3fffbdfc 3fff0f2c 3ffe992e
3ffffe30:  40210c59 40210b96 3fff0f2c 3fffbdfc
3ffffe40:  00000018 3ffed4ac 3ffed428 00000000
3ffffe50:  40210cf4 3ff20a00 3fff0f2c 3ffea5b6
3ffffe60:  3ffea594 40210e20 3fffbdfc 3ffea594
3ffffe70:  3ffea5b6 0000002c 00000004 401004f4
3ffffe80:  3ffea59e 3fff13a4 4020da3f 3ff20a00
3ffffe90:  3fff0f2c 3fff328c 00000015 4020d911
3ffffea0:  4000050c 00000030 0000001c ffffffff
3ffffeb0:  40000f83 00000030 0000001c ffffffff
3ffffec0:  40000f3d 00000023 00000000 3fffd9d0
3ffffed0:  00000000 00000000 00000000 fffffffe
3ffffee0:  ffffffff 3fffc6fc 00000001 3fffdab0
3ffffef0:  00000000 3fffdad0 3ffef230 00000017
3fffff00:  3ffea5ac 00000000 00000051 401004d8
3fffff10:  40214eb9 fffffff1 00000000 40107034
3fffff20:  4020d1a9 3ffea594 3ffeca98 3fff0f2c
3fffff30:  00000000 3ffea59e 3ffea5c0 40105e3e
3fffff40:  40104fb6 00000000 3ffea59e 40226b29
3fffff50:  00000036 3ffe8e64 3fff13a4 3ffea588
3fffff60:  00000000 00000051 40208226 3ffeca98
3fffff70:  3ffea588 3fffdcc0 3ffe90a0 3fff11d4
3fffff80:  3ffea5a4 00000040 00000000 3ffef240
3fffff90:  40207b73 3fffdab0 00000000 40205f2b
3fffffa0:  3ffe90a0 40000f49 3fffdab0 40000f49
<<<stack<<<


Exception 29: StoreProhibited: A store referenced a page mapped with an attribute that does not permit stores
Decoding 24 results
0x40208932: pp_attach at ?? line ?
0x40210c59: ieee80211_alloc_proberesp at ?? line ?
0x40210b96: ieee80211_alloc_proberesp at ?? line ?
0x40210cf4: ieee80211_send_proberesp at ?? line ?
0x40210e20: ieee80211_send_proberesp at ?? line ?
0x401004f4: calloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1684
0x4020da3f: hostap_input at ?? line ?
0x4020d911: hostap_input at ?? line ?
0x401004d8: malloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1664
0x40214eb9: cnx_node_search at ?? line ?
0x40107034: pvPortMalloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/heap.c line 13
0x4020d1a9: hostap_input at ?? line ?
0x40105e3e: igmp_timer at /Users/igrokhotkov/espressif/arduino/tools/sdk/lwip/src/core/timers.c line 222
0x40104fb6: wdt_feed at ?? line ?
0x40226b29: sys_check_timeouts at /Users/igrokhotkov/espressif/arduino/tools/sdk/lwip/src/core/timers.c line 420
0x40208226: pp_tx_idle_timeout at ?? line ?
0x40207b73: ppPeocessRxPktHdr at ?? line ?
0x40205f2b: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56





===============================================



Exception (29):
epc1=0x4000e1c3 epc2=0x00000000 epc3=0x00000000 excvaddr=0x00000018 depc=0x00000000

ctx: sys
sp: 3ffffc80 end: 3fffffb0 offset: 01a0

>>>stack>>>
3ffffe20:  40208932 3fffbdf4 3fff0f2c 3ffeb882
3ffffe30:  40210c59 40210b96 3fff0f2c 3fffbdf4
3ffffe40:  00000018 3ffed4ac 3ffed428 00000000
3ffffe50:  40210cf4 3ff20a00 3fff0f2c 3ffe9f72
3ffffe60:  3ffe9f50 40210e20 3fffbdf4 3ffe9f50
3ffffe70:  3ffe9f72 0000002c 00000004 401004f4
3ffffe80:  3ffe9f5a 3fff13a4 4020da3f 3ff20a00
3ffffe90:  3fff0f2c 3fff2de4 00000015 4020d911
3ffffea0:  40105a33 00000030 00000010 ffffffff
3ffffeb0:  40205f17 3ffef230 3ffe98a8 3fffd9d0
3ffffec0:  00000000 00000000 00000000 fffffffe
3ffffed0:  ffffffff 3fffc6fc 00000000 3fffdab0
3ffffee0:  00000000 3fffdad0 3ffef230 00000030
3ffffef0:  00000000 3fffdad0 3ffef230 00000002
3fffff00:  3ffe9f68 00000000 00000052 401004d8
3fffff10:  40214eb9 fffffff2 00000000 40107034
3fffff20:  4020d1a9 3ffe9f50 3ffeca70 3fff0f2c
3fffff30:  00000000 3ffe9f5a 3ffe9f7c 40105e3e
3fffff40:  40104fb6 00000000 3ffe9f5a 40226b29
3fffff50:  00000036 3ffe8e64 3fff13a4 3ffe9f44
3fffff60:  00000000 00000052 40208226 3ffeca70
3fffff70:  3ffe9f44 3fffdcc0 3ffe9160 3fff11d4
3fffff80:  3ffe9f60 00000040 00000000 3ffef240
3fffff90:  40207b73 3fffdab0 00000000 40205f2b
3fffffa0:  3ffe9160 40000f49 3fffdab0 40000f49
<<<stack<<<


Exception 29: StoreProhibited: A store referenced a page mapped with an attribute that does not permit stores
Decoding 23 results
0x40208932: pp_attach at ?? line ?
0x40210c59: ieee80211_alloc_proberesp at ?? line ?
0x40210b96: ieee80211_alloc_proberesp at ?? line ?
0x40210cf4: ieee80211_send_proberesp at ?? line ?
0x40210e20: ieee80211_send_proberesp at ?? line ?
0x401004f4: calloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1684
0x4020da3f: hostap_input at ?? line ?
0x4020d911: hostap_input at ?? line ?
0x40105a33: system_get_time at ?? line ?
0x40205f17: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56
0x401004d8: malloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1664
0x40214eb9: cnx_node_search at ?? line ?
0x40107034: pvPortMalloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/heap.c line 13
0x4020d1a9: hostap_input at ?? line ?
0x40105e3e: igmp_timer at /Users/igrokhotkov/espressif/arduino/tools/sdk/lwip/src/core/timers.c line 222
0x40104fb6: wdt_feed at ?? line ?
0x40226b29: sys_check_timeouts at /Users/igrokhotkov/espressif/arduino/tools/sdk/lwip/src/core/timers.c line 420
0x40208226: pp_tx_idle_timeout at ?? line ?
0x40207b73: ppPeocessRxPktHdr at ?? line ?
0x40205f2b: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56




==============================================


Exception (29):
epc1=0x4000e1c3 epc2=0x00000000 epc3=0x00000000 excvaddr=0x00000018 depc=0x00000000

ctx: sys
sp: 3ffffc80 end: 3fffffb0 offset: 01a0

>>>stack>>>
3ffffe20:  40208932 3fffbde4 3fff0f2c 3ffe9f72
3ffffe30:  40210c59 40210b96 3fff0f2c 3fffbde4
3ffffe40:  00000018 3ffed4ac 3ffed428 00000000
3ffffe50:  40210cf4 3ff20a00 3fff0f2c 3ffeb23e
3ffffe60:  3ffeb21c 40210e20 3fffbde4 3ffeb21c
3ffffe70:  3ffeb23e 0000002c 00000004 401004f4
3ffffe80:  3ffeb226 3fff13a4 4020da3f 3ff20a00
3ffffe90:  3fff0f2c 3fff2efc 00000015 4020d911
3ffffea0:  40106ec7 00000030 0000001c ffffffff
3ffffeb0:  40205f33 3fff0240 00000001 feefeffe
3ffffec0:  feefeffe 00000000 3fffd9d0 3ffef230
3ffffed0:  00000000 00000000 00000001 3ffef240
3ffffee0:  00000000 3fffdad0 3ffef230 00000030
3ffffef0:  00000000 3fffdad0 3ffef230 0000001a
3fffff00:  3ffeb234 00000000 00000053 401004d8
3fffff10:  40214eb9 fffffff3 00000000 00000000
3fffff20:  4020d1a9 3ffeb21c 3ffeca70 3fff0f2c
3fffff30:  00000000 3ffeb226 3ffeb248 3ffe8e64
3fffff40:  3ffee230 00000000 3ffeb226 00000001
3fffff50:  00000036 3ffe8e64 3fff13a4 3ffeb210
3fffff60:  00000000 00000053 40208226 3ffeca70
3fffff70:  3ffeb210 3fffdcc0 3ffe9078 3fff11d4
3fffff80:  3ffeb22c 00000040 00000000 3ffef240
3fffff90:  40207b73 3fffdab0 00000000 40205f2b
3fffffa0:  3ffe9078 40000f49 3fffdab0 40000f49
<<<stack<<<

Exception 29: StoreProhibited: A store referenced a page mapped with an attribute that does not permit stores
Decoding 19 results
0x40208932: pp_attach at ?? line ?
0x40210c59: ieee80211_alloc_proberesp at ?? line ?
0x40210b96: ieee80211_alloc_proberesp at ?? line ?
0x40210cf4: ieee80211_send_proberesp at ?? line ?
0x40210e20: ieee80211_send_proberesp at ?? line ?
0x401004f4: calloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1684
0x4020da3f: hostap_input at ?? line ?
0x4020d911: hostap_input at ?? line ?
0x40106ec7: cont_check at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/cont_util.c line 42 (discriminator 2)
0x40205f33: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56
0x401004d8: malloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1664
0x40214eb9: cnx_node_search at ?? line ?
0x4020d1a9: hostap_input at ?? line ?
0x40208226: pp_tx_idle_timeout at ?? line ?
0x40207b73: ppPeocessRxPktHdr at ?? line ?
0x40205f2b: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56



===============================================

Exception (29):
epc1=0x4000e1c3 epc2=0x00000000 epc3=0x00000000 excvaddr=0x00000018 depc=0x00000000

ctx: sys
sp: 3ffffc80 end: 3fffffb0 offset: 01a0

>>>stack>>>
3ffffe20:  40208932 3fffbddc 3fff0f2c 3ffe992e
3ffffe30:  40210c59 40210b96 3fff0f2c 3fffbddc
3ffffe40:  00000018 3ffed4ac 3ffed428 00000000
3ffffe50:  40210cf4 3ff20a00 3fff0f2c 3ffeb882
3ffffe60:  3ffeb860 40210e20 3fffbddc 3ffeb860
3ffffe70:  3ffeb882 0000002c 00000004 401004f4
3ffffe80:  3ffeb86a 3fff13a4 4020da3f 3ff20a00
3ffffe90:  3fff0f2c 3fff2dec 00000015 4020d911
3ffffea0:  40205f25 00000030 0000001c ffffffff
3ffffeb0:  40205f17 3ffef240 40205f9c 3fffd9d0
3ffffec0:  00000000 00000000 00000000 fffffffe
3ffffed0:  ffffffff 3fffc6fc 00000001 3ffef240
3ffffee0:  00000000 3fffdad0 3ffef230 00000030
3ffffef0:  00000000 0000000b 0000014a 0000001a
3fffff00:  3ffeb878 00000000 00000026 401004d8
3fffff10:  40214eb9 ffffffc6 00000000 40107034
3fffff20:  4020d1a9 3ffeb860 3ffeca98 3fff0f2c
3fffff30:  00000000 3ffeb86a 3ffeb88c 40105e3e
3fffff40:  40104fb6 00000000 3ffeb86a 40226b29
3fffff50:  00000036 3ffe8e64 3fff13a4 3ffeb854
3fffff60:  00000000 00000026 40208226 3ffeca98
3fffff70:  3ffeb854 3fffdcc0 3ffe9078 3fff11d4
3fffff80:  3ffeb870 00000040 00000000 3ffef240
3fffff90:  40207b73 3fffdab0 00000000 40205f2b
3fffffa0:  3ffe9078 40000f49 3fffdab0 40000f49
<<<stack<<<


Exception 29: StoreProhibited: A store referenced a page mapped with an attribute that does not permit stores
Decoding 24 results
0x40208932: pp_attach at ?? line ?
0x40210c59: ieee80211_alloc_proberesp at ?? line ?
0x40210b96: ieee80211_alloc_proberesp at ?? line ?
0x40210cf4: ieee80211_send_proberesp at ?? line ?
0x40210e20: ieee80211_send_proberesp at ?? line ?
0x401004f4: calloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1684
0x4020da3f: hostap_input at ?? line ?
0x4020d911: hostap_input at ?? line ?
0x40205f25: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56
0x40205f17: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56
0x40205f9c: loop_wrapper at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56
0x401004d8: malloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1664
0x40214eb9: cnx_node_search at ?? line ?
0x40107034: pvPortMalloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/heap.c line 13
0x4020d1a9: hostap_input at ?? line ?
0x40105e3e: igmp_timer at /Users/igrokhotkov/espressif/arduino/tools/sdk/lwip/src/core/timers.c line 222
0x40104fb6: wdt_feed at ?? line ?
0x40226b29: sys_check_timeouts at /Users/igrokhotkov/espressif/arduino/tools/sdk/lwip/src/core/timers.c line 420
0x40208226: pp_tx_idle_timeout at ?? line ?
0x40207b73: ppPeocessRxPktHdr at ?? line ?
0x40205f2b: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56




===============================================


Exception (29):
epc1=0x4000e1c3 epc2=0x00000000 epc3=0x00000000 excvaddr=0x00000018 depc=0x00000000

ctx: sys
sp: 3ffffc80 end: 3fffffb0 offset: 01a0

>>>stack>>>
3ffffe20:  40208932 3fffbe54 3fff0f2c 3ffea5b6
3ffffe30:  40210c59 40210b96 3fff0f2c 3fffbe54
3ffffe40:  00000018 3ffed4ac 3ffed428 00000000
3ffffe50:  40210cf4 3ff20a00 3fff0f2c 3ffe9f72
3ffffe60:  3ffe9f50 40210e20 3fffbe54 3ffe9f50
3ffffe70:  3ffe9f72 0000002c 00000004 401004f4
3ffffe80:  3ffe9f5a 3fff13a4 4020da3f 3ff20a00
3ffffe90:  3fff0f2c 3fff0b14 00000015 4020d911
3ffffea0:  40205f2d 00000030 0000001c ffffffff
3ffffeb0:  40205f2b 3ffef240 00000001 00000000
3ffffec0:  3fffdab0 00000000 3fffd9d0 3ffef230
3ffffed0:  00000000 00000000 00000001 3ffef240
3ffffee0:  00000000 3fffdad0 3ffef230 00000030
3ffffef0:  00000000 3fffdad0 3ffef230 0000001a
3fffff00:  3ffe9f68 00000000 00000050 401004d8
3fffff10:  40214eb9 fffffff0 00000000 00000000
3fffff20:  4020d1a9 3ffe9f50 3ffeca98 3fff0f2c
3fffff30:  00000000 3ffe9f5a 3ffe9f7c 3ffe8e64
3fffff40:  40104fb6 00000000 3ffe9f5a 00000001
3fffff50:  00000036 3ffe8e64 3fff13a4 3ffe9f44
3fffff60:  00000000 00000050 40208226 3ffeca98
3fffff70:  3ffe9f44 3fffdcc0 3ffe9078 3fff1ce4
3fffff80:  3ffe9f60 00000040 00000000 3ffef240
3fffff90:  40207b73 3fffdab0 00000000 40205f2b
3fffffa0:  3ffe9078 40000f49 3fffdab0 40000f49
<<<stack<<<


Exception 29: StoreProhibited: A store referenced a page mapped with an attribute that does not permit stores
Decoding 20 results
0x40208932: pp_attach at ?? line ?
0x40210c59: ieee80211_alloc_proberesp at ?? line ?
0x40210b96: ieee80211_alloc_proberesp at ?? line ?
0x40210cf4: ieee80211_send_proberesp at ?? line ?
0x40210e20: ieee80211_send_proberesp at ?? line ?
0x401004f4: calloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1684
0x4020da3f: hostap_input at ?? line ?
0x4020d911: hostap_input at ?? line ?
0x40205f2d: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56
0x40205f2b: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56
0x401004d8: malloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1664
0x40214eb9: cnx_node_search at ?? line ?
0x4020d1a9: hostap_input at ?? line ?
0x40104fb6: wdt_feed at ?? line ?
0x40208226: pp_tx_idle_timeout at ?? line ?
0x40207b73: ppPeocessRxPktHdr at ?? line ?
0x40205f2b: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56





















=====================================================

Exception (29):
epc1=0x4000e1c3 epc2=0x00000000 epc3=0x00000000 excvaddr=0x00000018 depc=0x00000000

ctx: sys
sp: 3ffffc80 end: 3fffffb0 offset: 01a0

>>>stack>>>
3ffffe20:  40208932 3fffbe54 3fff0f2c 3ffea5b6
3ffffe30:  40210c59 40210b96 3fff0f2c 3fffbe54
3ffffe40:  00000018 3ffed4ac 3ffed428 00000000
3ffffe50:  40210cf4 3ff20a00 3fff0f2c 3ffe9f72
3ffffe60:  3ffe9f50 40210e20 3fffbe54 3ffe9f50
3ffffe70:  3ffe9f72 0000002c 00000004 401004f4
3ffffe80:  3ffe9f5a 3fff13a4 4020da3f 3ff20a00
3ffffe90:  3fff0f2c 3fff0b14 00000015 4020d911
3ffffea0:  40205f2d 00000030 0000001c ffffffff
3ffffeb0:  40205f2b 3ffef240 00000001 00000000
3ffffec0:  3fffdab0 00000000 3fffd9d0 3ffef230
3ffffed0:  00000000 00000000 00000001 3ffef240
3ffffee0:  00000000 3fffdad0 3ffef230 00000030
3ffffef0:  00000000 3fffdad0 3ffef230 0000001a
3fffff00:  3ffe9f68 00000000 00000050 401004d8
3fffff10:  40214eb9 fffffff0 00000000 00000000
3fffff20:  4020d1a9 3ffe9f50 3ffeca98 3fff0f2c
3fffff30:  00000000 3ffe9f5a 3ffe9f7c 3ffe8e64
3fffff40:  40104fb6 00000000 3ffe9f5a 00000001
3fffff50:  00000036 3ffe8e64 3fff13a4 3ffe9f44
3fffff60:  00000000 00000050 40208226 3ffeca98
3fffff70:  3ffe9f44 3fffdcc0 3ffe9078 3fff1ce4
3fffff80:  3ffe9f60 00000040 00000000 3ffef240
3fffff90:  40207b73 3fffdab0 00000000 40205f2b
3fffffa0:  3ffe9078 40000f49 3fffdab0 40000f49
<<<stack<<<


Exception 29: StoreProhibited: A store referenced a page mapped with an attribute that does not permit stores
Decoding 20 results
0x40208932: pp_attach at ?? line ?
0x40210c59: ieee80211_alloc_proberesp at ?? line ?
0x40210b96: ieee80211_alloc_proberesp at ?? line ?
0x40210cf4: ieee80211_send_proberesp at ?? line ?
0x40210e20: ieee80211_send_proberesp at ?? line ?
0x401004f4: calloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1684
0x4020da3f: hostap_input at ?? line ?
0x4020d911: hostap_input at ?? line ?
0x40205f2d: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56
0x40205f2b: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56
0x401004d8: malloc at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/umm_malloc/umm_malloc.c line 1664
0x40214eb9: cnx_node_search at ?? line ?
0x4020d1a9: hostap_input at ?? line ?
0x40104fb6: wdt_feed at ?? line ?
0x40208226: pp_tx_idle_timeout at ?? line ?
0x40207b73: ppPeocessRxPktHdr at ?? line ?
0x40205f2b: loop_task at /home/mfalce/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/core_esp8266_main.cpp line 56





