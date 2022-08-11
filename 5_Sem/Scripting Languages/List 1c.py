# import random
# def recur(sai2):
# 	if len(sai2)==1:
# 		return sai2[0]
# 	else:
# 		m=recur(sai2[1:])
# 		return m if m>sai2[0] else sai2[0]
# sai=[]
# for i in range(10):
# 	sai.append(random.randint(1,30))
# # print(sai)
# print(recur(sai)) 

# def Max(list):
#     if len(list) == 1:
#         return list[0]
#     else:
#         m = Max(list[1:])
#         return m if m > list[0] else list[0]

# def main():
# 	try:
# 		list = int(input("Enter a list of numbers: "))
# 		# list=[int(i) for i in input().split()]
# 		print ("The largest number is: ", Max(list))
# 	except SyntaxError:
# 		print ("Please enter comma separated numbers")
# 	except:
# 		print ("Enter only numbers")

# main()


def maxi(l):
	if len(l)==1:
		return l[0]
	m=maxi(l[1:])
	return m if m > l[0] else l[0]

if __name__=="__main__":
	l=[int(i) for i in input().split()]
	print("Max element is:",maxi(l))
