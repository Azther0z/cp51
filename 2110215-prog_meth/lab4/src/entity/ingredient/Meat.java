package entity.ingredient;

import entity.base.Choppable;
import entity.base.Cookable;
import entity.base.Ingredient;
import logic.StringUtil;

public class Meat extends Ingredient implements Choppable, Cookable {

	private boolean chopState;
	private int cookedPercentage;

	public Meat() {
		super("Meat");
		this.setChopState(false);
		this.setCookedPercentage(0);
	}

	private void cookSteak() {
		this.setCookedPercentage(this.getCookedPercentage() + 10);
		int x = this.getCookedPercentage();
		if (0 < x && x <= 50) {
			this.setName("Raw Meat");
			this.setEdible(false);
		} else if (50 < x && x <= 80) {
			this.setName("Medium Rare Steak");
			this.setEdible(true);
		} else if (80 < x && x <= 100) {
			this.setName("Well Done Steak");
			this.setEdible(true);
		} else if (100 < x) {
			this.setName("Burnt Steak");
			this.setEdible(false);
		}
	}

	private void cookBurger() {
		this.setCookedPercentage(this.getCookedPercentage() + 15);
		int x = this.getCookedPercentage();
		if (0 < x && x <= 80) {
			this.setName("Raw Burger");
			this.setEdible(false);
		} else if (80 < x && x <= 100) {
			this.setName("Cooked Burger");
			this.setEdible(true);
		} else if (100 < x) {
			this.setName("Burnt Burger");
			this.setEdible(false);
		}
	}

	@Override
	public void cook() {
		if (this.isChopped()) {
			cookBurger();
		} else {
			cookSteak();
		}
	}

	@Override
	public boolean isBurnt() {
		if (this.getCookedPercentage() > 100) {
			return true;
		}
		return false;
	}

	@Override
	public void chop() {
		if (!this.isChopped()) {
			this.setName("Minced Meat");
			this.setChopState(true);
		}
	}

	@Override
	public boolean isChopped() {
		return chopState;
	}

	public void setChopState(boolean chopState) {
		this.chopState = chopState;
	}

	public int getCookedPercentage() {
		return cookedPercentage;
	}

	public void setCookedPercentage(int cookedPercentage) {
		if (cookedPercentage < 0) {
			cookedPercentage = 0;
		}
		this.cookedPercentage = cookedPercentage;
	}

	@Override
	public String toString() {
		return StringUtil.formatNamePercentage(this.getName(), this.getCookedPercentage());
	}

}
