import sys

def ownerfile(d):
	result = {}
	for key, value in d.items:
		if value in result.values:
			result[value]+=", " + key
		else:
			result[value]= key
	for key,value in result.items:
	    s=key + ": " + value
        print(s)
	return result
	
