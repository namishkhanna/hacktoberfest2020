#Palindrome or Not?
s = input('Enter your string: ')
s = s.lower()   #Make string lowercase if string contain uppercase

if s[:]==s[::-1]:       #condition check      
        print('Palindrome!')
else:
        print('Not Palindrome!')
