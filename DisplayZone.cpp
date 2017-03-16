
#include "DisplayZone.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QtGui>
#include <QWidget>

DisplayZone::DisplayZone(QWidget *parent,const char*name):QWidget(parent){
  l1 = new QLabel();
  l2 = new QLabel(); 

Hlayout = new QHBoxLayout(parent);
  Hlayout->addWidget(l1);
  Hlayout->addWidget(l2);
  this->setLayout(Hlayout);
  
};
void DisplayZone::setValue(int n){
  l2->setNum(n);
}

 void DisplayZone::ini(char* string,int n){
   l1->setText(string);
   l2->setNum(n);
 }