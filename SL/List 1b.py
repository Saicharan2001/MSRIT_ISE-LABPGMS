from collections import Counter
def word_count(fname):
	# with open(fname) as f:
	f=open(fname)
	return Counter(f.read().split())
print("Number of words in the provided file : ",word_count('song.txt'))
