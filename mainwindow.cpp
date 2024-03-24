#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QTableView tableView;
//        QStandardItemModel model(100, 2); // 100 строк и 2 столбца

//        for (int row = 0; row < 100; ++row)
//        {
//            for (int col = 0; col < 2; ++col)
//            {
//                model.setItem(row, col, new QStandardItem(QString("Row %1 Col %2").arg(row+1).arg(col+1)));
//            }
//        }

//        ui->tableView->setModel(&model);
//        tableView.show();



//    // Создание модели данных
//    QStandardItemModel model(100, 2);

//    // Заголовки столбцов
//    model.setHorizontalHeaderLabels(QStringList() << "Column 1" << "Column 2");

//    // Заполнение модели данными
//    for (int row = 0; row < 100; ++row)
//    {
//        for (int col = 0; col < 2; ++col)
//        {
//            model.setItem(row, col, new QStandardItem(QString("Row %1, Column %2").arg(row + 1).arg(col + 1)));
//        }
//    }

//    // Создание виджета QTableView и привязка к модели
////    QTableView tableView;

//    ui->tableView->setModel(&model);


//    QFile file (fileName);

//    int i = 0;
//    if(file.open(QIODevice::ReadOnly | QFile::Text))
//    {
//        QTextStream stream(&file);

//        while (!stream.atEnd())
//        {
//            str = stream.readLine();
////            qDebug() << str;

//            if(str.mid(0, 4).toDouble() == 0)
//            {
//                newFormat = true;

//                if(i < 5)
//                    metaData << str;

//                if(i > 5)
//                    strlst << str;

//                strRes.clear();

//            }
//            else /*if(strRes[0].mid(0, 4).toDouble() != 0)*/
//            {
//                //                    newFormat = false;
//                strlst << str;
//                //                    strRes.clear();
//            }
//            i++;
//        }
//        if(stream.status()!= QTextStream::Ok)
//        {
//            qDebug() << "Ошибка чтения файла";
//        }
//        file.close();
//    }
//    else
//        qDebug() << "Ошибка чтения файла";





    // определяем данные для модели
//        QStandardItemModel* model=  new QStandardItemModel(3, 2);
//        model->setItem(0, 0, new QStandardItem("Tom"));
//        model->setItem(0, 1, new QStandardItem(39));
//        model->setItem(1, 0, new QStandardItem("Bob"));
//        model->setItem(1, 1, new QStandardItem(43));
//        model->setItem(2, 0, new QStandardItem("Sam"));
//        model->setItem(2, 1, new QStandardItem(28));

        // установка заголовков таблицы
//        model->setHeaderData(0, Qt::Horizontal, "Name");
//        model->setHeaderData(1, Qt::Horizontal, "Age");
//        // определяем представление
////        QTableView *view = new QTableView(widget);
//        ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pBgeneretionWord_clicked()
{
    QString FPath = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.*");

    QString str;
    QStringList strlst, strlstGenertion;

    QFile file(FPath);

    if(file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");

        while (!stream.atEnd())
        {
            str = stream.readLine();
            strlst << /*QString::fromLocal8Bit(*/str;
            //            qDebug() << str;
        }
        if(stream.status()!= QTextStream::Ok)
        {
            qDebug() << "Ошибка чтения файла";
        }
        file.close();
    }
    else
        qDebug() << "Ошибка чтения файла";


    ui->tableView->horizontalHeader()->hide();

    model = new QStandardItemModel;

    QStringList HorizontalHeader;
    HorizontalHeader << "Русские слова" << "Сгенерированные слова";

   model->setHorizontalHeaderLabels(HorizontalHeader);
//   ui->tableView->verticalHeader()->hide();

   int syllableCount = 4/*2*/;

    for(int i = 0; i < strlst.count(); i++)
    {
//        for(int j = 0; j < 2; j++)
//        {
        QStandardItem *item1 = new QStandardItem( strlst[i]);
        model->setItem(i, 0, item1);
        strlstGenertion << generateWord(syllableCount);
            QStandardItem *item2 = new QStandardItem( strlstGenertion[i]);
            model->setItem(i, 1, item2);
//        }
    }

    ui->tableView->setModel(model);

    QFile fileOut("output1.txt");
    if (fileOut.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&fileOut);

        for(int i = 0; i < strlst.count(); i++)
        {
            stream << strlst[i] << " " << strlstGenertion[i] << "\n";
        }

        //            stream << "Hello, World!" << endl;
        //            stream << "This is a sample text that will be written to the file." << endl;
        fileOut.close();
        //            qDebug() << "Data has been written to the file.";
    }
    else
    {
        qDebug() << "Failed to open the file for writing.";
    }
}

void MainWindow::on_pushButtonPerevod_clicked()
{
    QString inputText = ui->textEditInput->toPlainText();

    // разделение предложения на отдельные слова
    QStringList words = inputText.split(" ", QString::SkipEmptyParts);

    for(int i = 0; i < words.count(); i++)
    {
        words.indexOf("ть");
    }


    QString str;
    QStringList strlst, strlstGenertion;

    QFile file("output1.txt");

    if(file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");

        while (!stream.atEnd())
        {
            str = stream.readLine();
            strlst << /*QString::fromLocal8Bit(*/str;
            //            qDebug() << str;
        }
        if(stream.status()!= QTextStream::Ok)
        {
            qDebug() << "Ошибка чтения файла";
        }
        file.close();
    }
    else
        qDebug() << "Ошибка чтения файла";

    for(int i = 0; i < words.count(); i++)
    {
        for(int j = 0; j < strlst.count(); j++)
        {
            if(strlst[i] == words[i])
            {
                strlstGenertion << strlst[i];
            }
        }
    }

    ui->textEditOutput->setText(strlstGenertion.join(" "));
}
