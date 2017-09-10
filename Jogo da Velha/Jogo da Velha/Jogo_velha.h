#pragma once

#include "stdafx.h"
#include <iostream>

using namespace std;

#define TAMANHO_LINHA 3
#define TAMANHO_COLUNA 3

bool verificacao_de_esqueleto(int coluna, char linha_caracter, char mapa[TAMANHO_COLUNA][TAMANHO_LINHA]) {
	int A = 0;
	int B = 1;
	int C = 2;
	int linha = 4;

	if (linha_caracter == 'A') {
		linha = A;
	}
	else if (linha_caracter == 'B') {
		linha = B;
	}
	else {
		linha = C;
	}
	if (mapa[linha][coluna] == 'X' || mapa[linha][coluna] == 'O') {
		cout << "Casa já escolhida em alguma jogada anterior, escolha outra posição" << endl;
		return true;
	}
	return false;
}

void transformar_em_mapa_numerico(int mapa_inteiro[3][3], char mapa[3][3]) {
	for (int linha = 0; linha < 3; linha++) {
		for (int coluna = 0; coluna < 3; coluna++) {
			if (mapa[linha][coluna] == 'X') {
				mapa_inteiro[linha][coluna] = 1;
			}
			else if (mapa[linha][coluna] == 'O') {
				mapa_inteiro[linha][coluna] = 2;
			}
		}
	}
}

void atualizacao_de_esqueleto(int &jogador, int coluna, char linha, char mapa[3][3]) {

	switch (jogador) {
	case 1:
		if (linha == 'A') {
			for (int indice = 0; indice < 3; indice++) {
				if (coluna == indice) {
					mapa[0][coluna] = 'X';
				}
			}
		}
		else if (linha == 'B') {
			for (int indice = 0; indice < 3; indice++) {
				if (coluna == indice) {
					mapa[1][coluna] = 'X';
				}
			}
		}
		else {
			for (int indice = 0; indice < 3; indice++) {
				if (coluna == indice) {
					mapa[2][coluna] = 'X';
				}
			}
		}
		jogador = 2;
		break;
	case 2:
		if (linha == 'A') {
			for (int indice = 0; indice < 3; indice++) {
				if (coluna == indice) {
					mapa[0][coluna] = 'O';
				}
			}
		}
		else if (linha == 'B') {
			for (int indice = 0; indice < 3; indice++) {
				if (coluna == indice) {
					mapa[1][coluna] = 'O';
				}
			}
		}
		else {
			for (int indice = 0; indice < 3; indice++) {
				if (coluna == indice) {
					mapa[2][coluna] = 'O';
				}
			}
		}
		jogador = 1;
		break;
	}
}

void atualizacao_de_esqueleto(char &jogador, int coluna, char linha, char mapa[3][3]) {

	switch (jogador) {
	case '1':
		if (linha == 'A') {
			for (int indice = 0; indice < 3; indice++) {
				if (coluna == indice) {
					mapa[0][coluna] = 'X';
				}
			}
		}
		else if (linha == 'B') {
			for (int indice = 0; indice < 3; indice++) {
				if (coluna == indice) {
					mapa[1][coluna] = 'X';
				}
			}
		}
		else {
			for (int indice = 0; indice < 3; indice++) {
				if (coluna == indice) {
					mapa[2][coluna] = 'X';
				}
			}
		}
		jogador = '2';
		break;
	case '2':
		if (linha == 'A') {
			for (int indice = 0; indice < 3; indice++) {
				if (coluna == indice) {
					mapa[0][coluna] = 'O';
				}
			}
		}
		else if (linha == 'B') {
			for (int indice = 0; indice < 3; indice++) {
				if (coluna == indice) {
					mapa[1][coluna] = 'O';
				}
			}
		}
		else {
			for (int indice = 0; indice < 3; indice++) {
				if (coluna == indice) {
					mapa[2][coluna] = 'O';
				}
			}
		}
		jogador = '1';
		break;
	}
}

#pragma once
