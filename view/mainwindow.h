#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QMainWindow>
#include <QStandardItemModel>
#include "model/datacollection.h"
#include "utils/datareader.h"
#include "utils/datawriter.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void clearInput();

private:
    Ui::MainWindow *ui;
    DataCollection *collection;
    DataReader *reader;
    DataWriter *writer;
    QStandardItemModel *viewModel;

private slots:
    void addTerm();
    void editTerm(QListWidgetItem *item);
    void renderCollection();
};

#endif // MAINWINDOW_H
