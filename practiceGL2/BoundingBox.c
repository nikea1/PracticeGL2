//
//  BoundingBox.c
//  practiceGL2
//
//  Created by Adenike Adeyemi on 2/26/18.
//  Copyright © 2018 Adenike Adeyemi. All rights reserved.
//

#include "BoundingBox.h"

BoundingBox makeBoundingBox(int top, int bottom, int left, int right){
    BoundingBox out;
    out.top = top;
    out.bottom = bottom;
    out.left = left;
    out.right = right;
    
    return out;
}
