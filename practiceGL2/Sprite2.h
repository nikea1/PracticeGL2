//
//  Sprite2.h
//  practiceGL2
//
//  Created by Adenike Adeyemi on 2/26/18.
//  Copyright © 2018 Adenike Adeyemi. All rights reserved.
//

#ifndef Sprite2_h
#define Sprite2_h

#include <stdio.h>
#include <GLUT/GLUT.h>
#include "Vector2.h"

typedef struct Sprite2{
    GLuint _TextureBufferID;
    Vector2 _Position;
    Vector2 _Velocity;
    void (* render)(struct Sprite2*);
    void (* update)(struct Sprite2*);
    
} Sprite2;

Sprite2 *initSprite2(GLuint textureBufferID, Vector2 position);
/* */
#endif /* Sprite2_h */
