	AREA PROG1,CODE,READONLY
A RN 1
D RN 2
N RN 3
ENTRY	MOV A,#1
		MOV D,#2
		MOV N,#10
		MOV R5,#0x40000000
LOOP	MUL A,D,A
			;getting line 13 here gives you another geometric progression
		SUBS N,N,#1
		STR A,[R5],#4
		;MOV A,R6
		BNE LOOP
STOP B STOP
		END
