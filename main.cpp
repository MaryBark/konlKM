#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

//#include <QCoreApplication>
//#include <QDebug>
//#include <QString>
//#include <QMap>

//// Функция для перевода русского слова в конланг (простой пример)
//QString translateToConlang(const QString& russianWord)
//{
//    // Пример простого "перевода" - замена первой буквы на "C"
//    QString conlangWord = "C" + russianWord.mid(1);
//    return conlangWord;
//}

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    // Пример предложения на русском
//    QString russianSentence = "Привет, как дела?";

//    // Разделение предложения на отдельные слова
//    QStringList words = russianSentence.split(" ", QString::SkipEmptyParts);

//    // Карта для хранения переведенных слов
//    QMap<QString, QString> translationMap;

//    // Перевод каждого слова и сохранение в карту
//    for (const auto& word : words)
//    {
//        translationMap.insert(word, translateToConlang(word));
//    }

//    // Вывод переведенного предложения
//    qDebug() << "Перевод на конланг:";
//    for (const auto& word : words)
//    {
//        qDebug() << translationMap.value(word);
//    }

//    return a.exec();
//}





//#include <QCoreApplication>
////#include <QNetworkAccessManager>
////#include <QNetworkRequest>
////#include <QNetworkReply>
//#include <QJsonDocument>
//#include <QJsonObject>
//#include <QJsonArray>
//#include <QString>
//#include <QDebug>

//class Translator : public QObject {
//    Q_OBJECT

//public:
//    explicit Translator(QObject *parent = nullptr) : QObject(parent) {
//        // API ключ для Google Translate API (замените на свой)
//        apiKey = "YOUR_API_KEY";
//        networkManager = new QNetworkAccessManager(this);
//        connect(networkManager, &QNetworkAccessManager::finished, this, &Translator::onNetworkReply);
//    }

//    void translateFromRussianToConlang(const QString &text) {
//        QString url = "https://translation.googleapis.com/language/translate/v2?target=kl&key=" + apiKey + "&q=" + text;
//        networkManager->get(QNetworkRequest(QUrl(url)));
//    }

//private slots:
//    void onNetworkReply(QNetworkReply *reply) {
//            if (reply->error() == QNetworkReply::NoError) {
//                QJsonDocument jsonResponse = QJsonDocument::fromJson(reply->readAll());
//                QJsonObject jsonObject = jsonResponse.object();
//                QJsonObject data = jsonObject["data"].toObject();
//                QJsonArray translations = data["translations"].toArray();
//                QString translatedText = translations[0].toObject()["translatedText"].toString();
//                qDebug() << "Перевод на конланг:" << translatedText;
//            } else {
//                qDebug() << "Ошибка при сетевом запросе:" << reply->errorString();
//            }
//            reply->deleteLater();
//        }

//private:
//    QString apiKey;
//    QNetworkAccessManager *networkManager;
//};

//int main(int argc, char *argv[]) {
//    QCoreApplication app(argc, argv);

//    Translator translator;
//    translator.translateFromRussianToConlang("Привет, как дела?");

//    return app.exec();
//}

//#include "main.moc"



//#include <QCoreApplication>
//#include <QDateTime>
//#include <QDebug>

//QStringList vowels = {"а", "е", "ё", "и", "о", "у", "ы", "э", "ю", "я"};
//QStringList consonants = {"б", "в", "г", "д", "ж", "з", "к", "л", "м", "н", "п", "р", "с", "т", "ф", "х", "ц", "ч", "ш", "щ"};

//QString getRandomVowel()
//{
//    int index = qrand() % vowels.size();
//    return vowels[index];
//}

//QString getRandomConsonant()
//{
//    int index = qrand() % consonants.size();
//    return consonants[index];
//}

//QString generateSyllable()
//{
//    QString syllable;
//    if (qrand() % 2 == 0)
//    {
//        syllable += getRandomConsonant();
//    }
//    syllable += getRandomVowel();
//    return syllable;
//}

//QString generateWord(int syllableCount)
//{
//    QString word;
//    for (int i = 0; i < syllableCount; ++i)
//    {
//        word += generateSyllable();
//    }
//    return word;
//}

//void generateConlang(int wordCount, int syllableCount)
//{
//    qDebug() << "Generated Conlang:";
//    for (int i = 0; i < wordCount; ++i)
//    {
//        QString word = generateWord(syllableCount);
//        qDebug().noquote() << word;
//    }
//}

//int main(int argc, char* argv[])
//{
//    QCoreApplication a(argc, argv);
//    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);

//    int wordCount = 100;
//    int syllableCount = 4/*2*/;

//    generateConlang(wordCount, syllableCount);

//    return a.exec();
//}


//#include <QCoreApplication>
//#include <QDebug>
//#include <QString>
//#include <QMap>

//QMap<QChar, QString> languageMap;

//void initializeLanguageMap()
//{
//    // Здесь можно добавить другие символы древнерусского алфавита и их соответствующие значения на конланге
//    languageMap['А'] = "Kal";
//    languageMap['Б'] = "Ven";
//    languageMap['В'] = "Rot";
//    languageMap['Г'] = "Yar";
//    languageMap['Д'] = "Lok";
//    languageMap['Е'] = "Gon";
//    languageMap['Ё'] = "Hor";
//    // ...
//}

//QString translateToConlang(const QString& phrase)
//{
//    QString conlangPhrase;
//    for (const QChar& letter : phrase)
//    {
//        QChar upperCaseLetter = letter.toUpper();
//        if (languageMap.contains(upperCaseLetter))
//        {
//            conlangPhrase += languageMap[upperCaseLetter];
//        }
//    }
//    return conlangPhrase;
//}

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    // Инициализация карты языка
//    initializeLanguageMap();

//    // Ввод фразы на русском языке
//    qDebug() << "Введите фразу на русском языке:";
//    QString russianPhrase;
//    QTextStream qin(stdin);
//    qin >> russianPhrase;

//    // Перевод фразы на конланг
//    QString conlangPhrase = translateToConlang(russianPhrase);

//    // Вывод перевода
//    qDebug() << "Перевод на конланг:";
//    qDebug() << conlangPhrase;

//    return a.exec();
//}

//#include <QtWidgets>
//#include <QMap>

//class MainWindow : public QMainWindow {
//    Q_OBJECT

//public:
//    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
//        // Создаем кнопку для генерации слова
//        QPushButton *generateButton = new QPushButton("Сгенерировать слово");
//        connect(generateButton, &QPushButton::clicked, this, &MainWindow::generateWord);

//        // Создаем метку для отображения сгенерированного слова
//        wordLabel = new QLabel();

//        // Создаем метку для отображения перевода слова
//        translationLabel = new QLabel();

//        // Создаем вертикальный компоновщик и добавляем в него кнопку и метки
//        QVBoxLayout *layout = new QVBoxLayout();
//        layout->addWidget(generateButton);
//        layout->addWidget(wordLabel);
//        layout->addWidget(translationLabel);

//        // Создаем виджет и устанавливаем в него компоновщик
//        QWidget *centralWidget = new QWidget();
//        centralWidget->setLayout(layout);

//        setCentralWidget(centralWidget);
//    }

//private slots:
//    void generateWord() {
//        // Мапа соответствия древнерусских букв и их транскрипции
//        QMap<QString, QString> letters;
//        letters["а"] = "a";
//        letters["б"] = "b";
//        letters["в"] = "v";
//        letters["г"] = "g";
//        letters["д"] = "d";
//        letters["е"] = "e";
//        letters["ж"] = "zh";
//        letters["з"] = "z";
//        letters["и"] = "i";
//        letters["й"] = "y";
//        letters["к"] = "k";
//        letters["л"] = "l";
//        letters["м"] = "m";
//        letters["н"] = "n";
//        letters["о"] = "o";
//        letters["п"] = "p";
//        letters["р"] = "r";
//        letters["с"] = "s";
//        letters["т"] = "t";
//        letters["у"] = "u";
//        letters["ф"] = "f";
//        letters["х"] = "kh";
//        letters["ц"] = "ts";
//        letters["ч"] = "ch";
//        letters["ш"] = "sh";
//        letters["щ"] = "shch";
//        letters["ъ"] = "'";
//        letters["ы"] = "y";
//        letters["ь"] = "'";
//        letters["э"] = "e";
//        letters["ю"] = "yu";
//        letters["я"] = "ya";

//        // Список древнерусских букв
//        QStringList russianLetters;
//        russianLetters << "а" << "б" << "в" << "г" << "д" << "е" << "ж" << "з" << "и" << "й" << "к" << "л" << "м" << "н" << "о" << "п" << "р" << "с" << "т" << "у" << "ф" << "х" << "ц" << "ч" << "ш" << "щ" << "ъ" << "ы" << "ь" << "э" << "ю" << "я";

//        // Генерируем случайное слово
//        QString word;
//        for (int i = 0; i < 5; ++i) {
//            int randomIndex = qrand() % russianLetters.size();
//            word += russianLetters[randomIndex];
//        }

//        // Отображаем сгенерированное слово
//        wordLabel->setText(word);

//        // Переводим слово на русский язык
//        QString translation;
//        for (const QChar &letter : word) {
//            QString russianLetter = QString(letter);
//            if (letters.contains(russianLetter)) {
//                translation += letters[russianLetter];
//            }
//        }

//        // Отображаем перевод слова
//        translationLabel->setText(translation);
//    }

//private:
//    QLabel *wordLabel;
//    QLabel *translationLabel;
//};

//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);

//    // Задаем случайное начальное значение для генератора случайных чисел
//    qsrand(QTime::currentTime().msec());

//    MainWindow mainWindow;
//    mainWindow.show();

//    return app.exec();
//}



//#include <QCoreApplication>
//#include <QDebug>
//#include <QString>
//#include <QMap>
//#include <QTime>

//QMap<QChar, QString> languageMap;

//void initializeLanguageMap()
//{
//    // Здесь можно добавить другие символы древнерусского алфавита и описать их соответствующие значения на конланге
//    languageMap['А'] = "Kal";
//    languageMap['Б'] = "Ven";
//    languageMap['В'] = "Rot";
//    languageMap['Г'] = "Yar";
//    languageMap['Д'] = "Lok";
//    languageMap['Е'] = "Gon";
//    languageMap['Ё'] = "Hor";
//    // ...
//}

//QString getRandomRussianWord()
//{
//    QStringList russianWords = {
//        "кот", "дом", "солнце", "вода", "дерево", "город",
//        "человек", "яблоко", "стол", "книга", "рука", "окно"
//    };

//    // Генерация случайного индекса
//    QTime time = QTime::currentTime();
//    qsrand(static_cast<uint>(time.msec()));
//    int randomIndex = qrand() % russianWords.size();

//    return russianWords[randomIndex];
//}

//QString translateToConlang(const QString& phrase)
//{
//    QString conlangPhrase;
//    for (const QChar& letter : phrase)
//    {
//        QChar upperCaseLetter = letter.toUpper();
//        if (languageMap.contains(upperCaseLetter))
//        {
//            conlangPhrase += languageMap[upperCaseLetter];
//        }
//    }
//    return conlangPhrase;
//}

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    // Инициализация карты языка
//    initializeLanguageMap();

//    // Ввод фразы на русском языке
//    qDebug() << "Введите фразу на русском языке:";
//    QString russianPhrase;
//    QTextStream qin(stdin);
//    qin >> russianPhrase;

//    // Перевод фразы на конланг
//    QString conlangPhrase = translateToConlang(russianPhrase);

//    // Получение случайного русского слова для перевода
//    QString randomRussianWord = getRandomRussianWord();

//    // Вывод перевода
//    qDebug() << "Перевод на конланг:";
//    qDebug() << conlangPhrase;
//    qDebug() << "Перевод на русский:";
//    qDebug() << randomRussianWord;

//    return a.exec();
//}



//#include <QtWidgets>
//#include <QMap>

//class MainWindow : public QMainWindow {
//    Q_OBJECT

//public:
//    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
//        // Создаем кнопку для генерации слова
//        QPushButton *generateButton = new QPushButton("Сгенерировать слово");
//        connect(generateButton, &QPushButton::clicked, this, &MainWindow::generateWord);

//        // Создаем метку для отображения сгенерированного слова
//        wordLabel = new QLabel();

//        // Создаем метку для отображения перевода слова
//        translationLabel = new QLabel();

//        // Создаем вертикальный компоновщик и добавляем в него кнопку и метки
//        QVBoxLayout *layout = new QVBoxLayout();
//        layout->addWidget(generateButton);
//        layout->addWidget(wordLabel);
//        layout->addWidget(translationLabel);

//        // Создаем виджет и устанавливаем в него компоновщик
//        QWidget *centralWidget = new QWidget();
//        centralWidget->setLayout(layout);

//        setCentralWidget(centralWidget);
//    }

//private slots:
//    void generateWord() {
//        // Мапа соответствия древнерусских букв и их транскрипции
//        QMap<QString, QString> letters;
//        letters["а"] = "a";
//        letters["б"] = "b";
//        letters["в"] = "v";
//        letters["г"] = "g";
//        letters["д"] = "d";
//        letters["е"] = "e";
//        letters["ж"] = "zh";
//        letters["з"] = "z";
//        letters["и"] = "i";
//        letters["й"] = "y";
//        letters["к"] = "k";
//        letters["л"] = "l";
//        letters["м"] = "m";
//        letters["н"] = "n";
//        letters["о"] = "o";
//        letters["п"] = "p";
//        letters["р"] = "r";
//        letters["с"] = "s";
//        letters["т"] = "t";
//        letters["у"] = "u";
//        letters["ф"] = "f";
//        letters["х"] = "kh";
//        letters["ц"] = "ts";
//        letters["ч"] = "ch";
//        letters["ш"] = "sh";
//        letters["щ"] = "shch";
//        letters["ъ"] = "'";
//        letters["ы"] = "y";
//        letters["ь"] = "'";
//        letters["э"] = "e";
//        letters["ю"] = "yu";
//        letters["я"] = "ya";

//        // Список древнерусских букв
//        QStringList russianLetters;
//        russianLetters << "а" << "б" << "в" << "г" << "д" << "е" << "ж" << "з" << "и" << "й" << "к" << "л" << "м" << "н" << "о" << "п" << "р" << "с" << "т" << "у" << "ф" << "х" << "ц" << "ч" << "ш" << "щ" << "ъ" << "ы" << "ь" << "э" << "ю" << "я";

//        // Генерируем случайное слово
//        QString word;
//        for (int i = 0; i < 5; ++i) {
//            int randomIndex = qrand() % russianLetters.size();
//            word += russianLetters[randomIndex];
//        }

//        // Отображаем сгенерированное слово
//        wordLabel->setText(word);

//        // Генерируем случайное русское слово в качестве перевода
//        QStringList russianWords;
//        russianWords << "кот" << "дом" << "солнце" << "лес" << "вода" << "цветок" << "ночь" << "день" << "звезда" << "птица";

//        int randomIndex = qrand() % russianWords.size();
//        QString translation = russianWords[randomIndex];

//        // Отображаем перевод слова
//        translationLabel->setText(translation);
//    }

//private:
//    QLabel *wordLabel;
//    QLabel *translationLabel;
//};

//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);

//    // Задаем случайное начальное значение для генератора случайных чисел
//    qsrand(QTime::currentTime().msec());

//    MainWindow mainWindow;
//    mainWindow.show();

//    return app.exec();
//}

//#include <QtWidgets>
//#include <random>
//#include <vector>
//#include <iostream>
//#include <ctime>

//class ConlangGenerator : public QWidget
//{
//    Q_OBJECT

//public:
//    ConlangGenerator(QWidget *parent = nullptr)
//        : QWidget(parent)
//    {
//        QPushButton *generateButton = new QPushButton("Сгенерировать слова");
//        connect(generateButton, &QPushButton::clicked, this, &ConlangGenerator::generateWords);

//        resultLabel = new QLabel("Нажмите кнопку для генерации");

//        QVBoxLayout *layout = new QVBoxLayout;
//        layout->addWidget(generateButton);
//        layout->addWidget(resultLabel);

//        setLayout(layout);

//        std::random_device rd;  // Получаем случайное устройство
//        gen = std::mt19937(rd());  // Используем генератор случайных чисел mt19937

//        loadDrevnerusskiiDictionary();  // Загрузка словаря древнерусского языка
//        loadRussianDictionary();  // Загрузка словаря русского языка
//    }

//public slots:
//    void generateWords()
//    {
//        std::uniform_int_distribution<> conlangDist(0, drevnerusskiiWords.size()-1);
//        std::uniform_int_distribution<> russianDist(0, russianWords.size()-1);

//        int conlangIndex = conlangDist(gen);
//        int russianIndex = russianDist(gen);

//        QString conlangWord = drevnerusskiiWords[conlangIndex];
//        QString russianWord = russianWords[russianIndex];

//        resultLabel->setText("На конланге: " + conlangWord + "\n" +
//                             "На русском: " + russianWord);
//    }

//private:
//    void loadDrevnerusskiiDictionary()
//    {
//        drevnerusskiiWords = {"слово1", "слово2", "слово3", "слово4", "слово5"}; // Замените на ваш словарь древнерусского языка
//    }

//    void loadRussianDictionary()
//    {
//        russianWords = {"word1", "word2", "word3", "word4", "word5"}; // Замените на ваш словарь русского языка
//    }

//    QLabel *resultLabel;
//    std::mt19937 gen;
//    std::vector<QString> drevnerusskiiWords;
//    std::vector<QString> russianWords;
//};

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    ConlangGenerator generator;
//    generator.show();

//    return a.exec();
//}


//#include <QCoreApplication>
//#include <QDebug>
//#include <QString>
//#include <QChar>
//#include <QList>
//#include <QStringList>
//#include <QRandomGenerator>

//QString generateSyllable()
//{
//    // Гласные буквы русского алфавита
//    QStringList vowels = {"а", "е", "ё", "и", "о", "у", "ы", "э", "ю", "я"};

//    // Согласные буквы русского алфавита
//    QStringList consonants = {"б", "в", "г", "д", "ж", "з", "к", "л", "м", "н",
//                              "п", "р", "с", "т", "ф", "х", "ц", "ч", "ш", "щ"};

//    // Генерация случайного числа от 2 до 4
//    int length = QRandomGenerator::global()->bounded(2, 5);

//    QString syllable;
//    bool hasVowel = false;

//    // Добавление букв в слог
//    for (int i = 0; i < length; ++i)
//    {
//        // Если в слоге еще нет гласной, добавляем гласную
//        if (!hasVowel)
//        {
//            syllable += vowels.at(QRandomGenerator::global()->bounded(vowels.length()));
//            hasVowel = true;
//        }
//        // В противном случае добавляем согласную
//        else
//        {
//            syllable += consonants.at(QRandomGenerator::global()->bounded(consonants.length()));
//        }
//    }

//    return syllable;
//}

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    QList<QString> syllables;

//    // Генерация 10 слогов
//    for (int i = 0; i < 10; ++i)
//    {
//        syllables.append(generateSyllable());
//    }

//    // Вывод сгенерированных слогов
//    qDebug() << "Слоги:";
//    for (const QString &syllable : syllables)
//    {
//        qDebug() << syllable;
//    }

//    return a.exec();
//}

//#include <QCoreApplication>
//#include <QDebug>
//#include <QString>
//#include <QChar>
//#include <QList>
//#include <QStringList>
//#include <QRandomGenerator>

//QString generateSyllable()
//{
//    // Гласные буквы русского алфавита
//    QStringList vowels = {"а", "е", "ё", "и", "о", "у", "ы", "э", "ю", "я"};

//    // Согласные буквы русского алфавита
//    QStringList consonants = {"б", "в", "г", "д", "ж", "з", "к", "л", "м", "н",
//                              "п", "р", "с", "т", "ф", "х", "ц", "ч", "ш", "щ"};

//    // Генерация случайного числа от 2 до 4
//    int length = QRandomGenerator::global()->bounded(2, 5);

//    QString syllable;
//    bool hasVowel = false;

//    // Добавление букв в слог
//    for (int i = 0; i < length; ++i)
//    {
//        // Если в слоге еще нет гласной, добавляем гласную
//        if (!hasVowel)
//        {
//            syllable += vowels.at(QRandomGenerator::global()->bounded(vowels.length()));
//            hasVowel = true;
//        }
//        // В противном случае добавляем согласную
//        else
//        {
//            syllable += consonants.at(QRandomGenerator::global()->bounded(consonants.length()));
//        }
//    }

//    return syllable;
//}

//QString generateWord(int syllableCount)
//{
//    QString word;

//    // Генерация указанного количества слогов
//    for (int i = 0; i < syllableCount; ++i)
//    {
//        word += generateSyllable();
//    }

//    return word;
//}

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    QList<QString> words;

//    // Генерация 10 слов, состоящих из 1-3 слогов
//    for (int i = 0; i < 10; ++i)
//    {
//        int syllableCount = QRandomGenerator::global()->bounded(1, 4);
//        words.append(generateWord(syllableCount));
//    }

//    // Вывод сгенерированных слов
//    qDebug() << "Сгенерированные слова:";
//    for (const QString &word : words)
//    {
//        qDebug() << word;
//    }

//    return a.exec();
//}


//#include <QCoreApplication>
//#include <QDebug>
//#include <QString>
//#include <QChar>
//#include <QList>
//#include <QStringList>
//#include <QRandomGenerator>

//QString generateSyllable()
//{
//    QStringList vowels = {"а", "е", "ё", "и", "о", "у", "ы", "э", "ю", "я"};
//    QStringList consonants = {"б", "в", "г", "д", "ж", "з", "й", "к", "л", "м",
//                              "н", "п", "р", "с", "т", "ф", "х", "ц", "ч", "ш", "щ"};

//    QString syllable;
//    bool hasVowel = false;

//    // Генерируем случайное количество букв от 2 до 4
//    int length = QRandomGenerator::global()->bounded(2, 4);

//    // Добавляем буквы в слог
//    for (int i = 0; i < length; ++i)
//    {
//        // Если в слоге еще нет гласной, добавляем гласную
//        if (!hasVowel)
//        {
//            syllable += vowels.at(QRandomGenerator::global()->bounded(vowels.length()));
//            hasVowel = true;
//        }
//        // Добавляем согласную
//        else
//        {
//            syllable += consonants.at(QRandomGenerator::global()->bounded(consonants.length()));
//        }
//    }

//    return syllable;
//}

//QString generateWord(int syllableCount)
//{
//    QString word;

//    // Генерируем указанное количество слогов
//    for (int i = 0; i < syllableCount; ++i)
//    {
//        word += generateSyllable();
//    }

//    return word;
//}

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    QList<QString> words;

//    // Генерируем 10 слов с 1-3 слогами
//    for (int i = 0; i < 10; ++i)
//    {
//        int syllableCount = QRandomGenerator::global()->bounded(1, 4);
//        words.append(generateWord(syllableCount));
//    }

//    // Выводим сгенерированные слова
//    qDebug() << "Сгенерированные слова:";
//    for (const QString &word : words)
//    {
//        qDebug() << word;
//    }

//    return a.exec();
//}

//#include <QCoreApplication>
//#include <QDebug>
//#include <QString>
//#include <QChar>
//#include <QList>
//#include <QStringList>
//#include <QRandomGenerator>

//QString generateSyllable()
//{
//    QStringList vowels = {"а", "е", "ё", "и", "о", "у", "ы", "э", "ю", "я"};
//    QStringList consonants = {"б", "в", "г", "д", "ж", "з", "й", "к", "л", "м",
//                              "н", "п", "р", "с", "т", "ф", "х", "ц", "ч", "ш", "щ"};

//    QString syllable;
//    int vowelCount = 0;

//    // Генерируем случайное количество букв от 2 до 4
//    int length = QRandomGenerator::global()->bounded(2, 5);

//    // Добавляем буквы в слог
//    for (int i = 0; i < length; ++i)
//    {
//        // Генерируем случайную букву
//        QString letter;
//        if (vowelCount < 2 && QRandomGenerator::global()->bounded(0, 10) < 3)
//        {
//            // Генерируем гласную, если в слоге еще нет двух гласных и с вероятностью 30%
//            letter = vowels.at(QRandomGenerator::global()->bounded(vowels.length()));
//            vowelCount++;
//        }
//        else
//        {
//            // Генерируем согласную
//            letter = consonants.at(QRandomGenerator::global()->bounded(consonants.length()));
//        }

//        syllable += letter;
//    }

//    return syllable;
//}

//QString generateWord(int syllableCount)
//{
//    QString word;

//    // Генерируем указанное количество слогов
//    for (int i = 0; i < syllableCount; ++i)
//    {
//        word += generateSyllable();
//    }

//    return word;
//}

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    QList<QString> words;

//    // Генерируем 10 слов со случайным количеством слогов от 1 до 3
//    for (int i = 0; i < 10; ++i)
//    {
//        int syllableCount = QRandomGenerator::global()->bounded(1, 4);
//        words.append(generateWord(syllableCount));
//    }

//    // Выводим сгенерированные слова
//    qDebug() << "Сгенерированные слова:";
//    for (const QString &word : words)
//    {
//        qDebug() << word;
//    }

//    return a.exec();
//}
