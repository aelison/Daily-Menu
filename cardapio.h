#ifndef CARDAPIO_H
#define CARDAPIO_H
#include "qobject.h"

class Cardapio
{
private:
QString produto;
float preco;
int quantidade;
float precototal;
public:
    Cardapio();
    QString getProduto() const;
    void setProduto(const QString &value);
    float getPreco() const;
    void setPreco(float value);
    int getQuantidade() const;
    void setQuantidade(int value);
    void setTotalprice();
    float getTotalprice()const;
    void setTotalpreco(int value);
};

#endif // CARDAPIO_H
