#include "todo.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    QSplashScreen * splash_screen = new QSplashScreen;
    splash_screen->setPixmap(QPixmap("/usr/share/pixmaps/todo-console.png"));
    splash_screen->show();

    Todo w;
    QTimer::singleShot(1500, splash_screen, SLOT( close() ));
    QTimer::singleShot(1500, &w, SLOT( show() ));

    return a.exec();
}
