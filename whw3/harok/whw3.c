#include <stdio.h>
#include <string.h>
#define HASH_PRIME 11117

int hash_record[HASH_PRIME];

void init_record()
{
  int i;
  for (i=0; i<HASH_PRIME; i++)
    hash_record[i] = 0;
}

int hash(char key[5])
{
  int i;
  long long x;
  x=0;
  for (i=0; i<4; i++) 
  {
    x=x+key[i];
    x=x<<8;
  }
  x=x+key[4];
  return x%HASH_PRIME;
}

int sum_col(int n)
{
  int i;
  int col=0;
  for (i=0; i<n; i++)
  {
    if (hash_record[i] != 0)
      col += hash_record[i]-1;
  }
  return col;
}

int key_comparisons()
{
  int i;
  int sum = 0;
  for (i=0; i<HASH_PRIME; i++)
    sum += hash_record[i]*(hash_record[i]+1)/2;
  return sum;
}
    

int main()
{
  int i;
  int cnt=0;
  char word[100];
  init_record();
  FILE *f;
  f=fopen("words.dat","r");
  for (i=0; i<5757; i++)
  {
    fgets(word,sizeof(word), f);
    hash_record[hash(word)] += 1;
  }
  fclose(f);

  //printf("Hash Prime:%d / Number of collisions:%d\n",HASH_PRIME, sum_col(HASH_PRIME));
  printf("Hash Prime:%d / Total number of key comparions:%d\n",HASH_PRIME, key_comparisons());
}

  
  
