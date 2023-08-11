#include <iostream>

using namespace std;

void converterDecimalBinario(int valor, int binario[], int &pos);

int main()
{
  int binario[5], valor;
  int pos = -1;

  cout << "Digite um numero que queira converter para binario: ";
  cin >> valor;

  converterDecimalBinario(valor, binario, pos);

  cout << "Numero em binario e: " << endl;

  for (int i = 0; i < pos; i++)
  {
    cout << binario[i];
  }

  return 0;
}

void converterDecimalBinario(int valor, int binario[], int &pos)
{
  while (valor > 2)
  {
    if (valor == 1)
    {
      pos++;
      binario[pos] = valor;
    }
    else
    {
      pos++;
      int quociente = valor / 2;
      int resto = valor % 2;
      binario[pos] = resto;
      valor = quociente;
    }
  }
}