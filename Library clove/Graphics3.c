#include "clove.h"
int main() {
    // Armazenar os resultados em uma matriz
    String results[3];

    for (int i = 0; i < 3; ++i) {
        results[i] = inputDialog("Digite alguma coisa",500,500);
    }

    // Exemplo de uso dos resultados no terminal
    for (int i = 0; i < 3; ++i) {
        printf("Resultado %d: %s\n", i + 1, results[i]);
    }
    
    //Exemplo usando modo gráficoS
    
    for (int i = 0; i < 3; ++i) {
		showMessageDialog(results[i]);
    }
   
    return 0;
}
