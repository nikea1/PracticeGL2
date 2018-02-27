//
//  Pet.h
//  practiceGL2
//
//  Created by Adenike Adeyemi on 2/26/18.
//  Copyright © 2018 Adenike Adeyemi. All rights reserved.
//

#ifndef Pet_h
#define Pet_h

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>
#include "Vector2.h"


typedef struct Pet{
    void (* setPosition)(Vector2);
    Vector2 (* getPosition)(void);
    void (* setVelocity)(Vector2);
    Vector2 (* getVelocity)(void);
    void (* render)(void);
    void (* update)(void);
    
} Pet;

Pet *initPet(GLuint, Vector2);
void destroyPet(Pet *);




#endif /* Pet_h */
