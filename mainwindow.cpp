#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getFileContent(QString path) {
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Service::Error";
        return "-1";
    }

    QString content = QTextCodec::codecForMib(106)->toUnicode(file.readAll());

    file.close();

    return content;
}

void MainWindow::on_btn_parse_clicked()
{

    QFileDialog dialog;
    QString adress = dialog.getOpenFileName();
    QStringList dirParts = adress.split("/");

    dirParts.removeLast();

    QString dir = dirParts.join("/");

    ui->file_adress->setText(adress);

    QString result;
    QString source = getFileContent(adress);
    QRegularExpression regex("[a-z-A-Z-0-9\\-_]{1,}\\.(cpp|h|ui)");
    QRegularExpressionMatchIterator iterator = regex.globalMatch(source);

    while (iterator.hasNext()) {
        QRegularExpressionMatch match = iterator.next();
        QString filename = match.captured(0);
        QString path = dir + "/" + filename;
        QString content = getFileContent(path);

        result += content + "\r\n___________________________________\r\n\r\n";
    }

    QString filename = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/data.txt";

    QFile file_out(filename);

    if (!file_out.open(QIODevice::WriteOnly)) {
        qDebug() << "Service::Error";
        return;
    }

    file_out.write(result.toUtf8());

}
