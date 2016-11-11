#include "canvasconnection.h"
#include <QCoreApplication>
using namespace std;

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    canvasConnection A;
    canvasConnection B;
    canvasConnection C;
    A.sendRequest("http://www.yafeilinux.com");
    B.sendRequest("https://canvas.instructure.com/api/v1/courses?access_token=1030~y2v695pyuP5tf7SbJVuosakVODI0LyqrA5MXFWgJYscYmgOSL3VqXezUdOSyMYxL");
    C.sendRequest("https://google.com");
    return a.exec();
}

