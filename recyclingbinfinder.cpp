#include "recyclingbinfinder.h"
#include "./ui_recyclingbinfinder.h"
#include "specificborough.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

RecyclingBinFinder::RecyclingBinFinder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecyclingBinFinder)
{
    ui->setupUi(this);
    loadFile();
}

RecyclingBinFinder::~RecyclingBinFinder()
{
    delete ui;
}

void RecyclingBinFinder::on_manButton_clicked()
{
    ui->displayWindow->clear();
    specificBorough man;
    man.setName("MAN");
    QStringList manList = man.boroList(binList);
    for(int i = 0; i<manList.length(); i++)
        ui->displayWindow->insertPlainText(manList[i]);
}


void RecyclingBinFinder::on_qnsButton_clicked()
{
    ui->displayWindow->clear();
    specificBorough qns;
    qns.setName("QNS");
    QStringList qnsList = qns.boroList(binList);
    for(int i = 0; i<qnsList.length(); i++)
        ui->displayWindow->insertPlainText(qnsList[i]);
}


void RecyclingBinFinder::on_bkButton_clicked()
{
    ui->displayWindow->clear();
    specificBorough bk;
    bk.setName("BKN");
    QStringList bkList = bk.boroList(binList);
    for(int i = 0; i<bkList.length(); i++)
        ui->displayWindow->insertPlainText(bkList[i]);
}


void RecyclingBinFinder::on_bxButton_clicked()
{
    ui->displayWindow->clear();
    specificBorough bx;
    bx.setName("BX");
    QStringList bxList = bx.boroList(binList);
    for(int i = 0; i<bxList.length(); i++)
        ui->displayWindow->insertPlainText(bxList[i]);
}


void RecyclingBinFinder::on_siButton_clicked()
{
    ui->displayWindow->clear();
    specificBorough si;
    si.setName("SI");
    QStringList siList = si.boroList(binList);
    for(int i = 0; i<siList.length(); i++)
        ui->displayWindow->insertPlainText(siList[i]);
}

void RecyclingBinFinder::on_homeButton_clicked()
{
    ui->displayWindow->clear();
    for(int i = 0; i < 136; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(j == 3)
            {
               ui->displayWindow->insertPlainText(binList[(7*i)+j] + "\n");
            }
        }
    }
}

void RecyclingBinFinder::loadFile()
{
    QFile file(":/Public_Recycling_Bins.csv");
    if(!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.errorString();
            return;
    }
    if(!file.exists())
    {
        throw 1;
    }
    QTextStream test(&file);
    while(!test.atEnd())
    {
        binList.append(test.readLine().split(","));
    }
}

