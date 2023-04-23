#ifndef WORLD_H
#define WORLD_H

#include <QString>
#include "entity.h"

using namespace std;

class World
{
public:
    /**
     * @brief World constructor
     * @param worldName
     * @param dimX
     * @param dimY
     * @param texturePath
     */
    World(QString worldName, unsigned int dimX, unsigned int dimY, QString texturePath);
    ~World();
    /**
     * @brief playMusic a music in the world
     * @param filepath of the song
     */
    void playMusic(QString filepath);
    /**
     * @brief Save the world (position of entity, texture...)
     * @fn save
     */
    void save();
    /**
     * @brief Load the world
     * @fn load
     * @param filepath of the file to load
     */
    void load(QString filepath);

private:
    /**
     * @brief displayed name of the world
     */
    QString name;
    /**
     * @brief is the direct path to the texture of a world
     */
    QString texturePath;
    /**
     * @brief dimension X of the World
     */
    int dimX;
    /**
     * @brief dimension Y of the World
     */
    int dimY;
    /**
     * @brief tab of Entity pointers, on the world
     */
    Entity * tab;
};
#endif
