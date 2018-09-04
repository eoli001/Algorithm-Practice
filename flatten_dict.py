
'''
import sys

def solution(dlist, a):
    for key,value in dlist.items():
        #if(type(value) is dict):
        #print('key  '+ key)
        if (type(value) is str):
            if a == '':
                print (key + '：' + value + '\n')
            else:
                print(a + ' => ' + key + '：' + value + '\n')
        elif(isinstance(value,dict)):
            a = key
            #print (key + ' => ')
            solution(value, a)

def flatten_dict(d, main_key):
  new_d = {}
  for key in d.keys():
    if isinstance(d[key], dict): 
      new_d.update(flatten_dict(d[key],main_key + key + " => "))
    else:
      new_d[main_key + key] = d[key]
  return new_d

'''

import sys

def solution(dlist, a):
    new_d = {}
    for key,value in dlist.items():
        if (type(value) is str):
            new_d[a + key] = value
        elif(isinstance(value,dict)):
            new_d.update(solution(value, a + key + "=>"))
    return new_d
    

d = {
 "phones": {
 "iphone": "7",
 "android": "Pixel",
 },
 "computer": {
 'PC': {
 'Lenovo': "Thinkpad",
 'Microsoft': "Surface",
 },
 'Apple': "Mac",
 }
} 


print(solution(d, ''))


                
                
                
                    
            
            
    
        


