#include "produtos.h"
#include <QDebug>
bool produtos::testarcardapio(Cardapio a)
{
    if(testarproduto(a.getProduto())  && testarquantidade(a.getQuantidade()) && testarpreco(a.getPreco()) && testarigualdade((a.getProduto())) && testarnumero((a.getProduto()))){

    return 1;
    }
    return 0;

}

bool produtos::testarcardapiob(Cardapio a)
{
    if(testarproduto(a.getProduto())  && testarquantidade(a.getQuantidade()) && testarpreco(a.getPreco()) && testarigualdadeb((a.getProduto())) && testarnumero((a.getProduto()))){

    return 1;
    }
    return 0;
}

int produtos::quantidadedProd()
{
    int total = 0;
    for(int i = 0;i<cardapios.size();i++){
        total = cardapios[i].getQuantidade() + total;
    }
    return total;
}

void produtos::OrganizarPorPrecoTotal()
{
    std::sort(cardapios.begin(),cardapios.end(),organizarPorPrecoTotal);
}

void produtos::OrganizarPorProduto()
{
    std::sort(cardapios.begin(),cardapios.end(),organizarPorProduto);
}

void produtos::OrganizarPorQuantidade()
{
    std::sort(cardapios.begin(),cardapios.end(),organizarPorQuantidade);
}

void produtos::OrganizarPorPreco()
{
    std::sort(cardapios.begin(),cardapios.end(),organizarPorPreco);
}

void produtos::inserirCardapio(Cardapio a)
{  
    cardapios.push_back(a);
}

Cardapio produtos::operator[](int b)
{
    return cardapios[b];
}

produtos::produtos()
{  

}

bool produtos::testarigualdade(QString value)
{
    for(int i =0;i < cardapios.size();i++){
        if (value.toLower() == cardapios[i].getProduto().toLower()){
            return 0;
        }
    }
    return 1;
}

bool produtos::testarigualdadeb(QString value)
{
    for(int i =0;i < cardapios.size();i++){
        if (value.toLower() == cardapios[i].getProduto().toLower()){
            return 1;
        }
    }
    return 0;
}

bool produtos::testarnumero(QString value)
{
    QString num = "0123456789";
    for(int i = 0;i<value.size();i++){
        for(int j = 0;j<num.size();j++){
            if(value[i] == num[j]){
                return 0;
            }
        }
    }
    return 1;
}

int produtos::procurarcardapio(Cardapio a)
{
    int i;
    qDebug() << cardapios.size();
    for(i = 0;cardapios[i].getProduto() != a.getProduto();i++){
        qDebug() << "iaiessa";
        qDebug() << cardapios[i].getProduto();
    }
    qDebug()<< cardapios[i].getProduto();
    return i;
}

void produtos::editarcardapio(Cardapio a)
{
    int i = procurarcardapio(a);
    cardapios[i].setPreco(a.getPreco());
    cardapios[i].setQuantidade(a.getQuantidade());
    cardapios[i].setTotalprice();
}

float produtos::calcularprecototal()
{
    float precototal = 0;
    for(int i = 0;i < cardapios.size() ; i++){
        precototal = cardapios[i].getTotalprice()+precototal;
    }
    return precototal;
}

float produtos::calcularprecomedio()
{
    float precomedio = 0;
    for(int i = 0;i < cardapios.size() ; i++){
        precomedio = cardapios[i].getPreco()+precomedio;
    }
    return precomedio/cardapios.size();
}

bool organizarPorProduto(const Cardapio a,const Cardapio b){
    return a.getProduto().toLower()<b.getProduto().toLower();
}

bool organizarPorQuantidade(const Cardapio a,const Cardapio b){
    return a.getQuantidade()>b.getQuantidade();
}

bool organizarPorPreco(const Cardapio a,const Cardapio b){
    return a.getPreco()>b.getPreco();
}

bool organizarPorPrecoTotal(const Cardapio a,const Cardapio b){
    return a.getTotalprice()>b.getTotalprice();
}

bool produtos::salvarCardapio(QString arquivo)
{
    QFile file(arquivo);
    QString linha;
    if(!file.open(QIODevice::WriteOnly))
        return false;

    for(Cardapio a : cardapios){
        linha = a.getProduto() + ',' + QString::number(a.getQuantidade()) + ',' + QString::number(a.getPreco()) + ',' + QString::number(a.getTotalprice()) + '\n';
        file.write(linha.toLocal8Bit());
    }
    return true;

}

bool produtos::carregarCardapio(QString arquivo)
{

    QFile file(arquivo);
    if(!file.open(QIODevice::ReadOnly))
        return false;

    QString linha;
    Cardapio a;
    while(!file.atEnd()){
        linha = file.readLine();
        QStringList dados = linha.split(",");
        a.setProduto(dados[0]);
        qDebug()<<a.getProduto();
        a.setQuantidade(dados[1].toDouble());
        a.setPreco(dados[2].toDouble());
        a.setTotalpreco(dados[3].toDouble());
        inserirCardapio(a);
    }
    return true;
}

int produtos::size()
{
    return cardapios.size();
}

bool testarproduto(QString value)
{
    if(value.size() < 3){
        return 0;
   }
    return 1;
}

bool testarquantidade(int value)
{
    if (value < 0 || value == 0){
        return 0;
    }
    return 1;
}

bool testarpreco(float value)
{
    if (value < 0 || value == 0){
        return 0;
    }
    return 1;
}

