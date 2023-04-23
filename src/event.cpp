#include "../include/event.h"

Event::Event(World* worldId,
             int numberOfParticipants,
             Entity* participants,
             QString description)
{
    this->worldId = worldId;
    this->numberOfParticipants = numberOfParticipants;
    this->participants = participants;
    this->description = description;
}

Event::~Event()
{
    this->description = "none";
    this->numberOfParticipants = 0;
    this->participants = nullptr;
    this->worldId = nullptr;
}
