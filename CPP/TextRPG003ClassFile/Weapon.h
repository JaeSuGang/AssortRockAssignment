#pragma once
class Weapon
{
public:
	int GetTotalDamage();
	int GetBaseDamage();
	void SetBaseDamage(int nDamage);
	int GetUpgradeCount();
	void SetUpgradeCount(int nCount);

public:
	Weapon();

protected:
	int m_nBaseDamage;
	double m_dUpgradeMultiplier;
	int m_nUpgradeCount;

};

