//
//  main.c
//  practiceGL2
//
//  Created by Adenike Adeyemi on 10/21/17.
//  Copyright © 2017 Adenike Adeyemi. All rights reserved.
//

#include <stdio.h>
#include <GLUT/glut.h>
#include "GameWindow.h"



GameWindow *gw;

void processSpecialKeys(unsigned char ch, int xx, int yy){
    int check;
    int state;
    check = getMonsterLvl();
    state = getMonsterState();
    printf("check is: %d\n", check);
    
    switch (ch) {
        case GLUT_KEY_LEFT:
            if(state > 0){
                state--;
                setMonsterState(state);
            }
            break;
            
        case GLUT_KEY_RIGHT:
            if(state < 7){
                state++;
                setMonsterState(state);
            }
            break;
            
        case GLUT_KEY_UP:
            if(check < 5){
                check++;
                printf("check is: %d\n", check);
                setMonsterLvl(check);
            }
            break;
            
        case GLUT_KEY_DOWN:
            if(check > 0){
                check--;
                printf("check is: %d\n", check);
                setMonsterLvl(check);
            }
            break;
            
        default:
            break;
    }
}
void processNormalKeys(unsigned char ch, int xx, int yy){
    
    switch(ch){
        case 27:
            destroyGameWindow(gw);
            
            exit(0);
            break;
    }
}

int main(int argc, const char * argv[]) {
    
    
    
    //initialize window through GLUT
    glutInit(&argc, argv);
    glutInitWindowSize(display_width, display_height);
    glutInitWindowPosition(320, 320);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Practice2");
    
    //load GameWindow struct
    gw = initGameWindow();
    
    //start define render function
    glutDisplayFunc(*(gw->render));
    glutIdleFunc(*(gw->render));
    //define button commands
    glutKeyboardFunc(processNormalKeys);
    glutSpecialUpFunc(processSpecialKeys);
    
    printf("Hello, World!\n");
    
    //run glut loop
    glutMainLoop();
    return 0;
}
