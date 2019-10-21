#include <QFile>
#include <QMetaType>
#include <QTextStream>
#include "application/controller/termdelegate.h"
#include "application/model/dataentity.h"
#include "application/view/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    qRegisterMetaType<DataEntity>("DataEntity");
    reader = new DataReader("backup.xml");
    writer = new DataWriter("backup.xml");
    collection = new DataCollection(reader->read());
    viewModel = new QStandardItemModel();

    viewModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Term")));
    viewModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Definition")));
    ui->setupUi(this);

    connect(ui->addTermButton, SIGNAL(clicked()), this, SLOT(addTerm()));
    connect(ui->modelView, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(editTerm(QListWidgetItem *)));

    renderCollection();
}

MainWindow::~MainWindow()
{
    writer->write(collection);
    delete ui;
    delete reader;
    delete writer;
    delete collection;
    delete viewModel;
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
    TermDelegate * delegate = new TermDelegate();
    
    viewModel->clear();
    foreach(QObject *data_object, *collection->toList())
    {
        DataEntity *data_entity = qobject_cast<DataEntity *>(data_object);
        QList<QStandardItem*> data_row;

        data_row.append(new QStandardItem(data_entity->getTerm()));
        data_row.append(new QStandardItem(data_entity->getDefinition()));
        viewModel->appendRow(data_row);
    }

    ui->modelView->setModel(viewModel);
    ui->modelView->setItemDelegate(delegate);
    clearInput();
}

void MainWindow::clearInput()
{
    ui->termLineEdit->clear();
    ui->termLineEdit->setStyleSheet("");
    ui->definitionTextEdit->clear();
}
