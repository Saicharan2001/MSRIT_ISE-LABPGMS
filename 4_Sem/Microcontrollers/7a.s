		AREA PROG7,CODE,READONLY
DIVIDEND RN 1
DIVISOR RN 2
QUOTIENT RN 3
REMAINDER RN 4
RESULT RN 5
ENTRY	LDR DIVIDEND,=12345
		MOV DIVISOR,#10
		MOV RESULT,#0
LOOP	BL DIV
		ADD RESULT,REMAINDER,RESULT
		CMP QUOTIENT,#0
		MOVNE DIVIDEND,QUOTIENT
		BNE LOOP
STOP    B   STOP
DIV		MOV QUOTIENT,#0
LOOP1	SUBS DIVIDEND,DIVIDEND,DIVISOR
		ADDPL QUOTIENT,QUOTIENT,#1
		BPL LOOP1
		ADDMI REMAINDER,DIVIDEND,DIVISOR
		MOV PC,LR     ;BX LR (Both are same)
		END