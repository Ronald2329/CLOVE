#include "clove.h"

int main() {
    // Armazenar os resultados em um vetor
    int results[8] = {42, 99, 23,10,11,123,4551,1243};

    // Exibir os resultados no showMessageDialog
    showResultsDialog(results, 8, sizeof(int), "Integer");

    return 0;
}