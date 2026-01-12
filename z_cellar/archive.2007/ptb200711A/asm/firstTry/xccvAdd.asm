;--------------------------------UNCLASSIFIED----------------------------------;
; File: xccvAddi686.asm
; Desc: This file contains the code for the vectorUtils routine xccvAddi686.
; Hist: When       Who  What
;       04/19/04   ptb  Initial code.
;------------------------------------------------------------------------------;
; Preprocessor directives -----------------------------------------------------;
;------------------------------------------------------------------------------;
%define PADDINT08 PADDSB
%define PADDINT16 PADDSW
%define PADDINT32 PADDD
%define PADDINT64 PADDQ
%define PADDUNT08 PADDUSB
%define PADDUNT16 PADDUSW
%define PADDUNT32 PADDD
%define PADDUNT64 PADDQ

%define PADDCINT08 PADDSB
%define PADDCINT16 PADDSW
%define PADDCINT32 PADDD
%define PADDCINT64 PADDQ
%define PADDCUNT08 PADDSB
%define PADDCUNT16 PADDSW
%define PADDCUNT32 PADDD
%define PADDCUNT64 PADDQ

; Include files ---------------------------------------------------------------;
;------------------------------------------------------------------------------;
%include "xmc.hasm" 
 
; Constants -------------------------------------------------------------------;
;------------------------------------------------------------------------------;
; Type defines ----------------------------------------------------------------;
;------------------------------------------------------------------------------;
; Macros ----------------------------------------------------------------------;
;------------------------------------------------------------------------------;
; Prototypes ------------------------------------------------------------------;
;------------------------------------------------------------------------------;

;------------------------------------------------------------------------------;
; _BSS.  Align on a 16 byte boundry.                                           ;
;------------------------------------------------------------------------------;
section .bss align=16
x0 RES32 1 ;
x1 RES32 1 ;
x2 RES32 1 ;
x3 RES32 1 ;

y0 RES32 1 ;
y1 RES32 1 ;
y2 RES32 1 ;
y3 RES32 1 ;

;------------------------------------------------------------------------------;
; DATA.  Align on a  4 byte boundry.                                           ;
;------------------------------------------------------------------------------;
section .data align=4

;------------------------------------------------------------------------------;
; TEXT                                                                         ;
;------------------------------------------------------------------------------;
section .text

; Routines --------------------------------------------------------------------;
;------------------------------------------------------------------------------;
%if 0
PERL_PREPROCESS_START
PERL_PREPROCESS         BEGIN                   ; This is a macro to start the routine.
PERL_PREPROCESS
PERL_PREPROCESS         MOV  EAX, p2a           ; Load the address of "a" in EAX.
PERL_PREPROCESS         MOV  EBX, p2b           ; Load the address of "b" in EBX.
PERL_PREPROCESS         MOV  ECX, p2c           ; Load the address of "c" in ECX.
PERL_PREPROCESS         MOV  EDX, n             ; Load the number of elements into EDX.
PERL_PREPROCESS
PERL_PREPROCESS .label01:
PERL_PREPROCESS         MOVDQA XMM0, a          ; Fetch 16 bytes of XXXXX data from "a".
PERL_PREPROCESS         MOVDQA XMM1, b          ; Fetch 16 bytes of XXXXX data from "b".
PERL_PREPROCESS         PADDXXXXX XMM0, XMM1    ; Add XXXXXs.
PERL_PREPROCESS         MOVDQA c, XMM0          ; Put the results in "c".
PERL_PREPROCESS 
PERL_PREPROCESS         ADD  EAX,16             ; Increment address for a by 16 bytes.
PERL_PREPROCESS         ADD  EBX,16             ; Increment address for b by 16 bytes.
PERL_PREPROCESS         ADD  ECX,16             ; Increment address for c by 16 bytes.
PERL_PREPROCESS         SUB  EDX,16             ; Decrement the counter   by 16 bytes.
PERL_PREPROCESS         JNZ .label01            ; Are we at zero yet?
PERL_PREPROCESS
PERL_PREPROCESS         END_IT                  ; This is a macro to end the routine.
%endif


;------------------------------------------------------------------------------;
; VOID _xccvAddXXXXX_i686(XXXXX *a, XXXXX *b, XXXXX *c, UNT32 n)
; Constraints:  Input  data needs to be 16 byte aligned.
;               Input  data needs to be in multiples of 16/XXXXX.
;               Output data needs to be 16 byte aligned.
;               Output data needs to be in multiples of 16/XXXXX.
;------------------------------------------------------------------------------;
%define p2a [EBP+ 8]
%define p2b [EBP+12]
%define p2c [EBP+16]
%define n   [EBP+20]
%define a   [EAX]
%define b   [EBX]
%define c   [ECX]

;------------------------------------------------------------------------------;
; VOID _xccvAddINT08_i686(INT08 *a, INT08 *b, INT08 *c, UNT32 n)
;------------------------------------------------------------------------------;
global _xccvAddINT08_i686		;
                                        ;
_xccvAddINT08_i686:                     ;

;------------------------------- COMMON-CODE_ASM INT08 PADDINT08   START.
         BEGIN                   ; This is a macro to start the routine.

         MOV  EAX, p2a           ; Load the address of "a" in EAX.
         MOV  EBX, p2b           ; Load the address of "b" in EBX.
         MOV  ECX, p2c           ; Load the address of "c" in ECX.
         MOV  EDX, n             ; Load the number of elements into EDX.

 .label01:
         MOVDQA XMM0, a          ; Fetch 16 bytes of INT08 data from "a".
         MOVDQA XMM1, b          ; Fetch 16 bytes of INT08 data from "b".
         PADDINT08 XMM0, XMM1    ; Add INT08s.
         MOVDQA c, XMM0          ; Put the results in "c".
 
         ADD  EAX,16             ; Increment address for a by 16 bytes.
         ADD  EBX,16             ; Increment address for b by 16 bytes.
         ADD  ECX,16             ; Increment address for c by 16 bytes.
         SUB  EDX,16             ; Decrement the counter   by 16 bytes.
         JNZ .label01            ; Are we at zero yet?

         END_IT                  ; This is a macro to end the routine.
;------------------------------- COMMON-CODE_ASM INT08 PADDINT08    STOP.


;------------------------------------------------------------------------------;
; VOID _xccvAddINT16_i686(INT16 *a, INT16 *b, INT16 *c, UNT32 n)
;------------------------------------------------------------------------------;
global _xccvAddINT16_i686		;
                                        ;
_xccvAddINT16_i686:                     ;

;------------------------------- COMMON-CODE_ASM INT16 PADDINT16   START.
         BEGIN                   ; This is a macro to start the routine.

         MOV  EAX, p2a           ; Load the address of "a" in EAX.
         MOV  EBX, p2b           ; Load the address of "b" in EBX.
         MOV  ECX, p2c           ; Load the address of "c" in ECX.
         MOV  EDX, n             ; Load the number of elements into EDX.

 .label01:
         MOVDQA XMM0, a          ; Fetch 16 bytes of INT16 data from "a".
         MOVDQA XMM1, b          ; Fetch 16 bytes of INT16 data from "b".
         PADDINT16 XMM0, XMM1    ; Add INT16s.
         MOVDQA c, XMM0          ; Put the results in "c".
 
         ADD  EAX,16             ; Increment address for a by 16 bytes.
         ADD  EBX,16             ; Increment address for b by 16 bytes.
         ADD  ECX,16             ; Increment address for c by 16 bytes.
         SUB  EDX,16             ; Decrement the counter   by 16 bytes.
         JNZ .label01            ; Are we at zero yet?

         END_IT                  ; This is a macro to end the routine.
;------------------------------- COMMON-CODE_ASM INT16 PADDINT16    STOP.

;------------------------------------------------------------------------------;
; VOID _xccvAddINT32_i686(INT32 *a, INT32 *b, INT32 *c, UNT32 n)
;------------------------------------------------------------------------------;
global _xccvAddINT32_i686		;
                                        ;
_xccvAddINT32_i686:                     ;

;------------------------------- COMMON-CODE_ASM INT32 PADDINT32   START.
         BEGIN                   ; This is a macro to start the routine.

         MOV  EAX, p2a           ; Load the address of "a" in EAX.
         MOV  EBX, p2b           ; Load the address of "b" in EBX.
         MOV  ECX, p2c           ; Load the address of "c" in ECX.
         MOV  EDX, n             ; Load the number of elements into EDX.

 .label01:
         MOVDQA XMM0, a          ; Fetch 16 bytes of INT32 data from "a".
         MOVDQA XMM1, b          ; Fetch 16 bytes of INT32 data from "b".
         PADDINT32 XMM0, XMM1    ; Add INT32s.
         MOVDQA c, XMM0          ; Put the results in "c".
 
         ADD  EAX,16             ; Increment address for a by 16 bytes.
         ADD  EBX,16             ; Increment address for b by 16 bytes.
         ADD  ECX,16             ; Increment address for c by 16 bytes.
         SUB  EDX,16             ; Decrement the counter   by 16 bytes.
         JNZ .label01            ; Are we at zero yet?

         END_IT                  ; This is a macro to end the routine.
;------------------------------- COMMON-CODE_ASM INT32 PADDINT32    STOP.

;------------------------------------------------------------------------------;
; VOID _xccvAddINT64_i686(INT64 *a, INT64 *b, INT64 *c, UNT32 n)
;------------------------------------------------------------------------------;
global _xccvAddINT64_i686		;
                                        ;
_xccvAddINT64_i686:                     ;

;------------------------------- COMMON-CODE_ASM INT64 PADDINT64   START.
         BEGIN                   ; This is a macro to start the routine.

         MOV  EAX, p2a           ; Load the address of "a" in EAX.
         MOV  EBX, p2b           ; Load the address of "b" in EBX.
         MOV  ECX, p2c           ; Load the address of "c" in ECX.
         MOV  EDX, n             ; Load the number of elements into EDX.

 .label01:
         MOVDQA XMM0, a          ; Fetch 16 bytes of INT64 data from "a".
         MOVDQA XMM1, b          ; Fetch 16 bytes of INT64 data from "b".
         PADDINT64 XMM0, XMM1    ; Add INT64s.
         MOVDQA c, XMM0          ; Put the results in "c".
 
         ADD  EAX,16             ; Increment address for a by 16 bytes.
         ADD  EBX,16             ; Increment address for b by 16 bytes.
         ADD  ECX,16             ; Increment address for c by 16 bytes.
         SUB  EDX,16             ; Decrement the counter   by 16 bytes.
         JNZ .label01            ; Are we at zero yet?

         END_IT                  ; This is a macro to end the routine.
;------------------------------- COMMON-CODE_ASM INT64 PADDINT64    STOP.

;------------------------------------------------------------------------------;
; VOID _xccvAddUNT08_i686(UNT08 *a, UNT08 *b, UNT08 *c, UNT32 n)
;------------------------------------------------------------------------------;
global _xccvAddUNT08_i686		;
                                        ;
_xccvAddUNT08_i686:                     ;

;------------------------------- COMMON-CODE_ASM UNT08 PADDUNT08   START.
         BEGIN                   ; This is a macro to start the routine.

         MOV  EAX, p2a           ; Load the address of "a" in EAX.
         MOV  EBX, p2b           ; Load the address of "b" in EBX.
         MOV  ECX, p2c           ; Load the address of "c" in ECX.
         MOV  EDX, n             ; Load the number of elements into EDX.

 .label01:
         MOVDQA XMM0, a          ; Fetch 16 bytes of UNT08 data from "a".
         MOVDQA XMM1, b          ; Fetch 16 bytes of UNT08 data from "b".
         PADDUNT08 XMM0, XMM1    ; Add UNT08s.
         MOVDQA c, XMM0          ; Put the results in "c".
 
         ADD  EAX,16             ; Increment address for a by 16 bytes.
         ADD  EBX,16             ; Increment address for b by 16 bytes.
         ADD  ECX,16             ; Increment address for c by 16 bytes.
         SUB  EDX,16             ; Decrement the counter   by 16 bytes.
         JNZ .label01            ; Are we at zero yet?

         END_IT                  ; This is a macro to end the routine.
;------------------------------- COMMON-CODE_ASM UNT08 PADDUNT08    STOP.


;------------------------------------------------------------------------------;
; VOID _xccvAddUNT16_i686(UNT16 *a, UNT16 *b, UNT16 *c, UNT32 n)
;------------------------------------------------------------------------------;
global _xccvAddUNT16_i686		;
                                        ;
_xccvAddUNT16_i686:                     ;

;------------------------------- COMMON-CODE_ASM UNT16 PADDUNT16   START.
         BEGIN                   ; This is a macro to start the routine.

         MOV  EAX, p2a           ; Load the address of "a" in EAX.
         MOV  EBX, p2b           ; Load the address of "b" in EBX.
         MOV  ECX, p2c           ; Load the address of "c" in ECX.
         MOV  EDX, n             ; Load the number of elements into EDX.

 .label01:
         MOVDQA XMM0, a          ; Fetch 16 bytes of UNT16 data from "a".
         MOVDQA XMM1, b          ; Fetch 16 bytes of UNT16 data from "b".
         PADDUNT16 XMM0, XMM1    ; Add UNT16s.
         MOVDQA c, XMM0          ; Put the results in "c".
 
         ADD  EAX,16             ; Increment address for a by 16 bytes.
         ADD  EBX,16             ; Increment address for b by 16 bytes.
         ADD  ECX,16             ; Increment address for c by 16 bytes.
         SUB  EDX,16             ; Decrement the counter   by 16 bytes.
         JNZ .label01            ; Are we at zero yet?

         END_IT                  ; This is a macro to end the routine.
;------------------------------- COMMON-CODE_ASM UNT16 PADDUNT16    STOP.

;------------------------------------------------------------------------------;
; VOID _xccvAddUNT32_i686(UNT32 *a, UNT32 *b, UNT32 *c, UNT32 n)
;------------------------------------------------------------------------------;
global _xccvAddUNT32_i686		;
                                        ;
_xccvAddUNT32_i686:                     ;

;------------------------------- COMMON-CODE_ASM UNT32 PADDUNT32   START.
         BEGIN                   ; This is a macro to start the routine.

         MOV  EAX, p2a           ; Load the address of "a" in EAX.
         MOV  EBX, p2b           ; Load the address of "b" in EBX.
         MOV  ECX, p2c           ; Load the address of "c" in ECX.
         MOV  EDX, n             ; Load the number of elements into EDX.

 .label01:
         MOVDQA XMM0, a          ; Fetch 16 bytes of UNT32 data from "a".
         MOVDQA XMM1, b          ; Fetch 16 bytes of UNT32 data from "b".
         PADDUNT32 XMM0, XMM1    ; Add UNT32s.
         MOVDQA c, XMM0          ; Put the results in "c".
 
         ADD  EAX,16             ; Increment address for a by 16 bytes.
         ADD  EBX,16             ; Increment address for b by 16 bytes.
         ADD  ECX,16             ; Increment address for c by 16 bytes.
         SUB  EDX,16             ; Decrement the counter   by 16 bytes.
         JNZ .label01            ; Are we at zero yet?

         END_IT                  ; This is a macro to end the routine.
;------------------------------- COMMON-CODE_ASM UNT32 PADDUNT32    STOP.

;------------------------------------------------------------------------------;
; VOID _xccvAddUNT64_i686(UNT64 *a, UNT64 *b, UNT64 *c, UNT32 n)
;------------------------------------------------------------------------------;
global _xccvAddUNT64_i686		;
                                        ;
_xccvAddUNT64_i686:                     ;

;------------------------------- COMMON-CODE_ASM UNT64 PADDUNT64   START.
         BEGIN                   ; This is a macro to start the routine.

         MOV  EAX, p2a           ; Load the address of "a" in EAX.
         MOV  EBX, p2b           ; Load the address of "b" in EBX.
         MOV  ECX, p2c           ; Load the address of "c" in ECX.
         MOV  EDX, n             ; Load the number of elements into EDX.

 .label01:
         MOVDQA XMM0, a          ; Fetch 16 bytes of UNT64 data from "a".
         MOVDQA XMM1, b          ; Fetch 16 bytes of UNT64 data from "b".
         PADDUNT64 XMM0, XMM1    ; Add UNT64s.
         MOVDQA c, XMM0          ; Put the results in "c".
 
         ADD  EAX,16             ; Increment address for a by 16 bytes.
         ADD  EBX,16             ; Increment address for b by 16 bytes.
         ADD  ECX,16             ; Increment address for c by 16 bytes.
         SUB  EDX,16             ; Decrement the counter   by 16 bytes.
         JNZ .label01            ; Are we at zero yet?

         END_IT                  ; This is a macro to end the routine.
;------------------------------- COMMON-CODE_ASM UNT64 PADDUNT64    STOP.


;------------------------------------------------------------------------------;
; VOID _xccvAddFINT08INT08INT08_i686(INT08 *a, FLT32 *b, INT08 *c, UNT32 n)
;------------------------------------------------------------------------------;
global _xccvAddINT08FLT32INT08_i686		;
                        	                ;
_xccvAddFINT08INT08INT08_i686:                  ;

	BEGIN                   ; This is a macro to start the routine.

       	MOV  EAX, n     ;
        MOV  EBX, p2a   ;
        MOV  ECX, p2b   ;
        MOV  EDX, p2c   ;
	
	PUSH EAX         ;
        MOV  AL,  [EBX  ];
        MOV  [x0], AL    ;
        MOV  AL,  [EBX+1];
        MOV  [x1], AL    ;
        MOV  AL,  [EBX+2];
        MOV  [x2], AL    ;
        MOV  AL,  [EBX+3];
        MOV  [x3], AL    ;


        CVTPI2PS XMM0,[x0]; Convert 16 bytes of INT32 to FLT32
        MOVDQA   XMM1, b  ; Fetch 16 bytes of FLT32 data from "b".
        ;float add
        ;convert to INT32
        ;convert to INT08
        ;next



;        MOV  [z1], AL   ;
;        MOV  AL,  [w2]  ;
;                   MOV  [z2], AL   ;
;		   MOV  AL,  [w3]  ;
;                   MOV  [z3], AL   ;
;		   MOVDQA XMM0,[z0];
;                   CVTPI2PS XMM0,[z0];
;                   CVTPI2PS XMM1,[z2];
;		   MOV  AX,  [x]   ;
;		   MOV  [z], AX
