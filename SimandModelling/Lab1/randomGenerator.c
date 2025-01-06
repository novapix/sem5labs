#include <stdio.h>
#include <stdlib.h>

int main(){
  for ( int i=0;i<10;i++) {
    int randomNumber= rand();
    printf("Random Number: %d\n", randomNumber);
  }
  return 0;
}
