	AREA PROG5,CODE,READONLY
ENTRY
	LDR R7,=TAB
	MOV R2,#9
	LDRH R1,[R7]
LOOP
	LDRH R3,[R7,#2]!
	ADD R1,R1,R3
	SUBS R2,R2,#1
	BNE LOOP
	MOV R4,#0  ;QUOTIENT
	MOV R6,#10  ;DIVISOR
	MOV R5,R1	
BACK 
	SUBS R5,R5,R6
	ADDPL R4,R4,#1  ;N IS CLEAR
	BPL BACK
	ADDMI R5,R5,R6  ;N IS SET
GO  B GO
TAB DCW 1000,1001,1002,1003,1004,1005,1006,1007,1008,1009  ; Answer is 3EC
	END