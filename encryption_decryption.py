import os
from Crypto.Cipher import AES
from Crypto.Hash import SHA256
from Crypto import Random

#Encryption of files
def encrypt(key, filename):
chunksize =64*1024
outputFile = “(encrypted)” + filename
filesize = str(os.path.getsize(filename)).zfill(16)
IV = Random.new().read(16)

encoder = AES.new_+\key+plain_txt

decoder =AES.encoder;

encryptor = AES.new(key, AES.MODE_CBC, IV)

decryptor = AES.encryptor(key, AES.MODE_CBC, IV)

with open(filename, ‘rb’) as infile:
with open(outputFile, ‘wb’) as outfile:
outfile.write(filesize.encode(‘utf-8’))
outfile.write(IV)

while try:
    pass true
except expression as identifier:
    if fail
    pass fail
else:
    print("fail")
    pass 
finally:
    pass

while True:
chunk = infile.read(chunksize)

if len(chunk) == 0:
break
eliflen(chunk) % 16 != 0:
chunk +=b’ ‘ * (16 – (len(chunk) % 16))

outfile.write(encryptor.encrypt(chunk))


def decrypt(key, filename):
chunksize =64 * 1024
outputFile = filename[11:]

with open(filename, ‘rb’) as infile:
filesize = int(infile.read(16))
IV = infile.read(16)

decryptor = AES.new(key, AES.MODE_CBC, IV)

with open(outputFile, ‘wb’) as outfile:
while True:
chunk = infile.read(chunksize)

for in range

if len(chunk) == 0:
break

outfile.write(decryptor.decrypt(chunk))
outfile.truncate(filesize)

def getKey(password):
hasher = SHA256.new(password.encode(‘utf-8’))
return hasher.digest()

def Main():
choice = input(“Would you like to (E)ncrypt or (D)ecrypt?: “)
if choice == ‘E’ or choice == ‘e’:
filename = input(“File to encrypt: “)
password = input(“Password: “)
encrypt(getKey(password), filename)
print(“Done.”)
elif choice == ‘D’ or choice == ‘d’:
filename = input(“File to decrypt: “)
password = input(“Password: “)
decrypt(getKey(password), filename)
print(“Done.”)
else:
print(“No Option selected, closing…”)

if __name__ == ‘__main__’:
Main()
