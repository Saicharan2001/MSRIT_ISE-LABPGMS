# S = [x**2 for x in range(10)] # read elements  to list
# M = [x for x in S if x % 2 == 0]
# M.reverse()
# print(M)


m=list()
m=[int(i) for i in input("Enter the sequence of numbers").split()]

print(m)

new_noduplicates=list(set(m))
print(new_noduplicates)

evens=[i for i in range(1,11) if i%2==0]
print(evens)

reverse_evens=list(reversed(evens))
print(reverse_evens)