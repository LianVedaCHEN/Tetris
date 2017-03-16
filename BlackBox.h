//
//  tetris.h
//  tetris
//
//  Created by Veda on 16/10/2.
//  Copyright © 2016年 Veda. All rights reserved.
//

#ifndef BlackBox_H
#define BlackBox_H
#include <QWidget>
#include "block.h"

class BlackBox{
public:
    BlackBox();
    ~BlackBox();
    bool landOrNot;//according to this, Qt will determin to repaint the group
    bool getFlowState();
    bool move(int direction);//1 for left,2 for right,3 for down.results let Qt determine the block rotate or not
    bool rotate(int direction);//-1 for clock-rotation 1 for counter-clock. results let Qt determine the block rotate or not
    int gainScore();//Qt gain score from this
    int gainLevel();//Qt gain the level from this and set the autoTimer
   int** const  gainBlockGroup() ;
    void continueGame();
    int gainPreview();
    int* returnXaixs(int* array);
    int* returnYaixs(int* array2);
    int getType(int n);
     void startGame();
      void endGame();

private:
    bool flowState,tempState;
    int mark,level,limit;
  
    int** blockGroup=new int* [20];
    Blocks* currentBlocks;
    Blocks* nextBlocks;
   
  
    bool checkBounds(int var,int var2,int var3,int var4,int var5,int var6,int var7=1,int var8=1);
    bool checkMove(int LR, int Down);
    void changeMove(int LR, int Down);
    bool checkRotate(int clock);
    void changeRotate(int clock);
    Blocks* generateNewBlock(int n);
    void combo(int combo,int* neededDeleted);
    void addBlocksToGroup();
    bool checkFloor();
    void checkRow();
    void land();
    void increaseScore(int comboNum);
    void setLevel(int score);
    
    
};
#endif /* tetris_h */
