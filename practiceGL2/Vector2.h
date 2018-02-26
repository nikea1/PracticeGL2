//
//  Vector2.h
//  practiceGL2
//
//  Created by Adenike Adeyemi on 2/23/18.
//  Copyright © 2018 Adenike Adeyemi. All rights reserved.
//

#ifndef Vector2_h
#define Vector2_h

#include <stdio.h>
#include "GLUT/glut.h"

typedef struct{
    GLfloat x;
    GLfloat y;
}Vector2;

Vector2 makeVector(GLfloat x, GLfloat y);
Vector2 addVector(Vector2 first, Vector2 second);


#endif /* Vector2_h */
