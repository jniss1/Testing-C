#include <stdio.h>
#include <string.h>
// SOLUTION FILE

main()
{
  int var_int;                    // 2

  unsigned char uchar1, uchar2;   // 3
  signed char schar1, schar2;

  int x, y;                       // 4

  char i;                         // 5
  char shift_char;

  int a[10] = {0,10,20,30,40,50,60,70,80,90};    // 6

  int b[10], c[10];               // 7
  int *ip, *ip2;
  int j, k;

  char AString[] = "HAL";           // 8

  // 1 -- change "World" to your name
  printf("\n\n PART 1 ---------\n");

  printf("\n Hello Jacob! \n");

  // 2 -- find sizes of the other C datatypes
  printf("\n\n PART 2 ----------\n");

  printf("\n size of data type int = %lu bytes", sizeof(var_int));
  printf("\n size of data type char = %lu byte", sizeof(i));
  long int bannana;
  printf("\n size of data type long = %lu bytes", sizeof(bannana));

  // 3 -- explore signed versus unsigned datatypes and their interactions
  printf("\n\n PART 3 ----------\n");

  uchar1 = 0xFA;
  uchar2 = 0xFE;
  schar1 = 0xFA;
  schar2 = 0xFE;

  printf("\n uchar1 = %d ", uchar1);
  printf("\n schar1 = %d ", schar1);

  if (uchar1 > uchar2){
    printf("\n uchar1 (size %d) is larger than uchar2 (with size %d)", uchar1, uchar2);
  } else{
    printf("\n uchar2 (size %d) is larger than uchar1 (with size %d)", uchar2, uchar1);
  }

  if (schar1 > schar2){
    printf("\n schar1 (size %d) is larger than schar2 (with size %d)", schar1, schar2);
  } else{
    printf("\n schar2 (size %d) is larger than schar1 (with size %d)", schar2, schar1);
  }

  if (uchar1 > schar1){
    printf("\n uchar1 (size %d) is larger than schar1 (with size %d)", uchar1, schar1);
  } else{
    printf("\n schar1 (size %d) is larger than uchar1 (with size %d)", schar1, uchar1);
  }

  int scharSum = schar1 + schar2;
  printf("\n the sum of schar1 (%d) and schar2 (%d) is: %d", schar1, schar2, scharSum);

  int ucharSum = uchar1 + uchar2;
  printf("\n the sum of uchar1 (%d) and uchar2 (%d) is: %d", uchar1, uchar2, ucharSum);

  int mixedcharSum = uchar1 + schar1;
  printf("\n the sum of schar1 (%d) and uchar1 (%d) is: %d", schar1, uchar1, mixedcharSum);

  // 4 -- Booleans
  printf("\n\n PART 4 ----------\n");

  printf("\n 5 > 4: %d\n", (5 > 4));
  printf("\n the size of a boolean is: %lu bytes", sizeof((5 > 4)));

  int ape = 5;
  int beluga = 8;

  printf("\n This uses bitwise AND &: %d", ape & beluga);
  printf("\n This uses logical AND &&: %d", ape && beluga);
  printf("\n This uses bitwise NOT ~: %d", ~beluga);
  printf("\n This uses logical NOT !: %d", !beluga);

  // 5 -- shifts
  printf("\n\n PART 5 ----------\n");
  

  shift_char = 15; // 1111
  i = 1;

  printf("\n shift_char << %d = %d", i, shift_char << i); // 11110 = 30
  printf("\n shift_char >> %d = %d", i, shift_char >> i); // 0111 = 7
 
  i = 4;
 
  printf("\n shift_char << %d = %d", i, shift_char << i); // 11110000 = 240
  printf("\n shift_char >> %d = %d", i, shift_char >> i); // 0000 = 0

  i = 8;
 
  printf("\n shift_char << %d = %d", i, shift_char << i); // 111100000000 = 3840
  printf("\n shift_char >> %d = %d", i, shift_char >> i); // 0000 = 0

  // 6 -- pointer basics
  printf("\n\n PART 6 ----------\n");

  ip = a;
  //printf("\nstart %d %d %d %d %d %d %d \n",
	 //a[0], *(ip), *(ip+1), *ip++, *ip, *(ip+3), *(ip-1));
  printf("\nIssue fixed by printing on new line, \nnow going to modify output:");
  printf("\nstart %d", a[1]);
  printf(" %d", *(++ip));
  printf(" %d", *(ip+1));
  printf(" %d", *(ip++));
  printf(" %d", *ip);
  printf(" %d", *(ip+3));
  printf(" %d\n", *(ip-1));
  printf("Size of an integer pointer: %lu bytes\n", sizeof(ip));
  printf("Now printing the pointer values themselves:");
  printf("\nIssue fixed by printing on new line, \nnow going to modify output:");
  
  ip = a;  
  // Printing the pointer values themselves (adresses):
  printf(" %p", ip);           
  printf(" %p", (ip + 1));     
  printf(" %p", ip++);         
  printf(" %p", ip);           
  printf(" %p", (ip + 3));     
  printf(" %p\n", (ip - 1));   

  // 7 -- programming with pointers
  printf("\n\n PART 7 ----------\n");

  // Reversing array A
  int reverseIndex;
  int n = sizeof(var_int);

  // Method 1: 
  for (i = 0; i < n; i++) {
      reverseIndex = n - 1 - i;
      b[i] = a[reverseIndex]; // -1 is last elem, -i goes back to front
  }

  // Method 2:
  int *ipa = a;
  int *ipc = c;
  for (i=0; i < n; i++){
    reverseIndex = n - 1 - i;
    *(ipc + i) = *(ipa + reverseIndex); // Explaining the C: the * dereferences the array pointers and sets the item of c[i] to that of a[i]. As we saw before, adding n to an array pointer moves the pointer n slots along
  }

  printf("Input Array (a[]): ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Reversed Array using Method 1 (Indices) b[] = ");
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    printf("Reversed Array using Method 2 (pointers) c[] = ");
    for (i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }

  // 8 -- strings
  printf("\n\n PART 8 ----------\n");

  int length = strlen(AString);
  for (int i = 0; i < length + 1; i++) {
      printf("ASCII Value: %d\n", AString[i]);
  }

  char addOne[] = "HAL";
  for (int i = 0; i < length; i++) {
        addOne[i] = addOne[i] + 1;  // Add 1 to the ASCII value of each character
  }

  printf("Adding 1 to each char in HAL: %s\n", addOne);

  addOne[length] = addOne[length] + 60;
  printf("Adding 60 to final byte of modified HAL: %s\n", addOne);

  // 9 -- address calculation
  printf("\n\n PART 9 ----------\n");

  printf("\nCode Fragment 1: \n");
  for (k = 0; k < 10; k++) {
    printf("&a[%d] = %p, &b[%d] = %p\n", k, &a[k], k, &b[k]);
    b[k] = a[k];         // direct reference to array element    // direct reference to array element
  }

  ip = a;
  ip2 = b;
  printf("\nCode Fragment 2: \n");
  for (k = 0; k < 10; k++){
    printf("&ip   = %p, &ip2  = %p\n", ip, ip2);
    *ip2++ = *ip++;     // indirect reference to array element
  }
  // all done
  printf("\n\n ALL DONE\n");
}
