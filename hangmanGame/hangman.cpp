#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "nao_acertou.hpp"
#include "imprime_cabec.hpp"
#include "letra_existe.hpp"
#include "imprime_erros.hpp"
#include "chuta.hpp"
#include "imprime_palavra.hpp"
#include "adiciona_palavra.hpp"
#include "le_arquivo.hpp"
#include "salva_arquivo.hpp"
#include "sorteia_palavra.hpp"


using namespace std;
string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

int main()
{
    imprime_cabecalho();

    
    palavra_secreta = sorteia_palavra();

    while (nao_acertou(palavra_secreta, chutou) && chutes_errados.size() < 5)
    {
        imprime_erros(chutes_errados);

        imprime_palavra(palavra_secreta, chutou);

        chuta(chutou, chutes_errados);
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if (nao_acertou(palavra_secreta, chutou))
    {
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else
    {
        cout << "Parabens! Voce acertou a palavra secreta!" << endl;

        cout << "Voce deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if (resposta == 'S')
        {
            adiciona_palavra();
        }
    }
}