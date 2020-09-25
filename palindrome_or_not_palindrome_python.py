string =  input()
for i in range(0, int(len(string)/2)): 
        if(string[i] != string[len(string)-i-1]):
            ans=0
        else:
            ans=1
if(ans==1):
    print("Palindrome")
else:
    print("Not Palindrome")
