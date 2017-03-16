 
#ifndef preview_H
#define preview_H
#include <QWidget>
#include <QtGui>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
class PreviewWindow:public QLabel{
public:
  PreviewWindow(QWidget *parent=0);
  void paintPreview(int n);

private:
       QPixmap* temp;
       QImage image;
       QColor color[7]={QColor(255,0,0), QColor(0,255,0), QColor(0,0,255),
        QColor(0,128,182), QColor(255,128,128),QColor(255,255,0),
        QColor(0,128,64)};
};
#endif /* preview_h */
