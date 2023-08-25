/*
  2) Desenvolva uma função que avalie operações matemáticas de adição e subtração. Para isso, você deverá usar pilha
  e no parâmetro da função deve receber uma string com a operação matemática a ser resolvida.
  O retorno da função deverá retornar o resultado da operação. Ex: (57+5-)
*/

#include <iostream>
#include <string>

using namespace std;

int avaliarExpressao(char pilha[], string expressao, int &topo);

int main()
{
  char pilha[10];
  int topo = -1;
  string expressao;

  cout << "Digite uma expressao matematica de soma ou subtracao: Ex(15+5-)" << endl;
  cin >> expressao;

  int resultado = avaliarExpressao(pilha, expressao, topo);

  cout << "O resultado e: " << resultado << endl;

  return 0;
}

int avaliarExpressao(char pilha[], string expressao, int &topo)
{
  int tam = expressao.length();

  for (int i = 0; i < tam; i++)
  {
    if (expressao[i] >= '0' && expressao[i] <= '9')
    {
      topo++;
      pilha[topo] = expressao[i] - '0';
    }
    else if (expressao[i] == '+' || expressao[i] == '-')
    {
      int num1 = pilha[topo];
      topo--;
      int num2 = pilha[topo];
      topo--;

      if (expressao[i] == '+')
      {
        topo++;
        pilha[topo] = num1 + num2;
      }
      else
      {
        topo++;
        pilha[topo] = num1 - num2;
      }
    }
  }

  return pilha[topo];
}