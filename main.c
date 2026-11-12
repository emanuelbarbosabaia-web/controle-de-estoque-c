#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
    #define ESTOQUE "inventory.txt" 
        int  menu(); 
        void listarItens(); 
        void adicionarItem(); 
        void removerItem(); 
            typedef struct {
                char nome[100];
                int quantidade; 
            } item; 

int main(){
    char sair = ' ';
    char lixo;
do{
   int op = menu(); 
    switch (op) {
       case 1: 
         adicionarItem();
            break; 
               case 2: 
                 removerItem(); 
                   break; 
                       case 3: 
                         listarItens(); 
                           break; 
                               case 4: 
                                   sair = 'n'; 
                               break; 
                                   default: 
                                   break; 
    } 
                                            if (op != 4) { 
                                                do { 
                                                   printf("Deseja realizar outra operação? (s/n):\n");
                                                       if (scanf(" %c%c", &sair, &lixo) != 2) { 
                                                           printf("Entrada inválida!\n"); 
                                                            while (getchar() != '\n'); 
                                                            sair = ' '; 
                                                        }
                                                            else if (lixo != '\n'){
                                                                printf("Opção inválida! Tente novamente.\n");
                                                                while (getchar() != '\n'); 
                                                                sair = ' ';
                                                            }
                                                                if (sair != 's' && sair != 'S' && sair != 'n' && sair != 'N') { 
                                                                    printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n"); 
                                                                }
                                                } while (sair != 's' && sair != 'S' && sair != 'n' && sair != 'N'); 
                                           }
}while(sair == 's' || sair == 'S');
    printf("Obrigado por usar o Controle de Estoques! Até a próxima.\n");
return 0; 
}
int menu(){ 
    int op; 
    char lixo; // Armazena o caractere lido depois do número
    do {
        printf("================================\n");
        printf("\tControle de Estoque\n");
        printf("================================\n");
        printf("Selecione uma opção:\n");
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Estoque\n");
        printf("4. Sair\n");
        printf("Opção: ");
            if (scanf("%d%c", &op, &lixo) != 2) {
                printf("Entrada inválida!\n");
                    while (getchar() != '\n'); 
                        op = 0;
            }
                    else if (lixo != '\n'){
                        printf("Opção inválida! Tente novamente.\n");
                         while (getchar() != '\n'); 
                            op = 0;
                    }
                            else if (op < 1 || op > 4) { 
                                 printf("Opção inválida! Tente novamente.\n");
                                    }

        } while (op < 1 || op > 4); 

    return op;
}

void listarItens(){ 
    FILE *estoque = fopen(ESTOQUE, "r"); // Abre estoque no modo de leitura.
                item itemAtual; 
                    printf("=============================\n");
                    printf("\tEstoque Atual\n");
                    printf("=============================\n"); 
                        if (estoque == NULL) {
                            printf("O estoque está vazio.\n"); 
                            return;
                        }       
                                int c = 0; //contador 
                                while (fgets(itemAtual.nome, sizeof(itemAtual.nome), estoque) != NULL && fscanf(estoque, "%d", &itemAtual.quantidade) != -1) { 
                                        printf("Nome: %s\n", itemAtual.nome);
                                        printf("Quantidade: %d\n\n", itemAtual.quantidade); 
                                                int ch; 
                                                while ((ch = fgetc(estoque)) != '\n' && ch != EOF); 
                                    c++;
                                }
                                                if (c == 0) printf("O estoque está vazio.\n"); 
    fclose(estoque);
}


void adicionarItem(){ 
    item atualItem,  adicionarItem; 
    int c = 0, itemAdicionado = 0; 
            printf("Digite o nome do item: ");
            scanf(" %99[^\n]", adicionarItem.nome);
                while(getchar() != '\n');
                int i; for ( i = 0; adicionarItem.nome[i] == ' '; i++);
                for (int j = 0; (adicionarItem.nome[j] = adicionarItem.nome[i]) != '\0'; i++, j++);
                for (int r = strlen(adicionarItem.nome) - 1; r >= 0 && adicionarItem.nome[r] == ' '; adicionarItem.nome[r--] = '\0');
            printf("Digite a quantidade a ser adicionada: "); 
            if (scanf("%d", &adicionarItem.quantidade) != 1) {
                printf("Entrada inválida!\n");
                while (getchar() != '\n');
                return;
            } 
                if (adicionarItem.quantidade < 1) { 
                    printf("Quantidade invalida!\n"); 
                    return; 
                }
    FILE * estoque_real = fopen(ESTOQUE, "r");
                if (estoque_real == NULL){ 
                    printf("Erro ao abrir o arquivo do estoque!\n"); 
                    return; 
                }
    FILE * estoque_temp = fopen("temp.txt", "w"); 
                if (estoque_temp == NULL){ 
                    printf("Erro ao criar o arquivo temporário!\n"); 
                    fclose(estoque_real);
                    return;
                }
                            while (fscanf(estoque_real, " %99[^\n]\n%d", atualItem.nome, &atualItem.quantidade) == 2){
                                if (strcmp(atualItem.nome, adicionarItem.nome) == 0) {
                                    c = 1; 
                                    atualItem.quantidade += adicionarItem.quantidade; 
                                }
                                if (fprintf(estoque_temp, "%s\n%d\n", atualItem.nome, atualItem.quantidade) < 0) {
                                    printf("Erro ao escrever no arquivo temporário!\n");
                                    fclose(estoque_real);
                                    fclose(estoque_temp);
                                    remove("temp.txt");
                                    return;
                                }
                            }
                                if (fclose(estoque_real) == EOF) {
                                    printf("Erro ao fechar o arquivo do estoque!\n");
                                    fclose(estoque_temp);
                                    remove("temp.txt");
                                    return;
                                }                   
                                    if (c == 0) { 
                                        if (fprintf(estoque_temp, "%s\n%d\n", adicionarItem.nome, adicionarItem.quantidade) < 0) {
                                            printf("Erro ao escrever no arquivo temporário!\n");
                                            fclose(estoque_temp);
                                            remove("temp.txt");
                                            return;
                                        }
                                        itemAdicionado = 1; 
                                    }
                                if (fclose(estoque_temp) == EOF) {
                                    printf("Erro ao fechar o arquivo temporário!\n");
                                    remove("temp.txt");
                                    return;
                                }
                                            if (rename(ESTOQUE, "inventory.bak") != 0) {
                                                printf("Erro ao preservar o estoque original!\n");
                                                remove("temp.txt");
                                                return;
                                            }
                                            if (rename("temp.txt", ESTOQUE) != 0){
                                                printf("Erro ao atualizar o estoque!\n");
                                                if (rename("inventory.bak", ESTOQUE) != 0) {
                                                    printf("Erro ao restaurar o estoque original!\n");
                                                }
                                                return;
                                            }
                                            remove("inventory.bak");
                                                if (itemAdicionado)
                                                    printf("Item adicionado com sucesso!\n"); 
                                                else
                                                    printf("Quantidade do item atualizada com sucesso!\n");                                     
}
void removerItem(){ 
    item atualItem, removerItem; 
        int c = 0;
            printf("Digite o nome do item: ");
            scanf(" %99[^\n]", removerItem.nome);
                while(getchar() != '\n');
                int x; for ( x = 0; removerItem.nome[x] == ' '; x++);
                for (int j = 0; (removerItem.nome[j] = removerItem.nome[x]) != '\0'; x++, j++);
                for (int i = strlen(removerItem.nome) - 1 ; i >= 0 && removerItem.nome[i] == ' '; removerItem.nome[--i] = '\0');
            printf("Digite a quantidade a ser removida: "); 
            if (scanf("%d", &removerItem.quantidade) != 1) {
                printf("Entrada inválida!\n");
                while (getchar() != '\n');
                return;
            }
            if (removerItem.quantidade < 1) {
                printf("Quantidade invalida!\n");
                return; 
            }
    FILE * estoque_real = fopen(ESTOQUE, "r");
                if (estoque_real == NULL){ 
                    printf("Erro ao abrir o arquivo do estoque!\n"); 
                    return; 
                }
    FILE * estoque_temp = fopen("temp.txt", "w"); 
                if (estoque_temp == NULL){ 
                    printf("Erro ao criar o arquivo temporário!\n"); 
                    fclose(estoque_real);
                    return;
                }
                            while (fscanf(estoque_real, " %99[^\n]\n%d", atualItem.nome, &atualItem.quantidade) == 2){
                                if (strcmp(atualItem.nome, removerItem.nome) == 0) {
                                    if (atualItem.quantidade < removerItem.quantidade) { 
                                        printf("Estoque insuficiente. Quantidade disponível: %d\n", atualItem.quantidade); 
                                        fclose(estoque_real); 
                                        if (fclose(estoque_temp) == EOF) {
                                            printf("Erro ao fechar o arquivo temporário!\n");
                                            remove("temp.txt");
                                            return;
                                        } 
                                        remove("temp.txt"); 
                                        return; 
                                    }
                                    c = 1;
                                    atualItem.quantidade -= removerItem.quantidade;
                                        if (atualItem.quantidade == 0) c =2; 
                                }
                                if (atualItem.quantidade > 0) {
                                    if (fprintf(estoque_temp, "%s\n%d\n", atualItem.nome, atualItem.quantidade) < 0) {
                                        printf("Erro ao escrever no arquivo temporário!\n");
                                        fclose(estoque_real);
                                        fclose(estoque_temp);
                                        remove("temp.txt");
                                        return;
                                    }
                                }
                            }
                                if (fclose(estoque_real) == EOF) {
                                    printf("Erro ao fechar o arquivo do estoque!\n");
                                    fclose(estoque_temp);
                                    remove("temp.txt");
                                    return;
                                }                   
                                    if (c == 0) { 
                                        printf("Item não encontrado.\n"); 
                                        if (fclose(estoque_temp) == EOF) {
                                            printf("Erro ao fechar o arquivo temporário!\n");
                                            remove("temp.txt");
                                            return;
                                        }
                                        remove("temp.txt"); 
                                        return; 
                                    }
                                if (fclose(estoque_temp) == EOF) {
                                    printf("Erro ao fechar o arquivo temporário!\n");
                                    remove("temp.txt");
                                    return;
                                }
                                            remove("inventory.bak");
                                            if (rename(ESTOQUE, "inventory.bak") != 0) {
                                                printf("Erro ao preservar o estoque original!\n");
                                                remove("temp.txt");
                                                return;
                                            }
                                            if (rename("temp.txt", ESTOQUE) != 0){
                                                printf("Erro ao atualizar o estoque!\n");
                                                rename("inventory.bak", ESTOQUE);
                                                return;
                                            }
                                            remove("inventory.bak");
                                                if (c == 1) {
                                                    printf("Quantidade atualizada com sucesso!\n");
                                                } else
                                                if (c == 2) {
                                                    printf("Item removido com sucesso!\n");
                                                }
}
