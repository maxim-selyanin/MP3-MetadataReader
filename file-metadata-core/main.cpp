#include "widget.h"
#include "widget1.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    widget1 widget;
    widget.show();
    return app.exec();
}
