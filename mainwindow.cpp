#include <QFile>
#include <QMetaType>
#include <QTextStream>
#include "dataentity.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    qRegisterMetaType<DataEntity>("DataEntity");
    reader = new DataReader("backup.xml");
    writer = new DataWriter("backup.xml");
    collection = new DataCollection(reader->read());
    ui->setupUi(this);
    connect(ui->addTermButton, SIGNAL(clicked()), this, SLOT(addTerm()));
    connect(ui->termList, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(editTerm(QListWidgetItem *)));

    renderCollection();
}

MainWindow::~MainWindow()
{
    writer->write(collection);
    delete ui;
    delete reader;
    delete writer;
    delete collection;
}

void MainWindow::addTerm()
{
    QString inputTerm = ui->termLineEdit->text();
    QString inputDefinition = ui->definitionTextEdit->toPlainText();

    if (inputTerm.isEmpty())
    {
        ui->termLineEdit->setStyleSheet("QLineEdit { background: rgb(255, 0, 0)}");
        ui->termLineEdit->setFocus();
        return;
    }
    collection->add(new DataEntity(inputTerm, inputDefinition));
    renderCollection();
}

void MainWindow::editTerm(QListWidgetItem *item)
{
    ui->termLineEdit->setText(item->text());
}

void MainWindow::renderCollection()
{
    ui->termList->clear();
    foreach(QObject *data_object, *collection->toList())
    {
        DataEntity *data_entity = qobject_cast<DataEntity *>(data_object);
        ui->termList->addItem(data_entity->getTerm());
    }
    clearInput();
}

void MainWindow::clearInput()
{
    ui->termLineEdit->clear();
    ui->termLineEdit->setStyleSheet("");
    ui->definitionTextEdit->clear();
}
