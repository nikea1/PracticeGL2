//
//  sprite.h
//  practiceGL2
//
//  Created by Adenike Adeyemi on 2/23/18.
//  Copyright © 2018 Adenike Adeyemi. All rights reserved.
//

#ifndef sprite_h
#define sprite_h

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>

typedef struct{
    GLfloat x;
    GLfloat y;
}Vector2;

typedef struct{
    void (* setPosition)(Vector2);
    Vector2 (* getPosition)(void);
    void (* render)(void);
    void (* update)(void);
    
} Sprite;

Sprite *initSprite(GLuint, Vector2);
void destroySprite(Sprite *);


#endif /* sprite_h */
