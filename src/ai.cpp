#include "engine.h"
#include "entity.h"
#include "ai.h"
#include "world.h"
#include "skeletal_model.h"
#include "core/console.h"
#include "vt/tr_versions.h"
#include "mesh.h"
#include "room.h"
#include "path.h"

/*
 * Updates specific entity
 */

void AI_UpdateEntity(entity_p entity)
{
    uint32_t meshType = 0;
    entity_p targetEntity = World_GetPlayer();

    ///@TODO Only supporting TR1
    if(World_GetVersion() != TR_I)
    {
        return;
    }

    //We can only continue if entity and targetEntity are valid entities.
    if((entity != NULL) && targetEntity != NULL) //&& (entity != World_GetPlayer()))///@TODO and activated
    {
        ///@HACK Critical! AI loop should only be called when World is fully prepared!
        if(entity->bf == NULL) return;
        if(entity->bf->animations.model == NULL) return;

        meshType = entity->bf->animations.model->id;
        ///@TODO We only process 1 room right now
        if(entity->self->room->id != targetEntity->self->room->id)
        {
           return;
        }

        switch(meshType)
        {
    case tr1Enemy::WOLF:
        {
            CPathFinder* pathFinder = NULL;
            pathFinder = new CPathFinder();
            pathFinder->InitialiseSearch(entity->current_sector, targetEntity->current_sector);
            ///@TODO Pass path sector node to AI_Update* That is where we will move the entity
            AI_UpdateWolf(entity, pathFinder);
            delete pathFinder;
        }
        break;
    case tr1Enemy::BEAR:
        {
            CPathFinder* pathFinder = NULL;
            pathFinder = new CPathFinder();
            pathFinder->InitialiseSearch(entity->current_sector, targetEntity->current_sector);
            ///@TODO Pass path sector node to AI_Update* That is where we will move the entity
            AI_UpdateBear(entity, pathFinder);
            delete pathFinder;
        }
        break;
    default:
        //Nothing
        break;
        }
    }
}

///@TODO
void AI_UpdateWolf(entity_p entity, CPathFinder* path)
{
    if(entity != NULL)
    {

    }
}

///@TODO
void AI_UpdateBear(entity_p entity, CPathFinder* path)
{
    if(entity != NULL)
    {

    }
}
