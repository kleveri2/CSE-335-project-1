#pragma once
#include "Item.h"
#include "Game.h"
/**
* Class for the Villian Object
*/
class CVillain : public CItem
{
public:

	CVillain(std::shared_ptr<CDeclaration> declaration, double x, double y, double width, double height);

	/** Accept a visitor
	 * \param visitor The visitor we accept
	 * \param gnome The gnome we accept
	 */
	virtual void Accept(CItemVisitor* visitor, CGnome* gnome) override { visitor->VisitItem(this, gnome); }

	virtual void UpdateGame(CGame* game);
	virtual void Update(double elapsed, std::vector<CItem*>* toRemove);

	virtual void ResetItem();

	/** Gets the speed of the villain
	* \return the speed of the villain
	*/
	CVector GetSpeed() { return mV; }

	/** Sets the speed of the villain
	* \param speed the speed new of the villain
	*/
	void SetSpeed(CVector speed) { mV = speed; }

	/**Gets the time
	* \return the time
	*/
	double GetTime() { return mTime; }

	/**sets the time
	* \param t the time to be set
	*/
	void SetTime(double t) { mTime = t; }

private:
	///Speed of the item
	CVector mV;

	///The time it's been moving
	double mTime;
};