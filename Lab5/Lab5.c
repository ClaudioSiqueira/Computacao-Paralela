// Claudio Siqueira - 41916565

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define TMH 5

int v[TMH];

void* Func (void *arg) {
  int *val = (int *)(arg);
  if(*val == 1){
    printf("A primeira Thread foi iniciada\n");
    for (int i = 0; i < TMH / 2; i++){
      v[i] = v[i] * 4;
    }
  }
  else {
      printf("A segunda Thread foi iniciada\n");
      for (int i = TMH / 2; i < TMH; i++){
      v[i] = v[i] * 4;
    }
  }
  pthread_exit(Func);
} 

int main() {
  pthread_t t1, t2;
  int m = 1;
  int n = 2;
  printf("Digite 5 numeros: \n");
  for(int i = 0; i < TMH; i++) {
    
    scanf("%d", &v[i]);
  }
  pthread_create(&t1, NULL, Func, (void *)(&m));
  pthread_create(&t2, NULL, Func, (void *)(&n));
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  for(int i = 0; i < TMH; i++) {
    printf("%d ", v[i]);
  }

  exit(0);
  
}
