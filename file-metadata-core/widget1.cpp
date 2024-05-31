#include "widget1.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QTextEdit>

#include "binary.h"

widget1::widget1(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *lay = new QVBoxLayout;
    e = new QTextEdit;
    QPushButton *b = new QPushButton;
    b->setText("выбрать файл");
    lay->addWidget(b);
    lay->addWidget(e);
    setLayout(lay);

    connect(b, &QPushButton::pressed, this, &widget1::choose_file);
}

void widget1::choose_file()
{
    QFileDialog *pd = new QFileDialog(this);
    connect(pd, &QFileDialog::fileSelected, this, &widget1::parse_file);
    pd->exec();
}

void widget1::parse_file(const QString &path)
{
    static uint _count = 0;
    Binary b(path);
    qDebug() << "Widget: going to parse\n";
    if (b.parse()) {
        qDebug() << "Widget: parsed successfully\n";
        e->clear();
        qDebug() << "Widget: going to show\n";
        b.getData().showOnEdit(e);
        qDebug() << "Widget: ended showing, num" << _count++ << Qt::endl;
    }
    else {
        qDebug() << "Widget: can't open file\n";
    }
}
