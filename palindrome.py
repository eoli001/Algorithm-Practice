'''

                            Online Python Compiler.
                Code, Compile, Run and Debug python program online.
Write your code in this editor and press "Run" button to execute it.

'''

# Hello World program in Python
    
def checkpalindrome(word):
    lenword = len(word);
    if(lenword%2==0):
        mid = lenword//2-1;
    
    else:
        mid = lenword//2
    i=0
    j=lenword-1
    while(mid >= 0 ):
        print(mid)
        if(word[i]!=word[j]):
            print("false")
        else:
            i+=1
            j-=1
            mid=mid-1
    print("true")
    
#checkpalindrome("wo1aw")
#checkpalindrome("wo1ow")
checkpalindrome("")

