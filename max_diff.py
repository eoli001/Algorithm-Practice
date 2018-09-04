'''
import sys

def max_diff(lst):
	if lst != []:
		max_so_far = lst[0]
		min_so_far = lst[0]
		for num in lst:
			if num > max_so_far:
				max_so_far = num
			elif num < min_so_far:
				min_so_far = num
		return max_so_far - min_so_far
	else:
		return 0

print (max_diff([2, 4, 7, 6, 10, 9, 2]))

print (max_diff([ 8, 10, 6, 7, 5, 1 ]))
'''
import sys
def max_diff(lst):
	if lst != []:
		min_so_far = lst[0]
		max_so_far = lst[0]
		diff_so_far = 0
		cur_diff = 0 
		for i in range(len(lst)):
			if lst[i] < min_so_far:
				min_so_far = lst[i]
				max_so_far = lst[i]
			if lst[i] > max_so_far:
				max_so_far = lst[i]

			cur_diff = max_so_far - min_so_far
			if (cur_diff > diff_so_far):
				diff_so_far = cur_diff

		return diff_so_far
	else:
		return 0

print (max_diff([2, 4, 7, 6, 10, 9, 2]))

print (max_diff([ 8, 10, 6, 7, 5, 1 ]))

print (max_diff([ 4, 5, 7, 2, 3, 1, 6, 10, 6, 7, 5, 1 ]))