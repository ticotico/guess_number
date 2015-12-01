#include <stdio.h>
main()
{
  int i,j,k,l;
  int test[10][10][10][10] = {0};
  int sp_ans[4], sp_test[4], index[4], input;
  int a, b, A = 0, B;
  int count = 0;
  int m, n;
  int number;

  for(i = 0; i < 10; i++)
  for(j = 0; j < 10; j++)
  for(k = 0; k < 10; k++)
  for(l = 0; l < 10; l++)
    if(i == 0 || i == j || i == k || i == l
       || j== k || j == l || k == l)
         test[i][j][k][l] = 1;
 
  scanf("%d", &input);
  for(i = 3; i >= 0; i--) {
    sp_ans[i] = input % 10;
    input /= 10;
  }
  
  while(A != 4) {
    a = 0;
    b = 0;
    A = 0;
    B = 0;
    count++;
    i = 0;
    j = 0;
    k = 0;
    l = 0;

    for(number = 1234; number <= 9876 && test[i][j][k][l] == 1; number++) {
      i = number / 1000;
      j = (number % 1000) / 100;
      k = (number % 100) / 10;
      l = number % 10;
    }

    index[0] = i;
    index[1] = j;
    index[2] = k;
    index[3] = l;

    for(m = 0; m < 4; m++)
    for(n = 0; n < 4; n++) {
      if(index[n] == sp_ans[m]) {
        if(n == m) A++;
        else B++;
      }
    }

    for(number = 1234; number <= 9876; number++) {
      i = number / 1000;
      j = (number % 1000) / 100;
      k = (number % 100) / 10;
      l = number % 10;
      sp_test[0] = i;
      sp_test[1] = j;
      sp_test[2] = k;
      sp_test[3] = l;

      if(test[i][j][k][l] == 0) {
        for(m = 0; m < 4; m++) {
        for(n = 0; n < 4; n++) {
          if(sp_test[n] == index[m]) {
            if(n == m) a++;
            else b++;
          }
        }
        }
        if (A != a || B != b) {test[i][j][k][l] = 1;}
        a = 0;
        b = 0;
      }
    }


  }

  printf("count = %d\n", count);
  printf("answer = %d%d%d%d\n", index[0], index[1], index[2], index[3]);
}

