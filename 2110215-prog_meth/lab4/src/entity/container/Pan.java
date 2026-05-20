package entity.container;

import entity.base.Container;
import entity.base.Cookable;
import entity.base.Ingredient;

public class Pan extends Container {

	public Pan() {
		super("Pan", 1);
	}

	@Override
	public boolean verifyContent(Ingredient i) {
		if (i == null) {
			return false;
		}
		return i instanceof Cookable;
	}

	public void cook() {
		if (!this.isEmpty()) {
			for (Ingredient i : this.getContent()) {
				if (i instanceof Cookable) {
					Cookable c = (Cookable) i;
					c.cook();
				}
			}
		}
	}
}
