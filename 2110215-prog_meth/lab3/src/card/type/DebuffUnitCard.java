package card.type;

import card.base.UnitCard;
import player.Player;

//You CAN modify the first line
public class DebuffUnitCard extends UnitCard {

	private int debuffPower;

	public DebuffUnitCard(String name, String flavorText, int bloodCost, int power, int health, int debuffPower) {
		super(name, flavorText, bloodCost, power, health);
		this.setDebuffPower(debuffPower);
	}

	@Override
	public int attackUnit(UnitCard u) {
		int damage = u.getHealth() < this.getPower() ? u.getHealth() : this.getPower();
		u.setHealth(u.getHealth() - damage);
		u.setPower(u.getPower() - this.getDebuffPower());
		return damage;
	}

	public int getDebuffPower() {
		return debuffPower;
	}

	public void setDebuffPower(int debuffPower) {

		if (debuffPower < 0) {
			this.debuffPower = 0;
		} else {
			this.debuffPower = debuffPower;
		}
	}

}
