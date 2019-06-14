#include "cardapio.h"
#include <QObject>

QString Cardapio::getProduto() const
{
    return produto;
}

void Cardapio::setProduto(const QString &value)
{
    produto = value;
}

float Cardapio::getPreco() const
{
    return preco;
}

void Cardapio::setPreco(float value)
{
    preco = value;
}

int Cardapio::getQuantidade() const
{
    return quantidade;
}

void Cardapio::setQuantidade(int value)
{
    quantidade = value;
}

void Cardapio::setTotalprice()
{
    precototal = preco*quantidade;
}


float Cardapio::getTotalprice()const
{
    return precototal;
}

void Cardapio::setTotalpreco(int value)
{
    precototal = value;
}

Cardapio::Cardapio()
{
    produto = 'bo';
    quantidade = -1;
    preco = -1;
}
