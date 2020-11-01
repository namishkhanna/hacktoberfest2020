def main():
    msg = raw_input("enter your msg: ")
    enc = ''
    for i in msg:
        enc += chr((ord(i) + 13) % 0xff)
    print("your encrypted msg: " + enc)


if __name__ == "__main__":
    main()
