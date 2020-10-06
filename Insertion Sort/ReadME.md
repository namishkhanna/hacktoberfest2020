# Insertion Sort:
	Consider 8,4,1,2,3.
	Initially,8 is the smallest.
	then 4 is inserted such that 4 will come before 8.So I swap 4 and 8. 4,8,1,2,3
	8>4, so I will move to next number.
	Now, 1 is inserted in such a way that 1 will come before 4. Swapping 1,4,...1,8,4,2,3
	4<8
	Therefore, swap(4,8).Therefore 1,4,8,2,3.
	Next 2. 1,2...no swap.
			4,2...swap. Therefore 1,2,8,4,3
			4,8...swap. Therefore 1,2,4,8,3
	Next 3. 1,3...No swap.
			2,3...no swap
			4,3...Swap
	Final Answer= 1,2,3,4,8
	
	POINTS TO REMEMBER:
	
	1.NO EXTRA MEMORY REQUIRED.
	2.MAXIMUM NUMBER OF COMPARISONS REQUIRED ARE IN IN ORDER OF O(n^2).
	3.MAXIMUM NUMBER OF SWAPS REQUIRED ARE IN IN ORDER OF O(n^2).
	4.INSERTION SORT IS ADAPTIVE BY NATURE (SWAPS ONLY OCCUR WHEN REQUIRED).
	5.INSERTION SORT IS STABLE.


# Sample Output

Enter total number of elements

10

Start entering the numbers

5 3 1 4 8 22 2 50 98  -100

The elements are

5 3 1 4 8 22 2 50 98 -100


Iteration 1 :-         3 5 1 4 8 22 2 50 98 -100

Iteration 2 :-         1 3 5 4 8 22 2 50 98 -100

Iteration 3 :-         1 3 4 5 8 22 2 50 98 -100

Iteration 4 :-         1 3 4 5 8 22 2 50 98 -100

Iteration 5 :-         1 3 4 5 8 22 2 50 98 -100

Iteration 6 :-         1 2 3 4 5 8 22 50 98 -100

Iteration 7 :-         1 2 3 4 5 8 22 50 98 -100

Iteration 8 :-         1 2 3 4 5 8 22 50 98 -100

Iteration 9 :-        -100 1 2 3 4 5 8 22 50 98



AFter sorting the elements are as follows:-

-100 1 2 3 4 5 8 22 50 98




