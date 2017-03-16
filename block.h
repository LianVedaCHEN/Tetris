 
#ifndef block_H
#define block_H
#include <QWidget>

class Blocks{
    friend class BlackBox;
public:
    Blocks();
    Blocks(int n);
    void sortY();
    int getType();
    int x1,x2,xcenter,x3,y1,y2,y3,ycenter,ymin,ymax;
    int color;//storage the color of this blocks;

    
private:
    
      int type;
    
    
};

#endif 
