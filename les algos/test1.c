#include <stdio.h>

int main() {
    int n;
    printf("entrez le taille du tableau:\n");
    scanf("%d",&n);
    int array[n];
    printf("entrez les nombres:\n");
    for (int i=0;i<n;i++) {
        scanf("%d",&array[i]);
    }

for (int i=0;i<n;i++) {
    for (int j=0;j<n-1;j++) {
        if (array[j]>array[j+1]) {
            int temp = array[j+1];
            array[j+1]=array[j];
            array[j]=temp;
        }
    }
}

    for (int i=0;i<n;i++) {
        printf("%d,",array[i]);
    }

}