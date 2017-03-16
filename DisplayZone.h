 
#ifndef DisplayZone_H
#define DisplayZone_H
 
#include <QWidget>
#include <QtGui>
class DisplayZone:public QWidget{
  Q_OBJECT
public:
  DisplayZone(QWidget *parent=0,const char*name=0);
   void ini(char* string,int n);
public slots:
 void setValue(int n);

private:
  int valueStored;
   QLabel* l1;
   QLabel* l2;
   QHBoxLayout *Hlayout ;

   
};




#endif