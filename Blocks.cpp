//
//  Blocks.cpp
//  tetris
//
//  Created by Veda on 16/10/3.
//  Copyright © 2016年 Veda. All rights reserved.
//

#include "BlackBox.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include "block.h"
Blocks::Blocks(){
   x1=5;x2=5;xcenter=6;x3=6;y1=2;y2=3;y3=3;ycenter=2;ymin=2;ymax=3;
    type=2;
}
Blocks::Blocks(int n):type(n){
    switch(n){
        case 1:{x1=5;x2=5;xcenter=5;x3=5;y1=0;y2=1;y3=3;ycenter=2;ymin=0;ymax=3;break;}
        case 2:{x1=4;x2=4;xcenter=5;x3=5;y1=2;y2=3;y3=3;ycenter=2;ymin=2;ymax=3;break;}
        case 3:{x1=5;x2=6;xcenter=5;x3=6;y1=1;y2=2;y3=3;ycenter=2;ymin=1;ymax=3;break;}
        case 4:{x1=6;x2=6;xcenter=5;x3=5;y1=1;y2=2;y3=3;ycenter=2;ymin=1;ymax=3;break;}
        case 5:{x1=5;x2=5;xcenter=5;x3=6;y1=1;y2=3;y3=3;ycenter=2;ymin=1;ymax=3;break;}
        case 6:{x1=5;x2=5;xcenter=5;x3=4;y1=1;y2=3;y3=3;ycenter=2;ymin=1;ymax=3;break;}
        case 7:{x1=4;x2=5;xcenter=5;x3=6;y1=2;y2=1;y3=2;ycenter=2;ymin=1;ymax=2;break;}
            
    }
}
int Blocks::getType(){
    return type;
}
void Blocks::sortY(){
    int y[4];
    y[0]=ycenter;
    y[1]=y1;
    y[2]=y2;
    y[3]=y3;
    std::sort(y,y+4);
   ymax=y[3];
   ymin=y[0];
  
}


