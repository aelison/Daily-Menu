#ifndef PRODUTOS_H
#define PRODUTOS_H
#include <QObject>
#include <QVector>
#include <algorithm>
#include <QFile>
#include <cardapio.h>
class produtos
{
private:
QVector <Cardapio> cardapios;

public:
bool testarcardapio(Cardapio a);
bool testarcardapiob(Cardapio a);
int quantidadedProd();
void OrganizarPorPrecoTotal();
void OrganizarPorProduto();
void OrganizarPorQuantidade();
void OrganizarPorPreco();
void inserirCardapio(Cardapio a);
Cardapio operator[](int b) ;
bool salvarCardapio(QString arquivo);
bool carregarCardapio(QString arquivo);
int size();
produtos();
bool testarigualdade(QString value);
bool testarigualdadeb(QString value);
bool testarnumero(QString value);
int procurarcardapio(Cardapio a);
void editarcardapio(Cardapio a);
float calcularprecototal();
float calcularprecomedio();
};
bool organizarPorProduto(const Cardapio a,const Cardapio b);
bool organizarPorQuantidade(const Cardapio a,const Cardapio b);
bool organizarPorPreco(const Cardapio a,const Cardapio b);
bool organizarPorPrecoTotal(const Cardapio a,const Cardapio b);
bool testarproduto(QString value);
bool testarquantidade(int value);
bool testarpreco(float value);

#endif // PRODUTOS_H
