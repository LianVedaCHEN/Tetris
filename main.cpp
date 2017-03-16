#include <unistd.h>
#include <QtGui>
#include <QLabel>
#include <QApplication>
#include "GameBoard.h"
#include "DisplayZone.h"
#include "BlackBox.h"
#include <QWidget>
#include "block.h"

int main(int argc,char **argv){
        QApplication a(argc, argv);
	GameBoard* w =new GameBoard();
	w->show();
	return a.exec();
}