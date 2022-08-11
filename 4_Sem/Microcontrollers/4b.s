	AREA PROG9,CODE,READONLY
N RN 1
NPLUSONE RN 2
TEMP RN 3
RESULT RN 4
ENTRY
	MOV R5,#0x40000000
	LDR N,=3 
	ADD NPLUSONE,N,#1
	MUL TEMP,N,NPLUSONE
	MOV TEMP,TEMP,LSR #1
	MUL RESULT,TEMP,TEMP
	STR RESULT,[R5]
STOP B STOP
	END
		
//At line 8, Pseudo instruction is used as it is a immediate mode of addressing		

// This is working based on a formula i.e., 
// 1.NPLUSONE=N+1 (3+1)
//2. TEMP=N*NPLUSONE (3*4)
//3. TEMP=TEMP/2 (By LSR)
//4. RESULT=TEMP*TEMP (This contains the final result)

// Above process is (n^2(n+1)^2)/4
// TEMP = (n*(n+1))/2
// So Result is TEMP*TEMP
