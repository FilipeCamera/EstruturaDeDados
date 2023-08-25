/*
  1) Você foi designado para criar 2 funções em C++, uma que gere uma lista ordenada com números inseridos de forma randomica e uma segunda que recebe essa lista gerada na primeira função e um número alvo.
  Na segunda função o objetivo é encontrar se o número alvo está presente na lista.
  Implemente a função void gerarListaOrdenada(int lista[], int tamanho, int &quant) para resolver esse problema.
  Implemente a função bool buscaSequencialOrdenada(int lista[], int tamanho, int alvo) para resolver esse problema.
  A função deve retornar true se o número alvo estiver presente na lista e false caso contrário.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

void gerarListaOrdenada(int lista[], int tamanho, int &quant);
bool buscaSequencialOrdenada(int lista[], int quant, int alvo);

int main()
{
  int tam = 10, quant = 0;
  int lista[tam];
  int escolha;

  while (quant < tam)
  {
    gerarListaOrdenada(lista, tam, quant);
  }

  cout << "Tente adivinhar um número da lista" << endl;
  cout << "Diga um numero: ";

  cin >> escolha;

  if (buscaSequencialOrdenada(lista, quant, escolha) == true)
  {
    cout << "Voce acertou!";
  }
  else
  {
    cout << "Voce nao conseguiu acertar!";
  }
}

void gerarListaOrdenada(int lista[], int tamanho, int &quant)
{
  int i = 0, pos;
  int number_random = rand() % 100;

  while (lista[i] < number_random && i < quant)
  {
    i++;
  }

  pos = i;

  for (i = quant; i > pos; i--)
  {
    lista[i] = lista[i - 1];
  }

  lista[pos] = number_random;
  quant++;
}

bool buscaSequencialOrdenada(int lista[], int quant, int alvo)
{
  bool resultado = false;
  for (int i = 0; i <= quant; i++)
  {
    if (lista[i] == alvo)
    {
      resultado = true;
    }
  }
  return resultado;
}
