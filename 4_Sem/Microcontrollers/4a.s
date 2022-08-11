	AREA PROG8,CODE,READONLY
ENTRY
	MOV R1,#3
	MOV R2,#1
	LDR R3,=PRO 	;R3 contains the starting address of the space of 10 bytes
	STR R1,[R3]
	ADD R1,R1,#7
BACKK STR R1,[R3,#4]!  ;Pre-addressing format with write back implementation
	ADD R1,R1,#7
	ADD R2,R2,#1
	CMP R2,#10
	BNE BACKK
GO B GO
	AREA PROGRESSION,DATA,READWRITE
PRO SPACE 10
	END
