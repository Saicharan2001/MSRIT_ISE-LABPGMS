		AREA PROG1,CODE,READONLY
ENTRY
		MOV R7,#0
		MOV R4,#0
		MOV R2,#1
LOOP 	BL SQU
		ADD R7,R7,R4
		ADD R2,R2,#1
		CMP R2,#6
		BNE LOOP
GO  	B GO
SQU		MUL R4,R2,R2
		MOV PC,LR
		END
	
/*AREA PROG1,CODE,READONLY
ENTRY
	MOV R0,#0
	MOV R1,#1
	MOV R4,#0
LOOP
	MULS R4,R1,R1
	ADD R0,R0,R4
	ADD R1,R1,#1
	CMP R1,#6
	BNE LOOP
GO B GO
	END*/