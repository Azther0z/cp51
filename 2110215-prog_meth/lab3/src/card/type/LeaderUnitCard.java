package card.type;

import card.base.UnitCard;
import player.Player;

//You CAN modify the first line
public class LeaderUnitCard extends UnitCard {

	private int buffPower;
	private int buffHealth;

	public LeaderUnitCard(String name, String flavorText, int bloodCost, int power, int health, int buffPower,
			int buffHealth) {
		super(name, flavorText, bloodCost, power, health);
		this.setBuffHealth(buffHealth);
		this.setBuffPower(buffPower);
	}

	@Override
	public int attackUnit(UnitCard u) {
		int damage = u.getHealth() < this.getPower() ? u.getHealth() : this.getPower();
		u.setHealth(u.getHealth() - damage);
		return damage;
	}

	public void buffUnit(UnitCard[] alliesCard) {
		for (UnitCard card : alliesCard) {
			if (card != null) {
				card.setHealth(card.getHealth() + this.getBuffHealth());
				card.setPower(card.getPower() + this.getBuffPower());
			}
		}
	}

	@Override
	public String toString() {
		return super.getName() + " (POW: " + super.getPower() + ", HP: " + super.getHealth() + " | POW Inc: "
				+ this.getBuffPower() + ", HP Inc: " + this.getBuffHealth() + ")";
	}

	public int getBuffPower() {
		return buffPower;
	}

	public void setBuffPower(int buffPower) {
		if (buffPower < 0) {
			this.buffPower = 0;
		} else {

			this.buffPower = buffPower;

		}
	}

	public int getBuffHealth() {
		return buffHealth;
	}

	public void setBuffHealth(int buffHealth) {
		if (buffHealth < 0) {
			this.buffHealth = 0;
		} else {

			this.buffHealth = buffHealth;

		}
	}
}