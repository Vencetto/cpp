
#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

public:

	PlasmaRifle();
	~PlasmaRifle();
	PlasmaRifle(PlasmaRifle const & src);
	PlasmaRifle &operator=(PlasmaRifle const & src);

	void attack() const;
};

#endif