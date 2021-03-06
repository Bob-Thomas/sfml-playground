//
// Created by bob on 30-4-2015.
//

#ifndef CATRPG_CATEGORIES_H
#define CATRPG_CATEGORIES_H
namespace Category
{
    enum Type
    {
        None				= 0,
        SceneAirLayer		= 1 << 0,
        PlayerAircraft		= 1 << 1,
        AlliedAircraft		= 1 << 2,
        EnemyAircraft		= 1 << 3,
        Pickup				= 1 << 4,
        AlliedProjectile	= 1 << 5,
        EnemyProjectile		= 1 << 6,
        ParticleSystem      = 1 << 7,

        Aircraft = PlayerAircraft | AlliedAircraft | EnemyAircraft,
        Projectile = AlliedProjectile | EnemyProjectile,
    };
}
#endif //CATRPG_CATEGORIES_H
