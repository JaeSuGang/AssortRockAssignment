#include <iostream>
#include "Player.h"
#include "World.h"
#include "Weapon.h"

int main()
{
    UPlayer NewPlayer;
    UWorld World;
    Weapon DefaultWeapon{};
    DefaultWeapon.SetBaseDamage(5);
    NewPlayer.Equip(&DefaultWeapon);

    World.InPlayer(NewPlayer);
}
