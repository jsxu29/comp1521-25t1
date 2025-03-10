## Structs

The values in a struct are also stored one after another.

```
// 2D representation of a point, stored as a single struct
struct point2D {
    int row; (at bytes 0-4 of the struct)
    int col; (at bytes 4-8 of the struct)
} typedef point2D_t;
```

In MIPS, we should first define constants to make it more readable by avoiding magic numbers.

```
ROW_OFFSET = 0
COL_OFFSET = 4
POINT2D_SZ = 8
```

An example of accessing a struct point2D_t point from data.
```
la 	$t3, point
lw	$t1, ROW_OFFSET($t3)	# $t1 = point.row
lw	$t2, COL_OFFSET($t3)	# $t2 = point.col
```

## 2D Arrays

```
topography_grid:
	.word	0, 1, 1, 2, 3
	.word	1, 1, 2, 3, 4
	.word	1, 2, 3, 5, 7
	.word	3, 3, 4, 5, 6
	.word	3, 4, 5, 6, 7
```

position of that element = row size (number of columns in each row) * number of rows + column position


## 2D Array Address

i - row position \
j - col position \
address of array[i][j] \
= address of array + offset \
= address of array + ((number of columns in each row) * i + j) * sizeof(each array element)


1) Calculate the position of the element

```
mult    $t0, <number of columns in each row>, i
add     $t0, $t0, j
```

Multiply by the size of each array element.

i.e.
```
mul     $t1, $t0, <size of each array element>
```

2) Find the base address of the array

```
la     $t2, <array name> 
```

3) Add the offset to the base address

```
add     $t3, $t1, $t2
```

4) Store/load value at the calculated address

```
sw      <somewhere>, ($t3)
```

