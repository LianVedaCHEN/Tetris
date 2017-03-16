 This projected is finished by CHEN,Lian and Liu,Heshan
 CHEN,Lian's information
 Student ID:20328991
 ITSC: lchenbk
 
 LIU Heshan's information
 Student ID:20329141	
 ITSC: hliuav
 
 The whole program should be run in linux with the QT4’s support. If you install QT4 in your linux computer, you can use make to get executable program. 
 
 
 The program is made up of several classes, including class BlackBox, class Blocks, class GameBoard, class DisplayZone and class PreviewWindow.
 
 The UI part and core component part is seperated.
 
 The core component part includes class BlackBox, class Blocks.
 
 the class Block is served as data structure in BlackBox to store related information about blocks.
 the class BlackBox have several functions. The move(int n) is to check whether the block can move or not and if it can move, it will change the data of position.
 It used the function checkMove() to check and if it is Ok, it change the data by changeMove().There is an array called blockGroup to store the infomation about the blocks accumulated. 
 If it found it can not move due to it collide with the blockGroup,  it will call the function land() which add itself into the group by addedIntoGroup()
 and check whether it can comboed. If the rows can be comboed, it will delete them and change the score. During this process, if BlackBox found it can not combo and the 
 topest one coliide with the upper boundaries, it will end the game.
 The rotate() function is to to check whether the block can be rotated or not and if it can rotate, it will change the data of position.
  It used the function checkRotate() to check and if it is Ok, it change the data by changeRotate();
 Every time new blocks landed, it will be added into the blockGroup.

 
 The UI part includes  class GameBoard, class DisplayZone and class PreviewWindow. The preview window is used to construct a object that user can see the 
 next blocks. The displayZone class is to provide objects to show the mark and level. 
 The GameBoard part is the most important component of UI part.
 It contains a object of BlackBox called GameBack. GameBack stores all the infomation and oprate the the flow of the game.
 The object of it is to play the game by drawing graphics. But it only gain necessary information from the GameBack and draw. Every 1 second, it will call a function draw().
 This function use the interface  provided by GameBack to know the positions of falling blocks and draw it. It also draw the accumulated blocks by reading the
 the array copied from BlackBox. But the object of it can not change any data of GameBack. The object of GameBoard will send signals to change the scores and levels if it found they are changed.
