#include <stdio.h>

int sucessoraLexicografica(int ss[], int k, int n) {
    int i;
    for (i = k - 1; i >= 0; i--) {
        if (ss[i] < n - (k - 1 - i)) {
            break;
        }
    }
    if (i < 0){
        return 0;
    }
    ss[i]++;
    for (int j = i + 1; j < k; j++) {
        ss[j] = ss[j - 1] + 1;
    }
    return 1; // sucesso
}

int main() {
    int n, k;
    printf("Digite n e k: ");
    scanf("%d %d", &n, &k);

    int ss[100];

    printf("Digite a subsequencia ss[1..%d]: ", k);
    for (int i = 0; i < k; i++)
        scanf("%d", &ss[i]);

    if (sucessoraLexicografica(ss, k, n)) {
        printf("Sucessora lexicografica: ");
        for (int i = 0; i < k; i++)
            printf("%d ", ss[i]);
        printf("\n");
    } else {
        printf("Nao existe sucessora lexicografica.\n");
    }

    return 0;
}
