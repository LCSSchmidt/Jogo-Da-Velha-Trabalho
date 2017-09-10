// Jogo da Velha.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Jogo_velha.h"


using namespace std;

int menu() {
	int opcao = 0;

	do {
		cout << "\t\t Jogo da velha" << endl << "   Escolha uma opção de jogo" << endl << "1 - Player Vs Player" << "2 Player vs IA";
		cin >> opcao;
		if (opcao != 1 && opcao != 2) {
			cout << "Opção invalida, favor selecione uma opção valida";
		}
	} while (opcao != 1 && opcao != 2);
	return opcao;
}

void cpu_turn() {

}

void desenharesqueleto(char mapa[3][3]) {
	char barra = 196;
	cout << "  0  |  1  |  2" << endl << "A" << " " << mapa[0][0] << "  |  " << mapa[0][1] << "  |  " << mapa[0][2] << endl
		<< barra << barra << barra << barra << barra << "|" << barra << barra << barra << barra << barra << "|" << barra << barra << barra << barra << barra << endl
		<< "B" << " " << mapa[1][0] << "  |  " << mapa[1][1] << "  |  " << mapa[1][2] << endl
		<< barra << barra << barra << barra << barra << "|" << barra << barra << barra << barra << barra << "|" << barra << barra << barra << barra << barra << endl
		<< "C" << " " << mapa[2][0] << "  |  " << mapa[2][1] << "  |  " << mapa[2][2] << endl;
}

void escolhas(int &coluna, char &linha, char mapa[3][3]) {
	bool situacao = false;

	do {
		do {
			cout << "Escolha uma letra e um numero para fazer sua jogada" << endl << "Letra: ";
			cin >> linha;
			if (linha != 'A'  && linha != 'B' && linha != 'C') {
				situacao = true;
				cout << "Digite um caracter valido" << endl;
			}
			else {
				situacao = false;
			}
		} while (situacao);

		do {
			cout << "Numero: ";
			cin >> coluna;
			if (coluna != 0 && coluna != 1 && coluna != 2) {
				situacao = true;
				cout << "Digite um numero valido" << endl;
			}
			else {
				situacao = false;
			}
		} while (situacao);
		situacao = verificacao_de_esqueleto(coluna, linha, mapa);
	} while (situacao);
}

bool verificar_status_jogo(int &vencedor, int mapa_inteiro[3][3]) {
	int mapa[9] = { 0 };
	int pontuacao = 0;
	int condicoes_para_vitoria[14][9] = {
		{ 1, 0, 0, 0, 1, 0, 0, 0, 1 },{ 0, 0, 1, 0, 1, 0, 1, 0, 0 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 1, 1, 1, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 1, 1, 1 },
		{ 0, 0, 1, 0, 0, 1, 0, 0, 1 },{ 1, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 2, 0, 0, 0, 2, 0, 0, 0, 2 },{ 0, 0, 2, 0, 2, 0, 2, 0, 0 },
		{ 2, 2, 2, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 2, 2, 2, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 2, 2, 2 },
		{ 0, 0, 2, 0, 0, 2, 0, 0, 2 },{ 2, 0, 0, 2, 0, 0, 2, 0, 0 }
	};

	int auxiliar = 0;

	for (int linha = 0; linha < 3; linha++) {
		for (int coluna = 0; coluna < 3; coluna++) {
			mapa[auxiliar] = mapa_inteiro[linha][coluna];
			auxiliar++;
		}
	}

	for (int linha = 0; linha < 14; linha++) {
		for (int indice = 0; indice < 9; indice++) {
			if (mapa[indice] == condicoes_para_vitoria[linha][indice] && mapa[indice] != 0) {
				pontuacao++;
			}
		}
		if (pontuacao == 3) {
			if (linha > 6) {
				vencedor = 2;
			}
			return true;
		}
		else {
			pontuacao = 0;
		}
	}
	return false;

}

void jogo(int jogador, int vencedor, int mapa_inteiro[3][3], char mapa[3][3], bool &game_over) {
	int coluna = 0;
	char linha = 0;


	if (game_over) {
		desenharesqueleto(mapa);
		return;
	}
	else {
		desenharesqueleto(mapa);
		escolhas(coluna, linha, mapa);
		atualizacao_de_esqueleto(jogador, coluna, linha, mapa);
		system("cls");
		transformar_em_mapa_numerico(mapa_inteiro, mapa);
		game_over = verificar_status_jogo(vencedor, mapa_inteiro);
		jogo(jogador, vencedor, mapa_inteiro, mapa, game_over);
	}

}

void jogo(int vencedor, char jogador_char, int mapa_inteiro[3][3], char mapa[3][3], bool game_over) {
	int coluna = 0;
	char linha = 0;


	if (game_over) {
		desenharesqueleto(mapa);
		return;
	}
	else {
		desenharesqueleto(mapa);
		escolhas(coluna, linha, mapa);
		//atualizacao_de_esqueleto(jogador_char, coluna, linha, mapa);
		cpu_turn();
		system("cls");
		transformar_em_mapa_numerico(mapa_inteiro, mapa);
		game_over = verificar_status_jogo(vencedor, mapa_inteiro);
		jogo(vencedor, jogador_char, mapa_inteiro, mapa, game_over);
	}
}

int main()
{
	char mapa[3][3] = { 0 };
	int mapa_inteiro[3][3] = { 0 };
	int vencedor = 0;
	int jogador = 1;
	int opcao = 0;
	char jogador_char = '1';
	bool game_over = false;

	opcao = menu();
	if (opcao == 1) {
		jogo(jogador, vencedor, mapa_inteiro, mapa, game_over);
	}
	if (opcao == 2) {
		jogo(vencedor, jogador_char, mapa_inteiro, mapa, game_over);
	}

	return 0;
}
