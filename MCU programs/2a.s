	AREA PROG1,CODE,READONLY
ENTRY
	MOV R1,#0	;Storing the result
	MOV R2,#1	;Using as counter variable and to add in the operation
LOOP 
	ADD R1,R1,R2
	ADD R2,R2,#1
	CMP R2,#6	;comparing the values
	BNE LOOP	;Branch not equal to zero
GO B GO
	END