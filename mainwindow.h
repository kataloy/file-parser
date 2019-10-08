#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextCodec>
#include <QTextDocument>
#include <QRegularExpressionMatchIterator>
#include <QStringList>
#include <QPdfWriter>
#include <QPageSize>
#include <QPrinter>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QString getFileContent(QString path);

private slots:
    void on_btn_parse_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
