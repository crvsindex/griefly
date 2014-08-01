#include "Interface.h"

#include "Item.h"

void HumanInterface::InitSlots()
{
    r_hand_.SetPos(0, 14);
    r_hand_.GetView()->SetState("hand_r_inactive");
}

bool HumanInterface::Click(int x, int y)
{
    return false;
}

HumanInterface::~HumanInterface()
{
}

void HumanInterface::Draw()
{
    r_hand_.Draw();
}

unsigned int HumanInterface::hash() const
{
    unsigned int hash = 0;
    hash += r_hand_.hash_member();
    return hash;
}

void HumanInterface::Pick(id_ptr_on<Item> item)
{
    if (r_hand_.Get())
        return;
    r_hand_.Set(item);
}

void HumanInterface::Drop()
{
    r_hand_.Remove();
}

id_ptr_on<Item> HumanInterface::GetRHand()
{
    return r_hand_.Get();
}

std::ostream& operator<<(std::stringstream& file, HumanInterface& interf)
{
    interf.r_hand_.operator<<(file) << " ";
    return file;
}
std::istream& operator>>(std::stringstream& file, HumanInterface& interf)
{
    interf.r_hand_.operator>>(file);
    return file;
}