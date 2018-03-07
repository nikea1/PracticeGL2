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

 int display_width = SCREEN_WIDTH*MODIFIER;
 int display_height = SCREEN_HEIGHT*MODIFIER;

GLuint _GWtextureBufferID;
GLuint _GWvertexBufferID;
Sprite *monster;
Sprite2 *monster2;
Pet *monster3;


//vertex struct
typedef struct{
    GLfloat pos[3];
    GLfloat tex[2];
} VertexData;

//vertex data for a square {(x,y,x), (u,v)}
VertexData vertices[] = {
    {{ -50.0f, -50.0f, 0.0f}, {0.0, 0.0}},
    {{ -50.0f, 50.0f, 0.0f}, {0.0, 1.0}},
    {{50.0f, 50.0f, 0.0f}, {1.0, 1.0}},
    {{50.0f,   -50.0f, 0.0f}, {1.0, 0.0}}
};

//load image into texture
GLuint loadAndBufferImage(const char *filename){
    GLuint texture;
    glBMP img = initGLBMP(filename);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    if(img.hasAlpha)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width, img.height, 0, GL_BGRA, GL_UNSIGNED_BYTE, img.pixelData);
    else
       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.width, img.height, 0, GL_BGR, GL_UNSIGNED_BYTE, img.pixelData);

    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    //free(data);
    free(img.pixelData);
    return texture;
 
    
   
}

void gamewindowUpdate(){
    //monster->update();
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
    
    _GWtextureBufferID = loadAndBufferImage("testA.bmp");

    
    Vector2 monPos;
    monPos.x = 210;
    monPos.y = 120;
    monster3 = initPet(_GWtextureBufferID, monPos);
    monster3->sprite->_Velocity = makeVector(0.5f, 0.0f);
    monster3->_boundingbox = makeBoundingBox(display_height, 0, 0, display_width);
    return gw;
}

//destroy struct
void destroyGameWindow(GameWindow *gw){
    destroySprite(monster);
    destroySprite2(monster2);
    destroyPet(monster3);
    free(gw);
}
