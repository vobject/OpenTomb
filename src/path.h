#ifndef PATH_H
#define PATH_H

#include "render/render.h"///@FIXME room.h wants OpenGL

#include "room.h"
#include "path_node.h"

#include <cstdlib>
#include <vector>

class CPathFinder
{
public:
     CPathFinder();
    ~CPathFinder();

    void InitialiseSearch(room_sector_s* start, room_sector_s* target);///@TODO startSearch? rename?
    void ProcessNode(CPathNode* node);
    CPathNode* GetNextOpenNode();

private:
    std::vector<CPathNode>      m_nodes;                 ///List of all nodes
    std::vector<CPathNode*>     m_openList;              ///Nodes which have to be searched
    std::vector<CPathNode*>     m_closedList;            ///Nodes which have been searched and are now closed
    struct room_s               *m_startRoom;            ///Starting room of search
    struct room_s               *m_targetRoom;           ///target room to reach

    void AddToOpenList(CPathNode* node);
    void AddToClosedList(CPathNode* node);
    void RemoveFromOpenList(CPathNode* node);
    void RemoveFromClosedList(CPathNode* node);
    int  IsInOpenList(CPathNode* node);
    int  IsInClosedList(CPathNode* node);
    CPathNode* GetNodeFromXY(uint16_t x, uint16_t y);
    int  CalculateHeuristic(CPathNode* start, CPathNode* target);
    void GeneratePath(CPathNode* end_node);
    int  IsValidNeighbour(CPathNode* current_node, CPathNode* neighbour_node);
};

#endif // PATH_H
