#include "GameBoard.h"
#include "BlackBox.h"
#include <QtGui>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include "DisplayZone.h"
#include <QObject>
#include "preview.h"
#include <unistd.h>
#include "block.h"

GameBoard::GameBoard(QWidget *parent):QWidget(parent),levels(1),marks(0){
  //initialize the data member and set the GUI
   for(int j=0;j<20;j++){
      landedGroup[j]=new int[10];}
   for(int i=0;i<20;i++){

    for(int j=0;j<10;j++){landedGroup[i][j]=0;}
   }
   backGround.load("background.bmp");
   QPainter qPainter(&backGround);
   paintZone=new QLabel();
   paintZone->setPixmap(QPixmap::fromImage(backGround));
   GameBack = new BlackBox();
   score=new DisplayZone();
   level=new DisplayZone();
   score->ini("Score:",0);
   level->ini("Level:",1);
   preview1 = new PreviewWindow();
   //preview1->paintPreview(GameBack->getType(0));
   preview1->show();
   grid= new QGridLayout();
   rightBox=new QVBoxLayout();
   rightBox->addWidget(preview1);
   rightBox->addWidget(level);
   rightBox->addWidget(score);
   grid->addLayout(rightBox,0,1);
   grid->addWidget(paintZone,0,0);
   score->setGeometry(230,370,40,20);
   level->setGeometry(280,370,40,20);
   setLayout(grid);
   timer = new QTimer(this);
   QObject::connect(timer, SIGNAL(timeout()),this,SLOT(draw()));
   timer->start(1000-100*(levels-1));
   QObject::connect(this,SIGNAL(updateScore(int)),score,SLOT(setValue(int)));//establish the connetion so if the score is changed,the displayZone of score will show it
   QObject::connect(this,SIGNAL(updateLevel(int)),level,SLOT(setValue(int)));//establish the connetion so if the score is changed,the displayZone of level will show it

}
void GameBoard::initialize(BlackBox *GM){
  GameBack=GM;
  GameBack->returnXaixs(blocksX);
  GameBack->returnYaixs(blocksY);
}
void GameBoard::draw(){
  if(GameBack->getFlowState()){
    GameBack->move(3);
    update(0);


  }
  else{
    
    update(1);
    GameBack->endGame();
    timer->stop();
  }
}
void GameBoard::update(int n){
  // this function is only to draw accoring to the data from the BlackBox
    QPainter painter;
    backGround.load("background.bmp");
    painter.begin(&backGround);
    if(n==0){
    painter.setBrush(color[GameBack->getType(0)-1]);
    painter.setPen(Qt::black);
      GameBack->returnXaixs(blocksX);
              GameBack->returnYaixs(blocksY);
   
    painter.drawRect(blocksX[0]*20,blocksY[0]*20,20,20);
    painter.drawRect(blocksX[1]*20,blocksY[1]*20,20,20);
    painter.drawRect(blocksX[2]*20,blocksY[2]*20,20,20);
    painter.drawRect(blocksX[3]*20,blocksY[3]*20,20,20);}
    paintLandedBlocks(&painter);
    painter.end();
    preview1->paintPreview(GameBack->getType(1));
    int tempMark=GameBack->gainScore();
    //if the score is changed, it will send signals and change the number in the displayZone
    if(tempMark!=marks){

    marks=tempMark;
    int tempLevel= GameBack->gainLevel();
    if(tempLevel!=levels){
          //if the  level is changed, it will send signals and change the number in the displayZone. And it will set the timer.
         levels=GameBack->gainLevel();
    setTimer();
   
    }
    
   // send the signals so that the displayZone change show updated scores and levels
    emit updateScore(marks);
    emit updateLevel(levels);
    }
  
       paintZone->setPixmap(QPixmap::fromImage(backGround));

}
void GameBoard::paintLandedBlocks(QPainter *p){
  // used to paint the block groups accumulated 
 landedGroup= GameBack->gainBlockGroup();
   for(int i=0; i<20; ++i) {
            for(int j=0; j<10; ++j) {
                if (landedGroup[i][j]>0) {
                    p->setBrush(color[landedGroup[i][j]-1]);
                    p->setPen(Qt::black);
                    p->drawRect(j*20,i*20,20,20);
                }
            }
        }

     

}
void GameBoard::keyPressEvent(QKeyEvent* event){
	//key press event 
    switch (event->key()) {
        case Qt::Key_Down:
        if (GameBack->getFlowState()&&GameBack->move(3))
        {
           
            update(0);
        }
           break;  
        case Qt::Key_Left:
        if (GameBack->getFlowState()&&GameBack->move(1))
        {
            
            update(0);
        }
           break;
        case Qt::Key_Right:
         if (GameBack->getFlowState()&&GameBack->move(2))
        {
             
	     update(0);
            
        }
        break;
        case Qt::Key_Z:
        if (GameBack->getFlowState()&&GameBack->rotate(-1))
        {
             
            update(0);
        }
        break;
        case Qt::Key_X:
        if (GameBack->getFlowState()&&GameBack->rotate(1))
        {      
           update(0);

        } 
        break;
        case Qt::Key_Up:
	  
	     if(!GameBack->getFlowState()) 
        {
	          GameBack->startGame();
            timer->stop();
            timer->start(1000);
            update(0);
            GameBack->endGame();
	         // update(0);
        }
	  break;
        
    }
}
void GameBoard::setTimer(){
    timer->stop();
    timer->start(1000-100*(levels-1));
}

