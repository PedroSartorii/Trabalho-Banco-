#pragma once
#include <iostream>
using namespace std;

//este é o arquivo .h onde existe apenas as declarações dos atributos
//e métodos da classe. Aqui não existem as definições, implementações das funções,
//pois isso será feito no arquivo .cpp .

class Conta
{
//indica que o acesso a estes membros abaixo de private:
//só será permitido de dentro do código da classe

private:
	string Banco;
	int Agencia;
	int NumConta;
	string Titular;
	double Saldo{ 0.0 };

//indica que os membros abaixo pode ser acessados pelo objeto da classe Conta
//fora do código da classe Conta.

public:
	bool Sacar(double Valor);
	void Depositar(double Valor);
	//Neste caso o parâmetro Destino recebe apenas uma cópia
	//do valor do objeto. Ele não tem como alterer o objeto
	//pois só recebeu uma cópia dele
	//logo podemos usar o conceito de referência para passar a 
	//referência do objeto e com isso Destino vai poder alterar
	//este objeto pois será realizada uma passagem de argumentos
	// por Referência e não mais por valor
	void Transferir(Conta &Destino, double Valor);
	double ConsultarSaldo();
	string GetBanco();
	int GetAgencia();
	int GetNumConta();
	string GetTitular();
	void SetBanco(string Banco);
	void SetAgencia(int Agencia);
	void SetTitular(string Titular);
	void SetNumConta(int NumConta);
};
