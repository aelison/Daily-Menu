#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    i = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Addbtm_clicked()
{
    cardapio.setPreco(ui->Lpreco->text().toFloat());
    cardapio.setProduto(ui->Lproduto->text());
    cardapio.setQuantidade(ui->Lqntd->text().toInt());
    cardapio.setTotalprice();
    if (cardapios.testarcardapio(cardapio) && !(ui->Lpreco->text().isEmpty()) && !(ui->Lproduto->text().isEmpty()) && !(ui->Lqntd->text().isEmpty())) {
        cardapios.inserirCardapio(cardapio);
        ui->tableWidget->insertRow(i);
        i++;
        ui->labeldaverdade->setText("Produto cadastrado !");
        ui->Lqntd->clear();
        ui->Lpreco->clear();
        ui->Lproduto->clear();
    }
    else {
        ui->labeldaverdade->setText("Produto com informações inválidas");
        QMessageBox msg;
        msg.setText("        Dado inválido                ");
        msg.exec();
    }
    inserirNaTabela();

}

void MainWindow::inserirNaTabela(){

    for (int j = 0;j<cardapios.size();j++){
     ui->tableWidget->setItem(j,0,new QTableWidgetItem(cardapios[j].getProduto()));
     ui->tableWidget->setItem(j,1,new QTableWidgetItem(QString::number(cardapios[j].getQuantidade())));
     ui->tableWidget->setItem(j,2,new QTableWidgetItem(QString::number(cardapios[j].getPreco())));
     ui->tableWidget->setItem(j,3,new QTableWidgetItem(QString::number(cardapios[j].getTotalprice())));
    }
    inserirEstatiscas();
}

void MainWindow::inserirEstatiscas()
{
    ui->label_11->setText(QString::number(cardapios.quantidadedProd()));
    ui->label_9->setText(QString::number(cardapios.calcularprecototal()));
    ui->label_10->setText(QString::number(cardapios.calcularprecomedio()));
}

void MainWindow::on_ordnome_clicked()
{
    cardapios.OrganizarPorProduto();
    inserirNaTabela();
}

void MainWindow::on_ordqnt_clicked()
{
    cardapios.OrganizarPorQuantidade();
    inserirNaTabela();
}

void MainWindow::on_ordpreco_clicked()
{
    cardapios.OrganizarPorPreco();
    inserirNaTabela();
}

void MainWindow::on_pushButton_clicked()
{
    cardapios.OrganizarPorPrecoTotal();
    inserirNaTabela();
}

void MainWindow::on_actionSalvar_triggered()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,
                                                           "Cardapio",
                                                           "",
                                                           "CSV(*.csv)");
        cardapios.salvarCardapio(nomeArquivo);
}

void MainWindow::on_actionAbrir_triggered()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,
                                                          "Cardapio",
                                                          "",
                                                          "CSV(*.csv)");
       cardapios.carregarCardapio(nomeArquivo);
       for(;i<cardapios.size();){
           i++;
           ui->tableWidget->insertRow(i-1);
           inserirNaTabela();
       }
}


void MainWindow::on_cancelbtm_clicked()
{
    ui->lbum->clear();
    ui->lbdois->clear();
    ui->lbtres->clear();
}


void MainWindow::on_procurarbtm_clicked()
{
    Cardapio a;
    int i;

    a.setProduto(ui->lbum->text());
    if(cardapios.testarigualdadeb(a.getProduto())){
        i = cardapios.procurarcardapio(a);
        ui->lbtres->setText(QString::number(cardapios[i].getPreco()));
        ui->lbdois->setText(QString::number(cardapios[i].getQuantidade()));
        ui->lberror->setText("Produto encontrado;");
    }
    else{
        ui->lberror->setText("Produto não foi encontrado;");
        ui->lbdois->clear();
        ui->lbtres->clear();
    }

}

void MainWindow::on_editbtm_clicked()
{
    Cardapio a;
    a.setProduto(ui->lbum->text());
    a.setPreco(ui->lbtres->text().toFloat());
    a.setQuantidade(ui->lbdois->text().toInt());
    if(cardapios.testarcardapiob(a)){
        cardapios.editarcardapio(a);
        inserirNaTabela();
        ui->lberror->setText("Dados editados:");
    }
    else {
        ui->lberror->setText("Dados inválidos");
    }
    ui->lbum->clear();
    ui->lbdois->clear();
    ui->lbtres->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    int k = cardapios.size();
    for(int j = 0;j < cardapios.size();j++){
        ui->tableWidget->removeRow(k);
        k--;
        i--;
    }
    ui->tableWidget->removeRow(0);
    cardapios.limpardados();
    inserirNaTabela();
}

void MainWindow::on_retirarbtm_clicked()
{
   Cardapio a;
   a.setProduto(ui->lbum->text());
   if (cardapios.testeproduto(a))   {
   int tam = cardapios.procurarcardapio(a);
   i--;
   cardapios.apagarproduto(a);
   ui->tableWidget->removeRow(tam);
   inserirNaTabela();
   }
   ui->lbdois->clear();
   ui->lbtres->clear();
}
