#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>
#include <QTextEdit>

class widget1 : public QWidget
{
    Q_OBJECT

    QTextEdit *e;

public:
    explicit widget1(QWidget *parent = nullptr);


private slots:
    void choose_file();

    void parse_file(const QString &path);

};

#endif // WIDGET1_H
