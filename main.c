#include <stdio.h>
int iterador=1, condicion=0, finalizar=0;
void merge_sort(int i, int j, int a[], int aux[]) {
    if (j <= i) {
        return;
    }
    int mid = (i + j) / 2;


    merge_sort(i, mid, a, aux);
    merge_sort(mid + 1, j, a, aux);

    int pointer_left = i;
    int pointer_right = mid + 1;
    int k;


    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {
            aux[k] = a[pointer_left];
            pointer_left++;
        } else {
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) {
        a[k] = aux[k];
    }
}
int busqueda(int a[], int i){
        if(a[i]+iterador != a[i+1]){
        for(int j=0; j<i; j++){
         if((a[j]+a[i]) == (a[i]+iterador)){
            condicion = 1;
         }
         if(j+1 == i && condicion == 0){
            printf("%d", a[i]+iterador);
            finalizar = 1;
            return 0;
         }else if(a[i]+iterador+1 != a[i+1]){
          iterador++;
          condicion = 0;
          busqueda(a, i);
         }
        }
    }
}


int main() {
  int a[10000], aux[1000], n, i;


  scanf("%d", &n);


  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  merge_sort(0, n - 1, a, aux);


  for (i = 1; i < n-1; i++){
    busqueda(a, i);
    if(finalizar == 1){
        break;
    }
    iterador = 1;
  }

  return 0;
}
