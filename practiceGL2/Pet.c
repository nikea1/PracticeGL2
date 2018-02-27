//
//  Pet.c
//  practiceGL2
//
//  Created by Adenike Adeyemi on 2/26/18.
//  Copyright © 2018 Adenike Adeyemi. All rights reserved.
//

#include "Pet.h"
#include <stdlib.h>



void petUpdate(Pet *self){
    
    //pet moves left and right in window.
    if(self->sprite->_Position.x <= self->_boundingbox.left || self->sprite->_Position.x >= self->_boundingbox.right){
         self->sprite->_Velocity.x *= -1.0;
    }

    
    self->sprite->update(self->sprite);
}

Pet *initPet(GLuint textureBufferID, Vector2 position){
    Pet *out = NULL;
    out = malloc(sizeof(*out));
    out->sprite = initSprite2(textureBufferID, position);
    
    out->update = petUpdate;
    
    //out->setBoundingBox = petSetBoundingBox;
    
    return out;
}

void destroyPet(Pet* pet){
    free(pet->sprite);
    free(pet);
}
