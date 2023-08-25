/*
  3) Você está desenvolvendo um programa de atendimento ao cliente que lida com solicitações em uma ordem de chegada.
  Crie um programa em C++ que utilize a estrutura de dados de fila para gerenciar as solicitações.
  O programa deve adicionar algumas solicitações à fila e, em seguida,
  imprimir as solicitações na ordem em que foram recebidas.
*/

#include <iostream>

using namespace std;

int TAM = 3;

void filaSolicitacao(string fila[], int &finalzinho, string solicitacao);
void desenfileirar(string fila[], int &inicio, int finalzinho);

int main()
{
  string fila[TAM], solicitacao;
  int inicio = 0, finalzinho = -1;
  do
  {
    cout << "Digite uma solicitacao: ";
    cin >> solicitacao;

    filaSolicitacao(fila, finalzinho, solicitacao);
  } while (finalzinho < TAM - 1);

  desenfileirar(fila, inicio, finalzinho);
}

void filaSolicitacao(string fila[], int &finalzinho, string solicitacao)
{
  finalzinho++;
  fila[finalzinho] = solicitacao;
}

void desenfileirar(string fila[], int &inicio, int finalzinho)
{
  while (inicio <= finalzinho)
  {
    cout << fila[inicio] << endl;
    inicio++;
  }
}