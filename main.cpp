#include "canvasconnection.h"
#include <QCoreApplication>
using namespace std;

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    canvasConnection A;
    canvasConnection B;
    canvasConnection C;
  //A.sendRequest("http://www.yafeilinux.com");
    B.sendRequest("http://ip.jsontest.com/");
   // C.sendRequest("https://google.com");
    return a.exec();
}

