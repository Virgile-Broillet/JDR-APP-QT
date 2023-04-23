#include "../include/world.h"

World::World(QString worldName, unsigned int dimX, unsigned int dimY, QString texturePath)
{
    this->name = worldName;
    this->dimX = dimX;
    this->dimY = dimY;
    this->texturePath = texturePath;
}
World::~World()
{
    this->name = "Untitled World";
    this->dimX = 1;
    this->dimY = 1;
    this->texturePath = "none";
}
/*
void World::playMusic(QString filepath)
{

}
void World::save()
{

}
void World::load(QString filepath)
{

}
*/
