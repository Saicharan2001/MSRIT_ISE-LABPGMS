# from collections import Counter
# def word_count(fname):
# 	# with open(fname) as f:
# 	f=open(fname)
# 	# f.close()
# 	print(Counter(f.read().split()))
# 	f.close()
# word_count('song.txt')


from collections import Counter
def words(fname):
	fh=open(fname)
	print(Counter(fh.read().split()))
	fh.close()
words('song.txt')