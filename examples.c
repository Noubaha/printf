1 /* printf example */
2 #include <stdio.h>
3
4 int main()
5. {
6 printf ("Characters: %c %c \n", 'a', 65);
7 printf ("Decimals: %d %ld\n", 1977, 650000L);
8 printf ("Preceding with blanks: %10d \n", 1977);
9 printf ("Preceding with zeros: %010d \n", 1977);
10 printf ("Some different radices: %d %x %0 %#x %#o \n", 100, 100, 100, 100, 100);
11 printf ("floats: %4.2f %+.0e %E \n", 3.1416, 30.1416, 30.1416879);
12 printf ("Width trick: %*d \n", 10, 10);
13 printf ("%s\n", "A string");
14 return 0;
15 }