#include <iostream>
#include "Conta.h"
#include <string>
using namespace std;

/*Aqui o operador escopo:: está indicando que a função Método sacar
pertence a classe Conta e que este código a seguir vai implementar a fnção Sacar*/
bool Conta::Sacar(double Valor)
{
	/*Se o valor do Saldo no Objeto for menor que o valor a ser sacado, ele não poderá sacar*/
	if (Saldo < Valor)
	{
		cout << "\nSaldo Insuficiente!\n";
		cout << "Seu Saldo Atual: R$" << ConsultarSaldo() << "\n";
		return false;
	}
	else
	{
		/*Senão ele poderá sacar, temos que diminuir o saldo*/
		Saldo = Saldo - Valor;
		cout << "Seu Saldo Atual: R$" << ConsultarSaldo() << "\n";
		return true;
	}
}

void Conta::Depositar(double Valor)
{
	Saldo = Saldo + Valor;
	cout << "\nDeposito de R$ " << Valor << "Efetuado com Sucesso!\n";
}

/*A função recebe como argumentos para seus parâmentros um objeto do tipo Conta
e um valor double*/
void Conta::Transferir(Conta &Destino, double Valor)
{
	if (Saldo < Valor)
	{
		cout << "\nSaldo Insuficiente\n";
	}
	else
	{
		//Aqui Destino está com o objeto passado para a função
		//Logo vai chamar o método Depositar desta função
		Destino.Depositar(Valor);
		//Depois de depositar você deve retirar este valor depositado do saldo
		Saldo = Saldo - Valor;
		cout << "\n*****Dados*****\n";
		cout << "Titular: " << Destino.GetTitular() << "\n";
		cout << "Banco: " << Destino.GetBanco() << "\n";
		cout << "Agencia: " << Destino.GetAgencia() << "\n";
		cout << "Conta: " << Destino.GetNumConta() << "\n";
		cout << "Transferencia realizada com Sucesso!\n";
		cout << "Seu Saldo Atual: R$" << ConsultarSaldo() << "\n";
	}
}

double Conta::ConsultarSaldo()
{
	return Saldo;
}

string Conta::GetBanco()
{
	return Banco;
}

int Conta::GetAgencia()
{
	return Agencia;
}

int Conta::GetNumConta()
{
	return NumConta;
}

string Conta::GetTitular()
{
	return Titular;
}

void Conta::SetBanco(string Banco)
{
	//Como o compilador vai saber se Banco é variável local ou o atributo da classe???
	/*Se this é um ponteiro para chegar no apontado pelo ponteiro temos
	*this , mas como this é um ponteiro para um objeto ele precisa usar a notação
	ponto. para acessar atributos e executar funções do objeto*/

	//(*this).Banco = Banco;//
	this->Banco = Banco;

}

void Conta::SetAgencia(int Agencia)
{
	this->Agencia = Agencia;
}

void Conta::SetNumConta(int NumConta)
{
	this->NumConta = NumConta;
}

void Conta::SetTitular(string Titular)
{
	this->Titular = Titular;
}
