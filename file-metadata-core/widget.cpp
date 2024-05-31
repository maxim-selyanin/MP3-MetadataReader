#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget1)
{
    ui->setupUi(this);
    setAcceptDrops(true);

    QFileDialog *d = new QFileDialog(this);
    connect(d, &QFileDialog::fileSelected, this, &Widget::parseFile);
    d->exec();
}

Widget::~Widget() {
    delete ui;
}

void Widget::dragEnterEvent(QDragEnterEvent *e) {
    qDebug() << "dragEnterEvent\n";
    if (e->mimeData()->hasText()) {
        qDebug() << "Widget: got path\n";
        parseFile(e->mimeData()->text().remove(0,7));
    }
    else {
        qDebug() << "no text\n";
    }
}

void Widget::dropEvent(QDropEvent *)
{
    qDebug() << "aa";
}

void Widget::parseFile(const QString &path) {
    static uint _count = 0;
    Binary b(path);
    qDebug() << "Widget: going to parse\n";
    if (b.parse()) {
        qDebug() << "Widget: parsed successfully\n";
        ui->textEdit->clear();
        qDebug() << "Widget: going to show\n";
        b.getData().showOnEdit(ui->textEdit);
        qDebug() << "Widget: ended showing, num" << _count++ << Qt::endl;
    }
    else {
        qDebug() << "Widget: can't open file\n";
    }
}
