#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QStringList vowels = {"а", "е", "ё", "и", "о", "у", "ы", "э", "ю", "я"};
    QStringList consonants = {"б", "в", "г", "д", "ж", "з", "к", "л", "м", "н", "п", "р", "с", "т", "ф", "х", "ц", "ч", "ш", "щ"};

    QString getRandomVowel()
    {
        int index = qrand() % vowels.size();
        return vowels[index];
    }

    QString getRandomConsonant()
    {
        int index = qrand() % consonants.size();
        return consonants[index];
    }

    QString generateSyllable()
    {
        QString syllable;
        if (qrand() % 2 == 0)
        {
            syllable += getRandomConsonant();
        }
        syllable += getRandomVowel();
        return syllable;
    }

    QString generateWord(int syllableCount)
    {
        QString word;
        for (int i = 0; i < syllableCount; ++i)
        {
            word += generateSyllable();
        }
        return word;
    }

    void generateConlang(int wordCount, int syllableCount)
    {
    //    qDebug() << "Generated Conlang:";
        for (int i = 0; i < wordCount; ++i)
        {
            QString word = generateWord(syllableCount);
    //        qDebug().noquote() << word;
        }
    }


private slots:
    void on_pBgeneretionWord_clicked();

    void on_pushButtonPerevod_clicked();

private:
    Ui::MainWindow *ui;

    QStandardItemModel *model;
};





#endif // MAINWINDOW_H
