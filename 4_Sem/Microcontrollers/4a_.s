	AREA PROG4,CODE,READONLY
ENTRY
	MOV R0,#0
	LDR R3,=PRO
	ADD R0,R0,#3
	STR R0,[R3],#4
	ADD R0,R0,#7
	MOV R5,#0
LOOP
	STR R0,[R3],#4
	ADD R0,R0,#7
	ADD R5,R5,#1
	CMP R5,#9
	BNE LOOP
GO  B GO
	AREA PROG,DATA,READWRITE
PRO SPACE 10
	END
	