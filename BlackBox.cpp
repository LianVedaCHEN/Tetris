
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "BlackBox.h"
#include <unistd.h>
#include "block.h"
BlackBox::BlackBox():flowState(false),mark(0),level(1),limit(19),landOrNot(false),currentBlocks(generateNewBlock(1)),nextBlocks(generateNewBlock(2)){
  //constructor to initialize the BlackBox
    for(int j=0;j<20;j++){
      blockGroup[j]=new int[10];
     
    } 
    for(int i=0;i<20;i++){
       for(int j=0;j<10;j++){
         blockGroup[i][j]=0;
    
       }
    }
}
BlackBox::~BlackBox(){
  //destructor to prevent memory leak
    delete currentBlocks;
    delete  nextBlocks;
}
int BlackBox::gainPreview(){
    return nextBlocks->getType();
}
void BlackBox::startGame(){
   //change the state to strat
    flowState=true;
    delete nextBlocks;
    currentBlocks=generateNewBlock(1);
    nextBlocks=generateNewBlock(2);
 
}
void BlackBox::continueGame(){
if(flowState&&landOrNot){
    delete currentBlocks;
    currentBlocks=nextBlocks;
    nextBlocks=generateNewBlock(2);
    }
   
}
void BlackBox::endGame(){

   //end the game
    //nextBlocks=currentBlocks;
    for(int i=0;i<20;i++){
       for(int j=0;j<10;j++){
         blockGroup[i][j]=0;
    
       }
     }
    mark=0;
    level=1;
    limit=19;
    landOrNot=false;
}
bool BlackBox::getFlowState(){
    return flowState;
}
bool BlackBox::checkBounds(int var,int var2,int var3,int var4,int var5,int var6,int var7,int var8){
  //use to check whether it collide with the boundaries
    bool tempBool=false;
    if(var>=0&&var<=9&&var2>=0&&var2<=9&&var3>=0&&var3<=9&&var4<=19&&var5<=19&&var6<=19&&var7>=0&&var7<=9&&var8<=19)
        tempBool=true;
    return tempBool;
}
bool BlackBox::checkMove(int LR, int Down){
    int newx1,newx2,newxcenter,newx3,newy1,newy2,newy3,newycenter;
    bool isEmpyt=false;
    newxcenter=currentBlocks->xcenter+LR;
    newycenter=currentBlocks->ycenter+Down;
    newx1=currentBlocks->x1+LR;
    newy1=currentBlocks->y1+Down;
    newx2=currentBlocks->x2+LR;
    newy2=currentBlocks->y2+Down;
    newx3=currentBlocks->x3+LR;
    newy3=currentBlocks->y3+Down;
    if(newycenter<=19&&newy1<=19&&newy2<=19&&newy3<=19&&newx1>=0&&newx1<=9&&newx2>=0&&newx2<=9&&newx3>=0&&newx3<=9&&newxcenter>=0&&newxcenter<=9&&newycenter>=0&&newy1>=0&&newy2>=0&&newy3>=0){
    if((blockGroup[newycenter][newxcenter]<1)&&(blockGroup[newy1][newx1]<1)&&(blockGroup[newy2][newx2]<1)&&(blockGroup[newy3][newx3]<1)&&checkBounds(newx1,newx2,newx3,newy1,newy2,newy3,newxcenter,newycenter)){
        isEmpyt=true;
    }
    else isEmpyt=false;
    }
    else isEmpyt=false;
    return isEmpyt;
}
void BlackBox::changeMove(int LR, int Down){
    currentBlocks->x1+=LR;
    currentBlocks->y1+=Down;
    currentBlocks->x2+=LR;
    currentBlocks->y2+=Down;
    currentBlocks->x3+=LR;
    currentBlocks->y3+=Down;
    currentBlocks->xcenter+=LR;
    currentBlocks->ycenter+=Down;
    
}
bool BlackBox::move(int direction){
  //this function is used to change the position data.It will call the checkMove() to check and if it is Ok, it will cahnge the position data
    bool isMovable=false;
    int LR,UD;
   
    if(direction==1){
        LR=-1;
	if(currentBlocks->getType()==1&&currentBlocks->ycenter==2){UD=0;}
	else {UD=0;}
    }
    else if(direction==2){
        LR=1;
	if(currentBlocks->getType()==1&&currentBlocks->ycenter==2){UD=0;}
	else {UD=0;}
    }
    else if(direction==3){
       LR=0;UD=1;
     
    }
    else if(direction==4){
      LR=0;UD=-1;
    }
  
    isMovable=checkMove(LR,UD);
    if(isMovable){
 
        changeMove(LR,UD);

	   
    }
    else { 
        if(direction==3){
	
            land();
	  
	      landOrNot=true;
         
        }
    }
 
    return isMovable;
}
bool BlackBox::checkRotate(int clock){
    int newx1=currentBlocks->x1,newx2=currentBlocks->x2,newx3=currentBlocks->x3,newy1=currentBlocks->y1,newy2=currentBlocks->y2,newy3=currentBlocks->y3;
    bool isEmpyt=false;
    newx1=-1*clock*(currentBlocks->y1-currentBlocks->ycenter)+currentBlocks->xcenter;
    newy1=clock*(currentBlocks->x1-currentBlocks->xcenter)+currentBlocks->ycenter;
    newx2=-1*clock*(currentBlocks->y2-currentBlocks->ycenter)+currentBlocks->xcenter;
    newy2=clock*(currentBlocks->x2-currentBlocks->xcenter)+currentBlocks->ycenter;
    newx3=-1*clock*(currentBlocks->y3-currentBlocks->ycenter)+currentBlocks->xcenter;
    newy3=clock*(currentBlocks->x3-currentBlocks->xcenter)+currentBlocks->ycenter;
    if(newy1<=19&&newy2<=19&&newy3<=19&&newx1>=0&&newx1<=9&&newx2>=0&&newx2<=9&&newx3>=0&&newx3<=9&&newy1>=0&&newy2>=0&&newy3>=0){
    if((blockGroup[newy1][newx1]==0)&&(blockGroup[newy2][newx2]==0)&&(blockGroup[newy3][newx3]==0)&&checkBounds(newx1,newx2,newx3,newy1,newy2,newy3)){
        isEmpyt=true;
    }
    else isEmpyt=false;}
    else isEmpyt=false;
    return isEmpyt;
}
void BlackBox::changeRotate(int clock){
  int tempx1=currentBlocks->x1,tempy1=currentBlocks->y1,tempx2=currentBlocks->x2,tempy2=currentBlocks->y2,tempx3=currentBlocks->x3,tempy3=currentBlocks->y3;
   currentBlocks->x1=-1*clock*(tempy1-currentBlocks->ycenter)+currentBlocks->xcenter;
   currentBlocks->y1=clock*(tempx1-currentBlocks->xcenter)+currentBlocks->ycenter;
   currentBlocks->x2=-1*clock*(tempy2-currentBlocks->ycenter)+currentBlocks->xcenter;
   currentBlocks->y2=clock*(tempx2-currentBlocks->xcenter)+currentBlocks->ycenter;
   currentBlocks->x3=-1*clock*(tempy3-currentBlocks->ycenter)+currentBlocks->xcenter;
   currentBlocks->y3=clock*(tempx3-currentBlocks->xcenter)+currentBlocks->ycenter;

}
bool BlackBox::rotate(int direction){
     //this function is used to change the position data by rotating.It will call the checkRotate() to check and if it is Ok, it will change the position data
    bool isRotatable=false;
    isRotatable=checkRotate(direction);
    if(isRotatable){
        changeRotate(direction);
    }
    return isRotatable;
}
void BlackBox::addBlocksToGroup(){
  
    int blockColor=currentBlocks->type;
    blockGroup[currentBlocks->ycenter][currentBlocks->xcenter]=blockColor;
    blockGroup[currentBlocks->y1][currentBlocks->x1]=blockColor;
    blockGroup[currentBlocks->y2][currentBlocks->x2]=blockColor;
    blockGroup[currentBlocks->y3][currentBlocks->x3]=blockColor;
    currentBlocks->sortY();

}
void BlackBox::combo(int combo,int* neededDeleted){
  //aording to the result of checkRow(), it will deleted the full row and increase the mark;
    int count=combo;
    for(int i=neededDeleted[0];i>=0;i--){
        
      if(i==neededDeleted[combo-count]){
          count=count-1;
	
           
        }
      else{
        for(int j=0;j<10;j++){
            blockGroup[i+combo-count][j]=blockGroup[i][j];
        }
      }
    }
    for(int i=0;i<combo;i++){
        blockGroup[i][0]=0;blockGroup[i][1]=0;blockGroup[i][2]=0;blockGroup[i][3]=0;blockGroup[i][4]=0;blockGroup[i][5]=0;blockGroup[i][6]=0;blockGroup[i][7]=0;blockGroup[i][8]=0;blockGroup[i][9]=0;
    }
    increaseScore(combo);
}
bool BlackBox::checkFloor(){
  //this function is to check whether the topest one is collided with the boundaries
    bool tempFloor=false;
    int count=0;
    if(getType(0)==2||getType(0)==7){
    count=2;
    }
    else count=2;
    for(int i=0;i<count;i++){
      for(int j=0;j<10;j++){
          if(blockGroup[i][j]!=0){
	  tempFloor=true;}
	
      }
    }
    if(tempFloor){
     
      flowState=false;
	addBlocksToGroup();
        return true;
    }
         
    else {continueGame();return false;}//no collision with the floor
}
void BlackBox::checkRow(){
    int minRow=currentBlocks->ymin;
    int maxRow=currentBlocks->ymax;
    int deletedRows[4]={0,0,0,0};
    int comboTimes=0;
    bool comboOrNot=false;
    //It checks the rows affected by the new landed block. If those rows become full, it will delete those rows 
    for(int i=maxRow;i>=minRow;i--){
        bool isFull=true;
        for(int j=0;j<10;j++){
            if(blockGroup[i][j]<1) isFull=false;
	 
        }
        if(isFull){
            deletedRows[comboTimes]=i;
            comboTimes+=1;
            comboOrNot=true;//if one row can be deleted, it will not meet the floor
          
        }
    }
    if(comboOrNot){
        combo(comboTimes,deletedRows);
	continueGame(); 
    }
    else{
       checkFloor();

	
       
    }

}
void BlackBox::increaseScore(int comboNum){
    // increase the score
    mark= mark+10 * comboNum * comboNum;
    setLevel(mark);
}
void BlackBox::setLevel(int score){
   // increase the level
    level=score/100+1;
}
Blocks* BlackBox::generateNewBlock(int n){
    //generate the new block and return it 
    srand((unsigned)time(NULL)+10);
    Blocks* tempBlock= new Blocks(n*(rand()/3)%7+1);
    /* if(tempBlock->type==getType(0)&&getType(0)==getType(1)){
    delete tempBlock;
    tempBlock= new Blocks((rand()/4)%7);
    }*/
   //to check whether the new generated one is the same as currentBlocks and nextBlocks
    return tempBlock;
}

void BlackBox::land(){
  // check whether it can be comboed 
    addBlocksToGroup();
    checkRow();
  
}
int** const BlackBox::gainBlockGroup(){
  // return the blockGroup to GameBoard so that it can draw. But this can not be modified by GameBoard
    return blockGroup;
}
int* BlackBox::returnXaixs(int* array){
  // copy the X aixses to Gameboard so GameBoard can draw them
  array[0]=currentBlocks->xcenter;
  array[1]=currentBlocks->x1;
  array[2]=currentBlocks->x2;
  array[3]=currentBlocks->x3;
}
int* BlackBox::returnYaixs(int* array2){
  // copy the X aixses to Gameboard so GameBoard can draw them
  array2[0]=currentBlocks->ycenter;
  array2[1]=currentBlocks->y1;
  array2[2]=currentBlocks->y2;
  array2[3]=currentBlocks->y3;
}
int BlackBox::getType(int n){
  //let GameBoard to know the type of currentBlocks and nextBlocks
  switch(n){
  case 0: return currentBlocks->getType();break;
  case 1: return nextBlocks->getType();break;
  }
}
int BlackBox::gainScore(){
 return mark;
}
int BlackBox::gainLevel(){
 return level;
}

