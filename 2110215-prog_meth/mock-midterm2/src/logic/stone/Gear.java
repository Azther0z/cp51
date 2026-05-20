package logic.stone;

import logic.game.GameManager;
import utils.GameUtilities;

public class Gear extends HardStone {
	private int upgradeValue;

	public Gear(int posX, int posY, int upgradeValue) {
		super(posX, posY, 2);
		this.setUpgradeValue(upgradeValue);
	}

	public Gear(int posX, int posY) {
		super(posX, posY, 2);
		this.setUpgradeValue(1);
	}

	@Override
	public void destroy() {
		GameManager.getInstance().addDigPower(this.getUpgradeValue());
		GameUtilities.removeStone(this);
	}

	public int getUpgradeValue() {
		return upgradeValue;
	}

	public void setUpgradeValue(int upgradeValue) {
		if (upgradeValue < 1) {
			this.upgradeValue = 1;
		} else {
			this.upgradeValue = upgradeValue;
		}
	}

}
