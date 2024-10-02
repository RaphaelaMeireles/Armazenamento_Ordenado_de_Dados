// Bibliotecas necessárias
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Fila.h"
#include "Pilha.h"

//Nome: Raphaela Meireles de Souza

// Objetivo do programa: Armazenar dados dos alunos(Matrícula e Nota) de forma ordenada

// Como deve ser feita a entrada de dados: Selecione a opçao de Inserir Dados (1),
// assim o programa ira pedir a matricula e a nota, basta inserir o desejado.
// Ex: Matricula:1 Nota:2 >> Matricula:10 Nota:4 >> Matricula:2 Nota:1

//Resultado da execução do programa: Irá sair ordenado com a maior nota no topo até chegar na menor nota.
// e em caso de matriculas iguais a menor fica mais perto do topo.
//Ex: Matricula:10 Nota:4 >> Matricula:1 Nota:2 >>  Matricula:2 Nota:1

using namespace std;

int main() {
    Aluno dados;
    int opcao; // Variável utilizada no menu para testar a Fila
    int tamanho;
    int existe;

    Pilha_Construtor(); // Para iniciar a pilha
    Fila_Construtor();  // Para iniciar a fila

    do {
        system("cls");

        cout << "===ARMAZENAR DADOS DOS ALUNOS===" << endl;
        cout << "Escolha uma das opcoes abaixo.";
        cout << "\n1 - Inserir Dados";
        cout << "\n2 - Ordenar e Apresentar";
        cout << "\n3 - Sair\n";
        cout << "\nOpcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: //Aqui iremos armazenar todos os dados dos alunos

                cout << "\nDigite o n da Matricula: "; //pega dados da matricula
                cin >> dados.matricula;

                cout << "\nDigite a nota: "; //pega dados da nota
                cin >> dados.nota;

                existe = 0;
                tamanho = Fila_Tamanho(); //pega tamanho da fila

                for (int i = 0; i < tamanho; ++i) {
                    Aluno novo; //cria uma variavel que armazene os dados da matricula e nota que foram retirados. E para isso ser possível tem que usar "Aluno" ao invés de int ou float...
                    Fila_Desenfileirar(novo); // Retira da fila o novo elemento

                    // Verifica se a matrícula nova é igual a alguma na fila
                    if (dados.matricula == novo.matricula) {
                        existe = 1; //se existe a variavel ficará igual a 1
                    }

                    // Enfileira o elemento novo para voltar a fila ao normal
                    Fila_Enfileirar(novo);
                }

                // Caso a matrícula seja única ela será enfileirada
                if (existe == 0) {
                    Fila_Enfileirar(dados);
                } else { //caso tenha alguma igual a ela, mostrará uma mensagem de erro
                    cout << "Erro: Matricula ja existente!\n";
                }

                system("pause");
                break;

            case 2:

                // Enquanto o tamanho da fila for maior que 0 faça:
                while (Fila_Tamanho() > 0) {
                    Fila_Desenfileirar(dados); // Desenfileira os dados que estao na frente da fila

                    //cria uma variavel topo que armazene dados da matricula e nota. E para isso ser possível tem que usar "Aluno" ao invés de int ou float...
                    Aluno topo;

                    while (!Pilha_Vazia()) { //Enquanto a Pilha não estiver vazia faça:
                        Pilha_Topo(topo); // Pega o elemento do topo da Pilha

                        // Condição que se verdadeira, o topo é desempilhado e enfileirado
                        // E em caso de empate entre as notas a menor matricula fica mais perto do topo
                        if (topo.nota >= dados.nota && (topo.nota != dados.nota || topo.matricula < dados.matricula)) {

                            Pilha_Desempilhar(topo); //Desempilha o topo
                            Fila_Enfileirar(topo); // o topo é enfileirado

                        } else {
                            break; // Sai do loop se a condição for falsa
                        }
                    }

                    // Empilha o elemento atual após o loop
                    Pilha_Empilhar(dados);
                }


                cout << "\nElementos ordenados (Maior para a Menor nota):\n";

                //enquanto a pilha nao estiver vazia irá desempilhar e mostrar esse valor na tela.
                while (!Pilha_Vazia()) {
                    Pilha_Desempilhar(dados);
                    cout << "Matricula: " << dados.matricula << ", Nota: " << dados.nota << "\n";
                }

                system("pause");
                break;

            case 3:
                Fila_Destrutor(); //Destroi o restante da Fila
                Pilha_Destrutor(); //Destroi o restante da Pilha
                cout << "\n\n";
                system("pause");
                break;

            default:
                cout << "\n\nOpcao invalida\n\n"; //Caso o usuario digite uma opcao diferente das apresentadas
                system("pause");
        }
    } while (opcao != 3);

    system("pause");
    return 0;
}
