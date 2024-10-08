#pragma once

#include "../Managers/InputManager.h"
#include "../Managers/CollisionManager.h"
#include "../Entities/Characters/Player.h"

#include "../States/State.h"
using namespace States;

#include "../Observers/PlayerInputObserver.h"
using namespace Observers;

#include "../Utils/EntityList.h"
using namespace Lists;

namespace Levels
{
    class Level : public Being, public State 
    {
    protected:
        sf::Clock clock;
        float dt;

        Managers::InputManager* pIM;
        Managers::CollisionManager* pCM;
        Observers::PlayerInputObserver* pPIO;

        static unsigned int points;

        static bool twoPlayers;
        Player* pPlayer1;
        Player* pPlayer2;

        //sf::Text

        EntityList entityList;
        
        float end;

    public:
        Level(StateMachine* psm, sID id_);
        virtual ~Level();
        
        static void setTwoPlayers(const bool b);

        void Draw();
        virtual void Update() = 0;
        void updateDeltaTime();
        void updateView();
        virtual void Reset() = 0;
        //Observers::PlayerInputManager* getPlayerInputManager() const;

        void setupLevel();
        void createMap();
        virtual std::string getFileName() = 0;
        virtual void CreateEntity(char id, sf::Vector2f pos) = 0;

        void CreatePlayer(sf::Vector2f pos);
        void CreateGround(sf::Vector2f pos);
        void CreateRandomPlatform(sf::Vector2f pos, const bool first);
        void CreateGrass(sf::Vector2f pos);
        void CreateRandomGrassPatch(sf::Vector2f pos, const bool first);
        void CreateSnake(sf::Vector2f pos, const bool random = false);

        void addEntity(Entities::Entity* pEntity);

        void saveLevel();

        const bool checkWipe()const;
        const bool checkDone()const;

        static const unsigned int getPoints();

    };
}