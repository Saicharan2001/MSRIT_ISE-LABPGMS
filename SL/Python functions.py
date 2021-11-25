def celciustofarenhiet(c):
    return (c*(9/5) + 32)

def farenhiettocelcius(p):
    return ((p-32)*(5/9))

def celciustokelvin(x):
    return (x+273.15)

def kelvintocelcius(y):
    return (y-273.15)

def farenhiettokelvin(a):
    return celciustokelvin(farenhiettocelcius(a))

def kelvintofarenhiet(b):
    return celciustofarenhiet(kelvintocelcius(b))

select = "y"
op1=[]
op2=[]
op3=[]
op4=[]
op5=[]
op6=[]


while(select=="y" or select == "Y"):
    op = input("Enter the selection: 1.C->F  2.F->C  3.C->K  4.K->C  5.F->K  6.K->F \n")
    if(op=="1" or op=="2" or op=="3" or op=="4" or op=="5" or op=="6"):
        if(op=="1"):
            c = float(input("Enter the temperature in celsius:  "))
            op1 = op1 +[(c,celciustofarenhiet(c))]
            print("Celsius to Farenhiet\n")
            print(sorted(op1))
        elif(op=="2"):
            p = float(input("Enter the temperature in farenhiet:  "))
            op2=op2 + [(p,farenhiettocelcius(p))]
            print("Farenhiet to Celsius\n")
            print(sorted(op2))
        elif(op=="3"):
            x = float(input("Enter the temperature in celsius:  "))
            op3=op3 + [(x,celciustokelvin(x))]
            print("Celsius to Kelvin\n")
            print(sorted(op3))
        elif(op=="4"):
            y = float(input("Enter the temperature in kelvin:  "))
            op4 = op4+[(y,kelvintocelcius(y))]
            print("Kelvin to Celsius\n")
            print(sorted(op4))
        elif(op=="5"):
            a = float(input("Enter the temperature in farenhiet:  "))
            op5=op5+[(a,farenhiettokelvin(a))]
            print("Farenhiet to Kelvin\n")
            print(sorted(op5))
        elif(op=="6"):
            b = float(input("Enter the temperature in kelvin:  "))
            op6=op6+[(b,kelvintofarenhiet(b))]
            print("Kelvin to Farenhiet\n")
            print(sorted(op6))
    else:
        print("Invalid Input")
    select = input("Enter Y to continue and N to terminate\n")


# import sys
# def CF():
# 	#Write function
# 	k=int(input('Enter temp in celsius: '))
# 	print("The temperature in Farhenheit:",((k*(9/5))+32))
# 	print()
# def FC():
# 	#Write function
# 	k=int(input('Enter temp in Farhenheit: '))
# 	print("The temperature in celsius:",((5/9)*(k-32)))
# 	print()
# def conversion():

# if __name__=="__main__":
	
# 	while(True):
# 		print('Enter your requirement number from below')
# 		print("Farhenheit to celsius --->  1")
# 		print('celsius to Farhenheit ---> 2')
# 		print('View previous records ---> 3')
# 		print('To exit ---> 4')
# 		req=int(input("Enter the number from above: "))
# 		if req==1:
# 			FC()
# 		elif req==2:
# 			CF()
# 		elif req==3:
# 			conversion()
# 		else:
# 			print("Thank you")
# 			sys.exit()