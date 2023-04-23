#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include "entity.h"
#include "world.h"

class Event
{
public:
    /**
     * @brief Constructor of an Event
     */
    Event(World* worldId,
          int numberOfParticipants,
          Entity* participants,
          QString description);
    /**
     * @brief Destructor of an Event
     */
    ~Event();

private:
    /**
     * @brief pointer on the world
     */
    World* worldId;
    /**
     * @brief number of player in the event
     */
    int numberOfParticipants;
    /**
     * @brief tab of all entity in the event
     */
    Entity* participants;
    /**
     * @brief description of the event
     */
    QString description;

};

#endif
