#include "Weapon.h"

int Weapon::GetTotalDamage()
{
    int nTotalDamage = m_nBaseDamage;
    for (int i = 0; i < m_nUpgradeCount; i++)
    {
        nTotalDamage *= m_dUpgradeMultiplier;
    }
    return nTotalDamage;
}

int Weapon::GetBaseDamage()
{
    return m_nBaseDamage;
}

void Weapon::SetBaseDamage(int nDamage)
{
    m_nBaseDamage = nDamage;
}

int Weapon::GetUpgradeCount()
{
    return m_nUpgradeCount;
}

void Weapon::SetUpgradeCount(int nCount)
{
    m_nUpgradeCount = nCount;
}

Weapon::Weapon()
{
    m_nUpgradeCount = 0;
    m_dUpgradeMultiplier = 1.5;
    m_nBaseDamage = 5;
}
