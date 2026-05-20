package entity.counter;

import entity.base.Choppable;
import entity.base.Ingredient;
import logic.Player;

public class ChoppingBoard extends Counter {
	public ChoppingBoard() {
		super("Chopping Board");
	}

	public void interact(Player p) {
		if (!super.isPlacedContentEmpty()) {
			super.interact(p);
			return;
		}
		if (p.isHandEmpty()) {
			return;
		}
		if (p.getHoldingItem() instanceof Ingredient) {
			super.interact(p);
			if(super.getPlacedContent() instanceof Choppable) {
				Choppable c = (Choppable) super.getPlacedContent();
				c.chop();
			}
		}
	}
}
