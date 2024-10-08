#pragma once

#include <stdlib.h>

namespace States
{
	enum class sID
	{
		empty		  = -1,
		MainMenu	  =  0,
		pauseMenu	  =  1,
		newGameMenu   =  2,
		loadSave	  =  3,
		gameOver	  =  4,
		leaderBoard	  =  5,
		Evening		  =	 6,
		Dawn		  =	 7		
	};

	class StateMachine;

	class State
	{
	protected:
		sID id;
		bool isRuning;
		StateMachine* pSM;
		static State* previousState;
	public:
		State(StateMachine* psm = NULL, sID id_ = sID::empty);
		virtual ~State();
		
		void setSM(StateMachine* psm);
		const sID getStateID()const;
		const bool getIsRuning()const;
		void changeState(sID id_);

		virtual void Update() = 0;
		virtual void Draw()	  = 0;
		virtual void Reset();

		static State* getPreviousState();
	};
}