#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "datacollection.h"
#include "datareader.h"
#include "datawriter.h"

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

private slots:
    void addTerm();
    void editTerm(QListWidgetItem *item);
    void renderCollection();
};

#endif // MAINWINDOW_H
