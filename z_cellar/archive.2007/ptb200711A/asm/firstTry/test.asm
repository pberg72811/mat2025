global _iccAddINT32_i686        ;

; _BSS.  Align on a 16 byte boundry.
;-------------------------------------------------------------------------------
section .bss align=16
z0 resd 1 ; Reserve double (resd)
z1 resd 1 ; Reserve double (resd)
z2 resd 1 ; Reserve double (resd)
z3 resd 1 ; Reserve double (resd)
z  resw 1 ; Reserve word   (resw)

; DATA.  Align on a  4 byte boundry.
;-------------------------------------------------------------------------------
section .data align=4
w0   db 0x12
w1   db 0x22
w2   db 0x44
w3   db 0x66
x   dw 0xaabb
y   dd 0xaabbccdd

; TEXT
;-------------------------------------------------------------------------------
section .text

;-------------------------------------------------------------------------------
;
; VOID _iccAddFLT32_i686(FLT32 *a, FLT32 *b, FLT32 *c, UNT32 n)
;
;-------------------------------------------------------------------------------
%define p2a [EBP+ 8]
%define p2b [EBP+12]
%define p2c [EBP+16]
%define n   [EBP+20]
%define t   [EBP+24]
%define a   [EBX]
%define b   [ECX]
%define c   [EDX]

_iccAddINT32_i686: PUSH EBP        ;
                   MOV  EBP, ESP   ;
                   PUSH EAX        ;
                   PUSH EBX        ;
                   PUSH ECX        ;
                   PUSH EDX        ;

                   MOV  EAX, n     ;
                   MOV  EBX, p2a   ;
                   MOV  ECX, p2b   ;
                   MOV  EDX, p2c   ;
                   MOVHPD XMM0, t  ;
		   MOVD XMM0, a    ;
                   MOVQ XMM1, b    ;
		   MOV  AL,  [w0]  ;
                   MOV  [z0], AL   ;
		   MOV  AL,  [w1]  ;
                   MOV  [z1], AL   ;
		   MOV  AL,  [w2]  ;
                   MOV  [z2], AL   ;
		   MOV  AL,  [w3]  ;
                   MOV  [z3], AL   ;
		   MOVDQA XMM0,[z0];
                   CVTPI2PS XMM0,[z0];
                   CVTPI2PS XMM1,[z2];
		   MOV  AX,  [x]   ;
		   MOV  [z], AX
		   MOV  EAX,  [z0]   ;
		   MOV  EAX,  [y]   ;
                   MOV  EAX, n     ;
.label01                
                   MOVQ MM0, a     ;
                   MOVQ MM1, b     ;
                   PADDD MM0, MM1  ;
                   MOVQ c, MM0     ;
                   ADD  EBX,8      ;
                   ADD  ECX,8      ;
                   ADD  EDX,8      ;
                   SUB  EAX,2      ;
                   JNZ .label01    ;
                   EMMS

                   POP  EDX        ;
                   POP  ECX        ;
                   POP  EBX        ;
                   POP  EAX        ;
                   POP  EBP        ;

                   RET             ;


