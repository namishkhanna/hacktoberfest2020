def pascals(limit: int, times: int = 0, number: list = ["1"]) -> None:
    """
    A function to print Pascals Triangle pattern upto given limit.Only limit is required other arguements are for controlling the loop
    """
    print(" ".join(number).center(80))
    if times <= int(limit) - 2:
        newnumlis = ["1"]
        for i in range(len(number) - 1):
            newnum = int(number[i]) + int(number[i + 1])
            newnumlis.append(str(newnum))
        newnumlis.append("1")
        times += 1
        pascals(limit, times, newnumlis)


if __name__ == "__main__":
    inpu = str(input("Enter a Number:"))
    pascals(inpu)
