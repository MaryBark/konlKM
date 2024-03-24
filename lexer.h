#ifndef LEXER_H
#define LEXER_H


#include <QString>
#include <QList>

class Token {
public:
    enum Type {
        WORD,
        PUNCTUATION,
        END
    };

    Token(Type type, const QString& value) : m_type(type), m_value(value) {}

    Type type() const { return m_type; }
    QString value() const { return m_value; }

private:
    Type m_type;
    QString m_value;
};

class Lexer {
public:
    Lexer(const QString& input) : m_input(input), m_pos(0) {}

    Token nextToken() {
        if (m_pos >= m_input.size()) {
            return Token(Token::END, "");
        }

        QChar currentChar = m_input.at(m_pos);

        if (currentChar.isLetterOrNumber()) {
            QString word;
            while (m_pos < m_input.size() && m_input.at(m_pos).isLetterOrNumber()) {
                word.append(m_input.at(m_pos));
                m_pos++;
            }
            return Token(Token::WORD, word);
        } else {
            m_pos++;
            return Token(Token::PUNCTUATION, currentChar);
        }
    }

private:
    QString m_input;
    int m_pos;
};
#endif // LEXER_H
