#pragma once
#include "binary.h"

namespace Ui {
class Widget1;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    virtual void dragEnterEvent(QDragEnterEvent *) override;
    virtual void dropEvent(QDropEvent *) override;

private slots:
    void parseFile(const QString &);

public:
    virtual ~Widget() override;

private:
    Ui::Widget1 *ui;
};
