	AREA PROG3,CODE,READONLY
A RN 0
D RN 2
ENTRY
	MOV R5,#0x40000000
	MOV A,#1
	MOV D,#2
	MOV R3,#10
LOOP
	MUL A,D,A      ;MUL R6,R0,R2
	STR A,[R5],#4
	;MOV R0,R6
	SUBS R3,R3,#1
	BNE LOOP
GO  B GO
	END