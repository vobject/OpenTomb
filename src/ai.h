#ifndef AI_H
#define AI_H

#include "entity.h"
#include "path.h"

void AI_UpdateEntity(entity_p entity);
void AI_UpdateWolf(entity_p entity, CPathFinder* path);
void AI_UpdateBear(entity_p entity, CPathFinder* path);

enum tr1Enemy
{
    UNUSED_00,
    UNUSED_01,
    UNUSED_02,
    UNUSED_03,
    UNUSED_04,
    UNUSED_05,
    UNUSED_06,
    WOLF,
    BEAR
};
#endif // AI_H
