#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <vector>
#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>
#include "cardapio.h"
#include "produtos.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT 
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void inserirNaTabela();
    void inserirEstatiscas();

private slots:
    void on_Addbtm_clicked();

    void on_ordnome_clicked();

    void on_ordqnt_clicked();

    void on_ordpreco_clicked();

    void on_pushButton_clicked();

    void on_actionSalvar_triggered();

    void on_actionAbrir_triggered();

    void on_cancelbtm_clicked();

    void on_procurarbtm_clicked();

    void on_editbtm_clicked();

private:
    Cardapio cardapio;
    produtos cardapios;
    Ui::MainWindow *ui;
    int i;
};

#endif // MAINWINDOW_H
