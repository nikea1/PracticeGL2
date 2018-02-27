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
#include "Sprite2.h"
#include "BoundingBox.h"

typedef struct Pet{
    BoundingBox _boundingbox;
    Sprite2 *sprite;
    void (* update)(struct Pet*);
   
    
}Pet;

Pet *initPet(GLuint textureBufferID, Vector2 position);

void destroyPet(Pet*);


#endif /* Pet_h */
