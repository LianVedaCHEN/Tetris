#include "preview.h"

#include <QtGui>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QObject>
PreviewWindow::PreviewWindow(QWidget *parent):QLabel(parent){

  QPixmap previewArea(100,200);
   previewArea.fill();
   setPixmap(previewArea);

   setPixmap(previewArea);
   
}
void PreviewWindow::paintPreview(int n){
  //according to the Type of nextBlocks to draw it in the preview window
  int blockx1,blockx2,blockx3,blockxcenter,blocky1,blocky2,blocky3,blockycenter;
    QPainter painter2;

    QPixmap previewArea(100,200);
    previewArea.fill();
    painter2.begin(&previewArea);
    painter2.setBrush(color[n-1]);
    painter2.setPen(Qt::black);
 
     switch(n){
        case 1:{blockx1=6;blockx2=6;blockxcenter=6;blockx3=6;blocky1=0;blocky2=1;blocky3=2;blockycenter=3;break;}
        case 2:{blockx1=5;blockx2=5;blockxcenter=6;blockx3=6;blocky1=2;blocky2=3;blocky3=3;blockycenter=2;break;}
        case 3:{blockx1=5;blockx2=6;blockxcenter=5;blockx3=6;blocky1=1;blocky2=2;blocky3=3;blockycenter=2;break;}
        case 4:{blockx1=6;blockx2=5;blockxcenter=6;blockx3=5;blocky1=1;blocky2=2;blocky3=3;blockycenter=2;break;}
        case 5:{blockx1=5;blockx2=5;blockxcenter=5;blockx3=6;blocky1=1;blocky2=3;blocky3=3;blockycenter=2;break;}
        case 6:{blockx1=6;blockx2=6;blockxcenter=6;blockx3=5;blocky1=1;blocky2=3;blocky3=3;blockycenter=2;break;}
        case 7:{blockx1=5;blockx2=6;blockxcenter=6;blockx3=7;blocky1=3;blocky2=2;blocky3=3;blockycenter=3;break;}
            
    }
    painter2.drawRect(blockx1*20-80,(blocky1+5-blockycenter)*20,20,20);
    painter2.drawRect(blockx2*20-80,(blocky2+5-blockycenter)*20,20,20);
    painter2.drawRect(blockx3*20-80,(blocky3+5-blockycenter)*20,20,20);
    painter2.drawRect(blockxcenter*20-80,(blockycenter+5-blockycenter)*20,20,20);
    
    painter2.end();
    setPixmap(previewArea);
 
}
