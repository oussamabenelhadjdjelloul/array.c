#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
void tri_a_bulle_c(int *t,int n){
    int j =0;int tmp =0;int test =1;
    while(test){
        test = FALSE;
        for(j =0; j < n-1; j++){
            if(t[j] > t[j+1]){
                    tmp = t[j+1];
                    t[j+1] = t[j];t[j] = tmp;
                    test = TRUE;
            }
        }
    }
}
/// tri Ã  bulle
void tri_a_bulle_d(int *t,int n){
    int j =0;int tmp =0;int test =1;
    while(test){
        test = FALSE;
        for(j =n-1; j >0; j--){
            if(t[j] > t[j-1]){
                    tmp = t[j-1];
                    t[j-1] = t[j];
                    t[j] = tmp;
                    test = TRUE;
            }
        }
    }
}

/// tri par sÃ©lection croissance
void tri_selection_c(int *t, int n){
        int i, min, j , tmp;
        for(i =0; i < n -1; i++){
                min = i;
                for(j = i+1; j < n ; j++)
                    if(t[j] < t[min])
                        min = j;
                if(min != i){
                        tmp = t[i];
                        t[i] = t[min];
                        t[min] = tmp;
                }
        }
}
/// tri par sÃ©lection descroissance
void tri_selection_d(int *t, int n){
        int i, min, j , tmp;
        for(i =n-1; i <0; i--){
                min = i;
                for(j = i-1; j >0 ; j--)
                    if(t[j] > t[min])
                        min = j;
                if(min != i){
                        tmp = t[i];
                        t[i] = t[min];
                        t[min] = tmp;
                }
        }
}


/// tri par insertion croissance
void tri_insertion_c(int *t,int n){
        int i,p,j;
        int x;
        for(i =1; i < n; i++){
            x = t[i];p = i-1;
            while(t[p] > x && p-- >0){}
            p++;
            for(j = i-1; j >= p; j--){
                t[j+1] = t[j];
            }
            t[p] = x;
        }
}
/// tri par insertion
void tri_insertion_d(int *t,int n){
int i,j,x;
    for(i=1;i<=n-1;i++)
  {
      x=t[i];
      j=i;
      while((j>0) &&(t[j-1]<x))
      {
        t[j]=t[j-1];
        j=j-1;
      }
      t[j]=x;
  }

}


/* Fin de la dÃ©finition des fonctions de tri */

int main() {
  int i,j,n,m,num,k=0,vecteur[1000];


  //lire la taille
  printf("Hello, give me the number of rows :\n");
  scanf("%d",&n);
  printf("Hello, give me the number of cols :\n");
  scanf("%d",&m);

  int **mat=(int**) malloc(n*sizeof(int*));//allocation de ligne de pointer

  //allocation de cols de pointer
  for (i = 0; i < m-1; i++) {
    mat[i]=(int*)malloc(m*sizeof(int));
  }
  //remplir le matrice
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("la case nombre [%d][%d] :\n",i+1,j+1);
      scanf("%d",&mat[i][j]);
      vecteur[k]=mat[i][j];
      k++;
    }
  }
  printf("\n1. Le tri %c bulle\n",133);
  printf("2. Le tri par s%cl%cction\n",130,130);
  printf("3. Le tri par insertion\n");
  printf("4. Le tri %c bulle D\n",133);
  printf("5. Le tri par s%cl%cction D\n",130,130);
  printf("6. Le tri par insertion D\n");
  do{
      printf("\nVeuillez saisir le num%cro de de l'algorithme de tri %c appliquer: ",130,133);
  scanf("%d",&num);
  if((num>6)||(num<1))
      printf("\n(!) Ce num%cro ne figure pas dans la liste !\n",130);
  }while((num>6)||(num<1));
/// appliquer l'algorithme choisi
  if(num==1) tri_a_bulle_c(vecteur,k);
  if(num==2) tri_selection_c(vecteur,k);
  if(num==3) tri_insertion_c(vecteur,k);
  if(num==4) tri_a_bulle_d(vecteur,k);
  if(num==5) tri_selection_d(vecteur,k);
  if(num==6) tri_insertion_d(vecteur,k);
  for (i = 0; i <k; i++) {
    printf(" hak : %d \n",vecteur[i]);
  }
  printf("here's your matrice after sorting\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("la case nombre [%d][%d] est : %d \n",i+1,j+1,mat[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
  	printf("bye");
    free(mat[i]);
  }
  free(mat);
  printf("byo");
  system("pause");
  return 0;
}
