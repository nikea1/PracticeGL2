//
//  GameWindow.c
//  practiceGL2
//
//  Created by Adenike Adeyemi on 10/21/17.
//  Copyright © 2017 Adenike Adeyemi. All rights reserved.
//

#include "GameWindow.h"
#include "glbmp.h"
#include "sprite.h"
#include "Sprite2.h"
#include "Pet.h"

#define IDLE 0
#define HAPPY 1
#define ANGRY 2
#define SLEEP 3
#define EAT 4
#define ATTACK 5
#define HURT 6

int monster_state;
int old_monster_state;
int change;

int display_width = SCREEN_WIDTH*MODIFIER;
int display_height = SCREEN_HEIGHT*MODIFIER;

GLuint _GWtextureBufferID;
GLuint _GWvertexBufferID;
Sprite *monster;
Sprite2 *monster2;
Pet *monster3;
int timer = 100;
int x_num = 0;
int y_num = 0;
int sign = 1;


//vertex struct
typedef struct{
    GLfloat pos[3];
    GLfloat tex[2];
} VertexData;

//vertex data for a square {(x,y,x), (u,v)}
VertexData vertices[] = {
    {{ -50.0f,-50.0f, 0.0f}, {1.0/8 + 0.0, 0.0 * 1.0/6 + 0.0}},
    {{ -50.0f, 50.0f, 0.0f}, {1.0/8 + 0.0, 0.0 * 1.0/6 + 1.0/6}},
    {{  50.0f, 50.0f, 0.0f}, {1.0/8 + 1.0/8, 0.0 * 1.0/6 + 1.0/6}},
    {{  50.0f,-50.0f, 0.0f}, {1.0/8 + 1.0/8, 0.0 * 1.0/6 + 0.0}}
};

//======================================================================

//initialize texture
GLuint setTexture(){
    GLuint texture;
    //SETUP===============================================
    
    //generate texture bind texture
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    //set parameters for texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    //END OF SETUP========================================
    return texture;
}
//update texture
void updateTexture(const char* filename){
}

//load image into texture
GLuint loadAndBufferImage(const char *filename){
    GLuint texture;
    glBMP img = initGLBMP(filename);
    
    //SETUP===============================================
    
    //generate texture bind texture
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    //set parameters for texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    //END OF SETUP========================================
    
    //determine if alpha channel exists then write pixel data to texture buffer
    if(img.hasAlpha){
         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width, img.height, 0, GL_BGRA, GL_UNSIGNED_BYTE, img.pixelData);
        //printf("Help\n");
       // glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 4, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, img.pixelData);
    }
    else
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.width, img.height, 0, GL_BGR, GL_UNSIGNED_BYTE, img.pixelData);
    
    free(img.pixelData);
    return texture;
  
}

void gamewindowUpdate(){
    
   
            if(timer == 0){
                //determine what frame to pick from sheet
                //x_num picks the frame row
                //(0,0)
                vertices[0].tex[0] = x_num*1.0/8.0 + 0.0;
                vertices[0].tex[1] = y_num*1.0/6.0 + 0.0;
                
                vertices[1].tex[0] = x_num*1.0/8.0 + 0.0;
                vertices[1].tex[1] = y_num*1.0/6.0 + 1.0/6.0;
                
                vertices[2].tex[0] = x_num*1.0/8.0 + 1.0/8.0;
                vertices[2].tex[1] = y_num*1.0/6.0 + 1.0/6.0;
                
                vertices[3].tex[0] = x_num*1.0/8.0 + 1.0/8.0;
                vertices[3].tex[1] = y_num*1.0/6.0 + 0.0;
                
                glBindBuffer(GL_ARRAY_BUFFER, _GWvertexBufferID);
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
                //printf("hi\n");
                timer = 100;
                if(change && monster_state != IDLE){
                    monster3->sprite->_Velocity = makeVector(0.0f, 0.0f);
                    monster3->sprite->_Position = makeVector(210, 120);
                    change = 0;
                }
                else if(change && monster_state == IDLE){
                    monster3->sprite->_Velocity = makeVector(0.5f, 0.0f);
                    change = 0;
                }
                //printf("State is %d", monster_state);
                switch (monster_state) {
                    case IDLE:
                        if(x_num == 1)
                            x_num = 0;
                        else x_num = 1;
                    break;
                   
                    case HAPPY:
                        
                        if(x_num == 1)
                            x_num = 4;
                        else x_num = 1;
                    break;
                        
                    case ANGRY:
                        if(x_num == 1)
                            x_num = 5;
                        else x_num = 1;
                    break;
                     
                    case SLEEP:
                        x_num = 3;
                    break;
                    
                    case EAT:
                        if(x_num == 1)
                            x_num = 2;
                        else x_num = 1;
                    break;
                        
                    case ATTACK:
                        if(x_num == 1)
                            x_num = 6;
                        else x_num = 1;
                    break;
                    case HURT:
                        x_num = 7;
                    break;
                    
                    default:
                        x_num = 1;
                        monster_state = IDLE;
                    break;
                        /**/
                }
            //printf("%i\n", timer);
            
            }timer--;
}

//rendering function
void gamewindowRender(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Draw your stuff here
    //Note: (0,0) is center of window
    //without adjustments to view window
   /*
    glColor3f(1.0f, 0.0f, 0.0f);
    
    
    glLoadIdentity();
    
    //glDrawArrays(GL_QUADS, 0, 4);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, display_height);
    glVertex2f(display_width, display_height);
    glVertex2f(display_width, 0.0f);
    glEnd();
    
    glPushMatrix();
    //glMatrixMode(GL_MODELVIEW);
    glRotatef(30.0, 0.0f, 0.0f, 1.0f);
    
    
    glColor3f(1.0f, 1.0f, 0.0f);
    //can color individual points with this
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 100.0f);
    glVertex2f(100.0f, 100.0f);
    glVertex2f(100.0f, 0.0f);
    glEnd();
    glPopMatrix();
    */
    
    
     //glPushMatrix();
     
     //glTranslatef(xcenter, ycenter, 0);
     //glRotatef(10.0, 0.0, 0.0, 1.0);
     //glTranslatef(-xcenter, -ycenter, 0);
     
     //glPopMatrix();
    
    
    //End of drawing
    
    //monster2->render();
    //gamewindowUpdate();
    //monster->update();
    
    //sprite2Render(monster2);
    //sprite2Update(monster2);
    
    //monster2->render(monster2);
    //monster2->update(monster2);
    
    monster3->sprite->render(monster3->sprite);
    monster3->update(monster3);
    gamewindowUpdate();
    //swap buffers
    glutSwapBuffers();
}

//update function


//initialize gamewindow struct information
GameWindow *initGameWindow(){
    GameWindow *gw = malloc(sizeof(*gw));
    
    gw->render = gamewindowRender;
    gw->update = gamewindowUpdate;
    //end of initializing Game Window struct
    
    //begin initiallizing OPENGL
    
    //clears the screen with white background
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    //allows textures
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    //Adjust view window
    glMatrixMode(GL_PROJECTION);
    
    //ortho2d shifts 2D plain view
    gluOrtho2D(0, display_width, 0, display_height);
    glMatrixMode(GL_MODELVIEW);
    
    //generate buffers, bind BUFFERS!!!, load data
    glGenBuffers(1, &_GWvertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _GWvertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    //enable vertex array
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(VertexData), (GLvoid *)offsetof(VertexData, pos));
    
    //enables texture array
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, sizeof(VertexData), (GLvoid *)offsetof(VertexData, tex));
    
    //define image texture
    _GWtextureBufferID = loadAndBufferImage("testsheet.bmp");

    //define pet object
    monster_state = IDLE;
    old_monster_state = IDLE;
    change = 0;
    Vector2 monPos;
    monPos.x = 210;
    monPos.y = 120;
    monster3 = initPet(_GWtextureBufferID, monPos);
    monster3->sprite->_Velocity = makeVector(0.5f, 0.0f);
    monster3->_boundingbox = makeBoundingBox(display_height, 0, 0, display_width);
    return gw;
}

int getMonsterLvl(void){
    return y_num;
}

void setMonsterLvl(int lvl){
    y_num = lvl;
}

int getMonsterState(void){
    return monster_state;
}

void setMonsterState(int state){
    old_monster_state = monster_state;
    monster_state = state;
    change = 1;
}

//destroy struct
void destroyGameWindow(GameWindow *gw){
    destroySprite(monster);
    destroySprite2(monster2);
    destroyPet(monster3);
    free(gw);
}
