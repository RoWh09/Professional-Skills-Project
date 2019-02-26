#pragma once

//Each type of enemy will have their own method of approach
//aim (or lack of)
//fire(or explosion)
//might have reload
//and will be looking aimlessly around if the player is invisible
class IEnemy
{
public:
	virtual ~IEnemy() {}

	virtual void Approach() = 0;
	virtual void Aim() = 0;
	virtual void Fire() = 0;
	virtual void Reload() = 0;
	virtual void Looking() = 0;

};