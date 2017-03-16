#ifndef GameBoard_H
#define GameBoard_H
#include "BlackBox.h"
#include <QWidget>
#include <QtGui>
#include<QRect>
#include "preview.h"
#include "block.h"
#include "DisplayZone.h"
class GameBoard:public QWidget{
   Q_OBJECT
public:
   GameBoard(QWidget *parent=0);
   void initialize(BlackBox* GM);
public slots:
  void draw();
 signals:
   void updateScore(int n);
   void updateLevel(int n);
protected:
	void keyPressEvent(QKeyEvent *event);  
private:
  QLabel* paintZone;
  QImage backGround;
  QGridLayout *grid;
  DisplayZone *score;
  DisplayZone *level;
  GameBoard *current;
  QVBoxLayout *rightBox;
  PreviewWindow* preview1;
  BlackBox* GameBack;
  int blocksX[4]={0};
  int blocksY[4]={0};
  int** landedGroup=new int* [20];
  QTimer *timer;

  QColor color[7]={QColor(255,0,0), QColor(0,255,0), QColor(0,0,255),
        QColor(0,128,182), QColor(255,128,128),QColor(255,255,0),
        QColor(0,128,64)};
  void paintLandedBlocks(QPainter *p);
  void setTimer();

  int marks;
  int levels;
  void update(int n);
};





#endif
