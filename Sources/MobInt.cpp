#include "MobInt.h"
#include "Mob.h"
#include "MapClass.h"
#include "Turf.h"

IMob::IMob()
{
    thisMobControl = false;
    onMobControl = false;
    SetFreq(1);
    SetSprite("icons/ork.png");        
}

void IMob::cautOverMind()
{
    if(onMobControl)
    {
    }
};

void IMob::processGUI()
{
}

void IMob::delThis()
{
    DeinitGUI();
    cautOverMind();
    IOnMapObject::delThis();
}

void IMob::processGUImsg(const Message& msg)
{;
    if (msg.text == "SDLK_UP")
        checkMove(D_UP);
    else if (msg.text == "SDLK_DOWN")
        checkMove(D_DOWN);
    else if (msg.text == "SDLK_LEFT")
        checkMove(D_LEFT);
    else if (msg.text == "SDLK_RIGHT")
        checkMove(D_RIGHT);
}

void IMob::processPhysics()
{
    IMessageReceiver::processPhysics();
    if(thisMobControl) 
        GetManager()->UpdateVisible();
}

bool IMob::checkMove(Dir direct)
{
    if(IMovable::checkMove(direct))
    {        
        
        if(thisMobControl)
        {            
            //SYSTEM_STREAM << "Function IMob::checkMove called: onMobControl == true\n";
            GetManager()->checkMove(direct);
            GetManager()->UpdateVisible();
        }
        return true;
    }
    return false;
}