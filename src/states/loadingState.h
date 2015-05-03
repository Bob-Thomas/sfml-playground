//
// Created by bob on 2-5-2015.
//

#ifndef CATRPG_LOADINGSTATE_H
#define CATRPG_LOADINGSTATE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <src/stateArchitecture/stateStack.h>
#include <src/asyncTasks/parallelTask.h>

class LoadingState : public State
{
public:
    LoadingState(StateStack& stack, Context context);

    virtual void			draw();
    virtual bool			update(sf::Time dt);
    virtual bool			handleEvent(const sf::Event& event);

    void					setCompletion(float percent);

private:
    sf::Text				mLoadingText;
    sf::RectangleShape		mProgressBarBackground;
    sf::RectangleShape		mProgressBar;

    ParallelTask			mLoadingTask;
};
#endif //CATRPG_LOADINGSTATE_H
