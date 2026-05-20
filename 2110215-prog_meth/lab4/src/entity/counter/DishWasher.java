package entity.counter;

import entity.base.Updatable;
import entity.container.Dish;
import logic.Player;

public class DishWasher extends Counter implements Updatable {
	public DishWasher() {
		super("Dish Washer");
	}

	public void interact(Player p) {
		if (!this.isPlacedContentEmpty()) {
			super.interact(p);
			return;
		}
		if (p.isHandEmpty()) {
			return;
		}
		if (p.getHoldingItem() instanceof Dish) {
			Dish dish = (Dish) p.getHoldingItem();
			if (dish.isDirty()) {
				super.interact(p);
			}
			return;
		}
	}

	public void update() {
		if (this.isPlacedContentEmpty()) {
			return;
		}
		if (this.getPlacedContent() instanceof Dish) {
			Dish dish = (Dish) this.getPlacedContent();
			dish.clean(15);
		}
	}
}
