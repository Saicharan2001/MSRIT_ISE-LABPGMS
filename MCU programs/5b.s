	AREA PROG1,CODE,READONLY
ENTRY
	LDR R7,=TABLE
	MOV R0,#9
	LDRH R1,[R7]
BACKK LDRH R2,[R7,#2]!	
	ADD R1,R1,R2
	SUBS R0,R0,#1
	BNE BACKK
	MOV R3,#10
	MOV R4,#0
	MOV R5,R1
BACKK1 SUBS R5,R5,R3
	ADDPL R4,R4,#1	;Executes this condition if the N-flag is clear  (PL)
	BPL BACKK1	
	ADDMI R5,R5,R3	; Executes this only if the N-flag is set (MI)
GO B GO
TABLE DCW 1000,2564,8936,344,5667,908,786,654,9871,456
	END				;R4 will be having the quotient and R5 contains the remainder
	