//
// Created by bob on 30-4-2015.
//

#ifndef CATRPG_PLAYER_H
#define CATRPG_PLAYER_H

#include <SFML/Window/Event.hpp>
#include <map>
#include <src/command/command.h>

class CommandQueue;

class Player
{
public:
    enum Action
    {
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown,
        Fire,
        LaunchMissile,
        ActionCount
    };

    enum MissionStatus
    {
        MissionRunning,
        MissionSuccess,
        MissionFailure
    };


public:
    Player();

    void					handleEvent(const sf::Event& event, CommandQueue& commands);
    void					handleRealtimeInput(CommandQueue& commands);

    void					assignKey(Action action, sf::Keyboard::Key key);
    sf::Keyboard::Key		getAssignedKey(Action action) const;

    void 					setMissionStatus(MissionStatus status);
    MissionStatus 			getMissionStatus() const;

private:
    void					initializeActions();
    static bool				isRealtimeAction(Action action);


private:
    std::map<sf::Keyboard::Key, Action>		mKeyBinding;
    std::map<Action, Command>				mActionBinding;
    MissionStatus 							mCurrentMissionStatus;
};


#endif //CATRPG_PLAYER_H
