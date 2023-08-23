#include <iostream>

using namespace std;

int enfileirar(int valores[], int &fim, int tam, int valor);
int desenfileirar(int valores[], int &inicio, int fim, int &valor);
void menu(int valores[], int &inicio, int &fim, int &valor);

int tam = 10;

int main()
{
  int valores[tam], valor;
  int inicio = 0, fim = -1;

  menu(valores, inicio, fim, valor);

  return 0;
}

void menu(int valores[], int &inicio, int &fim, int &valor)
{
  int escolha = -1;
  cout << "Escolha as opcoes:" << endl;
  cout << "1- Digite (1) para adicionar um valor inteiro na fila" << endl;
  cout << "2- Digite (2) para desenfileirar a fila e mostrar os multiplos de 2" << endl;
  cout << "3- Digite (0) para encerrar o programa" << endl;

  while (escolha != 0)
  {
    cout << "Digite a opcao: ";
    cin >> escolha;

    if (escolha == 1)
    {
      cout << "digite um valor inteiro positivo: ";
      cin >> valor;
      if (valor > 0)
      {
        enfileirar(valores, fim, tam, valor);
      }
    }
    else if (escolha == 2)
    {
      cout << "numeros multiplos de 2: ";
      while (inicio <= fim)
      {
        if (desenfileirar(valores, inicio, fim, valor) % 2 == 0)
        {
          cout << valor << endl;
        }
      }
    }
  }
}

int enfileirar(int valores[], int &fim, int tam, int valor)
{
  if (fim >= tam - 1)
    return 1;

  fim = fim + 1;

  valores[fim] = valor;

  return 0;
}

int desenfileirar(int valores[], int &inicio, int fim, int &valor)
{
  if (inicio > fim)
    return 1;

  valor = valores[inicio];
  inicio++;

  return valor;
}