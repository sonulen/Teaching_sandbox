/*
 * NVI.h
 */

#ifndef MEYERS55_RULES_35_NVI_H_
#define MEYERS55_RULES_35_NVI_H_

namespace Meyers_Effective_C_55 {

class Character {
public:
	int what_about_health () {
		return this->get_health_value();
	}

	virtual ~Character() {};
protected:
	int health = 100;

private:
	virtual int get_health_value() const {
		return this->health;
	}
};

class Double_Health_Character : public Character {
public:
	~Double_Health_Character() override {};
private:
	int get_health_value() const override {
		return (2 * this->health);
	}
};

Character* create_default_unit () {
	return new Character;
}

Character* create_fat_unit () {
	return new Double_Health_Character;
}
}


#endif /* MEYERS55_RULES_35_NVI_H_ */
