#include <iostream>

using namespace std;

void bubbleSort(int values[], int tam);
void ordenacaoPorSelecao(int values[], int tam);
void insercao(int values[], int tam);
void inserir(int values[], int &pos, int tam, int valor);
void listar(int values[], int tam);

int main()
{
  int values[10], valor;
  int pos = 0;
  int comando;

  do
  {
    cout << "Digite um valor: ";
    cin >> valor;
    inserir(values, pos, 10, valor);
  } while (valor >= 0);

  cout << "Escolha um comando: " << endl;
  cout << "1- BubbleSort" << endl;
  cout << "2- Ordenacao por selecao" << endl;
  cout << "3- Insercao" << endl;

  do
  {
    cout << "Diga o comando que quer executar: ";
    cin >> comando;

    if (comando == 1)
    {
      bubbleSort(values, pos);
    }
    else if (comando == 2)
    {
      ordenacaoPorSelecao(values, pos);
    }
    else if (comando == 3)
    {
      insercao(values, pos);
    }

    listar(values, pos);
  } while (comando != 0);

  return 0;
}

void bubbleSort(int values[], int tam)
{
  for (int i = 0; i < tam - 1; i++)
  {
    for (int j = 0; j < tam - i - 1; j++)
    {
      if (values[j] > values[j + 1])
      {
        float aux = values[j];
        values[j] = values[j + 1];
        values[j + 1] = aux;
      }
    }
  }
}

void ordenacaoPorSelecao(int values[], int tam)
{
  for (int i = 0; i < tam - 1; i++)
  {

    int minPosicao = i;

    for (int j = i + 1; j < tam; j++)
    {
      if (values[j] < values[minPosicao])
      {
        minPosicao = j;
      }
    }
    int aux = values[i];
    values[i] = values[minPosicao];
    values[minPosicao] = aux;
  }
}

void insercao(int values[], int tam)
{
  for (int i = 1; i < tam; i++)
  {
    int valor = values[i];
    int j = i - 1;

    while (j >= 0 && values[j] > valor)
    {
      values[j + 1] = values[j];
      j = j - 1;
    }

    values[j + 1] = valor;
  }
}

void inserir(int values[], int &pos, int tam, int valor)
{
  if (valor < 0)
  {
    return;
  }
  if (pos == tam)
    return;
  values[pos] = valor;
  pos++;
  return;
}

void listar(int values[], int tam)
{
  int i;
  for (i = 0; i < tam; i++)
    cout << values[i] << endl;
}